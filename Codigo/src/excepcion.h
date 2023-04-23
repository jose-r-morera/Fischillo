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
 * @file    excepcion.h
 * @brief   Excepciones
 *
 *
 * @see
 *
 * Historial de revisiones
 *          22/04/2023 - Creación (primera versión) del código
 */

#ifndef EXCEPCION_H
#define EXCEPCION_H

#include <iostream>
#include <exception>

struct BaseDatosExcepcion : public std::exception {
  const char* what() const noexcept {
    return "Error detectado en el uso de la base de datos.";
  }
};

struct UsuarioNoExiste : public BaseDatosExcepcion {
  const char* what() const noexcept {
    return "El nombre de usuario introducido no existe.";
  }
};

// struct BigIntDivisionByZero : public BigIntException {
//   const char* what() const noexcept {
//     return "División inválida, tratando de dividir entre 0.";
//   }
// };

// struct BigIntBaseNotImplemented : public BigIntException {
//   const char* what() const noexcept {
//     return "La base introducida no se encuentra disponible.";
//   }
// };

#endif