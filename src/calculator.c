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

/** @file calculator.c
 ** @brief Implementación del módulo de calculadora
 **/

/* === Headers files inclusions ==================================================================================== */

#include "calculator.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* === Macros definitions ========================================================================================== */

/* === Private data type declarations ============================================================================== */

/** @brief estructura para las operaciones de la calculadora*/
typedef struct operationS * operationT;

struct operationS {
    char operator;
    operationFunc func;
    operationT next;
};

/** @brief estructura que define el objeto calculadora*/
struct calculatorS {
    operationT operation;
};

/* === Private function declarations =============================================================================== */

/**
 * @brief Verifica si existe una operación en la calculadora con el operador dado.
 *
 * @param calculator    Referencia al objeto calculadora.
 * @param operator      El operador de la operación a buscar.
 * @return operationT   Puntero a la operación encontrada o NULL si no existe.
 */
static operationT FindOperation(calculatorT calculator, char operator);

/* === Private variable definitions ================================================================================ */

/* === Public variable definitions ================================================================================= */

/* === Private function definitions ================================================================================ */

static operationT FindOperation(calculatorT calculator, char operator) {
    operationT current = calculator->operation;
    while (current != NULL) {
        if (current->operator == operator) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/* === Public function implementation ============================================================================== */

calculatorT CalculatorCreate(void) {
    calculatorT self = malloc(sizeof(struct calculatorS));
    if (self != NULL) {
        self->operation = NULL; // Inicializa la lista de operaciones como vacía
    }
    return self;
}

bool CalculatorAddOperation(calculatorT calculator, char operator, operationFunc func) {
    if (!calculator || !func || FindOperation(calculator, operator)) {
        return false; // Verifica si el puntero a la calculadora o la función es nulo
    }
    operationT newOperation = malloc(sizeof(struct operationS));
    if (newOperation != NULL) {
        newOperation->operator = operator;
        newOperation->func = func;
        newOperation->next = calculator->operation; // Inserta al inicio de la lista
        calculator->operation = newOperation;       // Actualiza la cabeza de la lista
        return true;
    }
    return false; // No se pudo asignar memoria para la nueva operación
}

int CalculatorCalculate(calculatorT calculator, const char * expression) {
    int a = 0, b = 0;
    char operator = 0;
    int result = 0;

    if (!calculator || !expression) {
        return 0; // Verifica si el puntero a la calculadora o la expresión es nulo
    }

    for (size_t i = 0; i < strlen(expression); i++) {
        if (expression[i] < '0' || expression[i] > '9') {
            operator = expression[i];
            a = atoi(expression);         // Convierte el número anterior a entero
            b = atoi(expression + i + 1); // Convierte el número siguiente a entero
            break;                        // Sale del bucle después de encontrar el operador
        }
    }

    operationT op = FindOperation(calculator, operator);

    if (op != NULL) {
        result = op->func(a, b); // Llama a la función de la operación encontrada
    } else {
        return 0; // Si no se encuentra la operación, retorna 0
    }

    return result;
}

int OperationAdd(int operand1, int operand2) {
    return operand1 + operand2;
}

int OperationSubtract(int operand1, int operand2) {
    return operand1 - operand2;
}

int OperationMultiply(int operand1, int operand2) {
    return operand1 * operand2;
}

int OperationDiv(int operand1, int operand2) {
    if (operand2 != 0) {
        return operand1 / operand2; // Evita división por cero
    } else {
        printf("Error: Division por cero\n");
    }

    return 404; // Retorna 0 si el divisor es cero
}
/* === End of documentation ======================================================================================== */
