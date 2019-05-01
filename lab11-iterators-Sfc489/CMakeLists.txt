cmake_minimum_required(VERSION 3.12)
project(lab11)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out)

add_executable(lab11 main.cpp Node.cpp Node.h lab11.h List.h LinkedList.cpp LinkedList.h PrecondViolatedExcep.cpp PrecondViolatedExcep.h LinkedIterator.cpp LinkedIterator.h)

add_custom_command(TARGET lab11 PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/srcData.txt ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})