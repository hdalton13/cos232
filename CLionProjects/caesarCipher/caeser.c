//local copy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
    char cryptStr[50]="null";
    int copyNumber;
    int key = 7;
    bool encryptBool = true;
    FILE * filePointer;
/*
    for (int i = 0; i < argc; i++){
        //if (strcmp(argv[i],"-d")) encryptBool=false; //decryption is wanted
        //if (strcmp(argv[i],"\"")) strcpy(cryptStr,argv[i]);

        printf("arg[%d] = %s\n", i, argv[i]);
    }
*/
    printf("%s         %d\n", cryptStr, encryptBool);
    if (argc <= 2) {
        printf("Need more arguments: program was aborted\n");
        abort();
    } //Checks to see if there is a valid amount of arguments

//checks for flags
    if (strcmp(argv[2],"-d")==0) {
        encryptBool = false;
        //check number
        copyNumber = atoi(argv[3]);
        if (copyNumber>0) key = copyNumber;
        else {
            printf("key set to default\n");
            filePointer = fopen(argv[3],"r");
        }

//checks for text
        if(!filePointer) filePointer = fopen(argv[4],"r");
        if (filePointer){
            char text1[50];
            int i=0;
            while(!feof(filePointer)) text1[i++] = fgetc(filePointer);
            strcpy(cryptStr,text1);
            printf("%s\n",cryptStr);


        }else{
            printf("\nNo plain text has been given.\n");
            printf( "Enter a value :\n");
            fgets( cryptStr,50,stdin);
        }
    } //decryption is wanted

    else if (strcmp(argv[2],"-e")==0) {
        encryptBool = true;
        //check number
        copyNumber = atoi(argv[3]);
        if (copyNumber>0) key = copyNumber;
        else {
            printf("key set to default\n");
            filePointer = fopen(argv[3],"r");
        }

//checks for text
        if(!filePointer) filePointer = fopen(argv[4],"r");
        if (filePointer){
            char text1[50];
            int i=0;
            while(!feof(filePointer)) text1[i++] = fgetc(filePointer);
            strcpy(cryptStr,text1);
            printf("%s\n",cryptStr);


        }else{
            printf("\nNo plain text has been given.\n");
            printf( "Enter a value :\n");
            fgets( cryptStr,50,stdin);
        }
    } //encryption is wanted

    else if (strcmp(argv[2],"-d")!=0 || strcmp(argv[2],"-e")!=0) {
        printf("Set as default of encrypting\n");

        copyNumber = atoi(argv[2]);
        if (copyNumber>0) key = copyNumber;
        else {
            printf("key set to default");
            filePointer = fopen(argv[3],"r");
        }

//checks for text
        if(!filePointer) filePointer = fopen(argv[4],"r");
        if (filePointer){
            char text2[50];
            int i=0;
            while(!feof(filePointer)) text2[i++] = fgetc(filePointer);
            strcpy(cryptStr,text2);
            printf("%s\n",cryptStr);

        }else{
            printf("\nNo plain text has been given.\n");
            printf( "Enter a value :\n");
            fgets( cryptStr,50,stdin);
        }

    } //no flag or wrong flag



//Caesar Cipher Code
    char ch;
    if(encryptBool==true){

        for(int i = 0; cryptStr[i] != '\0'; ++i){
            ch = cryptStr[i];

            if(ch >= 'a' && ch <= 'z'){
                ch = ch + key;

                if(ch > 'z'){
                    ch = ch - 'z' + 'a' - 1;
                }
                cryptStr[i] = ch;
            }
            else if(ch >= 'A' && ch <= 'Z'){
                ch = ch + key;

                if(ch > 'Z'){
                    ch = ch - 'Z' + 'A' - 1;
                }

                cryptStr[i] = ch;
            }
        }

    } //encrypt string
    else if (encryptBool==false){

        for(int i = 0; cryptStr[i] != '\0'; ++i){
            ch = cryptStr[i];

            if(ch >= 'a' && ch <= 'z'){
                ch = ch - key;

                if(ch < 'a'){
                    ch = ch + 'z' - 'a' + 1;
                }

                cryptStr[i] = ch;
            }
            else if(ch >= 'A' && ch <= 'Z'){
                ch = ch - key;

                if(ch < 'A'){
                    ch = ch + 'Z' - 'A' + 1;
                }

                cryptStr[i] = ch;
            }
        }
    } //decrypt string
    else printf("Something went horribly wrong");

    printf("%s         %d",cryptStr, encryptBool);



    //fclose(filePointer);
    return 0;

}

/*Test for C.L.
 * ./caesar -e 7 hello.txt
 * ./caesar /some/full/path/to/your/text/file/hello.txt
 * ./caesar -d 7 secret.txt
 * echo "hello" |./caesar
 * echo "hello" |./caesar -e 4000000
 * echo "hello" |./caesar -e 4000000 | ./caesar -d 4000000
 * echo "hello" |./caesar | ./caesar -d 7
 * */

