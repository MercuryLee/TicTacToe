#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"Functions.h"

int main() {
    init();
    menuDraw();//여기서 다시 리턴하면 게임 시작임
    DrawFrame();

    gotoxy(cursorx, cursory);
    int Frame[3][3];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Frame[i][j] = 0;
        }
    }
    for (int turn = 1; turn < 10; turn++) {
        GameControl(Frame, turn);
        if (GameOverChecker(Frame)) break;
    }
    system("cls");

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