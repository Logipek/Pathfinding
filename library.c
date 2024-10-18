#include <stdio.h>
#include <stdlib.h>

// +---------+
// |  NODES  |
// +---------+
void parse_nodes_file(FILE* file) {
    
}

int nodes_quantity(FILE* file) {
  char buffer[256];
  int i;
  while (fgets(buffer, 256, file) != NULL) {
    i++;
  }
  return i;
}