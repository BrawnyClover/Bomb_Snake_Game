#pragma once
#pragma warning(disable:4996)
#include <cstdio>
#include <Windows.h>

#define WM_KEYDOWN 0x0100
#define KEY_UP 72 // 상하좌우 키 값
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define WIDTH 28 // 맵의 너비, 높이 값
#define HEIGHT 28

int MapCheckArray[HEIGHT][WIDTH]; // 체크 배열 생성

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
void setCursurPos(int x, int y) // 콘솔 좌표 위치 지정
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int returnXpos()
{
	return 0;
}
static void drawBorderLine() // 맵의 테두리 그리는 함수
{
	for (int i = 0; i < HEIGHT; i++) {
		if (i == 0 || i == HEIGHT-1) {
			for (int j = 0; j < WIDTH; j++) {
				MapCheckArray[i][j] = 1;
			}
		}
		else {
			MapCheckArray[i][0] = 1;
			MapCheckArray[i][WIDTH-1] = 1;
		}
	}
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (MapCheckArray[i][j] == 1) {
				printf("■");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
}