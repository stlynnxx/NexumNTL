cmake_minimum_required(VERSION 4.1)
project(NexumNTL C)

set(CMAKE_C_STANDARD 11)

add_executable(NexumNTL main.c
        Lexer.c
        Lexer.h
        main.h
        SymbolTable.c
        SymbolTable.h
        SourceGenerator.c
        SourceGenerator.h)
target_compile_options(NexumNTL PRIVATE -Wall)