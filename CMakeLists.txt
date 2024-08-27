cmake_minimum_required(VERSION 3.22)

project(MorseCodeTranslator VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(MORSE_LIBRARY morse)
set(EXECUTABLE_NAME translator)

add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(app)