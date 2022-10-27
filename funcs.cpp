#include <iostream>
#include "imageio.h"
#include "funcs.h"
#include <cstdlib>

//Task A
void invert(std::string filename){
    int height, width;
    int image[MAX_H][MAX_W];
    readImage(filename, image, height, width);
    for(int row = 0; row < MAX_H; row++){
        for(int col = 0; col < MAX_W; col++){
            image[row][col] = abs(255 - image[row][col]);
        }//end inner for loop
    }//end for loop
    writeImage("taskA.pgm", image, height, width);
}//end invert function 


//Task B
void invert_half(std::string filename){
    int height, width;
    int image[MAX_H][MAX_W];
    readImage(filename, image, height, width);

    for(int row = 0; row < MAX_H; row++){
        for(int col = 0; col < MAX_W; col++){
            if(col >= MAX_H/2){
                image[row][col] = abs(255 - image[row][col]);
            }//end condition
        }//end inner for loop
    }//end for loop

     writeImage("taskB.pgm", image, height, width);
}//end invert-half


//Task C
void box(std::string filename){
    int height, width;
    int image[MAX_H][MAX_W];
    readImage(filename, image, height, width);

    for(int row = height/4; row < height * 3/4; row++){
        for(int col = width/4; col < width * 3/4; col++){
            image[row][col] = 255;
        }//end inner for loop
    }//end for loop
    writeImage("taskC.pgm", image, height, width);
}//end box method


//Task D
void frame(std::string filename){
    int height, width;
    int image[MAX_H][MAX_W];
    readImage(filename, image, height, width);

    for(int row = height/4; row < height * 3/4; row++){
        for(int col = width/4; col < width * 3/4; col++){
            if(row == height / 4 || row == height * 3/4 - 1 || col == width/4 || col == width * 3/4 - 1){
                image[row][col] = 255;
            }//end condition
        }//end inner for loop

    }//end for loop
    writeImage("taskD.pgm", image, height, width);
}//end frame function

//Task E
void scale(std::string filename){
    int height, width;
    int image[MAX_H][MAX_W];
    int outimage[MAX_H][MAX_W];
    readImage(filename, image, height, width);

    for(int row = 0; row < MAX_H; row++){
        for(int col = 0; col < MAX_W; col++){
            for(int outrow = row + 2; outrow < row + 4; outrow++){
                for(int outcol = col + 2; outcol < col + 4; outcol++){
                    outimage[outrow][outcol] = image[row][col];
                }//end inner for loop of out col
            }//end inner for loop of outrow
        }//end inner for loop
    }//end for loop

    writeImage("taskE.pgm", outimage, height, width);
}//end scale