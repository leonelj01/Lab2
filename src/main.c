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

/** @file main.c
 ** @brief codigo fuente principal del proyecto
 **/

/* === Headers files inclusions ==================================================================================== */

#include "calculator.h"
#include <stdlib.h>
#include <stdio.h>

/* === Macros definitions ========================================================================================== */

/* === Private data type declarations ============================================================================== */

/* === Private function declarations =============================================================================== */

/* === Private variable definitions ================================================================================ */

/* === Public variable definitions ================================================================================= */

/* === Private function definitions ================================================================================ */

/* === Public function implementation ============================================================================== */

int main(void) {

    static const char expression[] = "24+16";
    static const char expression2[] = "12*8";
    static const char expression3[] = "20-5";
    static const char expression4[] = "10/2";

    int result;

    calculatorT calculator = CalculatorCreate();
    CalculatorAddOperation(calculator, '+', OperationAdd);
    CalculatorAddOperation(calculator, '-', OperationSubtract);
    CalculatorAddOperation(calculator, '*', OperationMultiply);
    CalculatorAddOperation(calculator, '/', OperationDiv);

    result = CalculatorCalculate(calculator, expression);
    printf("Resultado de la expresion '%s': %d\n", expression, result);
    result = CalculatorCalculate(calculator, expression2);
    printf("Resultado de la expresion '%s': %d\n", expression2, result);
    result = CalculatorCalculate(calculator, expression3);
    printf("Resultado de la expresion '%s': %d\n", expression3, result);
    result = CalculatorCalculate(calculator, expression4);
    printf("Resultado de la expresion '%s': %d\n", expression4, result);

    return 0;
}

/* === End of documentation ======================================================================================== */
