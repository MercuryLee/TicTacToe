#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<conio.h>

int cursorx = 7;
int cursory = 3;
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define FSIZE 21
#define OS 1
#define XS -1

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
int GameDesDraw() {
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
    gotoxy(x - 15, y - 11);
    printf("TAB WASD TO MOVE, TAB SPACE TO SELECT");
    gotoxy(x - 2, y);
    printf("> 게임시작");
    gotoxy(x, y + 1);
    printf("게임정보");
    gotoxy(x, y + 2);
    printf("  종료  ");
    gotoxy(x - 1, y);
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
                GameDesDraw();
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
    system("mode con cols=50 lines=50| title TicTacToe");

    unsigned char a = 0xa6;
    unsigned char b[12];

    for (int i = 1; i < 12; i++) {
        b[i] = 0xa0 + i;
    }

    printf("%c%c%c%c", a, b[3], a, b[1]);

    for (int i = 1; i < FSIZE; i++) {
        if (i % (FSIZE / 3) != 0) {
            printf("%c%c%c%c", a, b[1], a, b[1]);
        }
        else {
            printf("%c%c%c%c", a, b[8], a, b[1]);
        }
    }
    printf("%c%c\n", a, b[4]);//첫번째 줄

    for (int i = 0; i <= 4; i++) {
        for (int i = 0; i <= FSIZE; i++) {
            if (i % (FSIZE / 3) == 0) {
                printf("%c%c ", a, b[2]);
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }//두번째 ~ 다섯번째 줄

    printf("%c%c%c%c", a, b[7], a, b[1]);

    for (int i = 1; i < FSIZE; i++) {
        if (i % (FSIZE / 3) != 0) {
            printf("%c%c%c%c", a, b[1], a, b[1]);
        }
        else {
            printf("%c%c%c%c", a, b[11], a, b[1]);
        }
    }
    printf("%c%c\n", a, b[9]);//여섯번째 줄

    for (int i = 0; i <= 4; i++) {
        for (int i = 0; i <= FSIZE; i++) {
            if (i % (FSIZE / 3) == 0) {
                printf("%c%c ", a, b[2]);
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }//일곱번째 ~ 열번째 줄

    printf("%c%c%c%c", a, b[7], a, b[1]);

    for (int i = 1; i < FSIZE; i++) {
        if (i % (FSIZE / 3) != 0) {
            printf("%c%c%c%c", a, b[1], a, b[1]);
        }
        else {
            printf("%c%c%c%c", a, b[11], a, b[1]);
        }
    }
    printf("%c%c\n", a, b[9]);//열한번째 줄

    for (int i = 0; i <= 4; i++) {
        for (int i = 0; i <= FSIZE; i++) {
            if (i % (FSIZE / 3) == 0) {
                printf("%c%c ", a, b[2]);
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }//열두번째 ~ 열여섯번째 줄


    printf("%c%c%c%c", a, b[6], a, b[1]);

    for (int i = 1; i < FSIZE; i++) {
        if (i % (FSIZE / 3) != 0) {
            printf("%c%c%c%c", a, b[1], a, b[1]);
        }
        else {
            printf("%c%c%c%c", a, b[10], a, b[1]);
        }
    }
    printf("%c%c\n", a, b[5]);//마지막 줄
    printf("            TAB SPACE TO SELECT\n");
}
int PlayerChoose() {

}//PVP OR PVE
int Row(int Frame[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (Frame[i][0] == Frame[i][1] && Frame[i][1] == Frame[i][2] && Frame[i][0] != 0) {
            return 1;
        }
    }
    return 0;
}//가로 확인 함수
int Col(int Frame[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (Frame[0][i] == Frame[1][i] && Frame[1][i] == Frame[2][i] && Frame[0][i] != 0) {
            return 1;
        }
    }
    return 0;
}//세로 확인 함수
int Dia(int Frame[3][3]) {
    if (Frame[0][0] == Frame[1][1] && Frame[1][1] == Frame[2][2] && Frame[0][0] != 0) return 1;
    else if (Frame[0][2] == Frame[1][1] && Frame[1][1] == Frame[2][0] && Frame[0][2] != 0) return 1;
    return 0;
}//대각선 확인 함수
int GameOverChecker(int Frame[3][3]) { //게임 끝이면 돌리기
    int flag = 1;
    if (Row(Frame)) return 1;
    if (Col(Frame)) return 1;
    if (Dia(Frame)) return 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Frame[i][j] == 0) {
                flag = 0;
            }
        }
    }
    return flag;
}
void printX() {
    gotoxy(cursorx - 4, cursory - 2);
    printf("*");
    gotoxy(cursorx - 4, cursory + 2);
    printf("*");
    gotoxy(cursorx - 2, cursory - 1);
    printf("*");
    gotoxy(cursorx - 2, cursory + 1);
    printf("*");
    gotoxy(cursorx + 4, cursory - 2);
    printf("*");
    gotoxy(cursorx + 4, cursory + 2);
    printf("*");
    gotoxy(cursorx + 2, cursory - 1);
    printf("*");
    gotoxy(cursorx + 2, cursory + 1);
    printf("*");
    gotoxy(cursorx, cursory);
    printf("*");
}
void printO() {
    gotoxy(cursorx - 5, cursory - 2);
    printf("    ***");
    gotoxy(cursorx - 5, cursory - 1);
    printf("  **   **");
    gotoxy(cursorx - 5, cursory);
    printf(" *       *");
    gotoxy(cursorx - 5, cursory + 1);
    printf("  **   **");
    gotoxy(cursorx - 5, cursory + 2);
    printf("    ***");
    gotoxy(cursorx, cursory);
}
int GameControl(int Frame[3][3], int turn) {
    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (cursory > 3) {
                gotoxy(cursorx, cursory -= 6);
            }
            break;
        }
        case DOWN: {
            if (cursory < 15) {
                gotoxy(cursorx, cursory += 6);
            }
            break;
        }
        case LEFT: {
            if (cursorx > 7) {
                gotoxy(cursorx -= 14, cursory);
            }
            break;
        }
        case RIGHT: {
            if (cursorx < 35) {
                gotoxy(cursorx += 14, cursory);
            }
            break;
        }
        case SUBMIT: {
            int xx, yy;
            xx = ((cursorx + 7) / 14) - 1;
            yy = ((cursory + 3) / 6) - 1;
            if (Frame[yy][xx] == 0) {
                if (turn % 2 == 0) {
                    printX();
                    Frame[yy][xx] = XS;
                }
                else if (turn % 2 == 1) {
                    printO();
                    Frame[yy][xx] = OS;
                }
                return 0;
            }
            break;
        }
        }
    }
}