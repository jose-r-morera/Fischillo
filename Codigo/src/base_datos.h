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

#include <vector>
#include <ctime>

typedef pair<Usuario, time_t> acceso;

class BaseDatos {
 public:

 private:
  // personas 
  std::vector<Usuario> usuarios_;
  // cerraduras?
  // permisos
  // accesos
  std::vector<acceso> accesos_;
};
