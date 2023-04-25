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
 * @file    cerradura_inteligente.h
 * @brief   Declaración de la clase "CerraduraInteligente". Permite a la
 *          cerradura abrirse y cerrarse.
 *
 *
 * @see
 *
 * Historial de revisiones
 *          17/04/2023 - Creación (primera versión) del código
 */

#ifndef CERRADURA_INTELIGENTE_H
#define CERRADURA_INTELIGENTE_H

#include <fstream>
#include <iostream>

class CerraduraInteligente {
 public:
  // Constructor
  CerraduraInteligente(const unsigned id = 0, const std::string nombre = "")
      : id_(id), nombre_(nombre) {}

  // Función para interactuar con la cerradura
  void Interaccion() { abierto_ = !abierto_; }

  // Función de serialización
  void Serialize(std::ostream& os) const;

  // Función de deserialización
  void Deserialize(std::istream& is);

  /// Getters
  bool Abierto() const { return abierto_; }
  unsigned Id() const { return id_; }
  std::string Nombre() const { return nombre_; }

 private:
  unsigned id_{};
  std::string nombre_{""};
  bool abierto_{false};
};

#endif
