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

#ifndef CONFIG_H_
#define CONFIG_H_

/** @file config.h
 ** @brief Archivo de configuración para el proyecto
 **/

/* === Headers files inclusions ==================================================================================== */

/* === Header for C++ compatibility ================================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =================================================================================== */

/**
 * @brief Seleccion del tipo de memoria a utilizar
 * 
 * Permite decidir si se desea usar memoria dinamica o estatica, al cambiar el valor de TIPO_MEMORIA.abort
 * Una vez cambiado el valor, el programa utiliza las funciones necesarias para la correcta implementacion del tipo de memoria elegida. 
 * 
 * 0: Memoria estatica, 1: Memoria dinamica
 */
#define TIPO_MEMORIA 0

// Definición de macros según el tipo de memoria
#if TIPO_MEMORIA == 0
    #define USAR_MEMORIA_ESTATICA
#elif TIPO_MEMORIA == 1
    #define USAR_MEMORIA_DINAMICA
#else
    #error "Error: TIPO_MEMORIA no definido correctamente. Debe ser 0 (memoria estatica) o 1 (memoria dinamica)."
#endif

// Configuración especifica para memoria estatica
#ifdef USAR_MEMORIA_ESTATICA
    #define ALUMNO_MAX_INSTANCIAS 2 //!< Cantidad maxima de instancias
#endif

/* === Public data type declarations =============================================================================== */

/* === Public variable declarations ================================================================================ */

/* === Public function declarations ================================================================================ */

/* === End of conditional blocks =================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* CONFIG_H_ */