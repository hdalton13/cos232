
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int addition(int * result, int a, int b){
    *result = a+b;
    if ( a>0 && b>0 && *result <0) return -1; //these two lines of code check to see if an integer overflow has occured
    if (a<0 && b<0 && *result >0) return -1; // that is what it means when it returns -1
    return 0;
}
int subtract(int * result, int a, int b){
    *result = a-b;
    if ( a>0 && b>0 && *result <0) return -1; //these two lines of code check to see if an integer overflow has occured
    if (a<0 && b<0 && *result >0) return -1; // that is what it means when it returns -1
    return 0;
}
int multiply(int *result, int a, int b){
    *result = a*b;
    if (a>0 && b>0 && *result <0) return -1;
    if (a<0 && b>0 && *result <0) return -1;
    return 0;
}
int divide(int * result, int a, int b){
    *result = a/b;
    if ( a>0 && b>0 && *result <0) return -1; //these two lines of code check to see if an integer overflow has occured
    if (a<0 && b<0 && *result >0) return -1; // that is what it means when it returns -1
    return 0;
}

int main() {
    int x=0;
    int y=0;
    //int x= 2147483640;
    //int y= 10;

    int *res = (int *)malloc(sizeof(int));

    int operationChoice;
    bool exit = false;

    while(!exit) {
        printf("\nBasic Calculator: \nWhat operation would you like to do? "
               "(0 == Addition, 1 == Subtraction, 2 == Multiplication, 3 == Division, "
               "4 == Clear, 5 == Exit) ");
        scanf("%d", &operationChoice);


        switch (operationChoice) {
            case 0:
                if (x == 0) {
                    printf("Set Value X: ");
                    scanf("%d", &x);
                }
                if (y == 0) {
                    printf("Set Value Y: ");
                    scanf("%d", &y);
                }
                addition(res, x, y);
                break;
            case 1:
                if (x == 0) {
                    printf("Set Value X: ");
                    scanf("%d", &x);
                }
                if (y == 0) {
                    printf("Set Value Y: ");
                    scanf("%d", &y);
                }
                subtract(res, x, y);
                break;
            case 2:
                if (x == 0) {
                    printf("Set Value X: ");
                    scanf("%d", &x);
                }
                if (y == 0) {
                    printf("Set Value Y: ");
                    scanf("%d", &y);
                }
                multiply(res, x, y);
                break;
            case 3:
                if (x == 0) {
                    printf("Set Value X: ");
                    scanf("%d", &x);
                }
                if (y == 0) {
                    printf("Set Value Y: ");
                    scanf("%d", &y);
                }
                divide(res, x, y);
                break;
            case 4:
                x = 0;
                y = 0;
                *res = 0;
                break;
            case 5:
                exit = true;
                break;
            default:
                printf("An ERROR OCCURRED in selecting an Operation\n");
                break;
        }

        if (operationChoice < 5) {
            printf("\n%d\n", *res); //prints the result of the added overflow item
        }
        //getchar();
    }
    return 0;

}



