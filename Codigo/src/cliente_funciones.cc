/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura:  Fundamentos de Ingeniería del software
 * Curso:       2º
 * Proyecto: App Smartlock
 *
 * @authors  María Ferrándiz Díaz, alu0101475899@ull.edu.es
 *           Hugo Hernández Martín, alu01014812276@ull.edu.es
 *           Valerio Luis Cabrera, alu0101476049@ull.edu.es
 *           José Ramón Morera Campos, alu0101471846@ull.edu.es
 *           Steven Rogriguez Morales, alu0101477381@ull.edu.es
 * @date    12/04/2023
 * @file    cliente.cc
 * @brief   Programa cliente. Aplicación para la gestión de cerraduras inteligentes.
 *
 * @see
 *
 * Historial de revisiones
 *          12/04/2023 - Creación (primera versión) del código
 */
#include "cliente_funciones.h"
#include "colores.h"
#include <unistd.h>  // para poder usar sleep

// Retorna la ID del usuario
unsigned Identificacion(const BaseDatos& kBaseDeDatos) {
  system("clear");
  std::cout << GREEN << "Bienvenido a Smartlock\n\n";
  std::cout << "Debe identificarse\n\n"
  "a) Registrarse\n"
  "b) Iniciar sesión\n";
  char opcion{};
  std::cin >> opcion;

  switch(opcion) {
    case 'a': { 
      std::cout << "- Registrarse -\n";
      /// Creamos un nuevo usuario
      Registrarse(kBaseDeDatos);
    }
    break;

    case 'b': {
      std::cout << "- Iniciar sesión -\n";  
      // Intentamos iniciar sesión
      IniciarSesion(kBaseDeDatos);
    }
    break;
  } 
  return 0;
}

bool Registrarse(const BaseDatos& kBaseDeDatos) { 
  // Comprobamos que el usuario no existe
  // Si no existe, creamos el usuario
  std::cout << "Introduzca un nombre de usuario: ";
  std::string nuevo_nombre_usuario{};
  std::cin >> nuevo_nombre_usuario;
  for (auto usuario : kBaseDeDatos.GetUsuarios()) {
    if (usuario.GetNombreUsuario() == nuevo_nombre_usuario) {
      std::cout << RED << "El usuario ya existe\n";
      return false;
    }
  }
  std::cout << "Introduzca una contraseña: ";
  std::string nueva_contrasena{};
  std::cin >> nueva_contrasena;
  // almacenamos la contraseña en la base de datos
  // no sé hacer que la contrasseña quede registrada en el atributo de la clase Usuario @joserra ayuda 
  std::cout << LGREEN << "Usuario registrado correctamente\n";
  return true; 
}

bool IniciarSesion(const BaseDatos& kBaseDeDatos) { 
  // Comprobamos que el usuario existe
  // Comprobamos que la contraseña es correcta
  // Si todo es correcto, retornamos true
  std::cout << "Introduzca su nombre de usuario: ";
  std::string nombre_usuario{};
  std::cin >> nombre_usuario;
  std::cout << "Introduzca su contraseña: ";
  std::string contrasena{};
  std::cin >> contrasena;
  for (auto usuario : kBaseDeDatos.GetUsuarios()) {
    if (usuario.GetNombreUsuario() == nombre_usuario) {
      if (usuario.ConfirmarContrasenya(contrasena)) {
        std::cout << GREEN << "Iniciando sesión...\n";
        // esperamos 2 segundos
        sleep(2);
        std::cout << LGREEN << "Inicio de sesión correcto\n";
        return true;
      } else {
        std::cout << RED << "Contraseña incorrecta\n";
        return false;
      }
    } else {
      std::cout << RED << "El usuario no existe\n";
      return false;
    }
  }
  std::cout << BOLD << RED << "Error al iniciar sesión\n";
  return false; 
}

bool InteractuarCerraduras(const BaseDatos& kBaseDeDatos) {
  
}

/**
 * @brief Un usuario administrador puede asignar acceso a una determinada cerradura
*/
bool ConcederAcceso(const BaseDatos& kBaseDeDatos, const Usuario kUsuario) {
  // Se comprueba si el usuario es administrador
  if (kUsuario.GetAdministrador()) {
    Asignar_Cerradura:
    std::cout << "A continuación se muestran las cerraduras pertencientes al sistema: " << std::endl;
    for (int i = 0; i < kBaseDeDatos.NumeroDeCerraduras(); i++) {
      std::cout << kBaseDeDatos.GetCerraduras()[i].Id() << " ";
    }
    std::cout << std::endl;
    unsigned id_cerradura;
    std::cin >> id_cerradura;
    std::cout << "Introducir el nombre del usuario al que se le quiere conceder acceso: " << std::endl;
    std::string usuario;
    std::cin >> usuario;
    kBaseDeDatos.BuscarUsuario(usuario).PermitirAccesoCerradura(id_cerradura);
    std::cout << "¿Quiere permitir algún otro acceso? [Si/No]" << std::endl;
    std::string respuesta;
    std::cin >> respuesta;
    if (respuesta == "Si" || respuesta == "si") {
      goto Asignar_Cerradura;
    }
    return true;
  }
  return false;
}