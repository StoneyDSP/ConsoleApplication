/*******************************************************************************
 *
 * @file main.cpp
 *
 * @author Nathan J. Hood (nathanjhood@googlemail.com)
 * @version 1.0.0.1
 * @date 2022-08-13
 *
 * @copyright Copyright (c) 2022 @StoneyDSP
 *
 *******************************************************************************
*/

#include "main.h"

/** main.
 * @brief Entry point for program execution.
 *
 * @param argc Number of strings in array argv.
 * @param argv Array of command-line argument strings.
 * @return Exit code.
 */
int main(int argc, char* argv[])
{
    using namespace stoneydsp;

    ignore(argc, argv);

    intro();

    print(CENTRE, cmakeCfgIntDir);

    endFunction();

    // Display each command-line argument.
    for (int i = 1; i < argc; i++)
    {
        print(CENTRE, argv[i]);
    }

    wait();

    Float a{ 1 };

    Float b{ 2 };

    Float c{ 3 };

    Float d{ a };

    Float e{ 10 };

    endFunction();

    print(CENTRE, "Addition Tests");
    lineBreak();
    e = e + d + c + b + a;
    endFunction();

    print(CENTRE, "Subtraction Tests");
    e = e - d - c - b - a;
    endFunction();

    print(CENTRE, "Multiplication Tests");
    e = e * d * c * b * a;
    endFunction();

    print(CENTRE, "Division Tests");
    e = e / d / c / b / a;
    endFunction();

    // print("Modulo Tests");
    // e = e % d % c % b % a;
    // endFunction();

    return outro();
}
