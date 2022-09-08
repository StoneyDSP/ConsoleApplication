# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.

# CMake requirements.
cmake_minimum_required(VERSION 3.7...3.24)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Toolchain location. Stores result in the CMakeCache.
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Toolchain file")

# Company/author name
set(CMAKE_COMPANY_NAME "StoneyDSP" CACHE STRING "Company Name")

set_property(GLOBAL PROPERTY USE_FOLDERS YES)

# Create a CMake project here.
# This is a standard CMake command.
project ("ConsoleApplication" LANGUAGES C CXX)

# create config file
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ConsoleApplication_Config.h.in
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ConsoleApplication_Config.h
)

add_executable (ConsoleApplication
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.h
	${CMAKE_CURRENT_SOURCE_DIR}/cmake/ConsoleApplication_Config.h
)

# set version
set(version 0.0.0.1)
set_property(TARGET ConsoleApplication PROPERTY VERSION ${version})
set_property(TARGET ConsoleApplication PROPERTY SOVERSION 0)
set_property(TARGET ConsoleApplication PROPERTY INTERFACE_ConsoleApplication_MAJOR_VERSION 3)
set_property(TARGET ConsoleApplication APPEND PROPERTY COMPATIBLE_INTERFACE_STRING ConsoleApplication_MAJOR_VERSION)

# set description
set(description "VS Console Application with CMake, vcpkg, Doxygen, and JUCE support")
set_property(TARGET ConsoleApplication PROPERTY PROJECT_DESCRIPTION ${description})

# set homepage
set(homepage https://stoneydsp.github.io/ConsoleApplication/html/index.html)
set_property(TARGET ConsoleApplication PROPERTY HOMEPAGE_URL ${homepage})

# set company/author name
set (author "StoneyDSP" CACHE STRING "Company Name")
set_property(TARGET ConsoleApplication PROPERTY AUTHOR ${author})

# specify the C++ standard
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED True)

# specify the C++ standard
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ConsoleApplication PROPERTY CXX_STANDARD 20)
endif()

#find_package(JUCE CONFIG REQUIRED)
#find_package(StoneyDSP CONFIG REQUIRED)

# Include sub-folder/projects to the build tree.
add_subdirectory (src)
add_subdirectory (cmake)

# link libraries and modules to other libraries or executables.
target_link_libraries(ConsoleApplication
    PRIVATE
    juce::juce_core
    stoneydsp::stoneydsp_core
    PUBLIC
    juce::juce_recommended_config_flags
    juce::juce_recommended_warning_flags
)

# add source files to a target.
 target_sources(ConsoleApplication
    PRIVATE
	"src/main.cpp"
	"src/main.h"
	"cmake/ConsoleApplication_Config.h"
)

# adds some preprocessor definitions to our target.
target_compile_definitions(ConsoleApplication
    PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
)


# Export options
#set(CMAKE_EXPORT_COMPILE_COMMANDS on)
#set(CMAKE_ENABLE_EXPORTS on)

# Add tests and install targets if needed. Comment out if not required.
#include(CPACK)
#include(CTest)

# Enable testing. Comment out if not required.
# enable_testing()
