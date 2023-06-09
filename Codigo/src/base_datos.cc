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
 * @brief   Implementación de la clase "BaseDatos". Permite almacenar información.
 *
 * @see     https://www.cs.cmu.edu/~410/doc/doxygen.html
 * 
 * Historial de revisiones
 *          23/04/2023 - Creación (primera versión) del código
 *          10/05/2023 - Última revisión para la entrega del proyecto  
 */

#include "base_datos.h"
#include "colores.h"

void acceso::Serialize(std::ostream& os) const {
  // Serializa usuario_
  std::size_t nombre_size = usuario_.size();
  os.write(reinterpret_cast<const char*>(&nombre_size), sizeof(nombre_size));
  os.write(usuario_.data(), nombre_size);

  // Serializa cerradura_
  os.write(reinterpret_cast<const char*>(&cerradura_), sizeof(cerradura_));

  // Serializa accion_
  std::size_t accion_size = accion_.size();
  os.write(reinterpret_cast<const char*>(&accion_size), sizeof(accion_size));
  os.write(accion_.data(), accion_size);

  // Serializa time_
  os.write(reinterpret_cast<const char*>(&time_), sizeof(time_));
}

/**
 * @brief Deserializa un objeto acceso: lee los datos de un flujo de entrada y los almacena en el objeto acceso
 * @param is  el flujo de entrada
 * @return    void
 * @pre       is debe estar abierto
 * @post      El objeto acceso queda inicializado con los datos leídos del flujo de entrada
*/
void acceso::Deserialize(std::istream& is) {
  // Deserializa usuario_
  std::size_t nombre_size;
  is.read(reinterpret_cast<char*>(&nombre_size), sizeof(nombre_size));
  usuario_.resize(nombre_size);
  is.read(&usuario_[0], nombre_size);

  // Deserializa cerradura_
  is.read(reinterpret_cast<char*>(&cerradura_), sizeof(cerradura_));

  // Deserializa accion_
  std::size_t accion_size;
  is.read(reinterpret_cast<char*>(&accion_size), sizeof(accion_size));
  accion_.resize(accion_size);
  is.read(&accion_[0], accion_size);

  // Deserializa time_
  is.read(reinterpret_cast<char*>(&time_), sizeof(time_));
}

/**
 * @brief Sobrecarga del operador de inserción de flujo para el tipo acceso
 *
 * @param out el flujo de salida
 * @param kAcceso el objeto que se muestra
 * @return el flujo
 */
std::ostream& operator<<(std::ostream& out, const acceso& kAcceso) {
  std::string texto_fecha{asctime(localtime(&kAcceso.time_))};
  texto_fecha.pop_back();
  out << BLUE << kAcceso.usuario_ << RESET << " -> " << CYAN << kAcceso.cerradura_ 
      << RESET << ": ";
  if (kAcceso.accion_ == "Abrir") {
    out << " " << LGREEN << kAcceso.accion_ << RESET << " (" << texto_fecha << ")\n";
  } else if (kAcceso.accion_ == "Cerrar") {
    out << " " << RED << kAcceso.accion_ << RESET << " (" << texto_fecha << ")\n";
  }
  return out;
}

/**
 * @brief Insertar Usuarios en la base de datos
 *
 * @param nuevo_usuario Usuario a insertar en la base de datos
 * @return true Se ha completado la inserción correctamente
 * @return false No se ha completado la inserción (nombre de usuario ya existe)
 */
bool BaseDatos::Insertar(const Usuario& nuevo_usuario) {
  // Comprueba que el id no se haya usado
  for (const auto& usuario : usuarios_) {
    if (usuario.GetNombreUsuario() == nuevo_usuario.GetNombreUsuario()) {
      return false;
    }
  }
  usuarios_.emplace_back(nuevo_usuario);
  return true;
}

/**
 * @brief Insertar nueva cerradura en la base de datos
 *
 * @param nueva_cerradura Cerradura a insertar en la base de datos
 * @return true Se ha completado la inserción correctamente
 * @return false No se ha completado la inserción (id de cerradura ya existe)
 */
bool BaseDatos::Insertar(const CerraduraInteligente& nueva_cerradura) {
  // Comprueba que el id no se haya usado
  for (const auto& cerradura : cerraduras_) {
    if (cerradura.Id() == nueva_cerradura.Id()) {
      return false;
    }
  }
  cerraduras_.emplace_back(nueva_cerradura);
  return true;
}

/**
 * @brief Insertar un nuevo acceso en la base de datos
 *
 * @param nuevo_acceso Acceso a insertar en la base de datos
 * @return true Se ha completado la inserción correctamente
 * @return false No se ha completado la insertación (no pasa nunca)
 */
bool BaseDatos::Insertar(const acceso& nuevo_acceso) {
  accesos_.emplace_back(nuevo_acceso);
  return true;
}

/**
 * @brief Elimina el usuario que coincida con el nombre de usuario introducido
 *
 * @param nombre_usuario Nombre del usuario a eliminar
 * @return true Se ha eliminado el usuario correctamente
 * @return false No se ha eliminado el usuario (no coincide ningún nombre de usuario)
 */
bool BaseDatos::EliminarUsuario(const std::string& nombre_usuario) {
  for (int i{0}; i < NumeroDeUsuarios(); ++i) {
    if (usuarios_[i].GetNombreUsuario() == nombre_usuario) {
      usuarios_.erase(usuarios_.begin() + i);
      return true;
    }
  }
  return false;
}

/**
 * @brief Elimina la cerradura que coincida con el id
 *
 * @param id Id de la cerradura a eliminar
 * @return true Se ha eliminado la cerradura correctamente
 * @return false No se ha eliminado la cerradura (no coincide ningún id)
 */
bool BaseDatos::EliminarCerradura(const unsigned id) {
  for (int i{0}; i < NumeroDeCerraduras(); ++i) {
    if (cerraduras_[i].Id() == id) {
      cerraduras_.erase(cerraduras_.begin() + i);
      for (auto& usuario : usuarios_) {
        usuario.RetirarAccesoCerradura(id);
      }
      return true;
    }
  }
  return false;
}

/**
 * @brief Obtiene todos los accesos que contengan la id de la cerradura dada
 *
 * @param id Id de la cerradura a buscar
 * @return std::vector<acceso> Vector de los accesos que contengan el id
 */
std::vector<acceso> BaseDatos::ObtenerRegistro(const unsigned id) const {
  std::vector<acceso> registro{};
  for (const auto& acceso : accesos_) {
    if (acceso.cerradura_ == id) {
      registro.emplace_back(acceso);
    }
  }
  return registro;
}

/**
 * @brief Obtiene todos los accesos que contengan el nombre de usuario dado
 *
 * @param nombre Nombre a buscar
 * @return std::vector<acceso> Vector de accesos con coincidencias de nombre
 */
std::vector<acceso> BaseDatos::ObtenerRegistro(const std::string& nombre) const {
  std::vector<acceso> registro{};
  for (const auto& acceso : accesos_) {
    if (acceso.usuario_ == nombre) {
      registro.emplace_back(acceso);
    }
  }
  return registro;
}

/**
 * @brief Serializa la base de datos para poder almacenarla
 *
 * @param os Referencia a un flujo de salida
 */
void BaseDatos::Serialize(std::ostream& os) const {
  // Serialize usuarios_
  std::size_t usuarios_size = usuarios_.size();
  os.write(reinterpret_cast<const char*>(&usuarios_size), sizeof(usuarios_size));
  for (const auto& usuario : usuarios_) {
    // Serialize each Usuario object
    usuario.Serialize(os);
  }

  // Serialize cerraduras_
  std::size_t cerraduras_size = cerraduras_.size();
  os.write(reinterpret_cast<const char*>(&cerraduras_size), sizeof(cerraduras_size));
  for (const auto& cerradura : cerraduras_) {
    // Serialize each CerraduraInteligente object
    cerradura.Serialize(os);
  }

  // Serialize accesos_
  std::size_t accesos_size = accesos_.size();
  os.write(reinterpret_cast<const char*>(&accesos_size), sizeof(accesos_size));
  for (const auto& acceso : accesos_) {
    // Serialize each acceso object
    acceso.Serialize(os);
  }

  // Serialize contador_id_
  os.write(reinterpret_cast<const char*>(&contador_id_), sizeof(contador_id_));
}

/**
 * @brief Deserializa la base de datos
 *
 * @param is Referencia al flujo de entrada
 */
void BaseDatos::Deserialize(std::istream& is) {
  // Deserialize usuarios_
  std::size_t usuarios_size;
  is.read(reinterpret_cast<char*>(&usuarios_size), sizeof(usuarios_size));
  usuarios_.resize(usuarios_size);
  for (auto& usuario : usuarios_) {
    // Deserialize each Usuario object
    usuario.Deserialize(is);
  }

  // Deserialize cerraduras_
  std::size_t cerraduras_size;
  is.read(reinterpret_cast<char*>(&cerraduras_size), sizeof(cerraduras_size));
  cerraduras_.resize(cerraduras_size);
  for (auto& cerradura : cerraduras_) {
    // Deserialize each CerraduraInteligente object
    cerradura.Deserialize(is);
  }

  // Deserialize accesos_
  std::size_t accesos_size;
  is.read(reinterpret_cast<char*>(&accesos_size), sizeof(accesos_size));
  accesos_.resize(accesos_size);
    for (auto& acceso : accesos_) {
    // Serialize each acceso object
    acceso.Deserialize(is);
  }

  // Deserialize contador_id_
  is.read(reinterpret_cast<char*>(&contador_id_), sizeof(contador_id_));
}

/**
 * @brief Comprueba si existe un usuario con ese nombre de usuario
 *
 * @param nombre_usuario Nombre de usuario a buscar
 * @return true Existe
 * @return false No existe
 */
bool BaseDatos::ExisteUsuario(const std::string& nombre_usuario) const {
  for (const auto& usuario : usuarios_) {
    if (usuario.GetNombreUsuario() == nombre_usuario) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Devuelve una referencia constante al usuario que coincide con el nombre introducido
 *
 * @param nombre_usuario Nombre introducido
 * @return const Usuario& Usuario con el nombre de usuario solicitado
 */
const Usuario& BaseDatos::BuscarUsuario(const std::string& nombre_usuario) const {
  if (ExisteUsuario(nombre_usuario)) {
    Usuario mi_usuario;
    for (const auto& usuario : usuarios_) {
      if (usuario.GetNombreUsuario() == nombre_usuario) {
        return usuario;
      }
    }
    throw UsuarioNoExiste();
  } else {
    throw UsuarioNoExiste();
  }
}

/**
 * @brief Devuelve una referencia al usuario que coincide con el nombre introducido
 *
 * @param nombre_usuario Nombre introducido
 * @return Usuario& Usuario con el nombre de usuario solicitado
 */
Usuario& BaseDatos::BuscarUsuario(const std::string& nombre_usuario) {
  if (ExisteUsuario(nombre_usuario)) {
    for (auto& usuario : usuarios_) {
      if (usuario.GetNombreUsuario() == nombre_usuario) {
        return usuario;
      }
    }
    throw UsuarioNoExiste();
  } else {
    throw UsuarioNoExiste();
  }
}

/**
 * @brief Comprueba si existe una cerradura con el Id dado
 *
 * @param id Id a buscar
 * @return true Existe una cerradura con el Id dado
 * @return false No existe cerradura con el Id dado
 */
bool BaseDatos::ExisteCerradura(const unsigned id) const {
  for (const auto& cerradura : cerraduras_) {
    if (cerradura.Id() == id) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Devuelve una referencia a la cerradura con el Id solicitado
 *
 * @param id Id a buscar
 * @return CerraduraInteligente& Cerradura con la Id solicitada
 */
CerraduraInteligente& BaseDatos::BuscarCerradura(const unsigned id) {
  if (ExisteCerradura(id)) {
    CerraduraInteligente cerradura_buscada;
    for (auto& cerradura : cerraduras_) {
      if (cerradura.Id() == id) {
        return cerradura;
      }
    }
    throw CerraduraNoExiste();
  } else {
    throw CerraduraNoExiste();
  }
}