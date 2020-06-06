#include <iostream>
#include <Windows.h>
#include<string>
#include <time.h>
#include <conio.h>

#define LEFT   75      
#define RIGHT  77     
#define UP     72     
#define DOWN   80   

using namespace std;

struct  _tagPoint {
	int x;
	int y;
};


typedef _tagPoint POINT_t;
typedef _tagPoint* PPOINT_t;

void gotoxy(int x, int y)
{
	COORD Cur = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	COORD Pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void SetMaze(PPOINT_t pPlayerPos, PPOINT_t pStartPos, PPOINT_t pEndPos, int SIZE_X, int SIZE_Y) {
	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = SIZE_X-1;
	pEndPos->y = SIZE_Y-1;

	pPlayerPos->x = 0;
	pPlayerPos->y = 0;




}
void Output(int **Maze, PPOINT_t pPlayerPos, int SIZE_X, int SIZE_Y) {
	gotoxy(0, 0);
	for (int i = 0; i < SIZE_X + 1; i++) {
		cout << "■";
	}
	gotoxy(0, SIZE_Y);
	for (int i = 0; i < SIZE_X + 1; i++) {
		cout << "■";
	}
	for (int i = 1; i < SIZE_Y; i++) {
		gotoxy(0, i);
		cout << "■";
	}
	for (int i = 1; i < SIZE_Y; i++) {
		gotoxy(1 + SIZE_X * 2, i + 1);
		cout << "■";
	}

	for (int i = 0; i < SIZE_Y-1; i++) {
		gotoxy(3, 2 + i);
		for (int j = 0; j < SIZE_X-1; j++) {

			if (pPlayerPos->x == j && pPlayerPos->y == i)
				cout << "☆";//☆

			else if (Maze[j][i] == 0)
				cout << "■";

			else if (Maze[j][i] == 1)
				cout << "  ";

			else if (Maze[j][i] == 3)
				cout << "◎";
		}
		cout << endl;
	}
}



void printEscape() {
	//E
	for (int i = 1; i < 10; i++) {
		gotoxy(10, i + 1);
		cout << "■";
	}
	gotoxy(12, 2);
	cout << "■■■";
	gotoxy(12, 6);
	cout << "■■■";
	gotoxy(12, 10);
	cout << "■■■";

	Sleep(500);//s
	gotoxy(20, 7);
	cout << "■";
	gotoxy(24, 9);
	cout << "■";
	gotoxy(20, 6);
	cout << "■■■";
	gotoxy(20, 8);
	cout << "■■■";
	gotoxy(20, 10);
	cout << "■■■";

	Sleep(500);//c
	for (int i = 1; i < 4; i++) {
		gotoxy(28, i + 6);
		cout << "■";
	}
	gotoxy(28, 6);
	cout << "■■■";
	gotoxy(28, 10);
	cout << "■■■";

	Sleep(500);//a
	for (int i = 1; i < 4; i++) {
		gotoxy(36, i + 6);
		cout << "■";
		gotoxy(40, i + 6);
		cout << "■";
	}
	gotoxy(36, 6);
	cout << "■■■";
	gotoxy(42, 9);
	cout << "■";
	gotoxy(36, 10);
	cout << "■■■■";

	Sleep(500);//p
	gotoxy(46, 6);
	cout << "■■■";
	for (int i = 1; i < 7; i++) {
		gotoxy(46, i + 6);
		cout << "■";
	}
	for (int i = 1; i < 4; i++) {
		gotoxy(50, i + 6);
		cout << "■";
	}
	gotoxy(48, 9);
	cout << "■";

	Sleep(500);//e
	gotoxy(54, 7);
	cout << "■";
	gotoxy(54, 9);
	cout << "■";
	gotoxy(54, 6);
	cout << "■■■";
	gotoxy(54, 8);
	cout << "■■■";
	gotoxy(54, 10);
	cout << "■■■";

	Sleep(500);//G
	gotoxy(62, 2);
	cout << "■■■■";
	gotoxy(68, 3);
	cout << "■";
	for (int i = 1; i < 9; i++) {
		gotoxy(62, i + 2);
		cout << "■";
	}
	gotoxy(62, 10);
	cout << "■■■";
	for (int i = 1; i < 6; i++) {
		gotoxy(68, i + 5);
		cout << "■";
	}
	gotoxy(66, 6);
	cout << "■■";

	Sleep(500);//a
	for (int i = 1; i < 4; i++) {
		gotoxy(72, i + 6);
		cout << "■";
		gotoxy(76, i + 6);
		cout << "■";
	}
	gotoxy(72, 6);
	cout << "■■■";
	gotoxy(78, 9);
	cout << "■";
	gotoxy(72, 10);
	cout << "■■■■";

	Sleep(500);//m
	gotoxy(82, 6);
	cout << "■■■■■";
	for (int i = 1; i < 5; i++) {
		gotoxy(82, 6 + i);
		cout << "■";
		gotoxy(86, 6 + i);
		cout << "■";
		gotoxy(90, 6 + i);
		cout << "■";
	}

	Sleep(500);//e
	gotoxy(94, 7);
	cout << "■";
	gotoxy(94, 9);
	cout << "■";
	gotoxy(94, 6);
	cout << "■■■";
	gotoxy(94, 8);
	cout << "■■■";
	gotoxy(94, 10);
	cout << "■■■";

	Sleep(1000);
}

int main() {
	int SIZE_X = 0;
	int SIZE_Y = 0;
	

	POINT_t tPlayerPos;
	POINT_t tStartPos;
	POINT_t tEndPos;

	string NAME;

	printEscape();

	gotoxy(20, 12);
	cout << "┏";
	gotoxy(21, 12);
	for (int i = 0; i < 60; i++)
		cout << "━";
	gotoxy(81, 12);
	cout << "┓";
	gotoxy(21, 28);
	for (int i = 0; i < 60; i++)
		cout << "━";
	gotoxy(20, 28);
	cout << "┗";
	for (int i = 0; i < 15; i++) {
		gotoxy(20, 13 + i);
		cout << "┃";
	}
	gotoxy(81, 28);
	cout << "┛";
	for (int i = 0; i < 15; i++) {
		gotoxy(81, 13 + i);
		cout << "┃";
	}

	gotoxy(25, 17);
	cout << "▶ 원하는 미로의 크기를 입력하세요 (ex 10x10) >>";
	cin >> SIZE_X;
	cin >> SIZE_Y;
	gotoxy(25, 21);
	cout << "▶ 아이디를 입력하세요 >> ";
	cin >> NAME;
//	char strMaze[SIZE_X][SIZE_Y] = {};
	int **Maze = new int*[SIZE_X];
	for (int i = 0; i < SIZE_Y; ++i)
		Maze[i] = new int[SIZE_Y];

//	*Maze = playdisplay(SIZE_X, SIZE_Y);
	int i, j, x = 0, y = 0, rotate;
	int** map = new int*[SIZE_X];
	for (int i = 0; i < SIZE_Y; ++i)
		map[i] = new int[SIZE_Y];

	for (i = 0; i < SIZE_Y; i++) {
		for (j = 0; j < SIZE_X; j++) {
			map[j][i] = 0;
		}
	}

	srand(time(NULL));
	map[x][y] = 1;
	//while(1){ 
	for (i = 0; i < 100000; i++) {
		rotate = rand() % 4 + 1; // 1위 2오른 3아래 4왼
		if (rotate == 1) {
			if (y == 0)
				continue; //만약 위에 공간이 없다면 rotate 다시설정
			if (map[x][y - 2] == 0) { //두칸위가 비어있다면
				y--; map[x][y] = 1;
				y--; map[x][y] = 1;
			}
			else { //두칸위가 채워져있다면
				y -= 2;
			}
		}

		if (rotate == 2) {
			if (x == SIZE_X - 2)
				continue;
			if (map[x + 2][y] == 0) {
				x++; map[x][y] = 1;
				x++; map[x][y] = 1;
			}
			else {
				x += 2;
			}
		}

		if (rotate == 3) {
			if (y == SIZE_Y - 2)
				continue;
			if (map[x][y + 2] == 0) {
				y++; map[x][y] = 1;
				y++; map[x][y] = 1;
			}
			else {
				y += 2;
			}
		}

		if (rotate == 4) {
			if (x == 0)
				continue;
			if (map[x - 2][y] == 0) {
				x--; map[x][y] = 1;
				x--; map[x][y] = 1;
			}
			else {
				x -= 2;
			}
		}
	}



	map[SIZE_X - 2][SIZE_Y - 2] = 3;



	//미로를 설정한다
	SetMaze(&tPlayerPos, &tStartPos, &tEndPos, SIZE_X, SIZE_Y);


	while (true) {
		system("cls");
		//미로를 출력한다
		Output(map, &tPlayerPos, SIZE_X, SIZE_Y);


		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
			break;

		

		if ((tPlayerPos).x == SIZE_X - 2 &&(tPlayerPos).y == SIZE_Y - 2) {
			system("cls");
			cout << "탈출 성공";
			Sleep(3000);
			break;
		}

	}

	return 0;
}