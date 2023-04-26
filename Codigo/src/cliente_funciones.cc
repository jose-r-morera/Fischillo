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
 * @param[out]  base_de_datosla base de datos con los usuarios existentes que se usa para verificar la identidad 
                        o añadir nuevos usuarios.
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
 * @brief Se crea un nuevo usuario con un nombre de usuario único (que no puede existir todavía)
 *        se solicita la contraseña, que debe tener una longitud mínima. Emplea la función auxiliar
 *        IntroducirContrasenya.
 *
 * @param[out] base_de_datos la base de datos en la que se almacena el nuevo usuario creado. 
 * @return el identificador del usuario creado o una cadena vacía en caso de que se haya abortado el registro.
 */
std::string Registrarse(BaseDatos& base_de_datos) {
  // Solicitamos un nombre de usuario hasta que sea válido o se solicite salir
  const std::string kPalabraSalir{"salir"};
  bool nombre_valido{false};
  std::string nuevo_nombre_usuario{""};
  while (!nombre_valido) {
    std::cout << "Introduzca un nombre de usuario.\n"
              << "Escriba \"" << kPalabraSalir << "\" para volver al menú de inicio de sesión.\n\n";
    std::cin >> nuevo_nombre_usuario;

    if (nuevo_nombre_usuario == kPalabraSalir) {
      std::cout << "Saliendo" << std::endl;
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
      std::cout << "Saliendo" << std::endl;
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
    return usuario.GetNombreUsuario();
  } else {
    std::cout << RED << "Contraseña incorrecta\n" << RESET;
    sleep(2);
    return "";
  }
}

/**
 * @brief Permite al usuario interactuar con las cerraduras a las que tiene acceso. Se muestra su nombre y su estado.
 *
 * @param base_datos
 * @return true
 * @return false
 */
void InteractuarCerraduras(BaseDatos& base_datos, const std::string& kNombreUsuario) {
  std::cout << GREEN << "Cerraduras del usuario\n " << RESET;
  Usuario usuario_actual = base_datos.BuscarUsuario(kNombreUsuario);

  /// Para cada cerradura mostramos un número, su nombre y su estado
  unsigned numero_cerradura{1};
  for(const unsigned kIdCerradura : usuario_actual.GetCerradurasPermitidas()) {
    const CerraduraInteligente kCerradura = base_datos.BuscarCerradura(kIdCerradura);
    std::cout << numero_cerradura << ") " << kCerradura.Nombre() << " -> ";
    if (kCerradura.Abierto()) {
      std::cout << GREEN << "ABIERTA\n" << RESET;
    } else {
      std::cout << RED << "CERRADA\n" << RESET;
    }
  }

  std::cout << "\nIntroduzca el número de la cerradura que desea abrir o cerrar\n"
                "(Si está abierta se cerrrará y viceversa)\n";
  unsigned numero_leido_cerradura{};
  std::cin >> numero_leido_cerradura;
  
  if(numero_cerradura > usuario_actual.GetCerradurasPermitidas().size()) {
    std::cout << RED << "Número incorrecto\n" << RESET;
  } else {
    unsigned id_cerradura_seleccionada = usuario_actual.GetCerradurasPermitidasAt(numero_leido_cerradura);
    CerraduraInteligente cerradura_seleccionada = base_datos.BuscarCerradura(id_cerradura_seleccionada);
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
bool ConcederAcceso(BaseDatos& base_de_datos, const Usuario kUsuario) {
  std::string respuesta = "si";
  while (respuesta == "si" || respuesta == "Si") {
    // Se comprueba si el usuario es administrador
    if (kUsuario.EsAdministrador()) {
      // Asignar_Cerradura:
      std::cout << "A continuación se muestran las cerraduras del sistema: " << std::endl;
      for (int i = 0; i < base_de_datos.NumeroDeCerraduras(); i++) {
        std::cout << base_de_datos.GetCerraduras()[i].Nombre() << " (" << base_de_datos.GetCerraduras()[i].Id() << ")" << std::endl;
      }
      std::cout << std::endl;
      unsigned id_cerradura;
      std::cin >> id_cerradura;
      std::cout << "Introducir el nombre del usuario al que se le quiere conceder acceso: " << std::endl;
      std::string usuario;
      std::cin >> usuario;
      Usuario usuario_encontrado = base_de_datos.BuscarUsuario(usuario);
      usuario_encontrado.PermitirAccesoCerradura(id_cerradura);

      std::cout << "El usuario " << usuario << " tiene acceso a " << std::endl;
      for (unsigned i = 0; i < usuario_encontrado.GetCerradurasPermitidas().size(); i++) {
        std::cout << base_de_datos.BuscarCerradura(usuario_encontrado.GetCerradurasPermitidasAt(i)).Nombre() << " (" << usuario_encontrado.GetCerradurasPermitidasAt(i) << ")" << std::endl;
      }

      std::cout << "¿Quiere permitir algún otro acceso? [Si/No]" << std::endl;
      std::cin >> respuesta;
      if (respuesta == "no" || respuesta == "No") {
        return true;
      }
    }
  }
  return false;
}

void GestionarCerraduras(const BaseDatos& kBaseDeDatos) {
  std::cout << "Creación de una cerradura.\n"
            << "Escriba \"confirmar\" para continuar.\n"
            << "Escriba \"salir\" para volver al menú de inicio de sesión.\n";
  std::string nuevo_nombre_usuario{""};
  std::cin >> nuevo_nombre_usuario;
}
