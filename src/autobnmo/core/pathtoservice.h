#ifndef AUTOBNMO_CORE_PATHTOSERVICE_H
#define AUTOBNMO_CORE_PATHTOSERVICE_H

#include "boolean.h"
#include "point.h"
#include "configdata.h"
#include <stdlib.h>

void
build_map(int ***map_original, boolean ***map_visited, int ***map_distance, int ***map_origin, point_t start,
          char goal);

void free_map(int ***map_original, boolean ***map_visited, int ***map_distance, int ***map_origin);

void get_min_distance(int **map_distance, boolean **map_visited, int currentX, int currentY, int *xMin, int *yMin);

void find_path(point_t start, point_t goal, point_t **path, int *steps);

#endif
