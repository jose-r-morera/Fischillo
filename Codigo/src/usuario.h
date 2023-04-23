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

#include <vector>
#include <iostream>
#include <fstream>

class Usuario {
 public:
  Usuario() : id_usuario_{0}, nombre_usuario_{""}, administrador_{false} {}
  // Constructor por defecto
  Usuario(unsigned id, std::string nombre, bool admin = false) : id_usuario_(id), nombre_usuario_(nombre), administrador_(admin) {}
  // Devuelve la ID del usuario
  unsigned Id() const { return id_usuario_; }
  // Asigna las cerraduras a las que tiene permitido el acceso el usuario
  void PermitirAccesoCerradura(unsigned id_cerradura_) { cerraduras_permitidas_.push_back(id_cerradura_); }
  // Comprueba si el usuario tiene permisos de administrador
  bool Administrador() { return administrador_; }

  void Serialize(std::ostream& os)const {
        // Serialize id_usuario_
        os.write(reinterpret_cast<const char*>(&id_usuario_), sizeof(id_usuario_));

        // Serialize nombre_usuario_
        std::size_t nombre_size = nombre_usuario_.size();
        os.write(reinterpret_cast<const char*>(&nombre_size), sizeof(nombre_size));
        os.write(nombre_usuario_.data(), nombre_size);

        // Serialize cerraduras_permitidas_
        std::size_t cerraduras_size = cerraduras_permitidas_.size();
        os.write(reinterpret_cast<const char*>(&cerraduras_size), sizeof(cerraduras_size));
        os.write(reinterpret_cast<const char*>(cerraduras_permitidas_.data()), cerraduras_size * sizeof(int));

        // Serialize administrador_
        os.write(reinterpret_cast<const char*>(&administrador_), sizeof(administrador_));
    }

    void Deserialize(std::istream& is)  {
        // Deserialize id_usuario_
        is.read(reinterpret_cast<char*>(&id_usuario_), sizeof(id_usuario_));

        // Deserialize nombre_usuario_
        std::size_t nombre_size;
        is.read(reinterpret_cast<char*>(&nombre_size), sizeof(nombre_size));
        nombre_usuario_.resize(nombre_size);
        is.read(&nombre_usuario_[0], nombre_size);

        // Deserialize cerraduras_permitidas_
        std::size_t cerraduras_size;
        is.read(reinterpret_cast<char*>(&cerraduras_size), sizeof(cerraduras_size));
        cerraduras_permitidas_.resize(cerraduras_size);
        is.read(reinterpret_cast<char*>(cerraduras_permitidas_.data()), cerraduras_size * sizeof(int));

        // Deserialize administrador_
        is.read(reinterpret_cast<char*>(&administrador_), sizeof(administrador_));
    }

    unsigned GetId() const { return id_usuario_; }

    std::string GetNombreUsuario() const { return nombre_usuario_; }
  
 private:

  // Identificador numérico del usuario
  unsigned id_usuario_;
  // Identificador alfabético del usuario
  std::string nombre_usuario_;
  // Cerraduras a las que tiene acceso el usuario
  std::vector<int> cerraduras_permitidas_{};
  // En caso de que el usuario tiene permisos de administrador
  bool administrador_;
};

#endif
