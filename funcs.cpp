#include <iostream>
#include "imageio.h"
#include "funcs.h"
#include <cstdlib>

//Task A
void invert(std::string filename){
    int height, width;
    int image[MAX_H][MAX_W];
    int outimage[MAX_H][MAX_W];
    readImage(filename, image, height, width);
    for(int row = 0; row < MAX_H; row++){
        for(int col = 0; col < MAX_W; col++){
            outimage[row][col] = abs(255 - image[row][col]);
        }//end inner for loop
    }//end for loop
    writeImage("taskA.pgm", outimage, height, width);
}//end invert function 


//Task B
void invert_half(std::string filename){
    int height, width;
    int image[MAX_H][MAX_W];
    int outimage[MAX_H][MAX_W];
    readImage(filename, image, height, width);

    for(int row = 0; row < MAX_H; row++){
        for(int col = 0; col < MAX_W; col++){
            if(col >= MAX_H/2){
                outimage[row][col] = abs(255 - image[row][col]);
            }else{
                outimage[row][col] = image[row][col];
            }//end condition
        }//end inner for loop
    }//end for loop

     writeImage("taskB.pgm", outimage, height, width);
}//end invert-half