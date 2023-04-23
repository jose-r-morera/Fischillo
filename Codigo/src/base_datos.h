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
 * @file    base_datos.h
 * @brief   Declaración de la clase "BaseDatos". Permite almacenar
 *          información.
 *
 *
 * @see
 *
 * Historial de revisiones
 *          22/04/2023 - Creación (primera versión) del código
 */

#ifndef BASE_DE_DATOS
#define BASE_DE_DATOS

#include <iostream>
#include <vector>
#include <ctime>

#include "usuario.h"
#include "cerradura_inteligente.h"

struct acceso {
  Usuario usuario;
  CerraduraInteligente cerradura;
  std::string accion;
  time_t time;
};

class BaseDatos {
 public:
  BaseDatos() {}

  bool Insertar(const Usuario& nuevo_usuario);
  bool Insertar(const CerraduraInteligente& nueva_cerradura);
  bool Insertar(const acceso& nuevo_acceso);
  
  bool EliminarUsuario(const int id);
  bool EliminarCerradura(const int id);

  unsigned NuevoId() { return ++contador_id_; }

  int NumeroDeUsuarios() const { return usuarios_.size(); }
  int NumeroDeCerraduras() const { return cerraduras_.size(); }

  std::vector<acceso> ObtenerRegistro(const int id) const;

  // Modificar usuarios (si id ya está sustituir)

  // Serializar

  // Deserializar
  
 private:
  // Personas 
  std::vector<Usuario> usuarios_;
  // Cerraduras
  std::vector<CerraduraInteligente> cerraduras_;
  // Accesos
  std::vector<acceso> accesos_;
  // Ids
  unsigned contador_id_{1000};
};


bool BaseDatos::Insertar(const Usuario& nuevo_usuario) {
  // Comprueba que el id no se haya usado
  for (const auto usuario : usuarios_)  {
    if (usuario.Id() == nuevo_usuario.Id()) {
      return false;
    }
  }
  for (const auto cerradura : cerraduras_)  {
    if (cerradura.Id() == nuevo_usuario.Id()) {
      return false;
    }
  }
  usuarios_.push_back(nuevo_usuario);
  return true;
}

bool BaseDatos::Insertar(const CerraduraInteligente& nueva_cerradura) {
  // Comprueba que el id no se haya usado
  for (const auto usuario : usuarios_)  {
    if (usuario.Id() == nueva_cerradura.Id()) {
      return false;
    }
  }
  for (const auto cerradura : cerraduras_)  {
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

bool BaseDatos::EliminarUsuario(const int id) {
  for (int i{0}; i < NumeroDeUsuarios(); ++i) {
    if (usuarios_[i].Id() == id) {
      usuarios_.erase(usuarios_.begin() + i);
      return true;
    }
  }
  return false;
}

bool BaseDatos::EliminarCerradura(const int id) {
  for (int i{0}; i < NumeroDeCerraduras(); ++i) {
    if (cerraduras_[i].Id() == id) {
      cerraduras_.erase(cerraduras_.begin() + i);
      return true;
    }
  }
  return false;
}

std::vector<acceso> BaseDatos::ObtenerRegistro(const int id) const {
  std::vector<acceso> registro;
  for (const auto acceso : accesos_)  {
    if (acceso.usuario.Id() == id || acceso.cerradura.Id() == id) {
      registro.push_back(acceso);
    }
  }
  return registro;
}

#endif