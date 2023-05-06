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
 * @file    identificacion.cc
 * @brief   Gestión identificación programa cliente
 *
 * @see
 *
 * Historial de revisiones
 *          6/05/2023 - Creación (primera versión) del código
 */


#include "cliente_funciones.h"

#include <unistd.h>  // para poder usar sleep y ocultar contraseña

#include <iostream>
#include <limits>

#include "colores.h"
#include "identificacion.h"

/**
 * @brief Permite al usuario identificarse iniciando sesión o creando una
 cuenta.
 *
 * @param[out]  base_de_datos la base de datos con los usuarios existentes que
 se usa para verificar la identidad o añadir nuevos usuarios.
 * @return el nombre del usuario que se ha identificado
 */
std::string Identificacion(BaseDatos &base_de_datos) {
  char opcion{};
  std::string nombre_usuario{""};
  while (nombre_usuario == "") {
    std::cout << "Debe identificarse\n\n"
              << CYAN << "a.- " << RESET << "Registrarse.\n"
              << CYAN << "b.- " << RESET << "Iniciar sesión.\n";
    std::cin >> opcion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("clear");

    switch (opcion) {
      case 'a': {
        std::cout << PURPLE << "- Registrarse -\n" << RESET;
        /// Creamos un nuevo usuario
        nombre_usuario = Registrarse(base_de_datos);
      } break;
      // En caso de que el usuario decida iniciar sesión,
      case 'b': {
        std::cout << PURPLE << "- Iniciar sesión -\n" << RESET;
        // Intentamos iniciar sesión
        nombre_usuario = IniciarSesion(base_de_datos);
      } break;
    }
    system("clear");
  }
  return nombre_usuario;
}

/**
 * @brief Permite leer una contraseña, que debe tener una longitud mayor a
 * kTamanyoMinContrasenya la contraseña no es mostrada por pantalla, puesto que
 * se usa la función getpass();
 *
 * @return la contraseña leída en texto plano
 */
std::string IntroducirContrasenya() {
  unsigned kTamanyoMinContrasenya{4};
  std::string nueva_contrasenya{};
  bool contrasenya_valida{false};

  /// Solicita la contraseña mientras no sea válida
  while (!contrasenya_valida) {
    nueva_contrasenya = getpass("Introduzca su contraseña: ");

    if (nueva_contrasenya.length() > kTamanyoMinContrasenya) {
      contrasenya_valida = true;
    } else {
      std::cout << RED << "Contraseña poco segura. Debe tener más de " << kTamanyoMinContrasenya
                << " caracteres. \n\n"
                << RESET << std::endl;
    }
  }
  return nueva_contrasenya;
}

/**
 * @brief se solicita la contraseña, que debe tener una longitud mínima. Emplea
 * la función auxiliar IntroducirContrasenya.
 *
 * @param[out] base_de_datos la base de datos en la que se almacena el nuevo
 * usuario creado.
 * @return el identificador del usuario creado o una cadena vacía en caso de que
 * se haya abortado el registro.
 */
std::string Registrarse(BaseDatos &base_de_datos) {
  std::cout << "Ha seleccionado la opción: " << PURPLE << "registrarse\n\n" << RESET;
  // Solicitamos un nombre de usuario hasta que sea válido o se solicite salir
  const std::string kPalabraSalir{"salir"};
  bool nombre_valido{false};
  std::string nuevo_nombre_usuario{""};
  while (!nombre_valido) {
    std::cout << "Introduzca un nombre de usuario.\n"
              << "Escriba \"" << kPalabraSalir << "\" para volver al menú de inicio de sesión.\n\n";
    std::cin >> nuevo_nombre_usuario;

    if (nuevo_nombre_usuario == kPalabraSalir) {
      std::cout << LGREEN << "\nSaliendo..." << RESET << std::endl;
      sleep(1);
      return "";
    } else if (base_de_datos.ExisteUsuario(nuevo_nombre_usuario)) {
      std::cout << RED << "El usuario ya existe\n" << RESET;
    } else {
      nombre_valido = true;
    }
  }

  const std::string kContrasenya = IntroducirContrasenya();
  // Creamos el usuario
  Usuario nuevo_usuario{nuevo_nombre_usuario, kContrasenya};
  base_de_datos.Insertar(nuevo_usuario);

  std::cout << LGREEN << "Usuario registrado correctamente\n" << RESET;
  sleep(2);
  return nuevo_usuario.GetNombreUsuario();
}

/**
 * @brief El usuario introduce un nombre de usuario existente y una contraseña
 * para identificarse.
 *
 * @param kBaseDeDatos la base de datos en la que se consulta el usuario y
 * contraseña
 * @return el nombre del usuario que se ha identificado o un string vacío si no
 * se ha identificado.
 */
std::string IniciarSesion(const BaseDatos &kBaseDeDatos) {
  std::string nombre_usuario{};
  Usuario usuario;
  bool existe_usuario{false};
  const std::string kPalabraSalir{"salir"};

  // Comprobamos que el usuario existe
  do {
    std::cout << "Introduzca su nombre de usuario o " << kPalabraSalir << ": ";
    std::cin >> nombre_usuario;
    if (nombre_usuario == kPalabraSalir) {
      std::cout << LGREEN << "\nSaliendo..." << RESET << std::endl;
      sleep(1);
      return "";
    }
    existe_usuario = true;
    try {
      usuario = kBaseDeDatos.BuscarUsuario(nombre_usuario);
    } catch (UsuarioNoExiste &excepcion) {
      std::cerr << RED << excepcion.what() << RESET << std::endl;
      existe_usuario = false;
    }
  } while (!existe_usuario);

  // Solicitamos la contraseña y comprobamos que es correcta
  std::string contrasenya = getpass("Introduzca su contraseña: ");
  if (usuario.ConfirmarContrasenya(contrasenya)) {
    std::cout << GREEN << "Iniciando sesión...\n";
    sleep(2);  // esperamos 2 segundos
    std::cout << LGREEN << "Inicio de sesión correcto\n" << RESET;
    sleep(2);
    return usuario.GetNombreUsuario();  // devolvemos el nombre del usuario que
                                        // se ha identificado
  } else {
    std::cout << RED << "Contraseña incorrecta\n" << RESET;
    sleep(2);
    return "";
  }
}