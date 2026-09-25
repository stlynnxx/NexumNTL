cmake_minimum_required(VERSION 4.1)
project(NexumNTL C)

set(CMAKE_C_STANDARD 11)

add_executable(NexumNTL Source/main.c
        Source/Lexer/Lexer.c
        Source/Lexer/Lexer.h
        Source/main.h
        Source/SymbolTable/SymbolTable.c
        Source/SymbolTable/SymbolTable.h
        Source/SourceGenerator/SourceGenerator.c
        Source/SourceGenerator/SourceGenerator.h
        Source/Parser/Parser.c
        Source/Parser/Parser.h
        Source/main.c
        Source/Compressor/compressor.c
        Source/Compressor/compressor.h
        Source/Usrmor/usermorpheme.c
        Source/Usrmor/usermorpheme.h
        Source/Parser/parserhelpers.c
        Source/Parser/parserhelpers.h
        Source/Lexer/lexerhelpers.c
        Source/Lexer/lexerhelpers.h
        Source/Usrmor/usrmorhelpers.c
        Source/Usrmor/usrmorhelpers.h
        Source/SourceGenerator/SGruninterface.c
        Source/SourceGenerator/SGruninterface.h
)
target_compile_options(NexumNTL PRIVATE -Wall)