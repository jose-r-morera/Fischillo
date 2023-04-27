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

#include <unistd.h>  // para poder usar sleep y ocultar contraseña

#include <iostream>

#include "colores.h"

/**
 * @brief Permite al usuario identificarse iniciando sesión o creando una cuenta.
 *
 * @param[out]  base_de_datos la base de datos con los usuarios existentes que se usa para verificar
 la identidad o añadir nuevos usuarios.
 * @return el nombre del usuario que se ha identificado
 */
std::string Identificacion(BaseDatos& base_de_datos) {
  char opcion{};
  std::string nombre_usuario{""};
  while (nombre_usuario == "") {
    std::cout << "Debe identificarse\n\n"
                 "a) Registrarse\n"
                 "b) Iniciar sesión\n";
    std::cin >> opcion;
    system("clear");

    switch (opcion) {
      case 'a': {
        std::cout << "- Registrarse -\n";
        /// Creamos un nuevo usuario
        nombre_usuario = Registrarse(base_de_datos);
      } break;
      // En caso de que el usuario decida iniciar sesión,
      case 'b': {
        std::cout << "- Iniciar sesión -\n";
        // Intentamos iniciar sesión
        nombre_usuario = IniciarSesion(base_de_datos);
      } break;
    }
    system("clear");
  }
  return nombre_usuario;
}

/**
 * @brief Permite leer una contraseña, que debe tener una longitud mayor a kTamanyoMinContrasenya
 *        la contraseña no es mostrada por pantalla, puesto que se usa la función getpass();
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
 * @brief
 *        se solicita la contraseña, que debe tener una longitud mínima. Emplea la función auxiliar
 *        IntroducirContrasenya.
 *
 * @param[out] base_de_datos la base de datos en la que se almacena el nuevo usuario creado.
 * @return el identificador del usuario creado o una cadena vacía en caso de que se haya abortado el
 * registro.
 */
std::string Registrarse(BaseDatos& base_de_datos) {
  std::cout << "Ha seleccionado la opción: registrarse\n\n";
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

  std::cout << LGREEN << "Usuario registrado correctamente\n";
  sleep(2);
  return nuevo_usuario.GetNombreUsuario();
}

/**
 * @brief El usuario introduce un nombre de usuario existente y una contraseña para identificarse.
 *
 * @param kBaseDeDatos la base de datos en la que se consulta el usuario y contraseña
 * @return el nombre del usuario que se ha identificado o un string vacío si no se ha identificado.
 */
std::string IniciarSesion(const BaseDatos& kBaseDeDatos) {
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
    } catch (BaseDatosExcepcion& excepcion) {
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
    return usuario.GetNombreUsuario();  // devolvemos el nombre del usuario que se ha identificado
  } else {
    std::cout << RED << "Contraseña incorrecta\n" << RESET;
    sleep(2);
    return "";
  }
}

void MostrarMenu(BaseDatos& base_datos, const Usuario& kUsuario) {
  bool salir{false};
  while (!salir) {
    // El panel de menú permite al usuario elegir una de las siguientes opciones:
    //  - Interactuar con las cerraduras a las que tiene acceso
    //  - Gestionar cerraduras (añadir, eliminar, modificar)
    //  - Conceder acceso a un usuario
    system("clear");
    // Comprobamos si el usuario es administrador o no, en caso de que lo sea le permitimos conceder
    // acceso a otros y si no lo es, no se muestra esto
    if (kUsuario.EsAdministrador()) {
      std::cout << ITALIC << BOLD << PURPLE << "Bienvenido " << UNDERLINE
                << kUsuario.GetNombreUsuario() << "(administrador)\n\n"
                << RESET;
      std::cout << "1. Interactuar con cerraduras\n"
                << "2. Gestionar cerraduras\n"
                << "3. Conceder acceso a un usuario\n"
                << "4. Salir\n\n";
    } else {
      std::cout << ITALIC << BOLD << PURPLE << "Bienvenido " << UNDERLINE
                << kUsuario.GetNombreUsuario() << "\n\n"
                << RESET;
      std::cout << "1. Interactuar con cerraduras\n"
                << "2. Salir\n\n";
    }

    // Preguntamos al usuario lo que desea hacer y comprobamos que la opción es válida
    std::cout << GREEN << "Opción: " << RESET;
    unsigned opcion{0};
    std::cin >> opcion;

    while (opcion < 1 || opcion > 4) {
      std::cout << RED << "Opción no válida. Introduzca un número entre 1 y 4\n" << RESET;
      std::cout << YELLOW << "Opción: ";
      std::cin >> opcion;
      std::cout << RESET;
      sleep(1);
    }
    system("clear");
    std::cout << ITALIC << "Ha seleccionado la opción: " << RESET;
    // Ejecutamos la opción elegida
    switch (opcion) {
      case 1:
        std::cout << PURPLE << "Interactuar con cerraduras\n\n" << RESET;
        InteractuarCerraduras(base_datos, kUsuario);
        break;
      case 2:
        if (kUsuario.EsAdministrador()) {
          std::cout << PURPLE << "Gestionar cerraduras\n\n" << RESET;
          GestionarCerraduras(base_datos);
        } else {
          salir = true;
        }
        break;
      case 3:
        if (kUsuario.EsAdministrador()) {
          std::cout << PURPLE << "Conceder acceso a un usuario\n\n" << RESET;
          ConcederAcceso(base_datos, kUsuario);
        } else {
          salir = true;
        }
        break;
      case 4:
        salir = true;
        break;
      default:
        std::cout << "Opción no válida. Introduzca un número entre 1 y 4\n" << RESET;
    }
  }
  std::cout << GREEN << "Salir -> Saliendo...\n" << RESET;
  sleep(2);
  system("clear");
  std::cout << BOLD << PURPLE << "😀🔑 Muchas gracias por contar con FISchillo, ¡Hasta pronto! 🔑😀\n"
            << RESET;
  std::cout << GREEN
            << "Estamos trabajando en posibles mejoras.\nSi tiene alguna sugerencia, no dude en "
               "contactar con nuestro equipo.\n"
            << RESET;
  sleep(3.5);
  system("clear");
}

/**
 * @brief Permite al usuario interactuar con las cerraduras a las que tiene acceso. Se muestra su
 * nombre y su estado.
 *
 * @param base_datos
 * @return true
 * @return false
 */
void InteractuarCerraduras(BaseDatos& base_datos, const Usuario& kUsuario) {
  std::cout << GREEN << "Cerraduras del usuario\n" << RESET;

  /// Para cada cerradura mostramos un número, su nombre y su estado
  unsigned numero_listado_cerraduras{1};
  for (const unsigned kIdCerradura : kUsuario.GetCerradurasPermitidas()) {
    const CerraduraInteligente& kCerradura = base_datos.BuscarCerradura(kIdCerradura);
    std::cout << numero_listado_cerraduras << ") " << kCerradura.Nombre() << " -> ";
    if (kCerradura.Abierto()) {
      std::cout << GREEN << "ABIERTA\n" << RESET;
    } else {
      std::cout << RED << "CERRADA\n" << RESET;
    }
    ++numero_listado_cerraduras;
  }

  std::cout << "\nIntroduzca el número de la cerradura que desea abrir o cerrar\n"
               "(Si está abierta se cerrará y viceversa)\n";
  unsigned numero_leido_cerradura{};
  std::cin >> numero_leido_cerradura;
  if (numero_leido_cerradura > kUsuario.GetCerradurasPermitidas().size()) {
    std::cout << RED << "Número incorrecto\n" << RESET;
    sleep(1);
  } else {
    unsigned id_cerradura_seleccionada =
        kUsuario.GetCerradurasPermitidasAt(numero_leido_cerradura - 1);
    CerraduraInteligente& cerradura_seleccionada =
        base_datos.BuscarCerradura(id_cerradura_seleccionada);
    cerradura_seleccionada.Interaccion();
    std::cout << LGREEN << "Cerradura '" << cerradura_seleccionada.Nombre() << "' ";
    if (cerradura_seleccionada.Abierto()) {
      std::cout << "abierta\n\n" << RESET;
    } else {
      std::cout << RED << "cerrada\n\n" << RESET;
    }
    sleep(1);
  }
}

/**
 * @brief Un usuario administrador puede asignar acceso a una determinada cerradura
 */
void ConcederAcceso(BaseDatos& base_datos, const Usuario& kUsuario) {
  std::string respuesta = "si";
  // Se comprueba si el usuario es administrador
  if (kUsuario.EsAdministrador()) {
    while (respuesta == "si" || respuesta == "Si" || respuesta == "sí" || respuesta == "Sí") {
      // Asignar_Cerradura:
      std::cout << "A continuación se muestran las cerraduras del sistema: " << std::endl;
      const std::vector<CerraduraInteligente> kCerraduras = base_datos.GetCerraduras();
      for (const auto& kCerradura : kCerraduras) {
        std::cout << "· " << LBLUE << kCerradura.Nombre() << RESET << CYAN << " ("
                  << kCerradura.Id() << ")" << RESET << std::endl;
      }
      std::cout << "\nIntroduzca el ID de la cerradura a la que se quiere acceder (o \"salir\"):" << std::endl;
      std::string id_cerradura;
      std::cin >> id_cerradura;
      if (id_cerradura == "salir") { return; } // Salir de la funcion 
      while (!(base_datos.ExisteCerradura(stoi(id_cerradura)))) {
        std::cout << RED << "La ID introducida no existe. Ingrésela de nuevo: " << RESET
                  << std::endl;
        std::cin >> id_cerradura;
        if (id_cerradura == "salir") { return; } // Salir de la funcion 
      }
      std::cout << "Introducir el nombre del usuario al que se le quiere conceder acceso:"
                << std::endl;
      std::string usuario;
      std::cin >> usuario;
      ///
      while (!(base_datos.ExisteUsuario(usuario))) {
        std::cout << RED << "El usuario introducido no existe. Ingréselo de nuevo: " << RESET
                  << std::endl;
        std::cin >> usuario;
      }
      Usuario& usuario_encontrado = base_datos.BuscarUsuario(usuario);
      usuario_encontrado.PermitirAccesoCerradura(stoi(id_cerradura));

      std::cout << "El usuario " << MAGENTA << usuario << RESET << " tiene acceso a: " << std::endl;
      for (unsigned i = 0; i < usuario_encontrado.GetCerradurasPermitidas().size(); i++) {
        std::cout
            << CYAN
            << base_datos.BuscarCerradura(usuario_encontrado.GetCerradurasPermitidasAt(i)).Nombre()
            << RESET << BLUE << " (" << usuario_encontrado.GetCerradurasPermitidasAt(i) << ")"
            << RESET << std::endl;
      }

      std::cout << "¿Quiere permitir algún otro acceso? [Si/No]" << std::endl;
      std::cin >> respuesta;
      if (respuesta == "no" || respuesta == "No") {
        break;
      }
    }
  } else {
    std::cerr << RED << "El usuario " << RESET << kUsuario.GetNombreUsuario() << RED
              << " no dispone de permisos de administrador." << RESET << std::endl;
  }
}

/**
 * @brief Añadir y eliminar cerraduras
 *
 * @param base_datos
 */
void GestionarCerraduras(BaseDatos& base_datos) {
  // Borrar un salto de linea anterior a esta funcion para que no sea leido como opcion
  std::string limpiar{};
  std::getline(std::cin, limpiar);
  // Gestion
  while (true) {
    std::cout << "Escriba \"crear\" o \"borrar\" para continuar.\n"
              << "Escriba cualquier otra cosa para volver al menu.\n";
    sleep(1);
    std::string opcion{};
    std::getline(std::cin, opcion);
    if (opcion == "crear") {
      std::cout << "Nombre para la cerradura:\n";
      std::string nombre_cerradura{};
      std::getline(std::cin, nombre_cerradura);
      // Insertar
      base_datos.Insertar(CerraduraInteligente{base_datos.NuevoId(), nombre_cerradura});
      std::cout << GREEN <<"¡Cerradura creada con éxito!\n\n" << RESET;
    }  else if (opcion == "borrar") {
      // Mostrar cerraduras
      std::cout << "A continuación se muestran las cerraduras del sistema: " << std::endl;
      const std::vector<CerraduraInteligente> kCerraduras = base_datos.GetCerraduras();
      for (const auto& kCerradura : kCerraduras) {
        std::cout << "· " << LBLUE << kCerradura.Nombre() << RESET << CYAN << " ("
                  << kCerradura.Id() << ")" << RESET << std::endl;
      }
      // Eliminar
      std::cout << "Id de la cerradura que desea borrar:\n";
      std::string id_cerradura{};
      std::getline(std::cin, id_cerradura);
      if (base_datos.EliminarCerradura(stoi(id_cerradura))) {
        std::cout << GREEN << "¡Cerradura eliminada con éxito!\n\n" << RESET;
      }  else {
        std::cout << "No existe ninguna cerradura con la id introducida\n\n";
      }
    }  else {
      break;
    }
  }
}
