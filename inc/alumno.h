/*********************************************************************************************************************
Copyright (c) 2025, Gustavo Leonel Juarez <leonellj01@gmail.com>
Copyright (c) 2025, Laboratorio de microprocesadores, Universidad Nacional de Tucumán, Argentina

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*********************************************************************************************************************/

#ifndef ALUMNO_H_
#define ALUMNO_H_

/** @file alumno.h
 ** @brief cabecera del modulo alumno
 ** @details Este archivo contiene las declaraciones de las funciones y variables del modulo alumno.
 **/

/* === Headers files inclusions ==================================================================================== */

#include <stdint.h>

/* === Header for C++ compatibility ================================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =================================================================================== */

/* === Public data type declarations =============================================================================== */
//! Puntero que representa un alumno
typedef struct alumno_s * alumno_t;

/* === Public variable declarations ================================================================================ */

/* === Public function declarations ================================================================================ */

/**
 * @brief Función para crear un nuevo alumno
 * 
 * @param nombre    Nombre del alumno 
 * @param apellido  Apellido del alumno
 * @param documento Número de documento del alumno
 * @return alumno_t Referencia al nuevo alumno creado
 */
alumno_t AlumnoCrear(char * nombre, char * apellido, uint32_t documento);

/**
 * @brief Función para serializar los datos de un alumno
 *
 * @param alumno Referencia al objeto a serializar
 * @param buffer Cadena de caracteres donde se guardarán los datos serializados
 * @param size   Espacio disponible en la cadena de caracteres
 * @retval la cantidad de caracteres escritos en la cadena
 * @retval -1 si no se pudo serializar el alumno
 */
int AlumnoSerializar(alumno_t alumno, char * buffer, uint32_t size);

/* === End of conditional blocks =================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /*ALUMNO_H_*/
