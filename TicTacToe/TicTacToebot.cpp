#include<stdio.h>

int BotMain(int frame[3][3]) {
	int score[3][3], i, j;

	RowColDia(frame, score); //���� �ʿ��Ѱ�

	return 0;
}

void RowColDia(int frame[3][3], int score[3][3]) {//���� ���� �밢���� ��� ���� �ΰ��� ���޾��ִ°� üũ�ϴ� �Լ�
	int i;

	for (i = 0; i < 3; i++) {
		if (frame[i][0] == frame[i][1] && frame[i][0] == 1) score[i][2] == 10;
		if (frame[i][1] == frame[i][2] && frame[i][1] == 1) score[i][0] == 10;
		if (frame[0][i] == frame[1][i] && frame[0][i] == 1) score[2][i] == 10;
		if (frame[1][i] == frame[2][i] && frame[1][i] == 1) score[0][i] == 10;
	}

	for (i = 0; i < 2; i++) {
		if (frame[i][i] == frame[i + 1][i + 1] && frame[i][i] == 1) score[i][2] == 10;
	}
	if (frame[0][0] == frame[1][1] && frame[0][0] == 1) score[2][2] == 10;
	if (frame[1][1] == frame[2][2] && frame[1][1] == 1) score[0][0] == 10;
	if (frame[0][2] == frame[1][1] && frame[1][1] == 1) score[2][0] == 10;
	if (frame[1][1] == frame[2][0] && frame[1][1] == 1) score[0][2] == 10;
}