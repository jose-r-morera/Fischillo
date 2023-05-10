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
 * @file    identificacion.h
 * @brief   Gestión identificación programa cliente
 *
 * @see
 *
 * Historial de revisiones
 *          6/05/2023 - Creación (primera versión) del código
 *          10/05/2023 - Última revisión para la entrega del proyecto
 */

#ifndef IDENTIFICACION_H
#define IDENTIFICACION_H

#include <string>

#include "base_datos.h"
#include "usuario.h"

// Retorna la ID del usuario
std::string Identificacion(BaseDatos& base_de_datos);

// Opciones de identificación
std::string Registrarse(BaseDatos& base_de_datos);
std::string IniciarSesion(const BaseDatos& kBaseDeDatos);

// Solicita contraseñas hasta que se introduzca una segura
std::string IntroducirContrasenya();

#endif // IDENTIFICACION_H