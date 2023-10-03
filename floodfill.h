
//dimensions 
#define SIZE 16
#define LARGEFLOOD 1000

//directions
#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

typedef struct Node {
    short floodval;
    short row;
    short column;
    short visited;

    //neighbors!
    struct Node *left;
    struct Node *right;
    struct Node *up;
    struct Node *down;
} Node;

typedef struct Maze {
    Node *map[SIZE][SIZE];
} Maze;

//Node functions
Node * new_Node(const short x, const short y);

//Maze functions
Maze * new_Maze();
Maze * open_Maze(const char *file);
void print_Maze(const Maze *this_maze);

//Flodfill functions
short get_smallest_neighbor(const Maze *this_maze);


