cmake_minimum_required(VERSION 3.23)
project(euystrukded C)

set(CMAKE_C_STANDARD 17)

include_directories(src/adt)
include_directories(src/commands)
include_directories(src/data)
include_directories(src/services)
include_directories(src/utils)

file(GLOB src
        "src/adt/*.h"
        "src/adt/*.c"
        "src/data/*.h"
        "src/data/*.c"
        "src/services/*.h"
        "src/services/*.c"
        "src/commands/*.h"
        "src/commands/*.c"
        "src/utils/*.h"
        "src/utils/*.c"
        )

add_executable(euystrukded
        ${src}
        src/main.c)
