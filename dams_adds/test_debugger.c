#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char path[1035];
    int traceFound = 0;

    // Liste des traceurs à vérifier
    const char* traceurs[] = {"strace", "ltrace", "dtrace", "ptrace", "[^a-zA-Z]gdb[^a-zA-Z]", "ghidra", "radare2", "r2", "lldb", "objdump", "[^a-zA-Z]nm[^a-zA-Z]", "readelf", "strings", "objcopy", "objd", "cutter", "ida", "gdbserver", "lldb-server", "binaryninja", "valgrind", "hopper", "peid"};
    int nbTraceurs = sizeof(traceurs) / sizeof(traceurs[0]);

    // Construit la commande pour vérifier tous les traceurs.
    char commande[256] = "lsof | grep -E '";
    for (int i = 0; i < nbTraceurs; ++i) {
        strcat(commande, traceurs[i]);
        if (i < nbTraceurs - 1) {
            strcat(commande, "|");
        }
    }
    strcat(commande, "'");

    // Exécute la commande.
    fp = popen(commande, "r");
    if (fp == NULL) {
        printf("Échec de l'exécution de la commande\n");
        return 1;
    }

    // Lit la sortie de la commande.
    while (fgets(path, sizeof(path), fp) != NULL) {
        for (int i = 0; i < nbTraceurs; ++i) {
            if (strstr(path, traceurs[i])) {
                printf("Danger %s détecté\n", traceurs[i]);
                traceFound = 1;
            }
        }
    }
    if (traceFound == 1) {
        printf("traceur détecté\n");
        return 1;
    } else {
        printf("Aucun traceur détecté\n");
    }

    // Ferme le flux.
    pclose(fp);
    return 0;
}
