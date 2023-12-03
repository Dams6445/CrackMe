#include <stdio.h>
#include <stdlib.h>
// #include <sys/ptrace.h>
#include <time.h>
#include <string.h>

int my_func001(char* var);
int my_func002(char* string, void* char2); // prefixe
int my_func003(char* string, double* var1, int var2);
int my_func004(char* string, short* var1, int var2); // key
int my_func005(char* string, int var); // first char
long my_func006(char* string, int var1, char* var2);
void my_func007(const char *string1, const char *string2, unsigned char *string3, int var); // Xor encrypt
char* my_func008(char* string, long var);
char* my_func009(char* string, char* varenv); // home env var
int my_func010(char* string, long var);
void my_func011(char* string, int* var1, short var2); // second char
float my_func012(char* string, char* var);
long *my_func013(const char *string1, int var, char *string2, const char *string3); // Xor decrypt
int my_func014(char* string, char* var);

int checkDebug() {
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

int main(int argc, char const *argv[])
{
    // // Tentative d'attachement avec ptrace pour empêcher le debugging
    // if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1) {
    //     printf("Debugging détecté !\n");
    //     return 1;
    // }

    // Tentative de vérification de l'existence de traceurs
    if (checkDebug() == 1) {
        return 1;
    }

    // Gestion de l'entrée utilisateur 
    char userInput[255] = argv[1];
    //appel asm function to crypt
    my_func36(userInput, cryptedInput)


    char password[255] = "";
    char key[255] = "";
    char var5[255] = "";

    void* var1;
    short var2;
    int* var3;
    void* var4;

    my_func002(password, var1);
    printf("password : %s\n", password);
    printf("var1 : %s\n", var1);
    my_func004(key, var4, 0xe);
    my_func005(password, 0x8c);
    my_func008(var5, 0x8);
    my_func009(password, var5);
    my_func011(password, var3, var2);

    printf("password : %s\n", password);
    printf("key : %s\n", key);
    if(!strcmp(password, argv[1])) {
        printf("OK\n");
    }
    return 0;
}
