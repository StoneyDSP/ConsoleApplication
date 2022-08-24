﻿# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.

# CMake requirements.
cmake_minimum_required (VERSION 3.8)

# Toolchain location. Stores result in the CMakeCache.
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Toolchain file")

# Replace the "yourCompany" string with the name of the author/company of this project. Stores result in the CMakeCache.
set(COMPANY_NAME "StoneyDSP" CACHE STRING "Name of author/company")

# Create a CMake project here.
project (
	"ConsoleApplication"
	VERSION 0.0.0.1
	DESCRIPTION "Console Application with CMake"
	HOMEPAGE_URL https://stoneydsp.github.io/ConsoleApplication/html/index.html
	LANGUAGES C CXX
)

# Add source to this project's executable.
add_executable (ConsoleApplication
	"${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/main.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/cfg/${CMAKE_PROJECT_NAME}_Config.h.in"
	"${CMAKE_CURRENT_SOURCE_DIR}/cfg/${CMAKE_PROJECT_NAME}_Config.h"
)

# Add packages (including IntelliSense) to the project.
find_package (fmt CONFIG REQUIRED)
target_link_libraries (${CMAKE_PROJECT_NAME} PRIVATE fmt::fmt)

find_package (CppUnit CONFIG REQUIRED)
target_link_libraries (${CMAKE_PROJECT_NAME} PRIVATE CppUnit)

# Add configuration file.
configure_file (
	"${CMAKE_CURRENT_SOURCE_DIR}/cfg/${CMAKE_PROJECT_NAME}_Config.h.in"
	"${CMAKE_CURRENT_SOURCE_DIR}/cfg/${CMAKE_PROJECT_NAME}_Config.h"
)

# Check language requirements.
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()

# Include sub-folder/projects.
add_subdirectory ("src")
add_subdirectory ("cfg")

# Add tests and install targets if needed. Comment out if not required.
include(CPACK)
include(CTest)

# Enable testing. Comment out if not required.
enable_testing()