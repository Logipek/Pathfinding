#ifndef PATHFINDING
#define PATHFINDING

#include <stdio.h>
#include <stdlib.h>

typedef enum {
  FILE_NOT_FOUND = 1,
  NO_START_NODE = 2,
  NO_END_NODE = 3,
  NO_VALID_PATH = 4,
  BAD_FILE_FORMAT = 5
} Error;

typedef struct n {
  int id;
  struct n **links;
} Node;

// +---------+
// |  NODES  |
// +---------+
void parse_nodes_file(FILE* file); // Assign every nodes in file to 
int nodes_quantity(FILE* file);
int nodes_links_quantity(FILE* file);
int node_start(FILE* file);
int node_end(FILE* file);

// +-------------------------+
// |  PATHFINDING ALGORITHM  |
// +-------------------------+

#endif