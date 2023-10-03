#include <stdio.h> 
#include <stdlib.h>

#include <string.h>

#include "floodfill.h"

Node * new_Node(const short x, const short y) {
    Node *this_node;
    
    this_node = (Node *) malloc(sizeof(Node));

    this_node->row = y;
    this_node->column = x;
    this_node->visited = false;

    char halfSIZE = SIZE/2;

    if (x < halfSIZE && y < halfSIZE) {
        this_node->floodval = (halfSIZE - 1 - x) + (halfSIZE - 1 - y);
    }
    else if (x >= halfSIZE && y < halfSIZE) {
        this_node->floodval = (x - halfSIZE) + (halfSIZE - 1 - y);
    }
    else if (x < halfSIZE && y >= halfSIZE) {
        this_node->floodval = (halfSIZE - 1 - x) + (y - halfSIZE);
    } 
    else {
        this_node->floodval = (x - halfSIZE) + (y - halfSIZE);
    }
    
    return this_node;
}

Maze * new_Maze() {
    Maze *this_maze;
    
    this_maze = (Maze *)malloc(sizeof(Maze));

    for(short x = 0; x < SIZE; x++) {
        for(short y = 0; y < SIZE; y++) {
            this_maze->map[x][y] = new_Node(x, y);
        }
    }
    
    //take the chance to set neighbors!
    for(short x = 0; x <  SIZE; x++) {
        for(short y = 0; y < SIZE; y++) {
            if (y != SIZE - 1) this_maze->map[x][y]->up = this_maze->map[x][y + 1];
            else this_maze->map[x][y]->up = NULL;
            if (y != 0) this_maze->map[x][y]->down = this_maze->map[x][y - 1];
            else this_maze->map[x][y]->down = NULL;
            if (x != 0) this_maze->map[x][y]->left = this_maze->map[x - 1][y];
            else this_maze->map[x][y]->left = NULL;
            if (x != SIZE - 1) this_maze->map[x][y]->right = this_maze->map[x + 1][y];
            else this_maze->map[x][y]->right = NULL;
        }
    }
    
    return this_maze;
}

void print_Maze(const Maze *this_maze) {
	short x, y;

	printf("\n%s\n\n", "Current Map Values: ");

	//prints out the flood values of each cell in the maze
	for (x = 0; x < SIZE; x++) {
		for (y = 0; y < SIZE; y++) {
			printf("%s%3hd", " ", this_maze->map[x][y]->floodval);
		}
		printf("\n\n");
	}

	printf("\n");
}

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

int main() {
    Maze *this_maze;

    const char *file = "maze_000.txt";
    Maze *test_maze = open_Maze(file);

    
    print_Maze(this_maze);
    
    return 0;
}