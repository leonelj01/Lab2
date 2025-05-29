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

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

/** @file calculator.h
 ** @brief Definición de la interfaz del módulo de calculadora
 **/

/* === Headers files inclusions ==================================================================================== */

#include <stdbool.h>

/* === Header for C++ compatibility ================================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =================================================================================== */

/* === Public data type declarations =============================================================================== */

typedef struct calculatorS * calculatorT;

typedef int (*operationFunc)(int, int);

/* === Public variable declarations ================================================================================ */

/* === Public function declarations ================================================================================ */

/**
 * @brief Construye un objeto calculadora.
 * 
 * @return calculatorT  Referencia al objeto calculadora creado.
 */
calculatorT CalculatorCreate(void);

/**
 * @brief Permite agregar una operación a la calculadora.
 * 
 * @param calculator    Referencia al objeto calculadora.
 * @param operator      El operador de la operación a agregar.
 * @param func          Puntero a la función que implementa la operación.
 * @return true         Si la operación se agregó correctamente.
 * @return false        Si la operación no se pudo agregar.
 */
bool CalculatorAddOperation(calculatorT calculator, char operator, operationFunc func);

/**
 * @brief Calcula el resultado de una expresión matemática.
 * 
 * @param calculator    Referencia al objeto calculadora.
 * @param expression    Cadena de caracteres que representa la expresión a calcular.
 * @return int          Resultado de la operación o 0 si no se pudo calcular.
 */
int CalculatorCalculate(calculatorT calculator,const char *expression);

/**
 * @brief Realiza la suma de dos operandos.
 * 
 * @param operand1  
 * @param operand2 
 * @return int 
 */
int OperationAdd(int operand1, int operand2);

/**
 * @brief Realiza la resta de dos operandos.
 * 
 * @param operand1  
 * @param operand2 
 * @return int 
 */
int OperationSubtract(int operand1, int operand2);


/* === End of conditional blocks =================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* CALCULATOR_H_ */
