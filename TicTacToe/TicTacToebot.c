#include<stdio.h>

void CheckGameOver(int frame[3][3], int score[3][3]) {//내가 게임을 끝낼수 있으면, 스코어에 20, 내가 끝날 위기라면, 스코어에 10
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
				if (frame[i][k] == frame[i][q] && frame[i][j] == 0 && frame[i][k] == occnum) score[i][j] = point;//가로
				if (frame[k][i] == frame[q][i] && frame[j][i] == 0 && frame[k][i] == occnum) score[j][i] = point;//세로
			}
			k = i + 1;
			if (k > 2) k -= 3;
			q = i + 2;
			if (q > 2) q -= 3;
			if (frame[i][i] == frame[k][k] && frame[q][q] == 0 && frame[i][i] == occnum) score[q][q] = point;
		}
		if (frame[0][2] == frame[1][1] && frame[2][0] == 0 && frame[1][1] == occnum) score[2][0] = point;
		if (frame[1][1] == frame[2][0] && frame[0][2] == 0 && frame[1][1] == occnum) score[0][2] = point;
		if (frame[0][2] == frame[2][0] && frame[1][1] == 0 && frame[0][2] == occnum) score[1][1] = point;//대각선
	}
}
void ExcludeScore(int frame[3][3], int score[3][3]) {
	int i, j, k, q;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (frame[i][j] != 0) {
				score[i][j] = -100;
			}
			else {
				k = j + 1;
				if (k > 2) k -= 3;
				q = j + 2;
				if (q > 2) q -= 3;

				if (frame[i][k] != frame[i][q] && frame[i][k] != 0 && frame[i][q] != 0) score[i][j] = -100;//가로
				if (frame[k][i] != frame[q][i] && frame[k][i] != 0 && frame[q][i] != 0) score[j][i] = -100;//세로
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
int BotMain(int frame[3][3]) {
	int score[3][3], i, j, hs = -100;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			score[i][j] = 0;
		}
	}
	if (frame[1][1] == 0) score[1][1] = 20;

	CheckGameOver(frame, score); //게임이 끝낼수 있을때 놓기
	ExcludeScore(frame, score);

	for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) if (score[i][j] > hs) hs = score[i][j];
	for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) if (score[i][j] == hs) break;

	return 0;
}