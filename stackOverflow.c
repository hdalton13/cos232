#include <signal.h>
#include <stdio.h>
#include<string.h>


int main(){
    char secretPassword[20];
    char passwordAttempt[20];
    char adminPassword[20]= "iAmAdmin123456";
    char message[100]= "The moon has moonquakes";
    char change[5];
    char quit[5]="n";

    while(strncmp(quit,"n",1)==0){
        printf("Password Check Program. \n\nEnter a Password: ");
        scanf("%s", secretPassword);

        printf("Password Check: ");
        scanf("%s",passwordAttempt);


        if(strncmp(secretPassword, passwordAttempt, 20)==0) {
            printf("\nAccess Granted");
            if (strncmp(adminPassword, passwordAttempt, 20)==0) {
                printf("\nAdministrative Level Granted");
                printf("\nWould you like to change the message? (y or n)");
                scanf("%s",change);
                if (strncmp(change,"y",1)==0){
                    printf("Type new seceret message: ");
                    scanf("%s", message);
                }
            }
            printf("\nSeceret message is: %s", message);
        }
        else printf("\nAccess Denied");

        printf("\nQuit?(y or n)");
        scanf("%s", quit);

        //raise(SIGINT);
        //printf("\nPassword attempt== %s ",passwordAttempt);
        //printf("\nActual Password== %s \n", secretPassword);
    }
    return 0;
}

