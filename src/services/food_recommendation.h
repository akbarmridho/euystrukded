#ifndef SERVICE_FOOD_RECOMMENDATION_h
#define SERVICE_FOOD_RECOMMENDATION_h


#include "../data/simulator.h"
#include "../data/configdata.h"
#include "../adt/set.h"


boolean is_path_exist(Tree recipe, Set inventory);

void food_recommendation();



#endif