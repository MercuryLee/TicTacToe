#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"Functions.h"
#include"TicTacToebot.h"

int main() {
    TicTacToeprint();
    menuDraw();//여기서 다시 리턴하면 게임 시작임

    int frame[3][3];
    int turn;

    while (1) {
        DrawFrame();
        FrameInit(frame);
        cursorx = 7;
        cursory = 3;
        gotoxy(cursorx, cursory);
        if (PlayerChoose()) {
            for (turn = 1; turn < 10; turn++) {
                if (turn % 2 == 1) GameControl(frame, turn);
                else Botmain();
                if (GameOverChecker(frame) || GameOverChecker(frame) == -1) break;
            }
        }
        else {
            for (turn = 1; turn < 10; turn++) {
                GameControl(frame, turn);
                if (GameOverChecker(frame) || GameOverChecker(frame) == -1) break;
            }
        }
        if (!PlayAgain(turn, GameOverChecker(frame))) break;
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