cmake_minimum_required(VERSION 3.20)
project(informatics)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        class_work
        3_semester/class_work/main.cpp
)

add_executable(
        straight_line
        3_semester/straight_line/main.cpp
        3_semester/straight_line/StraightLine.cpp
        3_semester/straight_line/StraightLine.h
)
add_executable(
        rational_number
        3_semester/rational_number/main.cpp
        3_semester/rational_number/RationalNumber.cpp
        3_semester/rational_number/RationalNumber.h
)
add_executable(
        complex_number
        3_semester/complex_number/main.cpp
        3_semester/complex_number/ComplexNumber.cpp
        3_semester/complex_number/ComplexNumber.h
)
add_executable(
        parabola
        3_semester/parabola/main.cpp
        3_semester/parabola/Parabola.cpp
        3_semester/parabola/Parabola.h
)
add_executable(
        resistor
        3_semester/resistor/main.cpp
        3_semester/resistor/Resistor.cpp
        3_semester/resistor/Resistor.h
)
add_executable(
        vector3D
        3_semester/vector3D/main.cpp
        3_semester/vector3D/Vector3D.cpp
        3_semester/vector3D/Vector3D.h
        3_semester/vector3D/Point3D.cpp
        3_semester/vector3D/Point3D.h
)
add_executable(
        boolean
        3_semester/boolean/main.cpp
        3_semester/boolean/Boolean.cpp
        3_semester/boolean/Boolean.h
)
add_executable(
        university_grades_control
        3_semester/university_grades_control/main.cpp
        3_semester/university_grades_control/sharedModule.h
        3_semester/university_grades_control/Person.cpp
        3_semester/university_grades_control/Person.h
        3_semester/university_grades_control/Teacher.cpp
        3_semester/university_grades_control/Teacher.h
        3_semester/university_grades_control/Student.cpp
        3_semester/university_grades_control/Student.h
        3_semester/university_grades_control/utils.h
        3_semester/university_grades_control/utils.cpp
        3_semester/university_grades_control/GradeBook.h
        3_semester/university_grades_control/GradeBook.cpp
)
add_executable(
        syntactic_analysis
        3_semester/syntactic_analysis/main.cpp
        3_semester/syntactic_analysis/SyntacticAnalyzer.h
        3_semester/syntactic_analysis/sharedModule.h
        3_semester/syntactic_analysis/utils.h
        3_semester/syntactic_analysis/utils.cpp
        3_semester/syntactic_analysis/Stack.h
        3_semester/syntactic_analysis/List.h
        3_semester/syntactic_analysis/Logger.h
        3_semester/syntactic_analysis/Logger.cpp
)

add_executable(
        big_int
        3_semester/big_int/main.cpp
        3_semester/big_int/BigInt.h
        3_semester/big_int/BigInt.cpp
        3_semester/stl_tasks/main.cpp 3_semester/stl_tasks/bus_routes.h)

add_executable(
        matrix
        3_semester/matrix/main.cpp
        3_semester/matrix/Matrix.h
        3_semester/matrix/Matrix.cpp
)

add_executable(
        maze
        3_semester/maze/main.cpp
        3_semester/maze/Stack.h
        3_semester/maze/Maze.h
        3_semester/maze/Maze.cpp
        3_semester/maze/shared.h
)

add_executable(
        vector
        3_semester/vector/main.cpp
        3_semester/vector/vector.h
)

add_executable(
        heap
        3_semester/heap/main.cpp
        3_semester/heap/Heap.h
)

add_executable(
        linkedList
        3_semester/linked_list/main.cpp
        3_semester/linked_list/Node.h
        3_semester/linked_list/Iterator.h
        3_semester/linked_list/LinkedList.h
        3_semester/linked_list/SorterLinkedList.h
)

add_executable(
        my_string
        3_semester/my_string/main.cpp
        3_semester/my_string/MyString.h
        3_semester/my_string/MyString.cpp
        3_semester/my_string/MyStringIdentifier.h
        3_semester/my_string/MyStringIdentifier.cpp
)

add_executable(
        shapes
        3_semester/shapes/main.cpp
        3_semester/shapes/utils.h
        3_semester/shapes/Shape.h
        3_semester/shapes/Triangle.h
        3_semester/shapes/Rectangle.h
        3_semester/shapes/Circle.h
)

add_executable(
        music_shop
        3_semester/music_shop/main.cpp
        3_semester/music_shop/Instrument.h
        3_semester/music_shop/Piano.h
        3_semester/music_shop/Drum.h
        3_semester/music_shop/Violin.h
        3_semester/music_shop/Trumpet.h
        3_semester/music_shop/Clarinet.h
        3_semester/music_shop/Xylophone.h
        3_semester/music_shop/Guitar.h
        3_semester/music_shop/Accordion.h
        3_semester/music_shop/Saxophone.h
        3_semester/music_shop/Instrument.cpp
)

add_executable(
        stl_tasks
        3_semester/stl_tasks/main.cpp
        3_semester/stl_tasks/bus_routes.h
)
