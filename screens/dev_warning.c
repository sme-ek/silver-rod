//
// Created by smeek on 14/03/2021.
//
#include "C:\Users\18432\Desktop\medoing\silver-rod-git\include\raylib.h"

int finishScreen;

void InitDevScreen(void){

};

void DrawDevScreen () {
    DrawText("WARNING: this is a developmental build."
             "Please report issues on github.", 1000, 1000, 20, BLACK);
}

void UpdateDevScreen(void){
    {
        finishScreen = 1;
    }
};

void UnloadDevScreen(void){

};
int FinishDevScreen(void){
    return finishScreen;
};