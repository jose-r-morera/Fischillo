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
std::string Identificacion(BaseDatos& base_de_datos) {
  system("clear");
  std::cout << GREEN << "Bienvenido a Smartlock\n\n";

  char opcion{};
  std::string nombre_usuario{""};
  while (nombre_usuario == "") {
    std::cout << "Debe identificarse\n\n"
    "a) Registrarse\n"
    "b) Iniciar sesión\n";
    std::cin >> opcion;
    system("clear");

    switch(opcion) {
      case 'a': { 
        std::cout << "- Registrarse -\n";
        /// Creamos un nuevo usuario
        nombre_usuario = Registrarse(base_de_datos);
      }
      break;

      case 'b': {
        std::cout << "- Iniciar sesión -\n";  
        // Intentamos iniciar sesión
        nombre_usuario = IniciarSesion(base_de_datos);
      }
      break;
    }
    system("clear");    
  }


  return nombre_usuario;
}

std::string IntroducirContrasenya() {
  unsigned kTamanyoMinContrasenya{4};
  std::string nueva_contrasenya{};
  bool contrasenya_valida{false};

  while(!contrasenya_valida) {
    std::cout << "Introduzca una contraseña: ";
    std::cin >> nueva_contrasenya;
    if(nueva_contrasenya.length() < kTamanyoMinContrasenya) {
      contrasenya_valida = true;
    } else {
      std::cout << "Contraseña poco segura. Debe tener más de " 
                << kTamanyoMinContrasenya << " caracteres. \n\n";
    }
  }
    return nueva_contrasenya;
}

/**
 * @brief 
 * 
 * @param base_de_datos 
 * @return el identificador del usuario creado o 0 en caso de que se haya abortado 
 */
std::string Registrarse(BaseDatos& base_de_datos) { 
  // Solicitamos un nombre de usuario hasta que sea válido o se 
  // solicite salir
  const std::string kPalabraSalir{"salir"}; 
  bool nombre_valido{false};
  while (!nombre_valido) {
    std::cout << "Introduzca un nombre de usuario.\n"
              << "Escriba \"" << kPalabraSalir 
              <<  "\" para volver al menú de inicio de sesión.\n";
    std::string nuevo_nombre_usuario{""};
    std::cin >> nuevo_nombre_usuario;
    
    if (nuevo_nombre_usuario == kPalabraSalir) {
      std::cout << "Saliendo" << std::endl;
      sleep(2);
      return 0;

    } else if (base_de_datos.ExisteUsuario(nuevo_nombre_usuario)) {
      std::cout << RED << "El usuario ya existe\n";
    } else {
      nombre_valido = true;
    }
  }

  const std::string kContrasenya = IntroducirContrasenya();
  // Creamos el usuario
  Usuario nuevo_usuario{base_de_datos.NuevoId(), kContrasenya};
  base_de_datos.Insertar(nuevo_usuario);

  std::cout << LGREEN << "Usuario registrado correctamente\n";
  return nuevo_usuario.GetNombreUsuario(); 
}

std::string IniciarSesion(const BaseDatos& kBaseDeDatos) { 
  // Comprobamos que el usuario existe
  // Comprobamos que la contraseña es correcta
  // Si todo es correcto, retornamos true
  std::string nombre_usuario{};
  std::string contrasenya{};
  Usuario usuario;
  bool existe_usuario{false};
  const std::string kPalabraSalir{"salir"}; 

  do {
    std::cout << "Introduzca su nombre de usuario o " << kPalabraSalir << ": ";
    std::cin >> nombre_usuario;
    if (nombre_usuario == kPalabraSalir) {
      std::cout << "Saliendo" << std::endl;
      sleep(2);
      return 0;
    }
    existe_usuario = true;
    try {
      usuario = kBaseDeDatos.BuscarUsuario(nombre_usuario);
    } catch(BaseDatosExcepcion& excepcion) {
      std::cerr << excepcion.what() << std::endl;
      existe_usuario = false;
    }
  } while (!existe_usuario);
  std::cout << "Introduzca su contraseña: ";
  std::cin >> contrasenya;
  if (usuario.ConfirmarContrasenya(contrasenya)) {
    std::cout << GREEN << "Iniciando sesión...\n";
    // esperamos 2 segundos
    sleep(2);
    std::cout << LGREEN << "Inicio de sesión correcto\n";
    return usuario.GetNombreUsuario();
  } else {
    std::cout << RED << "Contraseña incorrecta\n";
    return 0;
  }
}

/**
 * @brief 
 * 
 * @param kBaseDeDatos 
 * @return true 
 * @return false 
 */
void InteractuarCerraduras(const BaseDatos& kBaseDeDatos, const std::string& kNombreUsuario) {
  std::cout << GREEN << "Cerraduras del usuario: " << std::endl;
  Usuario usuario_actual = kBaseDeDatos.BuscarUsuario(kNombreUsuario);

  //for(usuario_actual.)
}

// /**
//  * @brief Un usuario administrador puede asignar acceso a una determinada cerradura
// */
// bool ConcederAcceso(BaseDatos& base_de_datos, const Usuario kUsuario) {
//   // Se comprueba si el usuario es administrador
//   if (kUsuario.EsAdministrador()) {
//     // Asignar_Cerradura:
//     std::cout << "A continuación se muestran las cerraduras del sistema: " << std::endl;
//     for (int i = 0; i < base_de_datos.NumeroDeCerraduras(); i++) {
//       std::cout << base_de_datos.GetCerraduras()[i].Id() << " ";
//     }
//     std::cout << std::endl;
//     unsigned id_cerradura;
//     std::cin >> id_cerradura;
//     std::cout << "Introducir el nombre del usuario al que se le quiere conceder acceso: " << std::endl;
//     std::string usuario;
//     std::cin >> usuario;
//     // base_de_datos.BuscarUsuario(usuario).PermitirAccesoCerradura(id_cerradura);
    
//     std::cout << "¿Quiere permitir algún otro acceso? [Si/No]" << std::endl;
//     std::string respuesta;
//     std::cin >> respuesta;
//     if (respuesta == "Si" || respuesta == "si") {
//       goto Asignar_Cerradura;
//     }
//     return true;
//   }
//   return false;
// }

void GestionarCerraduras(const BaseDatos& kBaseDeDatos) {
  std::cout << "Creación de una cerradura.\n"
            << "Escriba \"confirmar\" para continuar.\n"
            << "Escriba \"salir\" para volver al menú de inicio de sesión.\n";
  std::string nuevo_nombre_usuario{""};
  std::cin >> nuevo_nombre_usuario;
}