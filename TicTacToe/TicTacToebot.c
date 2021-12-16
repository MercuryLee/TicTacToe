#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<conio.h>
#include"Functions.h"

void CheckGameOver(int frame[3][3], int score[3][3]) {//���� ������ ������ ������, ���ھ 20, ���� ���� ������, ���ھ 10
	int occnum ,i, j, k, q, point;
	
	for (occnum = 1; occnum > -2; occnum -= 2) {
		if (occnum == 1) point = 10;
		else point = 20;

		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				k = j + 1;
				if (k > 2) k -= 3;
				q = j + 2;
				if (q > 2) q -= 3;
				if (frame[i][k] == frame[i][q] && frame[i][j] == 0 && frame[i][k] == occnum) score[i][j] = point;//����
				if (frame[k][i] == frame[q][i] && frame[j][i] == 0 && frame[k][i] == occnum) score[j][i] = point;//����
			}
			k = i + 1;
			if (k > 2) k -= 3;
			q = i + 2;
			if (q > 2) q -= 3;
			if (frame[i][i] == frame[k][k] && frame[q][q] == 0 && frame[i][i] == occnum) score[q][q] = point;
		}
		if (frame[0][2] == frame[1][1] && frame[2][0] == 0 && frame[1][1] == occnum) score[2][0] = point;
		if (frame[1][1] == frame[2][0] && frame[0][2] == 0 && frame[1][1] == occnum) score[0][2] = point;
		if (frame[0][2] == frame[2][0] && frame[1][1] == 0 && frame[0][2] == occnum) score[1][1] = point;//�밢��
	}
}
void ExcludeScore(int frame[3][3], int score[3][3]) {
	int i, j, k, q;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (frame[i][j] != 0) {
				score[i][j] = -500;
			}
			else {
				k = j + 1;
				if (k > 2) k -= 3;
				q = j + 2;
				if (q > 2) q -= 3;

				if (frame[i][k] != frame[i][q] && frame[i][k] != 0 && frame[i][q] != 0) score[i][j] = -100;//����
				if (frame[k][i] != frame[q][i] && frame[k][i] != 0 && frame[q][i] != 0) score[j][i] = -100;//����
			}
		}
		k = i + 1;
		if (k > 2) k -= 3;
		q = i + 2;
		if (q > 2) q -= 3;

		if (frame[i][i] == 0) {
			if (frame[k][k] != frame[q][q] && frame[k][k] != 0 && frame[q][q] != 0) score[i][i] = -50;
		}
	}
	if (frame[1][1] != frame[2][0] && frame[1][1] != 0 && frame[2][0] != 0) score[0][2] = -50;
	if (frame[2][0] != frame[0][2] && frame[2][0] != 0 && frame[0][2] != 0) score[1][1] = -50;
	if (frame[0][2] != frame[1][1] && frame[0][2] != 0 && frame[1][1] != 0) score[2][0] = -50;
}
void AddScoreDia(int score[3][3]) {
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (score[i][j] != -500) {
				if (i + j == 1 || i + j == 3) score[i][j] += 30;
				else if (i + j == 2 || i == j) score[i][j] += 50;
			}
		}
	}
}
int BotMain(int frame[3][3]) {
	int score[3][3], i, j, x, y;
	int hs = -100, ss = 1;//hightest score, samescore

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			score[i][j] = 0;
		}
	}

	if (frame[1][1] == 0) score[1][1] = 20;//1

	CheckGameOver(frame, score); //2, 3
	ExcludeScore(frame, score);//4
	AddScoreDia(score);//5

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (score[i][j] == hs) {
				ss++;
			}
			else if (score[i][j] > hs) {
				ss = 1;
				hs = score[i][j];
			}
		}
	}

	if (ss > 0) {
		int randint = rand() % ss;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (score[i][j] == hs) randint--;
				if (randint == 0) break;
			}
		}
	}

	else if (ss == 0) {
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (score[i][j] == hs) break;
			}
		}
	}

	gotoxy(cursorx + (14 * j), cursory + (6 * i));
	printX();
	frame[j][i] = XS;
	
	return 0;
}