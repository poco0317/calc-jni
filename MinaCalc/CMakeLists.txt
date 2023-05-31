add_subdirectory(Agnostic)
add_subdirectory(Dependent)

list(APPEND GENERAL_CALC_SRC
    "MinaCalc.h"
    "MinaCalc.cpp")

target_sources(Etterna PUBLIC ${GENERAL_CALC_SRC})