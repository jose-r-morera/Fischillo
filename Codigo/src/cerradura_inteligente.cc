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
 * @date    24/04/2023
 * @file    cerradura_inteligente.cc
 * @brief   Implementación de la clase "CerraduraInteligente". Permite a la
 *          cerradura abrirse y cerrarse.
 *
 *
 * @see
 *
 * Historial de revisiones
 *          24/04/2023 - Creación (primera versión) del código
 */

#include "cerradura_inteligente.h"

/**
 * @brief
 * @param os
 */
void CerraduraInteligente::Serialize(std::ostream &os) const {
  // Serialize id_
  os.write(reinterpret_cast<const char *>(&id_), sizeof(id_));
  // Serialize nombre_
  std::size_t nombre_size = nombre_.size();
  os.write(reinterpret_cast<const char*>(&nombre_size), sizeof(nombre_size));
  os.write(nombre_.data(), nombre_size);
  // Serialize abierto_
  os.write(reinterpret_cast<const char *>(&abierto_), sizeof(abierto_));
}

/**
 * @brief
 * @param is
 */
void CerraduraInteligente::Deserialize(std::istream &is) {
  // Deserialize id_
  is.read(reinterpret_cast<char *>(&id_), sizeof(id_));
  // Deserialize nombre_
  std::size_t nombre_size;
  is.read(reinterpret_cast<char*>(&nombre_size), sizeof(nombre_size));
  nombre_.resize(nombre_size);
  is.read(&nombre_[0], nombre_size);
  // Deserialize abierto_
  is.read(reinterpret_cast<char *>(&abierto_), sizeof(abierto_));
}