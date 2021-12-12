#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<conio.h>

int cursorx;
int cursory;
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define FSIZE 21
#define OS 1
#define XS -1

int gotoxy(int x, int y);
void FrameInit(int frame[3][3]);
void TicTacToeprint();
int keyControl();
int GameDesDraw();
int menuDraw();
void DrawFrame();
int PlayerChoose();
int PlayAgain(int turn, int isFull);
int Row(int frame[3][3]);
int Col(int frame[3][3]);
int Dia(int frame[3][3]);
int GameOverChecker(int frame[3][3]);
void printX();
void printO();
int GameControl(int frame[3][3], int turn);