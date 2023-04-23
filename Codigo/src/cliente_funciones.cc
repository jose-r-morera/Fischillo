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
 * @date    12/04/2023
 * @file    cliente.cc
 * @brief   Programa cliente. Aplicación para la gestión de cerraduras inteligentes.
 *
 * @see
 *
 * Historial de revisiones
 *          12/04/2023 - Creación (primera versión) del código
 */
#include "cliente_funciones.h"

// Retorna la ID del usuario
unsigned Identificacion(const BaseDatos& kBaseDeDatos) {

  std::cout << "Debe identificarse\n\n"
  "a) Registrarse\n"
  "b) Iniciar sesión\n";
  char opcion{};
  std::cin >> opcion;

  switch(opcion) {
    case 'a': { 
      /// Creamos un nuevo usuario
      Registrarse(kBaseDeDatos);
    }
    break;

    case 'b': {
      // Intentamos iniciar sesión
      IniciarSesion(kBaseDeDatos);
    }
    break;
  } 
  return 0;
}

bool Registrarse(const BaseDatos& kBaseDeDatos) {return false;}

bool IniciarSesion(const BaseDatos& kBaseDeDatos) {return false;}