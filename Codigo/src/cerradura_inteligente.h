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

#include <iostream>
#include <fstream>

class CerraduraInteligente {
 public:
  CerraduraInteligente(const unsigned id = 0) : id_(id) {}

  void Interaccion() { abierto_ = !abierto_; }

   // Serialize function
    void Serialize(std::ostream& os) const {
        // Serialize id_
        os.write(reinterpret_cast<const char*>(&id_), sizeof(id_));

        // Serialize abierto_
        os.write(reinterpret_cast<const char*>(&abierto_), sizeof(abierto_));
    }

    // Deserialize function
    void Deserialize(std::istream& is) {
        // Deserialize id_
        is.read(reinterpret_cast<char*>(&id_), sizeof(id_));

        // Deserialize abierto_
        is.read(reinterpret_cast<char*>(&abierto_), sizeof(abierto_));
    }
  
  /// Getters
  bool Abierto() const { return abierto_; }
  unsigned Id() const { return id_; }

 private:
  unsigned id_{};
  bool abierto_{false};
};

#endif