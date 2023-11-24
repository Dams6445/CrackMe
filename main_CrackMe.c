#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <time.h>
#include <string.h>

void *my_func001(char *var);
int my_func002(char *string, void *char1); // prefixe
int **my_func003(char *string, double *var1, size_t var2);
int my_func004(char* string2, void *char3); // key
// int my_func004(char *string, short *var1, int var2);
int my_func005(char *string, int var); // first char
long my_func006(char *string, int var1, char *var2);
void my_func007(char *string, double var);
int my_func008(char *string, long var);
char *my_func009(char *string, char *varenv); // home env var
char **my_func010(char *string, char offset);
void my_func011(char *string, int *var1, short var2); // second char
float my_func012(char *string, char *var);
long *my_func013(char *string, char var);
int my_func014(char *string, char *var);

//Fonction à définir en assembler pour définir le mot de passé crypté ainsi que la clé de cryptage
void xorEncrypt(const char *input, const char *key, unsigned char *output, int *length) {
    int inputLen = strlen(input);
    int keyLen = strlen(key);

    for (int i = 0; i < inputLen; i++) {
        output[i] = input[i] ^ key[i % keyLen];
    }
    *length = inputLen; // Définir la longueur réelle du texte chiffré
}

//Fonction à définir en assembler pour décrypter le mot de passé crypté
void xorDecrypt(const unsigned char *input, int length, char *output, const char *key) {
    int keyLen = strlen(key);

    for (int i = 0; i < length; i++) {
        output[i] = input[i] ^ key[i % keyLen];
    }

    output[length] = '\0'; // Null-terminate the decrypted string
}

int main(int argc, char const *argv[])
{
    // Tentative d'attachement avec ptrace pour empêcher le debugging
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1) {
        printf("Debugging détecté !\n");
        return 1;
    }

    char password[255] = "";
    char key[255] = "";

    void* var1;
    short var2;
    int* var3;
    void* var4; // key

    my_func004(key, var4);
    printf("my_func004 key : %s\n", key);
    printf("my_func004 var4 : %p\n", var4);
    my_func002(password, var1);
    printf("my_func002 password : %s\n", password);
    printf("my_func002 var1 : %p\n", var1);
    my_func005(password, 0x8c);
    my_func009(password, "HOME");
    my_func011(password, var3, var2);

    printf("password : %s\n", password);
    printf("key : %s\n", key);
    return 0;
}
