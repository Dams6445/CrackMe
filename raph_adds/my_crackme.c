#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void* my_func001(char* var);
int my_func002(char* string, void* char2); // prefixe
int** my_func003(char* string, double* var1, size_t var2);
int my_func004(char* string, short* var1, int var2);
int my_func005(char* string, int var); // first char
long my_func006(char* string, int var1, char* var2);
void my_func007(char* string, double var);
int my_func008(char* string, long var);
char* my_func009(char* string, char* varenv); // home env var
char** my_func010(char* string, char offset);
void my_func011(char* string, int* var1, short var2); // second char
float my_func012(char* string, char* var);
long* my_func013(char* string, char var);
int my_func014(char* string, char* var);

int main() {
    char password[255] = "";

    void* var1;
    short var2;
    int* var3;
    
    my_func002(password, var1);
    my_func005(password, 0x8c);
    my_func009(password, "HOME");
    my_func011(password, var3, var2);

    printf("%s\n", password);
    return 0;
}
