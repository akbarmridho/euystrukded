#ifndef COMMAND_PROCESSOR_H
#define COMMAND_PROCESSOR_H

#include "../services/food_processor.h"
#include "../services/simulator.h"
#include "../utils/validator.h"
#include "../services/history.h"
#include "../services/delivery.h"
#include "../utils/display.h"

void process_request(enum food_source source);

#endif
