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
#include "identificacion.h"

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
      std::cout << ITALIC << BOLD << PURPLE << "Bienvenido " << UNDERLINE << AQUA
                << usuario.GetNombreUsuario() << RESET << BOLD << " (administrador)\n\n"
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

    // Preguntamos al usuario lo que desea hacer y comprobamos que la opción es válida
    std::cout << GREEN << "Opción: " << RESET;
    std::string texto_opcion{};
    std::cin >> texto_opcion;
    unsigned opcion{};
    try {
      opcion = stoi(texto_opcion);
    } catch (...) {
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
        std::cout << RED << "Opción no válida. Reintroduzca su opción:\n" << RESET;
        sleep(2);
    }
  }
  std::cout << GREEN << "Abandonando el sistema...\n" << RESET;
  sleep(2);
  system("clear");
  std::cout << BOLD << PURPLE << "😀🔑 Muchas gracias por contar con FISchillo, ¡Hasta pronto! 🔑😀\n"
            << RESET;
  std::cout << GREEN
            << "Estamos trabajando en posibles mejoras.\nSi tiene alguna "
               "sugerencia, no dude en contactar con nuestro equipo.\n"
            << RESET;
  sleep(3);
  system("clear");
}

inline std::string PedirUsuario(const BaseDatos &kBaseDatos) {
  std::cout << "Introducir el nombre del usuario al que se le quiere "
               "modificar acceso (o " << CYAN << "\"salir\" " << RESET << "):"
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
              << "El usuario introducido no existe. Pruebe de nuevo o escriba " << RESET << "\"salir\""
              << RED " : " << RESET
              << std::endl;
    std::cin  >> usuario;
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

  std::cout << "\nIntroduzca el id de la cerradura que desea abrir o cerrar\n" <<
               "(Si está" << LGREEN << " abierta" << RESET << " se " 
                          << RED << "cerrará " << RESET << "y viceversa)\n";
  std::string numero_leido_cerradura_str{};
  std::cin >> numero_leido_cerradura_str;
  unsigned numero_leido_cerradura{};
  try {
    numero_leido_cerradura = stoi(numero_leido_cerradura_str);
  } catch (...) {
    std::cout << RED << "Opción no válida. Reintroduzca su opción:\n" << RESET;
    sleep(1);
    return;
  }
  if (numero_leido_cerradura > kUsuario.GetCerradurasPermitidas().size()) {
    std::cout << RED << "Número incorrecto\n" << RESET;
    sleep(1);
  } else {
    try {
      unsigned id_cerradura_seleccionada = kUsuario.GetCerradurasPermitidasAt(numero_leido_cerradura - 1);
      CerraduraInteligente &cerradura_seleccionada = base_datos.BuscarCerradura(id_cerradura_seleccionada);
      cerradura_seleccionada.Interaccion();
      std::cout << LGREEN << "Cerradura '" << cerradura_seleccionada.Nombre() << "' ";
      if (cerradura_seleccionada.Abierto()) {
        base_datos.Insertar(acceso{kUsuario.GetNombreUsuario(), id_cerradura_seleccionada, "Abrir"});
        std::cout << GREEN << "abierta\n\n" << RESET;
      } else {
        base_datos.Insertar(acceso{kUsuario.GetNombreUsuario(), id_cerradura_seleccionada, "Cerrar"});
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
    std::cout << "Escriba " << AQUA << "\"crear\" " << RESET << "o " 
              << MAGENTA << "\"borrar\"" << RESET << " para continuar.\n"
              << "Escriba cualquier otra cosa para volver al menú.\n";
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
      std::cout << BOLD << "· " << RESET  << LBLUE << kCerradura.Nombre() << RESET << CYAN << " ("
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
          std::cout << CYAN << "Volviendo al menú principal...\n" << RESET;
        } else {
          std::cerr << RED << "La id introducida no es numérica.\n" << RESET;
          sleep(2);
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
                 "añadir (o " << AQUA << "\"salir\"" << RESET << "):"
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
        std::cout << CYAN << "Volviendo al menú principal...\n" << RESET;
        return;  // Salir de la función
      } else {
        std::cerr << RED << "La id introducida no es numérica.\n" << RESET;
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
            << MAGENTA << usuario << RESET << std::endl;
  std::vector<unsigned> cerraduras_acceso{
      base_datos.BuscarUsuario(usuario).GetCerradurasPermitidas()};
  const std::vector<CerraduraInteligente> kCerraduras = base_datos.GetCerraduras();
  for (const auto &kCerradura : kCerraduras) {
    for (const auto id_cerradura : cerraduras_acceso) {
      if (id_cerradura == kCerradura.Id()) {
        std::cout << BOLD << "· " << RESET << LBLUE << kCerradura.Nombre() << RESET << CYAN << " ("
                  << kCerradura.Id() << ")" << RESET << std::endl;
      }
    }
  }

  unsigned id_numerica{0};
  bool cerradura_valida{false};
  while (!cerradura_valida) {
    std::cout << "\nIntroduzca el ID de la cerradura que se quiere "
                 "eliminar (o " << AQUA << "\"salir\"" << RESET << "):"
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
        std::cout << CYAN << "Volviendo al menú principal...\n" << RESET;
        return;  // Salir de la función
      } else {
        std::cerr << RED << "La id introducida no es numérica.\n" << RESET;
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
          std::cerr << RED << "Opción introducida erronea." << RESET << std::endl;
          return;
      }
      // Comprobar si desea continuar
      std::cout << "¿Quiere permitir o retirar algún otro acceso? " << PURPLE 
                << "[Si/No]" << RESET << std::endl;
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
                << "El nombre de usuario introducido ya se encuentra asignado a otro usuario." << std::endl
                << RESET << "Introduzca otro nombre: " << std::endl;
      std::cin  >> nuevo_nombre_usuario_1;
    }
    std::cout << "Introduza de nuevo el nombre de usuario:" << std::endl;
    std::cin  >> nuevo_nombre_usuario_2;
    if (nuevo_nombre_usuario_1 == nuevo_nombre_usuario_2) {
      usuario.SetNombreUsuario(nuevo_nombre_usuario_1);
      std::cout << "Se ha establecido " << CYAN << nuevo_nombre_usuario_1 << RESET
                << " como nombre de la cuenta." << std::endl;
      sleep(1);
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
      std::cerr << RED << "No se puede introducir la misma contraseña." << RESET << std::endl
                << "Introduzca la nueva contraseña:" << std::endl;
      nueva_contrasenya_1 = IntroducirContrasenya();
    }
    std::cout << "Introduza de nuevo la contraseña:" << std::endl;
    nueva_contrasenya_2 = IntroducirContrasenya();
    if (nueva_contrasenya_1 == nueva_contrasenya_2) {
      usuario.SetContrasenya(nueva_contrasenya_1);
      std::cout << "Se ha establecido la nueva contraseña del usuario "
                << CYAN << usuario.GetNombreUsuario() << RESET << "." << std::endl;
      sleep(1);
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
  std::cout << PURPLE << "¿Qué datos se desea cambiar? " << RESET << std::endl
            << CYAN << "1. " << RESET << " Modificar nombre de usuario" << std::endl
            << CYAN << "2. " << RESET << " Modificar contraseña" << std::endl
            << CYAN << "3. " << RESET << " Salir" << std::endl;

  std::string texto_opcion{};
  std::cin >> texto_opcion;
  unsigned opcion{};
  try {
    opcion = stoi(texto_opcion);
  } catch (...) {
    std::cerr << RED << "¡La opción debe ser numérica!\n" << RESET;
    return;
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
      std::cout << CYAN << "Volviendo al menú principal..." << RESET << std::endl;
      sleep(1);
      break;
    default:
      std::cout << RED << "Opción no válida. Reintroduzca su opción:\n" << RESET;
      break;
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
    std::cout << PURPLE << "Seleccione el criterio de búsqueda para los registros:\n" << RESET
              << CYAN << "a.- " << RESET << "Nombre de usuario\n"
              << CYAN << "b.- " << RESET << "Id de Cerradura\n"
              << CYAN << "c.- " << RESET << "Salir\n\n";
    char opcion{};
    std::cin >> opcion;

    switch (opcion) {
      case 'a': {
        std::string nombre_usuario{PedirUsuario(kBaseDatos)};
        if (nombre_usuario == "salir") {
          return;
        } else {
          system("clear");
          std::cout << "Registros del usuario " << PURPLE << nombre_usuario << RESET << '\n';
          std::vector<acceso> registros{kBaseDatos.ObtenerRegistro(nombre_usuario)};
          for (const acceso &kAcceso : registros) {
            std::cout << kAcceso << '\n';
          }
        }
      } break;
      case 'b': {
        bool cerradura_valida{false};
        unsigned id_numerica{};
        while (!cerradura_valida) {
          std::cout << "\nIntroduzca el ID de la cerradura que se quiere "
                       "consultar (o " << AQUA << "\"salir\"" << RESET << "):"
                     << std::endl;
          std::string id_cerradura;
          std::cin >> id_cerradura;
          try {
            id_numerica = stoi(id_cerradura);
            if (!(kBaseDatos.ExisteCerradura(id_numerica))) {
              std::cout << RED << "La ID introducida no existe." << RESET << std::endl;
            } else {
              cerradura_valida = true;
            }
          } catch (...) {
            if (id_cerradura == "salir" || id_cerradura == "Salir") {
              std::cout << CYAN << "Volviendo al menú principal...\n" << RESET;
              return;  // Salir de la función
            } else {
              std::cerr << RED << "La id introducida no es numérica.\n" << RESET;
            }
          }
        }
        system("clear");
        std::cout << "Registros de la cerradura " << PURPLE << id_numerica << RESET << '\n';
        std::vector<acceso> registros{kBaseDatos.ObtenerRegistro(id_numerica)};
        for (const acceso &kAcceso : registros) {
          std::cout << kAcceso << '\n';
        }
        break;
      }
      case 'c':
        salir = true;
        break;
      default:
        std::cout << RED << "Opción no válida. Reintroduzca su opción:\n" << RESET;
    }
  }
}
