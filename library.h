#ifndef PATHFINDING
#define PATHFINDING

typedef struct {

} n;

typedef struct {
  int id;
  struct n **links;
  int links_quantity;
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