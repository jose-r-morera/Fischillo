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

#ifndef CERRADURA_INTELIGENTE
#define CERRADURA_INTELIGENTE

class CerraduraInteligente {
 public:
  CerraduraInteligente(const int id) : id_(id) {}

  void Interaccion() { abierto_ = !abierto_; }
  bool Abierto() { return abierto_; }

  int id() const { return id_; }

 private:
  int id_;
  bool abierto_{false};
};

#endif