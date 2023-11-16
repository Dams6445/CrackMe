#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main() {
    char password[100];
    char secretPassword[100];
    time_t currentTime;
    struct tm *timeInfo;

    // Définissez le fuseau horaire sur CET
    setenv("TZ", "CET", 1);
    tzset();

    // Obtenez l'heure actuelle
    time(&currentTime);
    timeInfo = localtime(&currentTime);
    printf("The current time is: %s", asctime(timeInfo));

    // Générez un mot de passe en fonction de l'heure actuelle
    sprintf(secretPassword, "SuperSecret%d", timeInfo->tm_hour);
    printf("The password is: %s\n", secretPassword);

    printf("Enter the password: ");
    fgets(password, sizeof(password), stdin);

    // Supprimez le caractère de nouvelle ligne s'il existe
    password[strcspn(password, "\n")] = 0;

    // Comparez les mots de passe
    if (strcmp(password, secretPassword) == 0) {
        printf("OK\n");
    } else {
        printf("Incorrect password!\n");
    }

    return 0;
}
