#include "library.h"
#include <stdlib.h>
#include <string.h> // Inclusion de <string.h> pour utiliser strstr

void parse_nodes_file(FILE* file) {
    // Code pour analyser le fichier
}

int nodes_quantity(FILE* file) {
    char buffer[256];
    int count = 0; 
    while (fgets(buffer, 256, file) != NULL) {
        if (strstr(buffer, "#node") != NULL) {
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

int nodes_links_quantity(FILE* file) {
    char buffer[256];
    int count = 0; // Compteur pour les liens
    while (fgets(buffer, 256, file) != NULL) {
        if (strstr(buffer, "#links") != NULL) {
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
    rewind(file);
    char buffer[256];
    while (fgets(buffer, 256, file) != NULL) {
        if (strstr(buffer, "#start")) {
            while (fgets(buffer, 256, file)) {
                return atoi(buffer);
            }
        }
    }
    return -1;
}

int node_end(FILE* file) {
    rewind(file);
    char buffer[256];
    while (fgets(buffer, 256, file) != NULL) {
        if (strstr(buffer, "#end")) {
            while (fgets(buffer, 256, file)) {
                return atoi(buffer);
            }
        }
    }
    return -1; 
}

Node** init_nodes(char* filename) {
    FILE* file = fopen(filename, "r");
    Node** nodes = malloc(sizeof(Node*));
    int nodes_count = 0;

    char buffer[256];
    while (fgets(buffer, 256, file)) {
        if (strstr(buffer, "#nodes")) {
            while (fgets(buffer, 256, file)) {
                if (!strstr(buffer, "#links")) {
                    nodes[nodes_count] = malloc(sizeof(Node));
                    *nodes[nodes_count]->links = malloc(sizeof(Node*));
                    nodes[nodes_count]->id = atoi(buffer);                                    // Set the id of the node to the parsed id
                    nodes_count++;
                }
            }
        }
    }
    return nodes;
}

Node* init_graph(Node **nodes) {
    if (nodes == NULL || *nodes == NULL) { // if node is NULL return error
        return NULL; 
    }

    Node *head = nodes[0]; 
    Node *current = head;

    for (int i = 1; nodes[i] != NULL; i++) { // Loop through the nodes
        current->links = &nodes[i];
        current = nodes[i];
    }

    current->links = NULL; 

    return head; // Return the head of the graph    
}