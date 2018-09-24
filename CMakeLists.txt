cmake_minimum_required(VERSION 3.10)
project(assembly C)

set(CMAKE_C_STANDARD 99)

add_executable(assemblyc main.c check.c check.h process.c process.h clean-code.c clean-code.h errors.c errors.h)