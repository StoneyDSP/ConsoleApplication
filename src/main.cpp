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

/** Main.
 * @brief Entry point for program execution.
 *
 * @param argc int
 * @param argv char**
 * @param envp char**
 * @return int
 */
int main(int argc, char* argv[], char* envp[])
{
    using namespace stoneydsp;

    ignore(argc, argv, envp);

    intro();

    endFunction();

    //juce::ConsoleApplication app;

    Double a{ 1 };

    Double b{ 2 };

    Double c{ 3 };

    Double d{ a };

    Double e{ 10 };

    endFunction();

    //app.fail("?", 1);

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

    //print("Modulo Tests");
    //e = e % d % c % b % a;
    //endFunction();

    return outro();
}
