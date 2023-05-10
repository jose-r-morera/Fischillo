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
 * @file    usuario.cc
 * @brief   Definición de funciones de la clase "Usuario", que 
 *          permite registrar a los usuarios de la aplicación.
 * @see
 *
 * Historial de revisiones
 *          17/04/2023 - Creación (primera versión) del código
 *          10/05/2023 - Última revisión para la entrega del proyecto
 */

#include "usuario.h"

/**
 * @brief Añade una nueva cerradura al vector de cerraduras permitidas del usuario
 *        Solo añade cerraduras que no estuvieran, para evitar duplicidades.
 * @param id_cerradura la id de la cerradura a añadir
 */
void Usuario::PermitirAccesoCerradura(unsigned id_cerradura) {
  // Se utiliza un booleano que compruebe si la id ya pertenece al vector de accesos del usuario
  bool pertenece{false};
  for (unsigned i = 0; i < cerraduras_permitidas_.size(); i++) {
    if (GetCerradurasPermitidasAt(i) == id_cerradura) {
      pertenece = true;
      break;
    }
  } 
  // Si el Id no está registrado, se asigna su acceso al usuario
  if (pertenece == false) {
    cerraduras_permitidas_.push_back(id_cerradura);
  }
}

void Usuario::Serialize(std::ostream& os) const {
  // Serialize nombre_usuario_ (un string)
  std::size_t nombre_size = nombre_usuario_.size();
  os.write(reinterpret_cast<const char*>(&nombre_size), sizeof(nombre_size));
  os.write(nombre_usuario_.data(), nombre_size);

  // Serialize contrasenya_
  os.write(reinterpret_cast<const char*>(&contrasenya_), sizeof(contrasenya_));

  // Serialize cerraduras_permitidas_ (un vector de ints)
  std::size_t cerraduras_size = cerraduras_permitidas_.size();
  os.write(reinterpret_cast<const char*>(&cerraduras_size), sizeof(cerraduras_size));
  os.write(reinterpret_cast<const char*>(cerraduras_permitidas_.data()), cerraduras_size * sizeof(int));
  
  // Serialize administrador_
  os.write(reinterpret_cast<const char*>(&administrador_), sizeof(administrador_));
}

void Usuario::Deserialize(std::istream& is) {
  // Deserialize nombre_usuario_
  std::size_t nombre_size;
  is.read(reinterpret_cast<char*>(&nombre_size), sizeof(nombre_size));
  nombre_usuario_.resize(nombre_size);
  is.read(&nombre_usuario_[0], nombre_size);

  // Deserialize contrasenya_
  is.read(reinterpret_cast<char*>(&contrasenya_), sizeof(contrasenya_));

  // Deserialize cerraduras_permitidas_
  std::size_t cerraduras_size;
  is.read(reinterpret_cast<char*>(&cerraduras_size), sizeof(cerraduras_size));
  cerraduras_permitidas_.resize(cerraduras_size);
  is.read(reinterpret_cast<char*>(cerraduras_permitidas_.data()), cerraduras_size * sizeof(int));

  // Deserialize administrador_
  is.read(reinterpret_cast<char*>(&administrador_), sizeof(administrador_));
}

// Permite retirar el acceso de un usuario a una cerradura concreta
void Usuario::RetirarAccesoCerradura(unsigned id_cerradura) {
  for (unsigned i{0}; i < GetCerradurasPermitidas().size(); ++i) {
    if (cerraduras_permitidas_[i] == id_cerradura) {
      cerraduras_permitidas_.erase(cerraduras_permitidas_.begin() + i);
    }
  }
}