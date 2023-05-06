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

#ifndef CLIENTE_FUNCIONES_H
#define CLIENTE_FUNCIONES_H

#include <string>

#include "base_datos.h"
#include "usuario.h"


/// Opciones del menú de la app:

// Muestra las opciones del menú por pantalla
void MostrarMenu(BaseDatos& base_datos, Usuario& usuario);
// Permite al usuario interactuar con las cerraduras a las que tiene acceso
void InteractuarCerraduras(BaseDatos& base_datos, const Usuario& kUsuario);
// Permite añadir o eliminar cerraduras en el sistema
void GestionarCerraduras(BaseDatos& base_datos);
// Modifica los permisos de acceso para un usuario específico
void CambiarPermisos(BaseDatos& base_datos);
// Permite a cada usuario modificar sus atributos (nombre, contraseña, etc)
void ModificarCuentaUsuario(BaseDatos& base_datos, Usuario& usuario);
// Muestra los registros de accesos del sistema
void ConsultarRegistros(const BaseDatos& kBaseDatos);

#endif