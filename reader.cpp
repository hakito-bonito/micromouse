#include <stdio.h> 
#include <stdlib.h>

#include <string.h>

#include "floodfill.h"

Maze * open_Maze(const char *file) {
    Maze *this_maze = new_Maze();
    const char *folder_path = "/Users/hh/micromouse/f_files/test-mazes/";

    int new_size = strlen(folder_path) + strlen(file) + 1;
    char *file_path = (char *) malloc(new_size);

    strcpy(file_path, folder_path);
    strcat(file_path, file);

    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(file_path, "r");
    while ((read = getline(&line, &len, fp)) != -1) {
            
        char * token = strtok(line, ",");
        int x = atoi(token);
        token = strtok(NULL, ",");
        int y = atoi(token);
        token = strtok(NULL, ",");

        while(token != NULL) {
            if (strcmp("UP", token) == 0) {
                    this_maze->map[x][y]->up = NULL;
            }
            else if (strcmp("DOWN", token) == 0) {
                this_maze->map[x][y]->down = NULL;
            }
            else if (strcmp("LEFT", token) == 0) {
                this_maze->map[x][y]->left = NULL;
            }
            else {
                this_maze->map[x][y]->right = NULL;
            }

            token = strtok(NULL, ",");
        }    
    }

    fclose(fp);

    return this_maze;
}

int main () {
    return 0;
}