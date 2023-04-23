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

#ifndef  CLIENTE_FUNCIONES_H
#define  CLIENTE_FUNCIONES_H

#include <iostream>
#include <fstream>

#include "base_datos.h"

// Retorna la ID del usuario
unsigned Identificacion(const BaseDatos& kBaseDeDatos);

bool Registrarse(const BaseDatos& kBaseDeDatos);

bool IniciarSesion(const BaseDatos& kBaseDeDatos);

/// Opciones del menú de la app
bool InteractuarCerraduras(const BaseDatos& kBaseDeDatos);
bool ConcederAcceso(const BaseDatos& kBaseDeDatos, const Usuario& kUsuario);

#endif