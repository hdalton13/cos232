#include <stdio.h>
/*
int main() {
    int i;
    FILE* f = fopen("/home/CS/users/hdalton/.linux/sheldon.bmp", "rb");
    unsigned char info[54];

    // read the 54-byte header
    fread(info, sizeof(unsigned char), 54, f);

    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

    // allocate 3 bytes per pixel
    int size = 3 * width * height;
    unsigned char* data = new unsigned char[size];

    // read the rest of the data at once
    fread(data, sizeof(unsigned char), size, f);
    fclose(f);

    for(i = 0; i < size; i += 3)
    {
            // flip the order of every 3 bytes
            unsigned char tmp = data[i];
            data[i] = data[i+2];
            data[i+2] = tmp;
    }
}
 */

/* looping an image: https://processing.org/tutorials/pixels/
 *while(k<width && j<height){
        fread(header,sizeof(unsigned char), 54,imageFile);
        //go through each individual pixel and change the last bit of the RBG to
        //the last significant bit of the secret message
        // EX) R = 10101010     Say the char S = 01110011
        //     B = 11011011     //now we want to change the last item in R which is 0 to be the
        //     G = 00101010     //last significant digit of S which is 1

    }for (int i = 0 ; i < height * width; ++i) {
        int row = i / height;
        int col = i % width;
        if (row%2 != 0) col = width - col-1;
        //int pixel = bmp.GetPixel(col, row);
    }*/

