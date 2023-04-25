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

#ifndef BASE_DE_DATOS_H
#define BASE_DE_DATOS_H

#include <ctime>
#include <iostream>
#include <vector>

#include "cerradura_inteligente.h"
#include "excepcion.h"
#include "usuario.h"

struct acceso {
  acceso() {}
  acceso(const Usuario& usuario, const CerraduraInteligente& cerradura, const std::string& accion)
      : usuario_{usuario}, cerradura_{cerradura}, accion_{accion} {
    time(&time_);
  }
  Usuario usuario_{};
  CerraduraInteligente cerradura_{};
  std::string accion_{};
  time_t time_{};
};

class BaseDatos {
 public:
  BaseDatos() {}

  bool Insertar(const Usuario& nuevo_usuario);
  bool Insertar(const CerraduraInteligente& nueva_cerradura);
  bool Insertar(const acceso& nuevo_acceso);

  bool EliminarUsuario(const unsigned id);
  bool EliminarCerradura(const unsigned id);

  unsigned NuevoId() { return ++contador_id_; }

  int NumeroDeUsuarios() const { return usuarios_.size(); }
  int NumeroDeCerraduras() const { return cerraduras_.size(); }

  std::vector<acceso> ObtenerRegistro(const unsigned id) const;

  // Modificar usuarios (si id ya está sustituir)

  // Getters
  std::vector<Usuario> GetUsuarios() const { return usuarios_; }
  std::vector<CerraduraInteligente> GetCerraduras() const { return cerraduras_; }
  // Serializar
  void Serialize(std::ostream& os) const;
  // Deserializar
  void Deserialize(std::istream& is);

  // Buscar
  bool ExisteUsuario(const std::string& nombre_usuario) const;
  Usuario BuscarUsuario(const std::string& nombre_usuario) const;

 private:
  // Personas
  std::vector<Usuario> usuarios_{};
  // Cerraduras
  std::vector<CerraduraInteligente> cerraduras_{};
  // Accesos
  std::vector<acceso> accesos_{};
  // Ids
  unsigned contador_id_{1000};
};

#endif  // BASE_DE_DATOS_H
