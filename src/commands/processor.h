#ifndef COMMAND_PROCESSOR_H
#define COMMAND_PROCESSOR_H

#include "../services/chopper.h"
#include "../services/boiler.h"
#include "../services/mixer.h"
#include "../services/fryer.h"
#include "../services/boiler.h"
#include "../services/simulator.h"
#include "../utils/validator.h"
#include "../services/history.h"
#include "../services/delivery.h"
#include "../utils/display.h"

void process_request(enum food_source source);

#endif
