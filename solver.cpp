#include <stdlib.h>
#include <stdio.h>

#include "floodfill.h"

int main() {
    const char *file = "maze_000.txt";
    printf("%s", file);
    Maze *test_Maze = open_Maze(file);
    print_Maze(test_Maze);
    
    return 0;
}