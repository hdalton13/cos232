//stegonography in python: https://towardsdatascience.com/steganography-hiding-an-image-inside-another-77ca66b2acb1
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
//Parses command line arguments (M1)
    int i;
    for (i = 0; i < argc; i++)
        printf("arg[%d] = %s\n", i, argv[i]);

    char ogfile[20];
    strcpy(ogfile, argv[1]);
    char newFile[20];
    strcpy(newFile, argv[2]);
    unsigned char secret[50];
    strcpy(secret, argv[3]);

//Opens original bitmap file for reading (M1)
    FILE *imageFile = fopen(ogfile, "rb");
    //if (imageFile!=NULL) printf("opened image\n\n");
    //else printf("not open\n");

//Reads from bitmap and writes to STDOUT the starting position of the pixel array (M2)
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, imageFile);
    int startingPixel = *(int *) &header[10];
    //                   ^dereferences  ^offset dec; meaning the place in the header array where the pixel array can be found
    printf("\nPixel starting at: %d\n", startingPixel);

//Reads from bitmap and writes to STDOUT the width and height of image (M2)
    int width = *(int *) &header[18];
    int height = *(int *) &header[22];
    printf("Width of image: %d\nHeight of image: %d\n\n", width, height);

    //Opens output file for writing (M1)
    FILE *writeOutput;
    writeOutput = fopen("imageOutput.bmp", "w");

//Loop that iterates over all the pixels in the image(M3)
    fseek(imageFile, 0, 0);
    char characterF[1];
    int counting = 0;
    while (counting < startingPixel) {
        fread(characterF, 1, 1, imageFile);
        fwrite(characterF, 1, 1, writeOutput);
        counting++;
    }
    int sLength = strlen(secret);
    int count = 1;
    while (!feof(writeOutput)) {
        fread(characterF, 1, 1, imageFile);

        for (int l = 0; l < sLength; l++) {
            for (int bit = 1; bit <= 265; bit *= 2) {
                int lsb = secret[l] & bit;

                if ((characterF[0] == 1 && lsb == 1) || (characterF[0] == 0 && lsb == 0)) {
                    fwrite(characterF, 1, 1, writeOutput);
                }

                if (characterF[0] == 1 && lsb == 0 ){
                    characterF[0] = characterF ;
                    fwrite(characterF, 1, 1, writeOutput);
                }
                if( characterF[0] == 0 && lsb == 1){
                    fwrite(characterF, 1, 1, writeOutput);
                }


            }

        }//outer for


        fclose(writeOutput);


//Loop that iterates over all the bytes in the secret message(M3)
/*
    int letterBit[8];
    for( int l=0; l<sLength; l++ ) {
        if((int)secret[l]==32)
            //printf("the character %c decimal == %d\n",secret[l],secret[l]);
        else
            //printf("the character %c decimal == %d \n",secret[l],secret[l]);
    }
    //unsigned char secret[] = "Secret Secrets are no fun unless you tell everyone\0";
*/
        fclose(imageFile);


        return 0;
    }//closing brace
}