#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#pragma warning(disable:4996)

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define FSIZE 7
#define MUNGTANGE 18
#define Xs "○" //1
#define Os "×" //-1

int gotoxy(int x, int y) {//x, y로 커서 움직여줌
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
    return 0;
}
void init() {// 처음 세팅
    system("mode con cols=95 lines=20| title TicTacToe");//87 + 8 = 95
    printf("\n\n\n\n");
    printf("        TTTTT    IIIII    CCCCC    TTTTT      A      CCCCC    TTTTT    OOOOO    EEEEE\n");
    printf("          T        I      C          T       A A     C          T      O   O    E\n");
    printf("          T        I      C          T      AAAAA    C          T      O   O    EEEEE\n");
    printf("          T        I      C          T      A   A    C          T      O   O    E\n");
    printf("          T      IIIII    CCCCC      T      A   A    CCCCC      T      OOOOO    EEEEE\n\n\n");
}
int keyControl() {// 키 받아서 움직이기
    char temp = _getch();

    if (temp == 'W' || temp == 'w') {
        return UP;
    }
    else if (temp == 'S' || temp == 's') {
        return DOWN;
    }
    else if (temp == 'A' || temp == 'a') {
        return LEFT;
    }
    else if (temp == 'D' || temp == 'd') {
        return RIGHT;
    }
    else if (temp == ' ') {
        return SUBMIT;
    }
}
void GameDes() {
    system("cls"); //콘솔창 깔끔하게 지우기, 좌표 0, 0로 정하기
    printf("\n\n\n\n");
    printf("                   Tic-tac-toe is a paper-and-pencil game for two players who    \n");
    printf("               take turns marking the spaces in a three-by-three grid with O or X\n");//68개, 34개만 하면됨
    printf("                    The player who succeeds in placing three of their marks\n");
    printf("                   in a horizontal, vertical, or diagonal row is the winner.\n\n\n");
    printf("                           종이 위에 가로줄 2줄 세로줄 2줄을 그린다.\n");
    printf("                    이렇게 생긴 9칸 위에 1P는 O, 2P는 X를 번갈아가며 그린다.\n");
    printf("                      먼저 O나 X를 3개가 직선으로 이어지게 만들면 승리한다.\n\n\n");

    int x = 43;
    int y = 15;

    gotoxy(x - 2, y);
    printf("> 메뉴로");
    gotoxy(x, y + 1);
    printf(" 종료  ");

    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y == 16) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y == 15) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            if (y == 15) {
                system("cls");
                init();
                menuDraw();
                return 0;
            }
            else {
                exit(0);
            }
        }
        }
    }
}
int menuDraw() {
    int x = 43;
    int y = 12;
    gotoxy(x - 2, y);
    printf("> 게임시작");
    gotoxy(x, y + 1);
    printf("게임정보");
    gotoxy(x, y + 2);
    printf("  종료  ");
    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 12) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 14) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }

        case SUBMIT: {
            if (y == 12) {
                return 0;
            }
            else if (y == 13) {
                GameDes();
                return 0;
            }
            else if (y == 14) {
                exit(0);
            }
        }
        }
    }
}
void DrawFrame() {
    system("cls");
    system("mode con cols=40 lines=40| title TicTacToe");

    unsigned char a = 0xa6;
    unsigned char b[12];

    for (int i = 1; i < 12; i++) {
        b[i] = 0xa0 + i;
    }

        printf("%c%c%c%c", a, b[3], a, b[1]);

    for (int i = 1; i < MUNGTANGE; i++) {
        if (i % (MUNGTANGE / 3) != 0) {
            printf("%c%c%c%c", a, b[1], a, b[1]);
        }
        else {
            printf("%c%c%c%c", a, b[8], a, b[1]);
        }
    }
    printf("%c%c\n", a, b[4]);//첫번째 줄

    for (int i = 0; i <= MUNGTANGE / 6; i++) {
        for (int i = 0; i <= MUNGTANGE; i++) {
            if (i % (MUNGTANGE / 3) == 0) {
                printf("%c%c ", a, b[2]);
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }//두번째 ~ 다섯번째 줄

    printf("%c%c%c%c", a, b[7], a, b[1]);

    for (int i = 1; i < MUNGTANGE; i++) {
        if (i % (MUNGTANGE / 3) != 0) {
            printf("%c%c%c%c", a, b[1], a, b[1]);
        }
        else {
            printf("%c%c%c%c", a, b[11], a, b[1]);
        }
    }
    printf("%c%c\n", a, b[9]);//여섯번째 줄

    for (int i = 0; i <= MUNGTANGE / 6; i++) {
        for (int i = 0; i <= MUNGTANGE; i++) {
            if (i % (MUNGTANGE / 3) == 0) {
                printf("%c%c ", a, b[2]);
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }//일곱번째 ~ 열번째 줄

    printf("%c%c%c%c", a, b[7], a, b[1]);

    for (int i = 1; i < MUNGTANGE; i++) {
        if (i % (MUNGTANGE / 3) != 0) {
            printf("%c%c%c%c", a, b[1], a, b[1]);
        }
        else {
            printf("%c%c%c%c", a, b[11], a, b[1]);
        }
    }
    printf("%c%c\n", a, b[9]);//열한번째 줄

    for (int i = 0; i <= MUNGTANGE / 6; i++) {
        for (int i = 0; i <= MUNGTANGE; i++) {
            if (i % (MUNGTANGE / 3) == 0) {
                printf("%c%c ", a, b[2]);
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }//열두번째 ~ 열여섯번째 줄


    printf("%c%c%c%c", a, b[6], a, b[1]);

    for (int i = 1; i < MUNGTANGE; i++) {
        if (i % (MUNGTANGE / 3) != 0) {
            printf("%c%c%c%c", a, b[1], a, b[1]);
        }
        else {
            printf("%c%c%c%c", a, b[10], a, b[1]);
        }
    }
    printf("%c%c\n", a, b[5]);//일곱번째 줄
    
}
int Rule(char Frame[3][3]) { //매턴마다 돌려주는 규칙
    if (Row(Frame[3][3])) {
        return 1;
    }
    else if (Col(Frame[3][3])) {
        return 1;
    }
    else if (Dia(Frame[3][3])) {
        return 1;
    }
    return 0;
}
int Row(char Frame[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (Frame[i][0] == Frame[i][1] && Frame[i][1] == Frame[i][2]) {
            return 1;
        }
    }
    return 0;
}//가로 확인 함수
int Col(char Frame[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (Frame[0][i] == Frame[1][i] && Frame[1][i] == Frame[2][i]) {
            return 1;
        }
    }
    return 0;
}//세로 확인 함수
int Dia(char Frame[3][3]) {
    if (Frame[0][0] == Frame[1][1] && Frame[1][1] == Frame[2][2]) {
        return 1;
    }
    else if (Frame[0][2] == Frame[1][1] && Frame[1][1] == Frame[2][0]) {
        return  1;
    }
    return 0;
}//대각선 확인 함수
int FrameisFull(char Frame[3][3]) { //다 차있을때 True 리턴
    int flag = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Frame[i][j] == 0) {
                flag = 0;
            }
        }
    }
    return flag;
}
int main() {
    init();
    menuDraw();//여기서 다시 리턴하면 게임 시작임

    DrawFrame();

    char Frame[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Frame[i][j] = 0;
        }
    }
    
    while (!Rule(Frame[3][3]) || !FrameisFull(Frame[3][3])) {
          
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
This poem was written a long time ago, but still remains one of the favorite poems of Korea.*/