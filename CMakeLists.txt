cmake_minimum_required(VERSION 3.20)
project(informatics)

set(CMAKE_CXX_STANDARD 17)


add_executable(straight_line 3_semester/straight_line/main.cpp 3_semester/straight_line/StraightLine.cpp 3_semester/straight_line/StraightLine.h)
add_executable(rational_number 3_semester/rational_number/main.cpp 3_semester/rational_number/RationalNumber.cpp 3_semester/rational_number/RationalNumber.h)
add_executable(complex_number 3_semester/complex_number/main.cpp 3_semester/complex_number/ComplexNumber.cpp 3_semester/complex_number/ComplexNumber.h)
add_executable(parabola 3_semester/parabola/main.cpp 3_semester/parabola/Parabola.cpp 3_semester/parabola/Parabola.h)
add_executable(resistor 3_semester/resistor/main.cpp 3_semester/resistor/Resistor.cpp 3_semester/resistor/Resistor.h)