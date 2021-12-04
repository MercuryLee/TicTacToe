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
#define Xs "��" //1
#define Os "��" //-1

int gotoxy(int x, int y) {//x, y�� Ŀ�� ��������
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
    return 0;
}
void init() {// ó�� ����
    system("mode con cols=95 lines=20| title TicTacToe");//87 + 8 = 95
    printf("\n\n\n\n");
    printf("        TTTTT    IIIII    CCCCC    TTTTT      A      CCCCC    TTTTT    OOOOO    EEEEE\n");
    printf("          T        I      C          T       A A     C          T      O   O    E\n");
    printf("          T        I      C          T      AAAAA    C          T      O   O    EEEEE\n");
    printf("          T        I      C          T      A   A    C          T      O   O    E\n");
    printf("          T      IIIII    CCCCC      T      A   A    CCCCC      T      OOOOO    EEEEE\n\n\n");
}
int keyControl() {// Ű �޾Ƽ� �����̱�
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
    system("cls"); //�ܼ�â ����ϰ� �����, ��ǥ 0, 0�� ���ϱ�
    printf("\n\n\n\n");
    printf("                   Tic-tac-toe is a paper-and-pencil game for two players who    \n");
    printf("               take turns marking the spaces in a three-by-three grid with O or X\n");//68��, 34���� �ϸ��
    printf("                    The player who succeeds in placing three of their marks\n");
    printf("                   in a horizontal, vertical, or diagonal row is the winner.\n\n\n");
    printf("                           ���� ���� ������ 2�� ������ 2���� �׸���.\n");
    printf("                    �̷��� ���� 9ĭ ���� 1P�� O, 2P�� X�� �����ư��� �׸���.\n");
    printf("                      ���� O�� X�� 3���� �������� �̾����� ����� �¸��Ѵ�.\n\n\n");

    int x = 43;
    int y = 15;

    gotoxy(x - 2, y);
    printf("> �޴���");
    gotoxy(x, y + 1);
    printf(" ����  ");

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
    printf("> ���ӽ���");
    gotoxy(x, y + 1);
    printf("��������");
    gotoxy(x, y + 2);
    printf("  ����  ");
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
    printf("%c%c\n", a, b[4]);//ù��° ��

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
    }//�ι�° ~ �ټ���° ��

    printf("%c%c%c%c", a, b[7], a, b[1]);

    for (int i = 1; i < MUNGTANGE; i++) {
        if (i % (MUNGTANGE / 3) != 0) {
            printf("%c%c%c%c", a, b[1], a, b[1]);
        }
        else {
            printf("%c%c%c%c", a, b[11], a, b[1]);
        }
    }
    printf("%c%c\n", a, b[9]);//������° ��

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
    }//�ϰ���° ~ ����° ��

    printf("%c%c%c%c", a, b[7], a, b[1]);

    for (int i = 1; i < MUNGTANGE; i++) {
        if (i % (MUNGTANGE / 3) != 0) {
            printf("%c%c%c%c", a, b[1], a, b[1]);
        }
        else {
            printf("%c%c%c%c", a, b[11], a, b[1]);
        }
    }
    printf("%c%c\n", a, b[9]);//���ѹ�° ��

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
    }//���ι�° ~ ��������° ��


    printf("%c%c%c%c", a, b[6], a, b[1]);

    for (int i = 1; i < MUNGTANGE; i++) {
        if (i % (MUNGTANGE / 3) != 0) {
            printf("%c%c%c%c", a, b[1], a, b[1]);
        }
        else {
            printf("%c%c%c%c", a, b[10], a, b[1]);
        }
    }
    printf("%c%c\n", a, b[5]);//�ϰ���° ��
    
}
int Rule(char Frame[3][3]) { //���ϸ��� �����ִ� ��Ģ
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
}//���� Ȯ�� �Լ�
int Col(char Frame[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (Frame[0][i] == Frame[1][i] && Frame[1][i] == Frame[2][i]) {
            return 1;
        }
    }
    return 0;
}//���� Ȯ�� �Լ�
int Dia(char Frame[3][3]) {
    if (Frame[0][0] == Frame[1][1] && Frame[1][1] == Frame[2][2]) {
        return 1;
    }
    else if (Frame[0][2] == Frame[1][1] && Frame[1][1] == Frame[2][0]) {
        return  1;
    }
    return 0;
}//�밢�� Ȯ�� �Լ�
int FrameisFull(char Frame[3][3]) { //�� �������� True ����
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
    menuDraw();//���⼭ �ٽ� �����ϸ� ���� ������

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