#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

int my_strlen(char* input);

int main(int argc, char **argv){
    //test my_strlen
    char *test = "secretPassword";
    int orig = strlen(test);
    int yours = my_strlen(test);
    printf("your: %d\n", yours);
    printf("orig: %d\n", orig);
    assert( orig == yours);
    return 0;
} 