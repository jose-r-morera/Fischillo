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
 * @date    22/04/2023
 * @file    base_datos.cc
 * @brief   Implementación de la clase "BaseDatos". Permite almacenar
 *          información.
 *
 *
 * @see
 *
 * Historial de revisiones
 *          23/04/2023 - Creación (primera versión) del código
 */

#include "base_datos.h"

bool BaseDatos::Insertar(const Usuario& nuevo_usuario) {
  // Comprueba que el id no se haya usado
  for (const auto& usuario : usuarios_)  {
    if (usuario.GetId() == nuevo_usuario.GetId()) {
      return false;
    }
  }
  for (const auto& cerradura : cerraduras_)  {
    if (cerradura.Id() == nuevo_usuario.GetId()) {
      return false;
    }
  }
  usuarios_.push_back(nuevo_usuario);
  return true;
}

bool BaseDatos::Insertar(const CerraduraInteligente& nueva_cerradura) {
  // Comprueba que el id no se haya usado
  for (const auto& usuario : usuarios_)  {
    if (usuario.GetId() == nueva_cerradura.Id()) {
      return false;
    }
  }
  for (const auto& cerradura : cerraduras_)  {
    if (cerradura.Id() == nueva_cerradura.Id()) {
      return false;
    }
  }
  cerraduras_.push_back(nueva_cerradura);
  return true;
}

bool BaseDatos::Insertar(const acceso& nuevo_acceso) {
  accesos_.push_back(nuevo_acceso);
  return true;
}

bool BaseDatos::EliminarUsuario(const unsigned id) {
  for (int i{0}; i < NumeroDeUsuarios(); ++i) {
    if (usuarios_[i].GetId() == id) {
      usuarios_.erase(usuarios_.begin() + i);
      return true;
    }
  }
  return false;
}

bool BaseDatos::EliminarCerradura(const unsigned id) {
  for (int i{0}; i < NumeroDeCerraduras(); ++i) {
    if (cerraduras_[i].Id() == id) {
      cerraduras_.erase(cerraduras_.begin() + i);
      return true;
    }
  }
  return false;
}

std::vector<acceso> BaseDatos::ObtenerRegistro(const unsigned id) const {
  std::vector<acceso> registro;
  for (const auto& acceso : accesos_)  {
    if (acceso.usuario_.GetId() == id || acceso.cerradura_.Id() == id) {
      registro.push_back(acceso);
    }
  }
  return registro;
}

void BaseDatos::Serialize(std::ostream& os) const {
  // Serialize usuarios_
  std::size_t usuarios_size = usuarios_.size();
  os.write(reinterpret_cast<const char*>(&usuarios_size), sizeof(usuarios_size));
  for (const auto& usuario : usuarios_) {
    // Serialize each Usuario object
    // Note: implement serialize() function for Usuario class
    usuario.Serialize(os);
  }

  // Serialize cerraduras_
  std::size_t cerraduras_size = cerraduras_.size();
  os.write(reinterpret_cast<const char*>(&cerraduras_size), sizeof(cerraduras_size));
  for (const auto& cerradura : cerraduras_) {
    // Serialize each CerraduraInteligente object
    // Note: implement serialize() function for CerraduraInteligente class
    cerradura.Serialize(os);
  }

  // Serialize accesos_
  std::size_t accesos_size = accesos_.size();
  os.write(reinterpret_cast<const char*>(&accesos_size), sizeof(accesos_size));
  os.write(reinterpret_cast<const char*>(accesos_.data()), accesos_size * sizeof(acceso));

  // Serialize contador_id_
  os.write(reinterpret_cast<const char*>(&contador_id_), sizeof(contador_id_));
}

void BaseDatos::Deserialize(std::istream& is) {
  // Deserialize usuarios_
  std::size_t usuarios_size;
  is.read(reinterpret_cast<char*>(&usuarios_size), sizeof(usuarios_size));
  usuarios_.resize(usuarios_size);
  for (auto& usuario : usuarios_) {
    // Deserialize each Usuario object
    // Note: implement deserialize() function for Usuario class
    usuario.Deserialize(is);
  }

  // Deserialize cerraduras_
  std::size_t cerraduras_size;
  is.read(reinterpret_cast<char*>(&cerraduras_size), sizeof(cerraduras_size));
  cerraduras_.resize(cerraduras_size);
  for (auto& cerradura : cerraduras_) {
    // Deserialize each CerraduraInteligente object
    // Note: implement deserialize() function for CerraduraInteligente class
    cerradura.Deserialize(is);
  }

  // Deserialize accesos_
  std::size_t accesos_size;
  is.read(reinterpret_cast<char*>(&accesos_size), sizeof(accesos_size));
  accesos_.resize(accesos_size);
  is.read(reinterpret_cast<char*>(accesos_.data()), accesos_size * sizeof(acceso));

  // Deserialize contador_id_
  is.read(reinterpret_cast<char*>(&contador_id_), sizeof(contador_id_));
}


bool BaseDatos::ExisteUsuario(const std::string& nombre_usuario) const {
  for (const auto& usuario : usuarios_) {
    if (usuario.GetNombreUsuario() == nombre_usuario) {
      return true;
    }
  }
  return false;
}


const Usuario& BaseDatos::BuscarUsuario(const std::string& nombre_usuario) const {
  if (ExisteUsuario(nombre_usuario)) {
    for (const auto& usuario : usuarios_) {
      if (usuario.GetNombreUsuario() == nombre_usuario) {
        return usuario;
      }
    }
  } else {
    throw UsuarioNoExiste();
  }
}