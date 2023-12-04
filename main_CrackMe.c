#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int my_func001(char *var);
int my_func002(char *string, void *char2);
int my_func003(char *string, double *var1, int var2);
int my_func005(char *string, int var);
long my_func006(char *string, int var1, char *var2);
void my_func007(const char *string1, const char *string2, unsigned char *string3, int *var);
char *my_func008(char *string, long var);
char *my_func009(char *string, char *var);
void my_func011(char *string, int *var1, short var2);
int test_blk1(char *string);
int test_blk2(char *string);
int test_blk3(char *string, int var);
int my_func004(char *string1, char *string2);
int my_func012(const char *str1, const char *str2);

int checkDebug()
{
    FILE *fp;
    char path[1035];
    int traceFound = 0;

    const char *traceurs[] = {"strace", "ltrace", "dtrace", "ptrace", "[^a-zA-Z]gdb[^a-zA-Z]", "ghidra", "radare2", "[^a-zA-Z]r2[^a-zA-Z]", "lldb", "objdump", "[^a-zA-Z]nm[^a-zA-Z]", "readelf", "strings", "objcopy", "objd", "cutter", "ida", "gdbserver", "lldb-server", "binaryninja", "valgrind", "hopper", "peid"};
    int nbTraceurs = sizeof(traceurs) / sizeof(traceurs[0]);

    char commande[256] = "lsof | grep -E '";
    for (int i = 0; i < nbTraceurs; ++i)
    {
        strcat(commande, traceurs[i]);
        if (i < nbTraceurs - 1)
        {
            strcat(commande, "|");
        }
    }
    strcat(commande, "'");

    fp = popen(commande, "r");

    while (fgets(path, sizeof(path), fp) != NULL)
    {
        for (int i = 0; i < nbTraceurs; ++i)
        {
            if (strstr(path, traceurs[i]))
            {
                traceFound = 1;
            }
        }
    }
    if (traceFound == 1)
    {
        printf("debugger détecté\n");
        return 1;
    }

    // Ferme le flux.
    pclose(fp);
    return 0;
}

int main(int argc, char const *argv[])
{

    if (checkDebug() == 1)
    {
        printf("Failed!\n");
        return 1;
    }

    char userInput[255];
    if (argv[1] != NULL)
    {
        strncpy(userInput, argv[1], 254); 
        userInput[254] = '\0';            
    }
    else
    {
        printf("Failed!\n");
        return 1;
    }

    if (test_blk1(userInput) == 0)
    {
        printf("Failed!\n");
        return 1;
    }

    char upperInput[255] = "";
    int check_sum = my_func001(upperInput);
    strcpy(upperInput, userInput + 8);
    upperInput[strlen(upperInput)] = '\0';
    char lowerInput[255] = "";
    strncpy(lowerInput, userInput, 8);
    lowerInput[8] = '\0';

    char var1[255] = "";
    double *variable4;
    my_func003(var1, variable4, check_sum);
    char string1[255] = "";
    my_func004(var1, string1);

    unsigned char cryptedInput[255] = "";
    unsigned char cryptedInput2[255] = "";
    int cryptedInputLength;
    int cryptedInputLength2;

    my_func007(lowerInput, var1, cryptedInput, &cryptedInputLength);

    char password[255] = "";
    int variable3[5] = {0xc, 0x0, 0x5, 0xe, 0xc};
    char mdp[255] = "";
    my_func006(password, variable3[3], mdp);
    void *var2;
    my_func002(password, var2);
    my_func007(password, var1, cryptedInput2, &cryptedInputLength2);

    unsigned char *p = (unsigned char *)cryptedInput;
    unsigned char *p2 = (unsigned char *)cryptedInput2;
    while (*p != '\0' && *p != '\0')
    {
        p++;
        p2++;
 
        if (*p != *p2)
        {
            printf("Failed!\n");
            return 1;
        }
    }

    if (test_blk2(userInput) == 0)
    {
        printf("Failed!\n");
        return 1;
    }

    char password2[255] = "";
    my_func005(password2, 0x8c);
    strncpy(upperInput, upperInput, 1);
    char string044[3];
    sprintf(string044, "%02X", upperInput[0]);
    char string016[3];
    sprintf(string016, "%02X", password2[0]);
    //si password2[0] != upperInput[0] ou la valeur hexadecimale de password2[0] != upperInput[0]
    if (password2[0] != upperInput[0] || strcmp(string044, string016) != 0)
    {
        printf("Failed!\n");
        return 1;
    }
    char upperInput2[255] = "";
    char var5[255] = "";
    my_func008(var5, 0x8);

    strcpy(upperInput2, upperInput + 1);
    char str[255] = "";

    my_func009(str, var5);
    int tmp = strlen(str);
    if (test_blk3(upperInput2, strlen(str)) == 0)
    {
        printf("Failed!\n");
        return 1;
    }
    strcpy(upperInput, upperInput2 + strlen(str));
    strncpy(lowerInput, upperInput2, strlen(str));
    if (my_func012(lowerInput, str) != 0)
    {
        printf("Failed!\n");
        return 1;
    }
    if (test_blk3(upperInput, strlen("j")) == 0)
    {
        printf("Failed!\n");
        return 1;
    }
    strcpy(password2, "");
    short var20;
    int *var3;
    my_func011(password2, var3, var20);
    string044[3];
    sprintf(string044, "%02X", upperInput[0]);
    string016[3];
    sprintf(string016, "%02X", password2[0]);
    if (password2[0] == upperInput[0] || strcmp(string044, string016) == 0)
    {
        printf("OK\n");
        return 1;
    }
    else
    {
        printf("Failed!\n");
        return 1;
    }
    return 0;
}
