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

/** @file alumno.c
 ** @brief codigo fuente del modulo alumno
 ** @details Este archivo contiene la implementacion de las funciones y variables del modulo alumno.
 **/

/* === Headers files inclusions ==================================================================================== */

#include "alumno.h"
#include <stdio.h>

/* === Macros definitions ========================================================================================== */

/* === Private data type declarations ============================================================================== */

/* === Private function declarations =============================================================================== */

/**
 * @brief Serializa un par de variables del tipo caracter en formato JSON.
 *
 *
 * @param campo Cadena de caracteres que representa al campo de la estructura.
 * @param valor Cadena de caracteres asociada al campo.
 * @param buffer Buffer donde se escribe la cadena serializada.
 * @param size Tamaño máximo del buffer.
 *
 * @return Número de caracteres escritos (sin incluir el carácter nulo de fin de cadena),
 *         o un valor negativo si ocurre un error.
 */
static int SerializarCadena(char campo[], const char valor[], char buffer[], uint32_t size);

/**
 * @brief Serializa un campo con un valor numérico sin signo en formato JSON.
 *
 *
 * @param campo Cadena de caracteres que representa el nombre del campo.
 * @param valor Valor numérico sin signo de 32 bits a serializar.
 * @param buffer Buffer donde se escribe la cadena serializada.
 * @param size Tamaño máximo del buffer.
 *
 * @return Número de caracteres escritos (sin incluir el carácter nulo de fin de cadena),
 *         o un valor negativo si ocurre un error.
 */
static int SerializarNumero(char campo[], uint32_t valor, char buffer[], uint32_t size);

/* === Private variable definitions ================================================================================ */

int SerializarCadena(char campo[], const char valor[], char buffer[], uint32_t size) {
    return snprintf(buffer, size, "\"%s\":\"%s\",", campo, valor);
}

int SerializarNumero(char campo[], uint32_t valor, char buffer[], uint32_t size) {
    return snprintf(buffer, size, "\"%s\":\"%u\"}", campo, valor);
}

/* === Public variable definitions ================================================================================= */

/* === Private function definitions ================================================================================ */

int Serializar(const alumno_t alumno, char * buffer, uint32_t size) {
    int escritos;
    int resultado;

    buffer[0] = '{';
    buffer++;
    escritos = 1;

    resultado = SerializarCadena("nombre", alumno->nombre, buffer, size - escritos);

    if (resultado < 0 || resultado >= size - escritos) {
        return -1;
    }

    buffer = buffer + resultado;
    escritos += resultado;

    resultado = SerializarCadena("apellido", alumno->apellido, buffer, size - escritos);

    if (resultado < 0 || resultado >= size - escritos) {
        return -1;
    }

    buffer = buffer + resultado;
    escritos += resultado;

    resultado = SerializarNumero("documento", alumno->documento, buffer, size - escritos);

    return resultado < 0 ? -1 : escritos + resultado;
}

/* === Public function implementation ============================================================================== */

/* === End of documentation ======================================================================================== */
