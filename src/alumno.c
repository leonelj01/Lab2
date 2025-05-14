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
#include "config.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/* === Macros definitions ========================================================================================== */

#ifdef USAR_MEMORIA_ESTATICA
    #ifndef ALUMNO_MAX_INSTANCIAS
        #define ALUMNO_MAX_INSTANCIAS 2 //!< valor por defecto de ALUMNO_MAX_INSTANCIAS
    #endif
#endif

/* === Private data type declarations ============================================================================== */

struct alumnoS {
    char nombre[50];    //!< Nombre del alumno
    char apellido[50];  //!< Apellido del alumno
    uint32_t documento; //!< Número de documento del alumno
#ifdef USAR_MEMORIA_ESTATICA
    bool ocupado; //!< Indica si la instancia esta ocupada (0 = libre)
#endif
};

/* === Private function declarations =============================================================================== */

/**
 * @brief Crea una nueva instancia de la estructura alumno_s.
 *
 * @return Puntero a la nueva instancia de alumno_s, o NULL si no hay espacio disponible.
 */
#ifdef USAR_MEMORIA_ESTATICA
static alumnoT CrearInstancia(void);
#endif
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
static int SerializarCadena(char campo[], const char valor[], char buffer[], int size);

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
static int SerializarNumero(char campo[], uint32_t valor, char buffer[], int size);

/* === Private variable definitions ================================================================================ */

#ifdef USAR_MEMORIA_ESTATICA
    static struct alumnoS instancias[ALUMNO_MAX_INSTANCIAS] = {0}; //! <-- Instancias de la estructura alumnoS
#endif

/* === Public variable definitions ================================================================================= */

/* === Private function definitions ================================================================================ */

#ifdef USAR_MEMORIA_ESTATICA
static alumnoT CrearInstancia(void) {
    alumnoT self = NULL;

    for (int i = 0; i < ALUMNO_MAX_INSTANCIAS; i++) {
        if (!instancias[i].ocupado) {
            instancias[i].ocupado = true;
            self = &instancias[i];
            break;
        }
    }
    
    return self;
}
#endif

static int SerializarCadena(char campo[], const char valor[], char buffer[], int size) {
    return snprintf(buffer, size, "\"%s\":\"%s\",", campo, valor);
}

static int SerializarNumero(char campo[], uint32_t valor, char buffer[], int size) {
    return snprintf(buffer, size, "\"%s\":\"%u\"}", campo, valor);
}

/* === Public function implementation ============================================================================== */

alumnoT AlumnoCrear(char * nombre, char * apellido, uint32_t documento) {
#ifdef USAR_MEMORIA_DINAMICA
    alumnoT self = malloc(sizeof(struct alumnoS));
#else
    alumnoT self = CrearInstancia();
#endif
    if (self != NULL) {
        strncpy(self->nombre, nombre, sizeof(self->nombre) - 1);
        strncpy(self->apellido, apellido, sizeof(self->apellido) - 1);
        self->documento = documento;
    } else {
        printf("Error al crear un alumno.\n");
    }

    return self;
}

int AlumnoSerializar(alumnoT self, char * buffer, int size) {

    if(self == NULL) return -1;

    int escritos;
    int resultado;

    buffer[0] = '{';
    buffer++;
    escritos = 1;

    resultado = SerializarCadena("nombre", self->nombre, buffer, size - escritos);

    if (resultado < 0 || resultado >= size - escritos) {
        return -1;
    }

    buffer = buffer + resultado;
    escritos += resultado;

    resultado = SerializarCadena("apellido", self->apellido, buffer, size - escritos);

    if (resultado < 0 || resultado >= size - escritos) {
        return -1;
    }

    buffer = buffer + resultado;
    escritos += resultado;

    resultado = SerializarNumero("documento", self->documento, buffer, size - escritos);

    return (resultado < 0 || escritos + resultado >= size) ? -1 : escritos + resultado;
}

/* === End of documentation ======================================================================================== */
