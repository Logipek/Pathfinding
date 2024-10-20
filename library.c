#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// +---------+
// |  NODES  |
// +---------+
void parse_nodes_file(FILE* file) {
    
}

int nodes_quantity(FILE* file) {
    char buffer[256];
    int count = 0; 
    while (fgets(buffer, 256, file) != NULL) {
        if (strstr(buffer, "#node") != NULL) { // cherche le mot clé node 
            while (fgets(buffer, 256, file) != NULL && !strstr(buffer, "#links")) { 
                if (buffer [0] != '#' && buffer[0] != '\n' && buffer[0] != '\r') { // vérifie si la ligne n'est pas vide et qu'elle ne commence pas par #
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
        if (strstr(buffer, "#links") != NULL) { // cherche mot clé links
            while (fgets(buffer, 256, file) != NULL && buffer[0] != '#') {
                if (buffer[0] != '\n' && buffer[0] != '\r') {
                    count++;
                }
            }
            break;
        }
    }
    return count;
}

int node_start(FILE* file) {
    char buffer[256];
    while (fgets(buffer, 256, file) != NULL) {
        if (strstr(buffer, "#start") != NULL) { // cherche le mot start dans le txt
            if (fgets(buffer, 256, file) != NULL) { 
                return atoi(buffer); // retourne l'identifiant du nœud de départ
            }
        }
    }
    return -1; // retourn ça si ya rien dans le start 
}

int node_end(FILE* file) {
    char buffer[256];
    while (fgets(buffer, 256, file) != NULL) {
        if (strstr(buffer, "#end") != NULL) {
            if (fgets(buffer, 256, file) != NULL) {
                return atoi(buffer);
            }
        }
    }
    return -1; // retourn ça si ya rien dans le end
}