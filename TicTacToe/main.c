#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"Functions.h"

int main() {
    init();
    menuDraw();//여기서 다시 리턴하면 게임 시작임

    int Frame[3][3];
    int turn;

    while (1) {
        PlayerChoose();
        DrawFrame();

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Frame[i][j] = 0;
            }
        }
        cursorx = 7;
        cursory = 3;
        gotoxy(cursorx, cursory);
        for (turn = 1; turn < 10; turn++) {
            GameControl(Frame, turn);
            if (GameOverChecker(Frame) || GameOverChecker(Frame)== -1) break;
        }
        if (!PlayAgain(turn, GameOverChecker(Frame))) break;
        else continue;
    }

    return 0;
}

/*In the sky where seasons pass in a hurry
Autumn fills the air.

And ready I stand, without a worry,
To count all the stars there...

Memory for one star,
Love for another star,
Loneliness for another star,
Longing for another star,
Poetry for another star,
And, oh mother, mother for another star...

Have you read these lines before? 
They are the part of the poem by Yoon Dong-Ju, "Counting Stars at Night". 
This poem was written a long time ago, but still remains one of the Korea's favorite poems.*/