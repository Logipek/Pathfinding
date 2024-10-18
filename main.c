#include <stdio.h>
#include <stdlib.h>
#include "library.h"

// +--------+
// |  MAIN  |
// +--------+
int main(int argc, char *argv[]) {
  FILE* file = fopen(argv[1], "r");
  printf("nombre de noeud(s): %d", nodes_quantity(file)); // nodes_quantity test
  return 0;
}
