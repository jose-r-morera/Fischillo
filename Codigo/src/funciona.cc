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
 * @file    aplicacion.cc
 * @brief   Programa cliente. Aplicación para la gestión de cerraduras inteligentes.
 *
 * @see
 *
 * Historial de revisiones
 *          12/04/2023 - Creación (primera versión) del código
 */
#include <fstream>
#include <iostream>

#include "base_datos.h"

int main() {
  const std::string kFicheroBaseDatos{"base.datos"};
  std::cout << "Escriba 'a' para rehacer base de datos" << std::endl;
  std::string entrada{};
  std::cin >> entrada;
  if (entrada == "a") {
    BaseDatos base_datos_nueva{};
    // Open a file for writing
    std::ofstream ofs(kFicheroBaseDatos, std::ios::binary);
    // Serialize the object to the file
    base_datos_nueva.Serialize(ofs);
    // Close the file
    ofs.close();
  }

  // Leemos la base de datos del fichero que la contiene
  std::ifstream ifs(kFicheroBaseDatos, std::ios::binary);
  BaseDatos base_datos_leida{};
  base_datos_leida.Deserialize(ifs);  // Comentar para crear de cero
  ifs.close();

  std::cout << "¿Qué quieres hacer?\n"
               "a) Ver usuarios\n"
               "b) Añadir usuario\n"
               "c) Eliminar usuario\n";
  char opcion{};
  std::cin >> opcion;

  switch (opcion) {
    case 'a': {
      /// Vemos los usuarios existentes
      // Se muestran siempre xd
    } break;

    case 'b': {
      /// Creamos un usuario
      std::string nombre_introducido;
      std::cout << "Introduce nombre de usuario: ";
      std::cin >> nombre_introducido;
      base_datos_leida.Insertar(Usuario{nombre_introducido, "1234"});
    } break;

    case 'c': {
      // Eliminamos un usuario
      std::string nombre_usuario_eliminar;
      std::cout << "Introduce nombre del usuario a eliminar: ";
      std::cin >> nombre_usuario_eliminar;
      base_datos_leida.EliminarUsuario(nombre_usuario_eliminar);
    } break;
  }

  std::vector<Usuario> usuarios = base_datos_leida.GetUsuarios();
  for (const auto& usuario : usuarios) {
    std::cout << usuario.GetNombreUsuario() << "Admin" << usuario.EsAdministrador() << std::endl;
  }

  // Open a file for writing
  std::ofstream ofs(kFicheroBaseDatos, std::ios::binary);
  // Serialize the object to the file
  base_datos_leida.Serialize(ofs);
  // Close the file
  ofs.close();

  return 0;
}
