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
#include <fstream>
#include <iostream>

#include "base_datos.h"
#include "cliente_funciones.h"
#include "colores.h"

int main() {
  system("clear");
  std::cout << GREEN << "Bienvenido a Smartlock\n\n" << RESET;
  
  // Leemos la base de datos del fichero que la contiene
  const std::string kFicheroBaseDatos{"base.datos"};
  std::ifstream ifs(kFicheroBaseDatos, std::ios::binary);
  BaseDatos base_datos_leida{};
  base_datos_leida.Deserialize(ifs);
  ifs.close();

  /// El usuario se debe identificar
  const std::string kIdUsuario = Identificacion(base_datos_leida);

  // Mostramos el menú
  MostrarMenu(base_datos_leida, kIdUsuario);

  // Guardamos los cambios
  std::ofstream ofs(kFicheroBaseDatos, std::ios::binary);
  // Serializamos la base de datos, guardandola en el fichero
  base_datos_leida.Serialize(ofs);
  // Cerrramos el fichero
  ofs.close();

  return 0; 
}
