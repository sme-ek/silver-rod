//
// Created by smeek on 14/03/2021.
//

int finishScreen;

void InitDevScreen(void){
    DrawText("WARNING: this is a developmental build."
             "Please report issues on github.", 20, LIGHTGRAY);
}

void UpdateDevScreen(void){
    if ((IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
    {
        finishScreen = 1;
    }
}


};
void UnloadDevScreen(void){

}
int FinishDevScreen(void){
    return finishScreen;
}