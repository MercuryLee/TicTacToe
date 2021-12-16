#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<conio.h>
#include"Functions.h"

void CheckGameOver(int frame[3][3], int score[3][3]);
void ExcludeScore(int frame[3][3], int score[3][3]);
void AddScoreDia(int score[3][3]);
int BotMain(int frame[3][3]);