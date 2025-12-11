cmake_minimum_required(VERSION 3.26)
project(ELAs C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(ELAs
        src/main.c
        include/profissional.h
        src/profissional.c
        include/arquivo.h
        src/arquivo.c
        include/interface.h
        src/interface.c
        include/busca.h
        src/busca.c
        include/ordenacao.h
        src/ordenacao.c
        include/relatorio.h
        src/relatorio.c
        include/utils.h
        src/utils.c
)
