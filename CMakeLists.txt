# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.

# CMake requirements.
cmake_minimum_required (VERSION 3.15)

# Toolchain location. Stores result in the CMakeCache.
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Toolchain file")

# Company/author name
set(CMAKE_COMPANY_NAME "StoneyDSP" CACHE STRING "Company Name")

# Create a CMake project here.
# This is a standard CMake command.
project (
	"ConsoleApplication"
	VERSION 0.0.0.1
	DESCRIPTION "VS Console Application with CMake, vcpkg, Doxygen, and JUCE support"
	HOMEPAGE_URL https://stoneydsp.github.io/ConsoleApplication/html/index.html
	LANGUAGES C CXX
)

# create config file
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ConsoleApplication_Config.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/ConsoleApplication_Config.h
)

add_executable (ConsoleApplication
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.h
	${CMAKE_CURRENT_BINARY_DIR}/cmake/ConsoleApplication_Config.h
)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(JUCE CONFIG REQUIRED)
find_package(StoneyDSP CONFIG REQUIRED)

# Include sub-folder/projects to the build tree.
add_subdirectory (src)
add_subdirectory (cmake)

# set version
set(version 0.0.0.1)

set_property(TARGET ConsoleApplication PROPERTY VERSION ${version})
set_property(TARGET ConsoleApplication PROPERTY SOVERSION 0)
set_property(TARGET ConsoleApplication PROPERTY INTERFACE_ConsoleApplication_MAJOR_VERSION 3)
set_property(TARGET ConsoleApplication APPEND PROPERTY COMPATIBLE_INTERFACE_STRING
    ConsoleApplication_MAJOR_VERSION
)

# `juce_add_console_app` adds an executable target with the name passed as the first argument
# (ConsoleAppExample here). This target is a normal CMake target, but has a lot of extra properties
# set up by default. This function accepts many optional arguments. Check the readme at
# `docs/CMake API.md` in the JUCE repo for the full list.
#juce_add_console_app (ConsoleApplication
#    PRODUCT_NAME "ConsoleApplication"
#	COMPANY_NAME "StoneyDSP"
#	DESCRIPTION "VS Console Application with CMake, vcpkg, Doxygen, and JUCE support"
#)


# `target_link_libraries` links libraries and JUCE modules to other libraries or executables.
# Inter-module dependencies are resolved automatically. If you'd generated a binary data
# target above, you would need to link to it here too.
# This is a standard CMake command.
target_link_libraries(ConsoleApplication
    PRIVATE
    # ConsoleApplication_Data           # If we'd created a binary data target above, we'd link to it here
    juce::juce_core
    StoneyDSP::StoneyDSP_Core
    PUBLIC
    juce::juce_recommended_config_flags
    juce::juce_recommended_warning_flags
)

# specify the C++ standard
#if (CMAKE_VERSION VERSION_GREATER 3.12)
#  set_property(TARGET ConsoleApplication PROPERTY CXX_STANDARD 20)
#endif()


# `target_sources` adds source files to a target. We pass the target that needs the sources as the
# first argument, then a visibility parameter for the sources which should normally be PRIVATE.
# Finally, we supply a list of source files that will be built into the target.
# This is a standard CMake command.
 target_sources(ConsoleApplication
    PRIVATE
	"src/main.cpp"
	"src/main.h"
	"cmake/ConsoleApplication_Config.h"
)

# `target_compile_definitions` adds some preprocessor definitions to our target. In a Projucer
# project, these might be passed in the 'Preprocessor Definitions' field. JUCE modules also make use
# of compile definitions to switch certain features on/off, so if there's a particular feature you
# need that's not on by default, check the module header for the correct flag to set here. These
# definitions will be visible both to your code, and also the JUCE module code, so for new
# definitions, pick unique names that are unlikely to collide!
# This is a standard CMake command.
target_compile_definitions(ConsoleApplication
    PRIVATE
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_console_app` call
        JUCE_USE_CURL=0    # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_console_app` call
)


# Export options
#set(CMAKE_EXPORT_COMPILE_COMMANDS on)
#set(CMAKE_ENABLE_EXPORTS on)

# Add tests and install targets if needed. Comment out if not required.
#include(CPACK)
#include(CTest)

# Enable testing. Comment out if not required.
# enable_testing()
