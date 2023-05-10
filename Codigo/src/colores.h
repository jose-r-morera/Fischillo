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
 * @date    24/04/2023
 * @file    colores.h
 * @brief   Definiciones de colores para las fuentes y el fondo y todo l que sea necesario
 *
 *
 * @see
 *
 * Historial de revisiones
 *          24/04/2023 - Creación (primera versión) del código
 *          10/05/2023 - Última revisión para la entrega del proyecto
 */
 
#ifndef COLORES_H
#define COLORES_H

#include <iostream>

// COLOR DE LA FUENTE // 
#define BLACK   "\x1B[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1B[37m"
#define ORANGE  "\x1B[38;2;255;128;0m"
#define ROSE    "\x1B[38;2;255;151;203m"
#define LBLUE   "\x1B[38;2;53;149;240m"
#define AQUA   "\x1B[38;2;0;180;200m"
#define LGREEN  "\x1B[38;2;17;245;120m"
#define GRAY    "\x1B[38;2;176;174;174m"
#define PURPLE  "\x1B[38;2;128;0;128m"
#define PINK    "\x1B[38;2;255;192;203m"
#define RESET   "\x1b[0m"
#define BOLD    "\x1b[1m"
#define UNDERLINE "\x1b[4m"
#define ITALIC "\x1b[3m"

// COLOR DEL FONDO //
#define BG_BLACK   "\x1B[40m"
#define BG_RED     "\x1B[41m"
#define BG_GREEN   "\x1B[42m"
#define BG_YELLOW  "\x1B[43m"
#define BG_BLUE    "\x1B[44m"
#define BG_MAGENTA "\x1B[45m"
#define BG_CYAN    "\x1B[46m"
#define BG_WHITE   "\x1B[47m"
#define BG_ORANGE  "\x1B[48;2;255;128;0m"
#define BG_LBLUE   "\x1B[48;2;53;149;240m"
#define BG_LGREEN  "\x1B[48;2;17;245;120m"
#define BG_GRAY    "\x1B[48;2;176;174;174m"
#define BG_ROSE    "\x1B[48;2;255;151;203m"

#endif // COLORES_H
