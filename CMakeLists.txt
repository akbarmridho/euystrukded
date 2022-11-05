cmake_minimum_required(VERSION 3.23)
project(euystrukded C)

set(CMAKE_C_STANDARD 11)

include_directories(src/adt)
include_directories(src/autobnmo)
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
        "src/autobnmo/core/*.h"
        "src/autobnmo/core/*.c"
        "src/autobnmo/services/*.h"
        "src/autobnmo/services/*.c"
        "src/autobnmo/commands/*.h"
        "src/autobnmo/commands/*.c"
        )

add_executable(euystrukded
        ${src}
        src/main.c)
