//
// Created by smeek on 14/03/2021.
//

int finishScreen;

void InitDevScreen(void){
    DrawText("WARNING: this is a developmental build."
             "Please report issues on github.", 20);
};

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