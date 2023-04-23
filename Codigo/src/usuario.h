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
 * @brief   Declaración de la clase "Usuario", que permite registrar
 *          a los usuarios de la aplicación.
 *
 * @see
 *
 * Historial de revisiones
 *          17/04/2023 - Creación (primera versión) del código
 */

#ifndef USER_H_
#define USER_H_

#include <vector>

class Usuario {
 public:
  // Constructor por defecto
  Usuario(int id, std::string nombre, bool admin = false) : id_usuario_(id), nombre_usuario_(nombre), administrador_(admin) {}
  // Devuelve la ID del usuario
  int id() const { return id_usuario_; }
  // Asigna las cerraduras a las que tiene permitido el acceso el usuario
  void PermitirAccesoCerradura(int id_cerradura_) { cerraduras_permitidas_.push_back(id_cerradura_); }
  // Comprueba si el usuario tiene permisos de administrador
  bool Administrador() { return administrador_; }
  
 private:
  // Identificador numérico del usuario
  int id_usuario_;
  // Identificador alfabético del usuario
  std::string nombre_usuario_;
  // Cerraduras a las que tiene acceso el usuario
  std::vector<int> cerraduras_permitidas_;
  // En caso de que el usuario tiene permisos de administrador
  bool administrador_;
};

#endif