﻿/*******************************************************************************
 *
 * @file main.h
 *
 * @author Nathan J. Hood (nathanjhood@googlemail.com)
 * @version 1.0.0.1
 * @date 2022-08-13
 *
 * @copyright Copyright (c) 2022 @StoneyDSP
 *
 *******************************************************************************
*/

#pragma once

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

// Config file before modules!!! (use Forced Include if possible(?))
#include "../cfg/ConsoleApplication_Config.h"

// Standard Library includes
#include <iostream>
#include <string.h>

// 3rd Party Library includes
#include <juce_core/juce_core.h>
#include <stoneydsp_core/stoneydsp_core.h>

/** Main.
 * @brief Entry point for program execution.
 *
 * @param argc Number of strings in array argv
 * @param argv Array of command-line argument strings
 * @return int
 */
int main(int argc, char* argv[]);

#endif // MAIN_H_INCLUDED
