#ifdef
#define PATHFINDING

typedef struct {
    int id;
    struct n **links;
} Node;

// +---------+
// |  NODES  |
// +---------+
void parse_nodes_file(*FILE file);
int nodes_quantity(*FILE file);
int nodes_links_quantity(*FILE file);
int node_start(*FILE file);
int node_end(*FILE file);

#endif