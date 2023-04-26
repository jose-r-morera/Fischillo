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
 * @file    usuario.h
 * @brief   Declaración de la clase "Usuario", que permite registrar
 *          a los usuarios de la aplicación.
 * @see
 *
 * Historial de revisiones
 *          17/04/2023 - Creación (primera versión) del código
 */

#ifndef USUARIO_H
#define USUARIO_H

#include <fstream>
#include <iostream>
#include <vector>

#include "cerradura_inteligente.h"

class Usuario {
 public:
  //  **Constructores**:

  // Constructor por defecto
  Usuario() : nombre_usuario_{""}, contrasenya_{}, administrador_{false} {}

  // Constructor por parámetros
  Usuario(std::string nombre, std::string contrasenya = "", bool admin = false) :
    nombre_usuario_(nombre),
    contrasenya_(std::hash<std::string>{}(contrasenya)),
    administrador_(admin) {}
  
  //  **Getters**:

  // Devuelve el nombre del usuario
  std::string GetNombreUsuario() const { return nombre_usuario_; }

  // Devuelve las cerraduras a las que tiene acceso el usuario
  std::vector<unsigned> GetCerradurasPermitidas() const { return cerraduras_permitidas_; }
  unsigned GetCerradurasPermitidasAt(int i) const { return cerraduras_permitidas_[i]; }

  //  **Setters**:

  // Almacenamos la contraseña en contrasenya_
  void SetContrasenya(std::string contrasenya) {
    contrasenya_ = std::hash<std::string>{}(contrasenya);
  }

  //  **Otras funciones**:

  // Asigna las cerraduras a las que tiene permitido el acceso el usuario
  void PermitirAccesoCerradura(unsigned id_cerradura) { 
    cerraduras_permitidas_.push_back(id_cerradura);
  }

  // Comprueba si el usuario tiene permisos de administrador
  bool EsAdministrador() const { return administrador_; }
  
  // Comprueba si la contraseña introducida es correcta
  bool ConfirmarContrasenya(std::string contrasenya_introducida) const {
    return (std::hash<std::string>{}(contrasenya_introducida) == contrasenya_);
  }

  // Almacena cada uno de los datos introducidos, modificando su formato de entrada
  void Serialize(std::ostream& os) const;

  // Devuelve el formato original a los datos del usuario
  void Deserialize(std::istream& is);

 private:
  // Identificador alfabético del usuario
  std::string nombre_usuario_;
  // Contraseña de identificación del usuario; es un std::hash
  size_t contrasenya_;
  // Cerraduras a las que tiene acceso el usuario
  std::vector<unsigned> cerraduras_permitidas_{};
  // En caso de que el usuario tiene permisos de administrador
  bool administrador_;
};

#endif  // USUARIO_H
