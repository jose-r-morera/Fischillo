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
 * @brief   Programa cliente. Aplicación para la gestión de cerraduras
 * inteligentes.
 *
 * @see
 *
 * Historial de revisiones
 *          12/04/2023 - Creación (primera versión) del código
 */

#include "cliente_funciones.h"

#include <unistd.h>  // para poder usar sleep y ocultar contraseña

#include <iostream>
#include <limits>

#include "colores.h"

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
 * @brief
 *        se solicita la contraseña, que debe tener una longitud mínima. Emplea
 * la función auxiliar IntroducirContrasenya.
 *
 * @param[out] base_de_datos la base de datos en la que se almacena el nuevo
 * usuario creado.
 * @return el identificador del usuario creado o una cadena vacía en caso de que
 * se haya abortado el registro.
 */
std::string Registrarse(BaseDatos &base_de_datos) {
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

/**
 * @brief Muestra las distintas opciones del menú por pantalla.
 *
 * @param base_datos
 * @param kUsuario
 */
void MostrarMenu(BaseDatos &base_datos, Usuario &usuario) {
  bool salir{false};
  while (!salir) {
    // El panel de menú permite al usuario elegir una de las siguientes
    // opciones:
    //  - Interactuar con las cerraduras a las que tiene acceso
    //  - Gestionar cerraduras (añadir, eliminar, modificar)
    //  - Conceder acceso a un usuario
    system("clear");
    // Comprobamos si el usuario es administrador o no, en caso de que lo sea le
    // permitimos conceder acceso a otros y si no lo es, no se muestra esto
    if (usuario.EsAdministrador()) {
      std::cout << ITALIC << BOLD << PURPLE << "Bienvenido " << UNDERLINE
                << usuario.GetNombreUsuario() << "(administrador)\n\n"
                << RESET;
      std::cout << CYAN << "1. " << RESET << "Interactuar con cerraduras\n"
                << CYAN << "2. " << RESET << "Modificar datos del usuario\n"
                << CYAN << "3. " << RESET << "Gestionar cerraduras\n"
                << CYAN << "4. " << RESET << "Cambiar permisos a un usuario\n"
                << CYAN << "5. " << RESET << "Consultar registros\n"
                << CYAN << "6. " << RESET << "Salir\n\n";
    } else {
      std::cout << ITALIC << BOLD << PURPLE << "Bienvenido " << UNDERLINE
                << usuario.GetNombreUsuario() << "\n\n"
                << RESET;
      std::cout << CYAN << "1. " << RESET << "Interactuar con cerraduras\n"
                << CYAN << "2. " << RESET << "Modificar datos del usuario\n"
                << CYAN << "3. " << RESET << "Salir\n\n";
    }

    // Preguntamos al usuario lo que desea hacer y comprobamos que la opción es
    // válida
    std::cout << GREEN << "Opción: " << RESET;
    std::string texto_opcion{};
    std::cin >> texto_opcion;

    unsigned opcion;
    try {
      opcion = stoi(texto_opcion);

      while (opcion < 1 || opcion > 6) {
        std::cout << RED << "Opción no válida. Introduzca uno de los números i\n" << RESET;
        std::cout << GREEN << "Opción: " << RESET;
        std::cin >> opcion;
        std::cout << RESET;
        sleep(1);
      }
      system("clear");
      std::cout << ITALIC << "Ha seleccionado la opción: " << RESET;
      // Ejecutamos la opción elegida
      switch (opcion) {
        case 1:
          std::cout << PURPLE << "Interactuar con cerraduras.\n\n" << RESET;
          InteractuarCerraduras(base_datos, usuario);
          break;
        case 2:
          std::cout << PURPLE << "Modificar datos del usuario.\n\n" << RESET;
          ModificarCuentaUsuario(base_datos, usuario);
          break;
        case 3:
          if (usuario.EsAdministrador()) {
            std::cout << PURPLE << "Gestionar cerraduras.\n\n" << RESET;
            GestionarCerraduras(base_datos);
          } else {
            salir = true;
          }
          break;
        case 4:
          if (usuario.EsAdministrador()) {
            std::cout << PURPLE << "Cambiar permisos a un usuario.\n\n" << RESET;
            CambiarPermisos(base_datos);
          }
          break;
        case 5:
          if (usuario.EsAdministrador()) {
            std::cout << PURPLE << "Consultar registros.\n\n" << RESET;
            ConsultarRegistros(base_datos);
          }
          break;
        case 6:
          salir = true;
          break;
        default:
          std::cout << "Opción no válida.\n";
      }
    } catch (...) {
      std::cerr << RED << "¡La opción debe ser numérica!\n" << RESET;
      sleep(2);
    }
  }
  std::cout << GREEN << "Salir -> Saliendo...\n" << RESET;
  sleep(2);
  system("clear");
  std::cout << BOLD << PURPLE << "😀🔑 Muchas gracias por contar con FISchillo, ¡Hasta pronto! 🔑😀\n"
            << RESET;
  std::cout << GREEN
            << "Estamos trabajando en posibles mejoras.\nSi tiene alguna "
               "sugerencia, no dude en "
               "contactar con nuestro equipo.\n"
            << RESET;
  sleep(3);
  system("clear");
}

inline std::string PedirUsuario(const BaseDatos &kBaseDatos) {
  std::cout << "Introducir el nombre del usuario al que se le quiere "
               "modificar acceso, (o \"salir\"):"
            << std::endl;
  std::string usuario{};
  std::cin >> usuario;
  // Mientras que el usuario introducido no sea encontrado en la base de
  // datos, se mostrará por pantalla este error
  while (!(kBaseDatos.ExisteUsuario(usuario))) {
    if (usuario == "salir" || usuario == "Salir") {
      std::cout << CYAN << "Volviendo al menú anterior..." << RESET << std::endl;
      sleep(1);
      return "salir";
    }
    std::cout << RED
              << "El usuario introducido no existe. Pruebe de nuevo o escriba \"salir\": " << RESET
              << std::endl;
    std::cin >> usuario;
  }
  return usuario;
}

/**
 * @brief Permite al usuario interactuar con las cerraduras a las que tiene
 * acceso. Se muestra su nombre y su estado.
 *
 * @param base_datos
 * @return true
 * @return false
 */
void InteractuarCerraduras(BaseDatos &base_datos, const Usuario &kUsuario) {
  std::cout << GREEN << "Cerraduras del usuario\n" << RESET;

  /// Para cada cerradura mostramos un número, su nombre y su estado
  unsigned numero_listado_cerraduras{1};
  for (const unsigned kIdCerradura : kUsuario.GetCerradurasPermitidas()) {
    try {
      const CerraduraInteligente &kCerradura = base_datos.BuscarCerradura(kIdCerradura);
      std::cout << numero_listado_cerraduras << ") " << kCerradura.Nombre() << " -> ";
      if (kCerradura.Abierto()) {
        std::cout << GREEN << "ABIERTA\n" << RESET;
      } else {
        std::cout << RED << "CERRADA\n" << RESET;
      }
      ++numero_listado_cerraduras;
    } catch (CerraduraNoExiste &excepcion_cerradura) {
      // Excepción en caso de que no se encuentre la cerradura:
      std::cerr << RED << excepcion_cerradura.what() << RESET << std::endl;
    }
  }

  std::cout << "\nIntroduzca el número de la cerradura que desea abrir o cerrar\n"
               "(Si está abierta se cerrará y viceversa)\n";
  unsigned numero_leido_cerradura{};
  std::cin >> numero_leido_cerradura;
  if (numero_leido_cerradura > kUsuario.GetCerradurasPermitidas().size()) {
    std::cout << RED << "Número incorrecto\n" << RESET;
    sleep(1);
  } else {
    try {
      unsigned id_cerradura_seleccionada =
          kUsuario.GetCerradurasPermitidasAt(numero_leido_cerradura - 1);
      CerraduraInteligente &cerradura_seleccionada =
          base_datos.BuscarCerradura(id_cerradura_seleccionada);
      cerradura_seleccionada.Interaccion();
      std::cout << LGREEN << "Cerradura '" << cerradura_seleccionada.Nombre() << "' ";
      if (cerradura_seleccionada.Abierto()) {
        base_datos.Insertar(
            acceso{kUsuario.GetNombreUsuario(), id_cerradura_seleccionada, "Abrir"});
        std::cout << "abierta\n\n" << RESET;
      } else {
        base_datos.Insertar(
            acceso{kUsuario.GetNombreUsuario(), id_cerradura_seleccionada, "Cerrar"});
        std::cout << RED << "cerrada\n\n" << RESET;
      }
      sleep(2);
    } catch (CerraduraNoExiste &excepcion_cerradura) {
      // Excepción en caso de que no se encuentre la cerradura:
      std::cerr << RED << excepcion_cerradura.what() << RESET << std::endl;
    }
  }
}

/**
 * @brief Añadir y eliminar cerraduras
 *
 * @param base_datos
 */
void GestionarCerraduras(BaseDatos &base_datos) {
  // Borrar un salto de linea anterior a esta funcion para que no sea leido como
  // opcion
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
      std::cout << GREEN << "¡Cerradura creada con éxito!\n\n" << RESET;
    } else if (opcion == "borrar") {
      // Mostrar cerraduras
      std::cout << "A continuación se muestran las cerraduras del sistema: " << std::endl;
      const std::vector<CerraduraInteligente> kCerraduras = base_datos.GetCerraduras();
      for (const auto &kCerradura : kCerraduras) {
        std::cout << "· " << LBLUE << kCerradura.Nombre() << RESET << CYAN << " ("
                  << kCerradura.Id() << ")" << RESET << std::endl;
      }
      // Eliminar
      std::cout << "Id de la cerradura que desea borrar:\n";
      std::string id_cerradura{};
      std::getline(std::cin, id_cerradura);
      try {
        if (base_datos.EliminarCerradura(stoi(id_cerradura))) {
          std::cout << GREEN << "¡Cerradura eliminada con éxito!\n\n" << RESET;
        } else {
          std::cerr << RED << "No existe ninguna cerradura con la id introducida\n\n" << RESET;
        }
      } catch (...) {
        if (id_cerradura == "salir" || id_cerradura == "Salir") {
          std::cout << CYAN << "Saliendo...\n" << RESET;
        } else {
          std::cerr << "La id introducida no es numérica.\n";
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return;
      }
    } else {
      break;
    }
  }
}

void ConcederPermiso(BaseDatos &base_datos, const std::string &usuario) {
  // Asignar_Cerradura:
  std::cout << "A continuación se muestran las cerraduras del sistema: " << std::endl;
  const std::vector<CerraduraInteligente> kCerraduras = base_datos.GetCerraduras();
  for (const auto &kCerradura : kCerraduras) {
    std::cout << BOLD << "· " << RESET << LBLUE << kCerradura.Nombre() << RESET << CYAN << " ("
              << kCerradura.Id() << ")" << RESET << std::endl;
  }

  unsigned id_numerica{0};
  bool cerradura_valida{false};
  while (!cerradura_valida) {
    std::cout << "\nIntroduzca el ID de la cerradura que se quiere "
                 "añadir (o \"salir\"):"
              << std::endl;
    std::string id_cerradura;
    std::cin >> id_cerradura;
    try {
      id_numerica = stoi(id_cerradura);
      if (!(base_datos.ExisteCerradura(id_numerica))) {
        std::cout << RED << "La ID introducida no existe." << RESET << std::endl;
      } else {
        cerradura_valida = true;
      }
    } catch (...) {
      if (id_cerradura == "salir" || id_cerradura == "Salir") {
        std::cout << CYAN << "Saliendo...\n" << RESET;
        return;  // Salir de la función
      } else {
        std::cerr << "La id introducida no es numérica.\n";
      }
    }
  }

  try {
    Usuario &usuario_encontrado = base_datos.BuscarUsuario(usuario);
    usuario_encontrado.PermitirAccesoCerradura(id_numerica);
    system("clear");
    std::cout << GREEN << "Cerradura añadida con éxito\n"
              << RESET << "El usuario " << MAGENTA << usuario << RESET << " tiene acceso a:\n";
    for (unsigned i = 0; i < usuario_encontrado.GetCerradurasPermitidas().size(); i++) {
      std::cout
          << CYAN
          << base_datos.BuscarCerradura(usuario_encontrado.GetCerradurasPermitidasAt(i)).Nombre()
          << RESET << BLUE << " (" << usuario_encontrado.GetCerradurasPermitidasAt(i) << ")"
          << RESET << std::endl;
    }
  } catch (CerraduraNoExiste &excepcion_cerradura) {
    // Excepción en caso de que no se encuentre la cerradura:
    std::cerr << RED << excepcion_cerradura.what() << RESET << std::endl;
  }
}

void EliminarPermiso(BaseDatos &base_datos, const std::string &usuario) {
  std::cout << "A continuación se muestran las cerraduras a las que tiene acceso el usuario: "
            << std::endl;
  std::vector<unsigned> cerraduras_acceso{
      base_datos.BuscarUsuario(usuario).GetCerradurasPermitidas()};
  for (const auto id_cerradura : cerraduras_acceso) {
    std::cout << BOLD << "· " << RESET << CYAN << id_cerradura << RESET << std::endl;
  }

  unsigned id_numerica{0};
  bool cerradura_valida{false};
  while (!cerradura_valida) {
    std::cout << "\nIntroduzca el ID de la cerradura que se quiere "
                 "eliminar (o \"salir\"):"
              << std::endl;
    std::string id_cerradura;
    std::cin >> id_cerradura;
    try {
      id_numerica = stoi(id_cerradura);
      if (!(base_datos.ExisteCerradura(id_numerica))) {
        std::cout << RED << "La ID introducida no existe." << RESET << std::endl;
      } else {
        cerradura_valida = true;
      }
    } catch (...) {
      if (id_cerradura == "salir" || id_cerradura == "Salir") {
        std::cout << CYAN << "Saliendo...\n" << RESET;
        return;  // Salir de la función
      } else {
        std::cerr << "La id introducida no es numérica.\n";
      }
    }
  }
  // Eliminar
  try {
    Usuario &usuario_encontrado = base_datos.BuscarUsuario(usuario);
    usuario_encontrado.RetirarAccesoCerradura(id_numerica);
    system("clear");
    std::cout << GREEN << "Cerradura eliminada con éxito\n"
              << RESET << "El usuario " << MAGENTA << usuario << RESET << " tiene acceso a:\n";
    for (unsigned i = 0; i < usuario_encontrado.GetCerradurasPermitidas().size(); i++) {
      std::cout
          << CYAN
          << base_datos.BuscarCerradura(usuario_encontrado.GetCerradurasPermitidasAt(i)).Nombre()
          << RESET << BLUE << " (" << usuario_encontrado.GetCerradurasPermitidasAt(i) << ")"
          << RESET << std::endl;
    }
  } catch (CerraduraNoExiste &excepcion_cerradura) {
    // Excepción en caso de que no se encuentre la cerradura:
    std::cerr << RED << excepcion_cerradura.what() << RESET << std::endl;
  }
}

/**
 * @brief Un usuario administrador puede asignar acceso a una determinada
 * cerradura
 *
 * @param base_datos
 * @param kUsuario
 */
void CambiarPermisos(BaseDatos &base_datos) {
  bool seguir{true};
  while (seguir) {
    std::string usuario{PedirUsuario(base_datos)};
    if (usuario == "salir") {
      seguir = false;
    } else {
      // Que cambio realizar
      char opcion_realizar;
      std::cout << "¿Qué acción desea realizar?\n"
                << CYAN << "1. " << RESET << "Añadir permiso a usuario.\n"
                << CYAN << "2. " << RESET << "Eliminar permiso a usuario." << std::endl;
      std::cin >> opcion_realizar;
      // Al haber extraído solo un caracter, pueden quedar en el flujo
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      switch (opcion_realizar) {
        case '1':
          ConcederPermiso(base_datos, usuario);
          break;
        case '2':
          EliminarPermiso(base_datos, usuario);
          break;
        default:
          std::cerr << "Opción introducida erronea." << std::endl;
          return;
      }
      // Comprobar si desea continuar
      std::cout << "¿Quiere permitir o retirar algún otro acceso? [Si/No]" << std::endl;
      std::string respuesta{};
      std::cin >> respuesta;
      if (respuesta != "Si" && respuesta != "si") {
        seguir = false;
      }
    }
  }
}

/**
 * @brief Modifica el nombre de un usuario
 *
 * @param base_datos
 */
void CambiarNombreUsuario(BaseDatos &base_datos, Usuario &usuario) {
  std::cout << "Introduzca el nuevo nombre de usuario:" << std::endl;
  std::string nuevo_nombre_usuario_1{"1"}, nuevo_nombre_usuario_2{""};
  while (nuevo_nombre_usuario_1 != nuevo_nombre_usuario_2) {
    std::cin >> nuevo_nombre_usuario_1;
    while (base_datos.ExisteUsuario(nuevo_nombre_usuario_1)) {
      std::cerr << RED
                << "El nombre de usuario introducido ya se encuentra asignado a otro usuario."
                << "Introduzca otro nombre" << RESET << std::endl;
      std::cin >> nuevo_nombre_usuario_1;
    }
    std::cout << "Introduza de nuevo el nombre de usuario:" << std::endl;
    std::cin >> nuevo_nombre_usuario_2;
    if (nuevo_nombre_usuario_1 == nuevo_nombre_usuario_2) {
      usuario.SetNombreUsuario(nuevo_nombre_usuario_1);
      std::cout << "Se ha establecido " << CYAN << nuevo_nombre_usuario_1 << RESET
                << " como nombre de la cuenta." << std::endl;
      break;
    } else {
      std::cerr << RED << "Los nombres de usuario no coinciden" << RESET << std::endl;
    }
  }
}

/**
 * @brief Modifica la contraseña del usuario
 *
 * @param base_datos
 */
void CambiarContrasenyaUsuario(Usuario &usuario) {
  std::string nueva_contrasenya_1{"1"}, nueva_contrasenya_2{""};
  while (nueva_contrasenya_1 != nueva_contrasenya_2) {
    nueva_contrasenya_1 = IntroducirContrasenya();
    while (usuario.ConfirmarContrasenya(nueva_contrasenya_1)) {
      std::cerr << RED << "No se puede introducir la misma contraseña." << RESET << std::endl;
      std::cin >> nueva_contrasenya_1;
    }
    std::cout << "Introduza de nuevo la contraseña:" << std::endl;
    nueva_contrasenya_2 = IntroducirContrasenya();
    if (nueva_contrasenya_1 == nueva_contrasenya_2) {
      usuario.SetContrasenya(nueva_contrasenya_1);
      std::cout << "Se ha establecido " << CYAN << nueva_contrasenya_1 << RESET
                << " como contraseña del usuario " << CYAN << usuario.GetNombreUsuario() << RESET
                << "." << std::endl;
      break;
    } else {
      std::cerr << RED << "Las contraseñas introducidas no coinciden." << RESET << std::endl;
    }
  }
}

/**
 * @brief Permite a un usuario modificar sus atributos (nombre, contraseña...)
 *
 * @param base_datos
 * @param kUsuario
 */
void ModificarCuentaUsuario(BaseDatos &base_datos, Usuario &usuario) {
  int opcion{0};
  std::cout << PURPLE << "¿Qué datos se desea cambiar? " << RESET << std::endl
            << CYAN << "1. " << RESET << " Modificar nombre de usuario" << std::endl
            << CYAN << "2. " << RESET << " Modificar contraseña" << std::endl
            << CYAN << "3. " << RESET << " Salir" << std::endl;
  std::cin >> opcion;

  try {
    while (opcion < 1 || opcion > 6) {
      std::cout << RED << "Opción no válida. Introduzca uno de los números i\n" << RESET;
      std::cout << GREEN << "Opción: " << RESET;
      std::cin >> opcion;
      std::cout << RESET;
    }
    system("clear");
    switch (opcion) {
      case 1:
        std::cout << PURPLE << "Modificar nombre de usuario." << RESET << std::endl;
        CambiarNombreUsuario(base_datos, usuario);
        break;
      case 2:
        std::cout << PURPLE << "Modificar contraseña." << RESET << std::endl;
        CambiarContrasenyaUsuario(usuario);
        break;
      case 3:
        std::cout << "Saliendo al menú principal..." << std::endl;
        sleep(1);
        break;
      default:
        std::cout << RED << "Opción no válida. Reintroduzca su opción\n" << RESET;
        break;
    }
  } catch (...) {
    std::cerr << RED << "¡La opción debe ser numérica!\n" << RESET;
  }
}

/**
 * @brief Muestra los registros del sistema
 *
 * @param kBaseDatos
 */
void ConsultarRegistros(const BaseDatos &kBaseDatos) {
  bool salir{false};
  while (!salir) {
    std::cout << "Seleccione el criterio de búsqueda para los registros:\n"
                 "a) Nombre de usuario\n"
                 "b) Id de Cerradura\n"
                 "c) Salir\n\n";
    char opcion{char(std::cin.get())};

    switch (opcion) {
      case 'a': {
        std::string nombre_usuario{};
        std::cout << "Introduzca el nombre de usuario: ";
        std::cin >> nombre_usuario;
        while (!kBaseDatos.ExisteUsuario(nombre_usuario)) {
          std::cout << "Introduzca un nombre de usuario válido o \"salir\": ";
          std::cin >> nombre_usuario;
        }

        std::vector<acceso> registros{kBaseDatos.ObtenerRegistro(nombre_usuario)};
        for (const acceso &kAcceso : registros) {
          // std::cout << kAcceso;
        }
      } break;
      case 'b':
        break;
      case 'c':
        salir = true;
        break;
      default:
        std::cout << RED << "Opción no válida\n" << RESET;
    }
  }
}
