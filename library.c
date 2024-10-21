#include "library.h"
#include <stdlib.h>
#include <string.h> // Inclusion de <string.h> pour utiliser strstr

void parse_nodes_file(FILE* file) {
    // Code pour analyser le fichier
}

int nodes_quantity(FILE* file) {
    char buffer[256];
    int count = 0; // Compteur pour les nœuds
    while (fgets(buffer, 256, file) != NULL) {
        // Cherche le mot-clé "#node" dans chaque ligne
        if (strstr(buffer, "#node") != NULL) {
            // Lire les lignes suivantes jusqu'à une ligne vide ou un autre mot-clé
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
        // Cherche le mot-clé "#links" dans chaque ligne
        if (strstr(buffer, "#links") != NULL) {
            // Lire les lignes suivantes jusqu'à une ligne vide ou un autre mot-clé
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
        // Cherche le mot-clé "#start" dans chaque ligne
        if (strstr(buffer, "#start") != NULL) {
            // Lire la ligne suivante pour obtenir l'identifiant du nœud de départ
            if (fgets(buffer, 256, file) != NULL) {
                return atoi(buffer);
            }
        }
    }
    return -1; // Retourne -1 si le nœud de départ n'est pas trouvé
}

int node_end(FILE* file) {
    char buffer[256];
    while (fgets(buffer, 256, file) != NULL) {
        // Cherche le mot-clé "#end" dans chaque ligne
        if (strstr(buffer, "#end") != NULL) {
            // Lire la ligne suivante pour obtenir l'identifiant du nœud de fin
            if (fgets(buffer, 256, file) != NULL) {
                return atoi(buffer);
            }
        }
    }
    return -1; // Retourne -1 si le nœud de fin n'est pas trouvé
}

Error init_graph(Node **nodes, Node **start_node) {
    if (nodes == NULL || *nodes == NULL) {
        return NO_START_NODE; // Retourne une erreur si le tableau de nœuds est vide
    }

    *start_node = nodes[0]; // Le premier nœud du tableau est la tête de la liste chaînée
    Node *current = *start_node;

    for (int i = 1; nodes[i] != NULL; i++) {
        current->next = nodes[i]; // Lien vers le nœud suivant
        current = nodes[i];
    }

    current->next = NULL; // Le dernier nœud ne pointe vers aucun autre nœud
 
    return 0; // Retourne 0 pour indiquer que tout s'est bien passé
}