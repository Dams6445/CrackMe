#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int custom_sprintf(char *str, const char *format, ...);

int main() {
    char buffer1[100];
    char buffer2[100];
    int num1, num2;
    const char *testString = "Test %d, %s";
    sleep(1);
    num1 = custom_sprintf(buffer1, testString, 123, "abc");
    // Utilisez la fonction sprintf de la bibliothèque standard
    num2 = sprintf(buffer2, testString, 123, "abc");
    int status = system("grep -q ^flags.*\\ hypervisor\\  /proc/cpuinfo");
    //VM detected : 
    if (status == 0) {
        printf("vm detected !\n");
        return 1;
    }
    // Comparer les résultats
    printf("Custom sprintf returned: %d, Output: %s\n", num1, buffer1);
    printf("Standard sprintf returned: %d, Output: %s\n", num2, buffer2);

    // Vérifier si les chaînes et les valeurs de retour sont identiques
    if (strcmp(buffer1, buffer2) == 0 && num1 == num2) {
        printf("Les deux fonctions sprintf produisent le même résultat.\n");
    } else {
        printf("Les résultats diffèrent.\n");
    }
    return 0;
}

//strip names : strip --strip-all exec_name
//              gcc -s custom_sprintf.o test_gcc.c -o gcc_test2
//
//static import : gcc -static test_gcc.c -o statically_linked
// les deux : gcc -static -s custom_sprintf.o test_gcc.c -o both_exec
// enfer avec ghidra on comprend r
// gcc -static -s custom_sprintf.o test_gcc.c -o gcc_test