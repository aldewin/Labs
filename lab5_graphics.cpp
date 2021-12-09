
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;


int main() {
	bool work = true;
	bool pause = false;
	double speed = 0.5;
	int frequence = 50;
	
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN);
	COORD BufSize = COORD{ 100, 400 };
	SetConsoleScreenBufferSize(hStdout, BufSize);
	SMALL_RECT WinSize = SMALL_RECT{ 0, 0, 100, 20 };
	SetConsoleWindowInfo(hStdout, true, &WinSize);
	CHAR_INFO ch = CHAR_INFO{ ' ' };
	SMALL_RECT ScrollRect = SMALL_RECT{ 0, 2, 99, 19 };

	cout << "speed: " << speed <<  endl;
	cout << "frequence: " << frequence << "%" << endl;

	int countLines = 2;
	while (work) {
		countLines++;

		// generation symbol
		if (!pause) {
			for (int i = 0; i < 100; i++) {
				char frequenceSpace = rand() % 100 + 1;
				if (frequenceSpace < frequence) {
					cout << char(rand() % 125 + 33);
				}
				else {
					cout << " ";
				}
			}
			cout << endl;
		}
		
		
		Sleep(speed * 1000);

		// KeyListener
		if (_kbhit()) {
			char in = _getch();
			switch (in) {
				case '=':
					pause = !pause;
					break;
				case '+':
					if (speed < 0.9)
						speed += 0.1;
					SetConsoleCursorPosition(hStdout, COORD{7, 0});
					cout << speed;
					SetConsoleCursorPosition(hStdout, COORD{ 0,  2});
					break;
				case '-':
					if (speed > 0.1)
						speed -= 0.1;
					SetConsoleCursorPosition(hStdout, COORD{ 7, 0 });
					cout << speed;
					SetConsoleCursorPosition(hStdout, COORD{ 0, 2});
					break;
				case 'w':
					if (frequence < 90)
						frequence += 10;
					SetConsoleCursorPosition(hStdout, COORD{ 11,1 });
					cout << frequence;
					SetConsoleCursorPosition(hStdout, COORD{ 0, 2});
					break;
				case 's':
					if (frequence > 10)
						frequence -= 10;
					SetConsoleCursorPosition(hStdout, COORD{ 11,1 });
					cout << frequence;
					SetConsoleCursorPosition(hStdout, COORD{ 0, 2});
					break;
				default:
					work = false;
					break;
			}
		}

		// Update
		if (countLines > 18) {
			ScrollConsoleScreenBuffer(hStdout, &ScrollRect, NULL, COORD{ 0, 3}, &ch);
			SetConsoleCursorPosition(hStdout, COORD{ 0, 2 });
		}
	}

	return 0;
} 