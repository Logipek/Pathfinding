#include "library.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// +---------+
// |  NODES  |
// +---------+
void parse_nodes_file(FILE* file) {
    char buffer[256];
    int count = 0; 
    while (fgets(buffer, 256, file) != NULL) {
        if (strstr(buffer, "#node") != NULL) { // cherche le mot clé node 
            while (fgets(buffer, 256, file) != NULL && !strstr(buffer, "#links")) { 
                if (buffer[0] != '#' && buffer[0] != '\n' && buffer[0] != '\r') { // vérifie si la ligne n'est pas vide et qu'elle ne commence pas par #
                    count++; 
                }
            }
            break; 
        }
    }
}

int nodes_quantity(FILE* file) {
    char buffer[256];
    int count = 0; 
    while (fgets(buffer, 256, file) != NULL) {
        if (strstr(buffer, "#node") != NULL) { // Search for "#nodes" in the file
            while (fgets(buffer, 256, file) != NULL && !strstr(buffer, "#links")) { 
                if (buffer[0] != '#') { // Check that the line is really a node
                    count++; 
                }
            }
            break; 
        }
    }
    return count;
}

int nodes_links_quantity(FILE* file) {
    char buffer[256];
    int count = 0; // Compteur pour les liens
    while (fgets(buffer, 256, file) != NULL) {
        printf("Debug: %s", buffer);
        if (strstr(buffer, "#links") != NULL) { // Search for "#links" in the file
            while (fgets(buffer, 256, file) != NULL) {
                count++;
            }
            break;
        }
    }
    return count;
}

int node_start(FILE* file) {
    char buffer[256];
    while (fgets(buffer, 256, file) != NULL) {
        if (strstr(buffer, "#start") != NULL) { // Search for "#start" in the file
            if (fgets(buffer, 256, file) != NULL) { 
                return atoi(buffer); // Return the line after it, aka the node
            }
        }
    }
    return NO_START_NODE; // Error
}

int node_end(FILE* file) {
    char buffer[256];
    while (fgets(buffer, 256, file) != NULL) {
        if (strstr(buffer, "#end") != NULL) { // Search for "#end" in the file
            if (fgets(buffer, 256, file) != NULL) {
                return atoi(buffer); // Return the line after it, aka the node
            }
        }
    }
    return NO_END_NODE; // Error
}