#include <stdio.h>
#include <stdlib.h>
// #include <sys/ptrace.h>
#include <time.h>
#include <string.h>

// int my_func001(char* var);
int my_func002(char* string, void* char2); // prefixe
// int my_func003(char* string, double* var1, int var2);
// int my_func004(char* string, short* var1, int var2); // key
int my_func005(char* string, int var); // first char
// long my_func006(char* string, int var1, char* var2);
void Xor_Encrypt(const char *input, const char *key, unsigned char *output, int *length);
// char* my_func008(char* string, long var);
char* my_func009(char* string, char* varenv); // home env var
// int my_func010(char* string, long var);
void my_func011(char* string, int* var1, short var2); // second char
// float my_func012(char* string, char* var);
// long *my_func013(const char *string1, int var, char *string2, const char *string3); // Xor decrypt
// int my_func014(char* string, char* var);
int test_blk1(char* string);
int test_blk2(char* string);
int test_blk3(char* string, int var);
int test_blk4(char* string, int var);
int get_string(char* string1, char* string2);
int my_strcmp(const char *str1, const char *str2);


int checkDebug() {
    FILE *fp;
    char path[1035];
    int traceFound = 0;

    // Liste des traceurs à vérifier
    const char* traceurs[] = {"strace", "ltrace", "dtrace", "ptrace", "[^a-zA-Z]gdb[^a-zA-Z]", "ghidra", "radare2", "[^a-zA-Z]r2[^a-zA-Z]", "lldb", "objdump", "[^a-zA-Z]nm[^a-zA-Z]", "readelf", "strings", "objcopy", "objd", "cutter", "ida", "gdbserver", "lldb-server", "binaryninja", "valgrind", "hopper", "peid"};
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
        printf("Failed!\n");
        return 1;
    }

    char userInput[255];
    if (argv[1] != NULL) {
        strncpy(userInput, argv[1], 254); // Utilisez strncpy pour éviter un dépassement de tampon
        userInput[254] = '\0'; // Assurez-vous que la chaîne est correctement terminée
    } else {
        printf("Failed!\n");
        return 1;
    }

    // Appel de test_blk1 et stockage du résultat
    if (test_blk1(userInput) == 0) {
        printf("Failed!\n");
        return 1;
    }

    //récupération des caractères de l'input supérieur à la longueur 8
    char upperInput[255] = "";
    strcpy(upperInput, userInput + 8);
    upperInput[strlen(upperInput)] = '\0';
    char lowerInput[255] = "";
    strncpy(lowerInput, userInput, 8);
    lowerInput[8] = '\0';

    //encrypt de l'input
    char var1[255] = "";
    char string1[255] = "";
    get_string(var1, string1);
    printf("var1 : %s\n", var1);
    printf("string1 : %s\n", string1);

    unsigned char cryptedInput[255] = "";
    unsigned char cryptedInput2[255] = "";
    int cryptedInputLength;
    int cryptedInputLength2;
    
    Xor_Encrypt(lowerInput, var1, cryptedInput, &cryptedInputLength);
    
    char password[255] = "";
    void* var2;
    my_func002(password, var2);
    printf("password : %s\n", password);
    Xor_Encrypt(password, var1, cryptedInput2, &cryptedInputLength2);
    
    printf("cryptedInput : %s\n", cryptedInput);
    unsigned char *p = (unsigned char *)cryptedInput;
    printf("cryptedInput2 : %s\n", cryptedInput2);  
    unsigned char *p2 = (unsigned char *)cryptedInput2;
    printf("Représentation hexadécimale : ");
    while (*p != '\0' && *p != '\0') {
        printf("%02x ", *p);  // Affiche le code hexadécimal de chaque caractère
        p++;
        printf("%02x ", *p2);  // Affiche le code hexadécimal de chaque caractère
        p2++;
        //comparaison p et p2
        if (*p != *p2) {
            printf("Failed!\n");
            return 1;
        }
    }
    printf("\n");

    printf("même chaine\n");
    // Appel de test_blk1 et stockage du résultat
    if (test_blk2(userInput) == 0) {
        printf("Failed!\n");
        return 1;
    }

    char password2[255] = "";
    my_func005(password2, 0x8c);
    printf("password2 : %s\n", password2);
    strncpy(upperInput, upperInput, 1);

    //comparaison de password2 avec le premier caractère de l'upper input
    if (password2[0] != upperInput[0]) {
        printf("Failed!\n");
        return 1;
    }
    // supprimer le caractère 0 de l'upper input
    char upperInput2[255] = "";

    strcpy(upperInput2, upperInput + 1);
    printf("upperInput2 : %s\n", upperInput2);
    char str[255] = "";
    char var5[255] = "HOME";
    my_func009(str, var5);
    int tmp = strlen(str);
    // Appel de test_blk3 et stockage du résultat
    if (test_blk3(upperInput2, strlen(str)) == 0) {
        printf("Failed!\n");
        return 1;
    }
    printf("str : %s\n", str);
    strcpy(upperInput, upperInput2 + strlen(str));
    strncpy(lowerInput, upperInput2, strlen(str));
    printf("upperInput : %s\n", upperInput);
    printf("lowerInput : %s\n", lowerInput);
    if (my_strcmp(lowerInput, str) != 0) {
        printf("Failed!\n");
        return 1;
    }
    printf("strlen(upperInput) : %d\n", strlen(upperInput));
    if (test_blk3(upperInput, strlen("j")) == 0) {
        printf("Failed!\n");
        return 1;
    }
    strcpy(password2, "");
    short var20;
    int* var3;
    my_func011(password2, var3, var20);
    printf("password2 : %s\n", password2);
    //comparation de password2 avec le premier caractère de l'upper input
    if (password2[0] == upperInput[0]) {
        printf("OK\n");
        return 1;
    } else {
        printf("Failed!\n");
        return 1;
    }
    return 0;
}
