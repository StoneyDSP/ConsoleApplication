# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.

# CMake requirements.
cmake_minimum_required(VERSION 3.7...3.24)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Toolchain location. Stores result in the CMakeCache.
set(CMAKE_TOOLCHAIN_FILE
  ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Toolchain file"
)

set_property(GLOBAL PROPERTY USE_FOLDERS YES)

# Create a CMake project here.
project (ConsoleApplication LANGUAGES C CXX)

# Add source to this project's executable.
add_executable (ConsoleApplication ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

# make cache variables for install destinations
include(GNUInstallDirs)

# include CMakePackageConfigHelpers macro
include(CMakePackageConfigHelpers)

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

# specify the C standard
#set(CMAKE_C_STANDARD 17)
#set(CMAKE_C_STANDARD_REQUIRED True)

# specify the C++ standard
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ConsoleApplication PROPERTY CXX_STANDARD 20)
endif()

# generate the version file for the config file
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/ConsoleApplicationConfigVersion.cmake
  VERSION ${version}
  COMPATIBILITY AnyNewerVersion
)

# create config file
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ConsoleApplicationConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/cmake/ConsoleApplicationConfig.cmake
  INSTALL_DESTINATION
    ${CMAKE_INSTALL_LIBDIR}/cmake/ConsoleApplication
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ConsoleApplicationConfig.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/ConsoleApplicationConfig.h
)

# install config files
install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/cmake/ConsoleApplicationConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/cmake/ConsoleApplicationConfigVersion.cmake
  DESTINATION
    ${CMAKE_INSTALL_LIBDIR}/cmake/ConsoleApplication
)

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
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.h
    ${CMAKE_CURRENT_BINARY_DIR}/cmake/ConsoleApplicationConfig.h
)

# adds some preprocessor definitions to our target.
target_compile_definitions(ConsoleApplication
  PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
)
