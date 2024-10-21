#ifndef PATHFINDING
#define PATHFINDING

#include <stdio.h>

// Déclarations d'énumérations et de structures
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

// Déclarations de fonctions
void parse_nodes_file(FILE* file);
int nodes_quantity(FILE* file);
int nodes_links_quantity(FILE* file);
int node_start(FILE* file);
int node_end(FILE* file);
Node* init_graph(Node **nodes); // Déclaration de la fonction init_graph

#endif