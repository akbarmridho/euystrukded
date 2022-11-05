#include "pathtoservice.h"

#define MAX_INT (1<<29)
#define NAN_INT (-1)

void display_graph_map(int **current_map) {
    for (int i = 0; i < map.rowEff; i++) {
        for (int j = 0; j < map.colEff; j++) {
            if (current_map[i][j] == MAX_INT) {
                printf("-1 ");
            } else {
                printf("%d ", current_map[i][j]);

            }
        }
        putchar('\n');
    }
}

void
build_map(int ***map_original, boolean ***map_visited, int ***map_distance, int ***map_origin, point_t start,
          char goal) {
    int row = map.rowEff;
    int col = map.colEff;

    *map_original = (int **) malloc(sizeof(int *) * row);
    *map_visited = (boolean **) malloc(sizeof(boolean *) * row);
    *map_distance = (int **) malloc(sizeof(int *) * row);
    *map_origin = (int **) malloc(sizeof(int *) * row);

    for (int i = 0; i < row; i++) {
        (*map_original)[i] = (int *) malloc(sizeof(int) * col);
        (*map_visited)[i] = (boolean *) malloc(sizeof(boolean) * col);
        (*map_distance)[i] = (int *) malloc(sizeof(int) * col);
        (*map_origin)[i] = (int *) malloc(sizeof(int) * col);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (map.mem[i][j] == goal) {
                (*map_original)[i][j] = 0; // jika target
                (*map_distance)[i][j] = MAX_INT;
            } else if (i == start.y && j == start.x) {
                (*map_original)[i][j] = 0; // jika jika current pos
                (*map_distance)[i][j] = 0;
            } else if (map.mem[i][j] == '#') {
                (*map_original)[i][j] = 1; // jika path kosong
                (*map_distance)[i][j] = MAX_INT;
            } else {
                (*map_original)[i][j] = MAX_INT; // jika obstacle atau service lain selain goal
                (*map_distance)[i][j] = MAX_INT;
            }
            (*map_visited)[i][j] = false;
            (*map_origin)[i][j] = NAN_INT;
        }
    }

    display_graph_map(*map_original);
}


void free_map(int ***map_original, boolean ***map_visited, int ***map_distance, int ***map_origin) {
    int row = map.rowEff;

    for (int i = 0; i < row; i++) {
        free((*map_original)[i]);
        free((*map_visited)[i]);
        free((*map_distance)[i]);
        free((*map_origin)[i]);
    }

    free(*map_original);
    free(*map_visited);
    free(*map_distance);
    free(*map_origin);
}

void get_min_distance(int **map_distance, boolean **map_visited, int currentX, int currentY, int *xMin, int *yMin) {
    int row = map.rowEff;
    int col = map.colEff;

    int rowMin;
    int colMin;
    int currentMin;
    boolean minSet = false;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (!map_visited[i][j]) {
                if (minSet) {
                    if (currentMin > map_distance[i][j]) {
                        currentMin = map_distance[i][j];
                        rowMin = i;
                        colMin = j;
                    }
                } else {
                    currentMin = map_distance[i][j];
                    rowMin = i;
                    colMin = j;
                    minSet = true;
                }
            }
        }
    }



//    if (currentX - 1 >= 0 && !map_visited[currentY][currentX - 1]) {
//        currentMin = map_distance[currentY][currentX - 1];
//        colMin = currentX - 1;
//        rowMin = currentY;
//        minSet = true;
//    }
//
//    if (currentX + 1 < col && !map_visited[currentY][currentX + 1]) {
//        if (minSet) {
//            if (map_distance[currentY][currentX + 1] < currentMin) {
//                currentMin = map_distance[currentY][currentX + 1];
//                colMin = currentX + 1;
//                rowMin = currentY;
//            }
//        } else {
//            currentMin = map_distance[currentY][currentX + 1];
//            colMin = currentX + 1;
//            rowMin = currentY;
//            minSet = true;
//        }
//    }
//
//    if (currentY - 1 >= 0 && !map_visited[currentY - 1][currentX]) {
//        if (minSet) {
//            if (map_distance[currentY - 1][currentX] < currentMin) {
//                currentMin = map_distance[currentY - 1][currentX];
//                colMin = currentX;
//                rowMin = currentY - 1;
//            }
//        } else {
//            currentMin = map_distance[currentY - 1][currentX];
//            colMin = currentX;
//            rowMin = currentY - 1;
//            minSet = true;
//        }
//    }
//
//    if (currentY + 1 < row && !map_visited[currentY + 1][currentX]) {
//        if (minSet) {
//            if (map_distance[currentY + 1][currentX] < currentMin) {
//                currentMin = map_distance[currentY + 1][currentX];
//                colMin = currentX;
//                rowMin = currentY + 1;
//            }
//        } else {
//            currentMin = map_distance[currentY + 1][currentX];
//            colMin = currentX;
//            rowMin = currentY + 1;
//            minSet = true;
//        }
//    }

    *xMin = colMin;
    *yMin = rowMin;
}

void find_path(point_t start, point_t goal, point_t **path, int *steps) {
    int **map_original;
    boolean **map_visited;
    int **map_distance;
    int **map_origin;

    build_map(&map_original, &map_visited, &map_distance, &map_origin, start, map.mem[goal.y][goal.x]);

    int col = map.colEff;
    int row = map.rowEff;
    int x = start.x;
    int y = start.y;
    boolean finished = false;

    int count = 0;

    // loop Dijkstra until reaching the target cell
    while (!finished) {
        // move to x+1,y
        if (x < col - 1) {
            if (map_distance[y][x + 1] > map_original[y][x + 1] + map_distance[y][x] && !map_visited[y][x + 1]) {
                map_distance[y][x + 1] = map_original[y][x + 1] + map_distance[y][x];
                map_origin[y][x + 1] = y * col + x;
            }
        }

        // move to x-1, y
        if (x > 0) {
            if (map_distance[y][x - 1] > map_original[y][x - 1] + map_distance[y][x] && !map_visited[y][x - 1]) {
                map_distance[y][x - 1] = map_original[y][x - 1] + map_distance[y][x];
                map_origin[y][x - 1] = y * col + x;
            }
        }

        // move to x, y+1
        if (y < row - 1) {
            if (map_distance[y + 1][x] > map_original[y + 1][x] + map_distance[y][x] && !map_visited[y + 1][x]) {
                map_distance[y + 1][x] = map_original[y + 1][x] + map_distance[y][x];
                map_origin[y + 1][x] = y * col + x;
            }
        }

        // move to x, y-1
        if (y > 0) {
            if (map_distance[y - 1][x] > map_original[y - 1][x] + map_distance[y][x] && !map_visited[y - 1][x]) {
                map_distance[y - 1][x] = map_original[y - 1][x] + map_distance[y][x];
                map_origin[y - 1][x] = y * col + x;
            }
        }

        map_visited[y][x] = true;

        int xMin, yMin;
        get_min_distance(map_distance, map_visited, x, y, &xMin, &yMin);
//
//        printf("Map Distance\n");
//        display_graph_map(map_distance);

        x = xMin;
        y = yMin;

        if (x == goal.x && y == goal.y) {
//            printf("Map Distance\n");
//            display_graph_map(map_distance);
//            printf("Map Origin\n");
//            display_graph_map(map_origin);
//            printf("Map Original\n");
//            display_graph_map(map_original);
            finished = true;
        }

        count++;

        if (count == 10000) {
            printf("MAXIMUM COUNT REACHED");
            break;
        }
    }

    printf("MAP ORIGIN\n");
    display_graph_map(map_origin);

    int xCurrent = goal.x;
    int yCurrent = goal.y;

    if (count == 0) {
        return;
    }

    *path = (point_t *) malloc(sizeof(point_t) * count);

    int i = 0;
    int dest_skipped = false;

    while (xCurrent != start.x || yCurrent != start.y) {
        point_t point;
        point.x = xCurrent;
        point.y = yCurrent;

        if (!dest_skipped) {
            dest_skipped = true;
        } else {
            (*path)[i++] = point;
        }

        if (xCurrent - 1 >= 0) {
            if (map_origin[yCurrent][xCurrent] == yCurrent * col + xCurrent - 1) {
                xCurrent--;
                continue;
            }
        }

        if (xCurrent + 1 < col) {
            if (map_origin[yCurrent][xCurrent] == yCurrent * col + xCurrent + 1) {
                xCurrent++;
                continue;
            }
        }

        if (yCurrent - 1 >= 0) {
            if (map_origin[yCurrent][xCurrent] == (yCurrent - 1) * col + xCurrent) {
                yCurrent--;
                continue;
            }
        }

        if (yCurrent + 1 < row) {
            if (map_origin[yCurrent][xCurrent] == (yCurrent + 1) * col + xCurrent) {
                yCurrent++;
                continue;
            }
        }

        printf("This code should not reached\n");
        break;
    }

    // poin terakhir adalah poin awal
//    point_t last;
//    last.x = xCurrent;
//    last.y = yCurrent;
//    (*path)[i++] = last;
    *steps = i;
    free_map(&map_original, &map_visited, &map_distance, &map_origin);
}