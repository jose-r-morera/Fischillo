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
#include <iostream>
#include <fstream>

#include "base_datos.h"

int main() {
  std::cout << "Hola, mundo!" << std::endl;
  
  // Leemos la base de datos del fichero que la contiene
  std::ifstream ifs("base_datos.txt", std::ios::binary);
  BaseDatos base_datos_leida{};
  base_datos_leida.Deserialize(ifs);
  ifs.close();

  std::cout << "¿Qué quieres hacer?\n"
  "a) Añadir usuario\n"
  "b) Eliminar usuario\n";
  char opcion{};
  std::cin >> opcion;

  switch(opcion) {
    case 'a': { 
      /// Creamos un usuario
      std::string nombre_introducido;
      std::cout << "Introduce nombre de usuario: ";
      std::cin >> nombre_introducido;
      base_datos_leida.Insertar(Usuario{base_datos_leida.NuevoId(), nombre_introducido});
    }
    break;

    case 'b': {
      // Eliminamos un usuario
      unsigned id_eliminar;
      std::cout << "Introduce id del usuario a eliminar: ";
      std::cin >> id_eliminar;
      base_datos_leida.EliminarUsuario(id_eliminar);
    }
    break;
  } 

  std::vector<Usuario> usuarios = base_datos_leida.GetUsuarios();
  for (const auto& usuario : usuarios) {
    std::cout << usuario.GetId() << " : " << usuario.GetNombreUsuario() << std::endl;
  }
  // Usuario platinita{base_datos_leida.NuevoId(), "platinita"};
  // base_datos_leida.Insertar(platinita);

  // Open a file for writing
  std::ofstream ofs("base_datos.txt", std::ios::binary);
  // Serialize the object to the file 
  base_datos_leida.Serialize(ofs);
  // Close the file
  ofs.close();

  return 0;
}