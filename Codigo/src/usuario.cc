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
 * @date    17/04/2023
 * @file    usuario.h
 * @brief   Declaración de la clase "Usuario", que permite registrar
 *          a los usuarios de la aplicación.
 * @see
 *
 * Historial de revisiones
 *          17/04/2023 - Creación (primera versión) del código
 */

#include "usuario.h"

void Usuario::Serialize(std::ostream& os) const {
  // Serialize id_usuario_
  os.write(reinterpret_cast<const char*>(&id_usuario_), sizeof(id_usuario_));

  // Serialize nombre_usuario_
  std::size_t nombre_size = nombre_usuario_.size();
  os.write(reinterpret_cast<const char*>(&nombre_size), sizeof(nombre_size));
  os.write(nombre_usuario_.data(), nombre_size);
  
  // Serialize cerraduras_permitidas_
  std::size_t cerraduras_size = cerraduras_permitidas_.size();
  os.write(reinterpret_cast<const char*>(&cerraduras_size), sizeof(cerraduras_size));
  os.write(reinterpret_cast<const char*>(cerraduras_permitidas_.data()), cerraduras_size * sizeof(int));
  // Serialize administrador_
  os.write(reinterpret_cast<const char*>(&administrador_), sizeof(administrador_));
}

void Usuario::Deserialize(std::istream& is)  {
  // Deserialize id_usuario_
  is.read(reinterpret_cast<char*>(&id_usuario_), sizeof(id_usuario_));

  // Deserialize nombre_usuario_
  std::size_t nombre_size;
  is.read(reinterpret_cast<char*>(&nombre_size), sizeof(nombre_size));
  nombre_usuario_.resize(nombre_size);
  is.read(&nombre_usuario_[0], nombre_size);

  // Deserialize cerraduras_permitidas_
  std::size_t cerraduras_size;
  is.read(reinterpret_cast<char*>(&cerraduras_size), sizeof(cerraduras_size));
  cerraduras_permitidas_.resize(cerraduras_size);
  is.read(reinterpret_cast<char*>(cerraduras_permitidas_.data()), cerraduras_size * sizeof(int));

  // Deserialize administrador_
  is.read(reinterpret_cast<char*>(&administrador_), sizeof(administrador_));
}