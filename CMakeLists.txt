cmake_minimum_required(VERSION 3.23)
project(euystrukded C)

set(CMAKE_C_STANDARD 11)

include_directories(src/adt)
include_directories(src/commands)
include_directories(src/data)
include_directories(src/services)
include_directories(src/utils)

add_executable(euystrukded
        src/adt/boolean.h
        src/adt/charmachine.h
        src/adt/food.h
        src/adt/list_delivery.h
        src/adt/list_food.h
        src/adt/list_food_recipe.h
        src/adt/matrix.h
        src/adt/notification.h
        src/adt/point.h
        src/adt/recipe.h
        src/adt/simulator.h
        src/adt/stack_command.h
        src/adt/string.h
        src/adt/time.h
        src/adt/tree.h
        src/adt/wordmachine.h
        src/commands/boil.h
        src/commands/buy.h
        src/commands/catalog.h
        src/commands/chop.h
        src/commands/cookbook.h
        src/commands/delivery.h
        src/commands/exit.h
        src/commands/fry.h
        src/commands/inventory.h
        src/commands/mix.h
        src/commands/move.h
        src/commands/redo.h
        src/commands/start.h
        src/commands/undo.h
        src/commands/wait.h
        src/data/configdata.h
        src/data/delivery.h
        src/data/history.h
        src/data/simulator.h
        src/services/boiler.h
        src/services/chopper.h
        src/services/clock.h
        src/services/delivery.h
        src/services/fryer.h
        src/services/history.h
        src/services/map.h
        src/services/mixer.h
        src/services/notifier.h
        src/services/simulator.h
        src/utils/parser.h
        src/main.c)
