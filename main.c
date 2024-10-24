#include <stdio.h>
#include <stdlib.h>
#include "library.h"

// +--------+
// |  MAIN  |
// +--------+
int main(int argc, char *argv[]) {
  FILE* file = fopen(argv[1], "r");
  printf("nombre de noeud(s): %d\n", nodes_quantity(file)); // nodes_quantity test
  printf("nombre de lien(s): %d\n", nodes_links_quantity(file)); // nodes_links_quantity test
  printf("start: %d\n", node_start(file));
  printf("end: %d\n", node_end(file));

  Node** nodes = init_nodes(argv[1]);

  printf("%d", nodes[0]->id);
  return 0;
}
