#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char path[1035];

    // Exécute une commande pipe.
    fp = popen("lsof | grep ghidra", "r");
    if (fp == NULL) {
        printf("Échec de l'exécution de la commande\n" );
        return 1;
    }

    printf("Résultat du fgets : %s", fgets(path, sizeof(path), fp));


    // Lit la sortie de la commande ligne par ligne.
    if (fgets(path, sizeof(path), fp) != NULL) {
        // Si on obtient une sortie, cela signifie que Ghidra est détecté.
        printf("Danger Ghidra\n");
    } else {
        // Si aucune sortie n'est obtenue, Ghidra n'est pas détecté.
        printf("Coucou\n");
    }

    // Ferme le flux de la commande pipe.
    pclose(fp);
    return 0;
}
