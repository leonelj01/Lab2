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
 * @brief 
 * 
 * @param campo 
 * @param valor 
 * @param buffer 
 * @param size 
 * @return int 
 */
static int SerializarCadena(char campo[],const char valor[], char buffer[], uint32_t size);

/**
 * @brief 
 * 
 * @param campo 
 * @param valor 
 * @param buffer 
 * @param size 
 * @return int 
 */

static int SerializarNumero(char campo[], int valor[], char buffer[], uint32_t size);

/* === Private variable definitions ================================================================================ */

int SerializarCadena(char campo[],const char valor[], char buffer[], uint32_t size){
    return snprintf(buffer, size, "\"%s\":\"%s\",", campo, valor);
}

int SerializarNumero(char campo[], int valor[], char buffer[], uint32_t size){
    return snprintf(buffer, size, "\"%s\":\"%i\",", campo, valor);
}

/* === Public variable definitions ================================================================================= */

/* === Private function definitions ================================================================================ */

int Serializar(const alumno_t alumno, char *buffer, uint32_t size){
    int escritos;
    int resultado;
    
    buffer[0] = '{';
    buffer++;
    escritos = 1;

    resultado = SerializarCadena("nombre", alumno->nombre, buffer, size - escritos);

    if (resultado < 0) return -1;

    buffer = buffer + resultado;
    escritos += resultado;

    escritos += SerializarCadena("apellido", alumno->apellido, buffer, size - escritos);

    return escritos;

}

/* === Public function implementation ============================================================================== */

/* === End of documentation ======================================================================================== */
