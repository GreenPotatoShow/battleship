#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
void delay(int ms) {
	int c = clock() + ms;
	while (clock() < c);
}

void poleVyvod(char num[]) {
	printf("    A  B  C  D  E  F  G  H  I  J\n");
	printf("________________________________\n");
	printf("0|  ");
	for (int i = 0; i < 100; i++) {
		if ((i + 1) % 10 == 0) {
			printf("%c\n", num[i]);
			if ((i + 1) < 100) { printf("%i|  ", ((i + 1) / 10)); }
		}
		else { printf("%c  ", num[i]); }
	}
}

void checkBan(int ban[]) {
	printf("    A  B  C  D  E  F  G  H  I  J\n");
	printf("________________________________\n");
	printf("0|  ");
	for (int i = 0; i < 100; i++) {
		if ((i + 1) % 10 == 0) {
			printf("%i\n", ban[i]);
			if ((i + 1) < 100) { printf("%i|  ", ((i + 1) / 10)); }
		}
		else { printf("%i  ", ban[i]); }
	}
}

int charToInt(char a) {
	switch (a) {
	case 'A':return 0; break;
	case 'B':return 1; break;
	case 'C':return 2; break;
	case 'D':return 3; break;
	case 'E':return 4; break;
	case 'F':return 5; break;
	case 'G':return 6; break;
	case 'H':return 7; break;
	case 'I':return 8; break;
	case 'J':return 9; break;
	case 'a':return 0; break;
	case 'b':return 1; break;
	case 'c':return 2; break;
	case 'd':return 3; break;
	case 'e':return 4; break;
	case 'f':return 5; break;
	case 'g':return 6; break;
	case 'h':return 7; break;
	case 'i':return 8; break;
	case 'j':return 9; break;
	default: return -1;
	}
}

int intToChar(int a) {
	switch (a) {
	case 0:return 'A'; break;
	case 1:return 'B'; break;
	case 2:return 'C'; break;
	case 3:return 'D'; break;
	case 4:return 'E'; break;
	case 5:return 'F'; break;
	case 6:return 'G'; break;
	case 7:return 'H'; break;
	case 8:return 'I'; break;
	case 9:return 'J';
	}
}

int ifShipPossible(int x, int y, int n, int ban[100]) {
	bool zapret;
	int i;
	zapret = false;
	if (x > y) { i = x; x = y; y = i; }
	if ((y - x == (n - 1)) && (y % 10 >= (n - 1))) {
		for (i = x; i <= y; i++) {
			if (ban[i] != 0) { zapret = true; }
		}
		if (zapret == false) { return 1; }
		else { return 3; }
	}
	if ((y - x == (n - 1) * 10) && (y >= (n - 1) * 10)) {
		for (i = x; i <= y; i = i + 10) {
			if (ban[i] != 0) { zapret = true; }
		}
		if (zapret == false) { return 2; }
		else { return 3; }
	}
	else { return 0; }
}

int ifKilled(int x, int size, char a, char pole2secret[]) {
	if (size == 2) {
		if (x % 10 <= 8) {
			if (pole2secret[x + 1] == a) { return x; }
		}
		if (x % 10 >= 1) {
			if (pole2secret[x - 1] == a) { return x - 1; }
		}
		if (x <= 89) {
			if (pole2secret[x + 10] == a) {
				if (x == 0) { return -1000; }
				else { return -x; }
			}
		}
		if (x >= 10) {
			if (pole2secret[x - 10] == a) {
				if ((x - 10) == 0) { return -1000; }
				else { return -(x - 10); }
			}
		}
		return 1000;
	}
	if (size == 3) {
		if ((x % 10 <= 8) && (x % 10 >= 1)) {
			if ((pole2secret[x + 1] == a) && (pole2secret[x - 1] == a)) { return x - 1; }
		}
		if (x % 10 <= 8) {
			if (x % 10 <= 7) {
				if ((pole2secret[x + 2] == a) && (pole2secret[x + 1] == a)) { return x; }
			}
		}
		if (x % 10 >= 1) {
			if (x % 10 >= 2) {
				if ((pole2secret[x - 2] == a) && (pole2secret[x - 1] == a)) { return x - 2; }
			}
		}
		if ((x <= 89) && (x >= 10)) {
			if ((pole2secret[x - 10] == a) && (pole2secret[x + 10] == a)) {
				if ((x - 10) == 0) { return -1000; }
				return -(x - 10);
			}
		}
		if (x <= 79) {
			if ((pole2secret[x + 10] == a) && (pole2secret[x + 20] == a)) {
				if (x == 0) { return -1000; }
				return -x;
			}
		}
		if (x >= 20) {
			if ((pole2secret[x - 20] == a) && (pole2secret[x - 10] == a)) {
				if ((x - 20) == 0) { return -1000; }
				return -(x - 20);
			}
		}
		return 1000;
	}
	if (size == 4) {
		if ((x % 10 <= 8) && (x % 10 >= 1)) {
			if ((pole2secret[x + 1] == a) && (pole2secret[x - 1] == a)) {
				if (x % 10 <= 7) {
					if (pole2secret[x + 2] == a) { return x - 1; }
				}
				if (x % 10 >= 2) {
					if (pole2secret[x - 2] == a) { return x - 2; }
				}
			}
		}
		if (x % 10 <= 6) {
			if ((pole2secret[x + 1] == a) && (pole2secret[x + 2] == a) && (pole2secret[x + 3] == a)) { return x; }
		}
		if (x % 10 >= 3) {
			if ((pole2secret[x - 1] == a) && (pole2secret[x - 2] == a) && (pole2secret[x - 3] == a)) { return x - 3; }
		}
		if ((x <= 89) && (x >= 10)) {
			if ((pole2secret[x + 10] == a) && (pole2secret[x - 10] == a)) {
				if (x <= 79) {
					if (pole2secret[x + 20] == a) {
						if ((x - 10) == 0) { return -1000; }
						else { return -(x - 10); }
					}
				}
				if (x >= 20) {
					if (pole2secret[x - 20] == a) {
						if ((x - 20) == 0) { return -1000; }
						else { return -(x - 20); }
					}
				}
			}
		}
		if (x <= 69) {
			if ((pole2secret[x + 30] == a) && (pole2secret[x + 20] == a) && (pole2secret[x + 10] == a)) {
				if (x == 0) { return -1000; }
				else { return -x; }
			}
		}
		if (x >= 30) {
			if ((pole2secret[x - 30] == a) && (pole2secret[x - 20] == a) && (pole2secret[x - 10] == a)) {
				if ((x - 30) == 0) { return -1000; }
				else { return -(x - 30); }
			}
		}
		return 1000;
	}
}

int main()
{
	int ban[100], ban2[100];
	char POLE[100], POLE2[100], pole2secret[100];
	int i, count4palub, count3palub, count2palub, count1palub, shipSize, shipBegin, shipEnd, myShip, doubleMove1, doubleMove2, close, newShot;
	char stolbets, stroka;
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	printf("Добро пожаловать в игру МОРСКОЙ БОЙ\n"); delay(1500);
	for (i = 0; i < 100; i++) {
		POLE[i] = '0';
		ban[i] = 0;
		POLE2[i] = '0';
		ban2[i] = 0;
		pole2secret[i] = '0';
	}
	count4palub = 1;
	count3palub = 2;
	count2palub = 3;
	count1palub = 4;
	shipSize = 4;
	myShip = 10;
	doubleMove1 = 0;
	doubleMove2 = 0;
	close = -1;
	newShot = 0;
	printf("Итак, для начала вам необходимо расставить корабли.\n\n"); delay(2000);
	printf("У вас имеется:\n"); delay(500);
	printf("1 четырёхпалубный корабль,\n"); delay(500);
	printf("2 трёхпалубных корабля,\n"); delay(500);
	printf("3 двухпалубных корабля,\n"); delay(500);
	printf("4 однопалубных корабля.\n\n"); delay(2000);
	printf("Учтите, что нельзя ставить корабли друг на друга или вплотную друг к другу.\n"); delay(2000);
	printf("Чтобы поставить корабль, введите номер клетки начала корабля, а затем конца.\n"); delay(2000);
	printf("Вводите номер клетки в формате 'А1', где А - номер столбца, 1 - номер строки.\n"); delay(2000);
	printf("Обратите внимание, что отсчёт начинается с нуля.\n\n"); delay(2000);
	while (count1palub != 0) {
		switch (shipSize) {
		case 4: printf("Вам осталось поставить %i четырёхпалубных корабля\n", count4palub); delay(1000);
			poleVyvod(POLE);
			printf("Введите номер клетки начала корабля: ");
			scanf("\n%c%c", &stolbets, &stroka);
			if (charToInt(stolbets) == -1) {
				printf("Вы ввели неверную букву.\n"); delay(2000);
				printf("Убедитесь, что вы вводите английские буквы из тех, что расположены над первой строкой поля, и попробуйте ещё раз.\n"); delay(2000);
			}
			else {
				shipBegin = (stroka - '0') * 10 + charToInt(stolbets);
				if (ban[shipBegin] != 0) { printf("Корабли пересекаются! Попробуйте ещё раз.\n\n"); delay(2000); }
				else {
					POLE[shipBegin] = 'T';
					printf("Вы поставили начальную точку корабля на клетку %c%c. Введите конечную точку корабля.\n", stolbets, stroka);
					poleVyvod(POLE); delay(1000);
					printf("Учтите, что корабли не могут пересекаться, а также сейчас ваш корабль должен иметь длину 4: ");
					scanf("\n%c%c", &stolbets, &stroka);
					if (charToInt(stolbets) == -1) {
						printf("Вы ввели неверную букву.\n"); delay(2000);
						printf("Убедитесь, что вы вводите английские буквы из тех, что расположены над первой строкой поля, и попробуйте ещё раз.\n"); delay(2000);
						POLE[shipBegin] = '0';
					}
					else {
						shipEnd = (stroka - '0') * 10 + charToInt(stolbets);
						if (ifShipPossible(shipBegin, shipEnd, shipSize, ban) == 0) {
							printf("Вы сделали что-то не так. Попробуйте ещё раз.\n\n"); delay(2000);
							POLE[shipBegin] = '0';
						}
						else if (ifShipPossible(shipBegin, shipEnd, shipSize, ban) == 3) {
							printf("Корабли пересекаются! Попробуйте ещё раз.\n\n"); delay(2000);
							POLE[shipBegin] = '0';
						}
						else if (ifShipPossible(shipBegin, shipEnd, shipSize, ban) == 1) {
							if (shipBegin < shipEnd) { i = shipEnd; shipEnd = shipBegin; shipBegin = i; }
							for (i = shipEnd; i <= shipBegin; i++) {
								POLE[i] = 'T';
								ban[i] = shipSize;
								if (i >= 10) { ban[i - 10] = shipSize; }
								if (i <= 89) { ban[i + 10] = shipSize; }
							}
							if (shipEnd % 10 >= 1) {
								ban[shipEnd - 1] = shipSize;
								if (shipEnd >= 10) { ban[shipEnd - 11] = shipSize; }
								if (shipEnd <= 89) { ban[shipEnd + 9] = shipSize; }
							}
							if (shipBegin % 10 <= 8) {
								ban[shipBegin + 1] = shipSize;
								if (shipBegin >= 10) { ban[shipBegin - 9] = shipSize; }
								if (shipBegin <= 89) { ban[shipBegin + 11] = shipSize; }
							}
							count4palub = count4palub - 1;
							printf("Отлично.\n\n"); delay(2000);
						}
						else if (ifShipPossible(shipBegin, shipEnd, shipSize, ban) == 2) {
							if (shipBegin < shipEnd) { i = shipEnd; shipEnd = shipBegin; shipBegin = i; }
							for (i = shipEnd; i <= shipBegin; i = i + 10) {
								POLE[i] = 'T';
								ban[i] = shipSize;
								if (i % 10 >= 1) { ban[i - 1] = shipSize; }
								if (i % 10 <= 8) { ban[i + 1] = shipSize; }
							}
							if (shipEnd >= 10) {
								ban[shipEnd - 10] = shipSize;
								if (shipEnd % 10 >= 1) { ban[shipEnd - 11] = shipSize; }
								if (shipEnd % 10 <= 8) { ban[shipEnd - 9] = shipSize; }
							}
							if (shipBegin <= 89) {
								ban[shipBegin + 10] = shipSize;
								if (shipBegin % 10 >= 1) { ban[shipBegin + 9] = shipSize; }
								if (shipBegin % 10 <= 8) { ban[shipBegin + 11] = shipSize; }
							}
							count4palub = count4palub - 1;
							printf("Отлично.\n\n"); delay(2000);
						}
					}
					if (count4palub == 0) { shipSize = shipSize - 1; }
				}
			};
			break;
		case 3: printf("Вам осталось поставить %i трёхпалубных корабля\n", count3palub); delay(1000);
			poleVyvod(POLE);
			printf("Введите номер клетки начала корабля: ");
			scanf("\n%c%c", &stolbets, &stroka);
			if (charToInt(stolbets) == -1) {
				printf("Вы ввели неверную букву.\n"); delay(2000);
				printf("Убедитесь, что вы вводите английские буквы из тех, что расположены над первой строкой поля, и попробуйте ещё раз.\n"); delay(2000);
			}
			else {
				shipBegin = (stroka - '0') * 10 + charToInt(stolbets);
				if (ban[shipBegin] != 0) { printf("Корабли пересекаются! Попробуйте ещё раз.\n\n"); delay(2000); }
				else {
					POLE[shipBegin] = 'T';
					printf("Вы поставили начальную точку корабля на клетку %c%c. Введите конечную точку корабля.\n", stolbets, stroka);
					poleVyvod(POLE); delay(1000);
					printf("Учтите, что корабли не могут пересекаться, а также сейчас ваш корабль должен иметь длину 3: ");
					scanf("\n%c%c", &stolbets, &stroka);
					if (charToInt(stolbets) == -1) {
						printf("Вы ввели неверную букву.\n"); delay(2000);
						printf("Убедитесь, что вы вводите английские буквы из тех, что расположены над первой строкой поля, и попробуйте ещё раз.\n"); delay(2000);
						POLE[shipBegin] = '0';
					}
					else {
						shipEnd = (stroka - '0') * 10 + charToInt(stolbets);
						if (ifShipPossible(shipBegin, shipEnd, shipSize, ban) == 0) {
							printf("Вы сделали что-то не так. Попробуйте ещё раз.\n\n"); delay(2000);
							POLE[shipBegin] = '0';
						}
						else if (ifShipPossible(shipBegin, shipEnd, shipSize, ban) == 3) {
							printf("Корабли пересекаются! Попробуйте ещё раз.\n\n"); delay(2000);
							POLE[shipBegin] = '0';
						}
						else if (ifShipPossible(shipBegin, shipEnd, shipSize, ban) == 1) {
							if (shipBegin < shipEnd) { i = shipEnd; shipEnd = shipBegin; shipBegin = i; }
							for (i = shipEnd; i <= shipBegin; i++) {
								POLE[i] = 'T';
								ban[i] = shipSize;
								if (i >= 10) { ban[i - 10] = shipSize; }
								if (i <= 89) { ban[i + 10] = shipSize; }
							}
							if (shipEnd % 10 >= 1) {
								ban[shipEnd - 1] = shipSize;
								if (shipEnd >= 10) { ban[shipEnd - 11] = shipSize; }
								if (shipEnd <= 89) { ban[shipEnd + 9] = shipSize; }
							}
							if (shipBegin % 10 <= 8) {
								ban[shipBegin + 1] = shipSize;
								if (shipBegin >= 10) { ban[shipBegin - 9] = shipSize; }
								if (shipBegin <= 89) { ban[shipBegin + 11] = shipSize; }
							}
							count3palub = count3palub - 1;
							printf("Отлично.\n\n"); delay(2000);
						}
						else if (ifShipPossible(shipBegin, shipEnd, shipSize, ban) == 2) {
							if (shipBegin < shipEnd) { i = shipEnd; shipEnd = shipBegin; shipBegin = i; }
							for (i = shipEnd; i <= shipBegin; i = i + 10) {
								POLE[i] = 'T';
								ban[i] = shipSize;
								if (i % 10 >= 1) { ban[i - 1] = shipSize; }
								if (i % 10 <= 8) { ban[i + 1] = shipSize; }
							}
							if (shipEnd >= 10) {
								ban[shipEnd - 10] = shipSize;
								if (shipEnd % 10 >= 1) { ban[shipEnd - 11] = shipSize; }
								if (shipEnd % 10 <= 8) { ban[shipEnd - 9] = shipSize; }
							}
							if (shipBegin <= 89) {
								ban[shipBegin + 10] = shipSize;
								if (shipBegin % 10 >= 1) { ban[shipBegin + 9] = shipSize; }
								if (shipBegin % 10 <= 8) { ban[shipBegin + 11] = shipSize; }
							}
							count3palub = count3palub - 1;
							printf("Отлично.\n\n"); delay(2000);
						}
					}
					if (count3palub == 0) { shipSize = shipSize - 1; }
				}
			}; break;
		case 2: printf("Вам осталось поставить %i двухпалубных корабля\n", count2palub); delay(1000);
			poleVyvod(POLE);
			printf("Введите номер клетки начала корабля: ");
			scanf("\n%c%c", &stolbets, &stroka);
			if (charToInt(stolbets) == -1) {
				printf("Вы ввели неверную букву.\n"); delay(2000);
				printf("Убедитесь, что вы вводите английские буквы из тех, что расположены над первой строкой поля, и попробуйте ещё раз.\n"); delay(2000);
			}
			else {
				shipBegin = (stroka - '0') * 10 + charToInt(stolbets);
				if (ban[shipBegin] != 0) { printf("Корабли пересекаются! Попробуйте ещё раз.\n\n"); delay(2000); }
				else {
					POLE[shipBegin] = 'T';
					printf("Вы поставили начальную точку корабля на клетку %c%c. Введите конечную точку корабля.\n", stolbets, stroka);
					poleVyvod(POLE); delay(1000);
					printf("Учтите, что корабли не могут пересекаться, а также сейчас ваш корабль должен иметь длину 2: ");
					scanf("\n%c%c", &stolbets, &stroka);
					if (charToInt(stolbets) == -1) {
						printf("Вы ввели неверную букву.\n"); delay(2000);
						printf("Убедитесь, что вы вводите английские буквы из тех, что расположены над первой строкой поля, и попробуйте ещё раз.\n"); delay(2000);
						POLE[shipBegin] = '0';
					}
					else {
						shipEnd = (stroka - '0') * 10 + charToInt(stolbets);
						if (ifShipPossible(shipBegin, shipEnd, shipSize, ban) == 0) {
							printf("Вы сделали что-то не так. Попробуйте ещё раз.\n\n"); delay(2000);
							POLE[shipBegin] = '0';
						}
						else if (ifShipPossible(shipBegin, shipEnd, shipSize, ban) == 3) {
							printf("Корабли пересекаются! Попробуйте ещё раз.\n\n"); delay(2000);
							POLE[shipBegin] = '0';
						}
						else if (ifShipPossible(shipBegin, shipEnd, shipSize, ban) == 1) {
							if (shipBegin < shipEnd) { i = shipEnd; shipEnd = shipBegin; shipBegin = i; }
							for (i = shipEnd; i <= shipBegin; i++) {
								POLE[i] = 'T';
								ban[i] = shipSize;
								if (i >= 10) { ban[i - 10] = shipSize; }
								if (i <= 89) { ban[i + 10] = shipSize; }
							}
							if (shipEnd % 10 >= 1) {
								ban[shipEnd - 1] = shipSize;
								if (shipEnd >= 10) { ban[shipEnd - 11] = shipSize; }
								if (shipEnd <= 89) { ban[shipEnd + 9] = shipSize; }
							}
							if (shipBegin % 10 <= 8) {
								ban[shipBegin + 1] = shipSize;
								if (shipBegin >= 10) { ban[shipBegin - 9] = shipSize; }
								if (shipBegin <= 89) { ban[shipBegin + 11] = shipSize; }
							}
							count2palub = count2palub - 1;
							printf("Отлично.\n\n"); delay(2000);
						}
						else if (ifShipPossible(shipBegin, shipEnd, shipSize, ban) == 2) {
							if (shipBegin < shipEnd) { i = shipEnd; shipEnd = shipBegin; shipBegin = i; }
							for (i = shipEnd; i <= shipBegin; i = i + 10) {
								POLE[i] = 'T';
								ban[i] = shipSize;
								if (i % 10 >= 1) { ban[i - 1] = shipSize; }
								if (i % 10 <= 8) { ban[i + 1] = shipSize; }
							}
							if (shipEnd >= 10) {
								ban[shipEnd - 10] = shipSize;
								if (shipEnd % 10 >= 1) { ban[shipEnd - 11] = shipSize; }
								if (shipEnd % 10 <= 8) { ban[shipEnd - 9] = shipSize; }
							}
							if (shipBegin <= 89) {
								ban[shipBegin + 10] = shipSize;
								if (shipBegin % 10 >= 1) { ban[shipBegin + 9] = shipSize; }
								if (shipBegin % 10 <= 8) { ban[shipBegin + 11] = shipSize; }
							}
							count2palub = count2palub - 1;
							printf("Отлично.\n\n"); delay(2000);
						}
					}
					if (count2palub == 0) { shipSize = shipSize - 1; }
				}
			}; break;
		case 1: printf("Вам осталось поставить %i однопалубных корабля\n", count1palub); delay(1000);
			poleVyvod(POLE);
			printf("Введите номер клетки начала корабля: ");
			scanf("\n%c%c", &stolbets, &stroka);
			if (charToInt(stolbets) == -1) {
				printf("Вы ввели неверную букву.\n"); delay(2000);
				printf("Убедитесь, что вы вводите английские буквы из тех, что расположены над первой строкой поля, и попробуйте ещё раз.\n"); delay(2000);
			}
			else {
				shipBegin = (stroka - '0') * 10 + charToInt(stolbets);
				if (ban[shipBegin] != 0) { printf("Корабли пересекаются! Попробуйте ещё раз.\n\n"); delay(2000); }
				else {
					POLE[shipBegin] = 'T';
					shipEnd = shipBegin;
					if (ifShipPossible(shipBegin, shipEnd, shipSize, ban) == 0) {
						printf("Вы сделали что-то не так. Попробуйте ещё раз.\n\n"); delay(2000);
						POLE[shipBegin] = '0';
					}
					else if (ifShipPossible(shipBegin, shipEnd, shipSize, ban) == 3) {
						printf("Корабли пересекаются! Попробуйте ещё раз.\n\n"); delay(2000);
						POLE[shipBegin] = '0';
					}
					else if (ifShipPossible(shipBegin, shipEnd, shipSize, ban) == 1) {
						if (shipBegin < shipEnd) { i = shipEnd; shipEnd = shipBegin; shipBegin = i; }
						for (i = shipEnd; i <= shipBegin; i++) {
							POLE[i] = 'T';
							ban[i] = shipSize;
							if (i >= 10) { ban[i - 10] = shipSize; }
							if (i <= 89) { ban[i + 10] = shipSize; }
						}
						if (shipEnd % 10 >= 1) {
							ban[shipEnd - 1] = shipSize;
							if (shipEnd >= 10) { ban[shipEnd - 11] = shipSize; }
							if (shipEnd <= 89) { ban[shipEnd + 9] = shipSize; }
						}
						if (shipBegin % 10 <= 8) {
							ban[shipBegin + 1] = shipSize;
							if (shipBegin >= 10) { ban[shipBegin - 9] = shipSize; }
							if (shipBegin <= 89) { ban[shipBegin + 11] = shipSize; }
						}
						count1palub = count1palub - 1;
						printf("Отлично.\n\n"); delay(2000);
					}
					else if (ifShipPossible(shipBegin, shipEnd, shipSize, ban) == 2) {
						if (shipBegin < shipEnd) { i = shipEnd; shipEnd = shipBegin; shipBegin = i; }
						for (i = shipEnd; i <= shipBegin; i = i + 10) {
							POLE[i] = 'T';
							ban[i] = shipSize;
							if (i % 10 >= 1) { ban[i - 1] = shipSize; }
							if (i % 10 <= 8) { ban[i + 1] = shipSize; }
						}
						if (shipEnd >= 10) {
							ban[shipEnd - 10] = shipSize;
							if (shipEnd % 10 >= 1) { ban[shipEnd - 11] = shipSize; }
							if (shipEnd % 10 <= 8) { ban[shipEnd - 9] = shipSize; }
						}
						if (shipBegin <= 89) {
							ban[shipBegin + 10] = shipSize;
							if (shipBegin % 10 >= 1) { ban[shipBegin + 9] = shipSize; }
							if (shipBegin % 10 <= 8) { ban[shipBegin + 11] = shipSize; }
						}
						count1palub = count1palub - 1;
						printf("Отлично.\n\n"); delay(2000);
					}
				}
				if (count1palub == 0) { shipSize = shipSize - 1; }
			};
		}
	}
	poleVyvod(POLE);
	count4palub = 1;
	count3palub = 2;
	count2palub = 3;
	count1palub = 4;
	shipSize = 4;
	while (count1palub != 0) {
		switch (shipSize) {
		case 4: shipBegin = rand() % 100;
			if (ban2[shipBegin] == 0) {
				i = rand() % 4;
				switch (i) {
				case 0:
					if (shipBegin - (shipSize - 1) >= 0) { shipEnd = shipBegin - (shipSize - 1); }
					else { shipEnd = shipBegin; }
					break;
				case 1:
					if (shipBegin + (shipSize - 1) <= 99) { shipEnd = shipBegin + (shipSize - 1); }
					else { shipEnd = shipBegin; }
					break;
				case 2:
					if (shipBegin - (shipSize - 1) * 10 >= 0) { shipEnd = shipBegin - (shipSize - 1) * 10; }
					else { shipEnd = shipBegin; }
					break;
				case 3:
					if (shipBegin + (shipSize - 1) * 10 <= 99) { shipEnd = shipBegin + (shipSize - 1) * 10; }
					else { shipEnd = shipBegin; }
				}
				if (ifShipPossible(shipBegin, shipEnd, shipSize, ban2) == 1) {
					if (shipBegin < shipEnd) { i = shipEnd; shipEnd = shipBegin; shipBegin = i; }
					for (i = shipEnd; i <= shipBegin; i++) {
						POLE2[i] = 'T';
						ban2[i] = shipSize;
						if (i >= 10) { ban2[i - 10] = shipSize; }
						if (i <= 89) { ban2[i + 10] = shipSize; }
					}
					if (shipEnd % 10 >= 1) {
						ban2[shipEnd - 1] = shipSize;
						if (shipEnd >= 10) { ban2[shipEnd - 11] = shipSize; }
						if (shipEnd <= 89) { ban2[shipEnd + 9] = shipSize; }
					}
					if (shipBegin % 10 <= 8) {
						ban2[shipBegin + 1] = shipSize;
						if (shipBegin >= 10) { ban2[shipBegin - 9] = shipSize; }
						if (shipBegin <= 89) { ban2[shipBegin + 11] = shipSize; }
					}
					count4palub = count4palub - 1;
				}
				else if (ifShipPossible(shipBegin, shipEnd, shipSize, ban2) == 2) {
					if (shipBegin < shipEnd) { i = shipEnd; shipEnd = shipBegin; shipBegin = i; }
					for (i = shipEnd; i <= shipBegin; i = i + 10) {
						POLE2[i] = 'T';
						ban2[i] = shipSize;
						if (i % 10 >= 1) { ban2[i - 1] = shipSize; }
						if (i % 10 <= 8) { ban2[i + 1] = shipSize; }
					}
					if (shipEnd >= 10) {
						ban2[shipEnd - 10] = shipSize;
						if (shipEnd % 10 >= 1) { ban2[shipEnd - 11] = shipSize; }
						if (shipEnd % 10 <= 8) { ban2[shipEnd - 9] = shipSize; }
					}
					if (shipBegin <= 89) {
						ban2[shipBegin + 10] = shipSize;
						if (shipBegin % 10 >= 1) { ban2[shipBegin + 9] = shipSize; }
						if (shipBegin % 10 <= 8) { ban2[shipBegin + 11] = shipSize; }
					}
					count4palub = count4palub - 1;
				}
			}
			if (count4palub == 0) { shipSize = shipSize - 1; }
			break;
		case 3: shipBegin = rand() % 100;
			if (ban2[shipBegin] == 0) {
				i = rand() % 4;
				switch (i) {
				case 0:
					if (shipBegin - (shipSize - 1) >= 0) { shipEnd = shipBegin - (shipSize - 1); }
					else { shipEnd = shipBegin; }
					break;
				case 1:
					if (shipBegin + (shipSize - 1) <= 99) { shipEnd = shipBegin + (shipSize - 1); }
					else { shipEnd = shipBegin; }
					break;
				case 2:
					if (shipBegin - (shipSize - 1) * 10 >= 0) { shipEnd = shipBegin - (shipSize - 1) * 10; }
					else { shipEnd = shipBegin; }
					break;
				case 3:
					if (shipBegin + (shipSize - 1) * 10 <= 99) { shipEnd = shipBegin + (shipSize - 1) * 10; }
					else { shipEnd = shipBegin; }
				}
				if (ifShipPossible(shipBegin, shipEnd, shipSize, ban2) == 1) {
					if (shipBegin < shipEnd) { i = shipEnd; shipEnd = shipBegin; shipBegin = i; }
					for (i = shipEnd; i <= shipBegin; i++) {
						POLE2[i] = 'T';
						ban2[i] = shipSize;
						if (i >= 10) { ban2[i - 10] = shipSize; }
						if (i <= 89) { ban2[i + 10] = shipSize; }
					}
					if (shipEnd % 10 >= 1) {
						ban2[shipEnd - 1] = shipSize;
						if (shipEnd >= 10) { ban2[shipEnd - 11] = shipSize; }
						if (shipEnd <= 89) { ban2[shipEnd + 9] = shipSize; }
					}
					if (shipBegin % 10 <= 8) {
						ban2[shipBegin + 1] = shipSize;
						if (shipBegin >= 10) { ban2[shipBegin - 9] = shipSize; }
						if (shipBegin <= 89) { ban2[shipBegin + 11] = shipSize; }
					}
					count3palub = count3palub - 1;
				}
				else if (ifShipPossible(shipBegin, shipEnd, shipSize, ban2) == 2) {
					if (shipBegin < shipEnd) { i = shipEnd; shipEnd = shipBegin; shipBegin = i; }
					for (i = shipEnd; i <= shipBegin; i = i + 10) {
						POLE2[i] = 'T';
						ban2[i] = shipSize;
						if (i % 10 >= 1) { ban2[i - 1] = shipSize; }
						if (i % 10 <= 8) { ban2[i + 1] = shipSize; }
					}
					if (shipEnd >= 10) {
						ban2[shipEnd - 10] = shipSize;
						if (shipEnd % 10 >= 1) { ban2[shipEnd - 11] = shipSize; }
						if (shipEnd % 10 <= 8) { ban2[shipEnd - 9] = shipSize; }
					}
					if (shipBegin <= 89) {
						ban2[shipBegin + 10] = shipSize;
						if (shipBegin % 10 >= 1) { ban2[shipBegin + 9] = shipSize; }
						if (shipBegin % 10 <= 8) { ban2[shipBegin + 11] = shipSize; }
					}
					count3palub = count3palub - 1;
				}
			}
			if (count3palub == 0) { shipSize = shipSize - 1; }
			break;
		case 2: shipBegin = rand() % 100;
			if (ban2[shipBegin] == 0) {
				i = rand() % 4;
				switch (i) {
				case 0:
					if (shipBegin - (shipSize - 1) >= 0) { shipEnd = shipBegin - (shipSize - 1); }
					else { shipEnd = shipBegin; }
					break;
				case 1:
					if (shipBegin + (shipSize - 1) <= 99) { shipEnd = shipBegin + (shipSize - 1); }
					else { shipEnd = shipBegin; }
					break;
				case 2:
					if (shipBegin - (shipSize - 1) * 10 >= 0) { shipEnd = shipBegin - (shipSize - 1) * 10; }
					else { shipEnd = shipBegin; }
					break;
				case 3:
					if (shipBegin + (shipSize - 1) * 10 <= 99) { shipEnd = shipBegin + (shipSize - 1) * 10; }
					else { shipEnd = shipBegin; }
				}
				if (ifShipPossible(shipBegin, shipEnd, shipSize, ban2) == 1) {
					if (shipBegin < shipEnd) { i = shipEnd; shipEnd = shipBegin; shipBegin = i; }
					for (i = shipEnd; i <= shipBegin; i++) {
						POLE2[i] = 'T';
						ban2[i] = shipSize;
						if (i >= 10) { ban2[i - 10] = shipSize; }
						if (i <= 89) { ban2[i + 10] = shipSize; }
					}
					if (shipEnd % 10 >= 1) {
						ban2[shipEnd - 1] = shipSize;
						if (shipEnd >= 10) { ban2[shipEnd - 11] = shipSize; }
						if (shipEnd <= 89) { ban2[shipEnd + 9] = shipSize; }
					}
					if (shipBegin % 10 <= 8) {
						ban2[shipBegin + 1] = shipSize;
						if (shipBegin >= 10) { ban2[shipBegin - 9] = shipSize; }
						if (shipBegin <= 89) { ban2[shipBegin + 11] = shipSize; }
					}
					count2palub = count2palub - 1;
				}
				else if (ifShipPossible(shipBegin, shipEnd, shipSize, ban2) == 2) {
					if (shipBegin < shipEnd) { i = shipEnd; shipEnd = shipBegin; shipBegin = i; }
					for (i = shipEnd; i <= shipBegin; i = i + 10) {
						POLE2[i] = 'T';
						ban2[i] = shipSize;
						if (i % 10 >= 1) { ban2[i - 1] = shipSize; }
						if (i % 10 <= 8) { ban2[i + 1] = shipSize; }
					}
					if (shipEnd >= 10) {
						ban2[shipEnd - 10] = shipSize;
						if (shipEnd % 10 >= 1) { ban2[shipEnd - 11] = shipSize; }
						if (shipEnd % 10 <= 8) { ban2[shipEnd - 9] = shipSize; }
					}
					if (shipBegin <= 89) {
						ban2[shipBegin + 10] = shipSize;
						if (shipBegin % 10 >= 1) { ban2[shipBegin + 9] = shipSize; }
						if (shipBegin % 10 <= 8) { ban2[shipBegin + 11] = shipSize; }
					}
					count2palub = count2palub - 1;
				}
			}
			if (count2palub == 0) { shipSize = shipSize - 1; }
			break;
		case 1:shipBegin = rand() % 100;
			if (ban2[shipBegin] == 0) {
				POLE2[shipBegin] = 'T';
				ban2[shipBegin] = shipSize;
				if (shipBegin >= 10) { ban2[shipBegin - 10] = shipSize; }
				if (shipBegin <= 89) { ban2[shipBegin + 10] = shipSize; }
				if (shipBegin % 10 >= 1) {
					ban2[shipBegin - 1] = shipSize;
					if (shipBegin >= 10) { ban2[shipBegin - 11] = shipSize; }
					if (shipBegin <= 89) { ban2[shipBegin + 9] = shipSize; }
				}
				if (shipBegin % 10 <= 8) {
					ban2[shipBegin + 1] = shipSize;
					if (shipBegin >= 10) { ban2[shipBegin - 9] = shipSize; }
					if (shipBegin <= 89) { ban2[shipBegin + 11] = shipSize; }
				}
				count1palub = count1palub - 1;
			}
			if (count1palub == 0) { shipSize = shipSize - 1; }
		}
	}
	count4palub = 1;
	count3palub = 2;
	count2palub = 3;
	count1palub = 4;
	printf("Поздравляю. Вы расставили корабли!\n"); delay(2000);
	printf("Теперь начинается морской бой!\n"); delay(2000);
	printf("Вы делаете первый выстрел.\n"); delay(2000);
	printf("Для этого вам необходимо выбрать клетку на поле противника, куда вы хотите выстрелить.\n"); delay(2000);
	printf("Помните, что ваша основная задача - уничтожить все корабли противника.\n"); delay(2000);
	while ((count4palub + count3palub + count2palub + count1palub != 0) && (myShip != 0)) {
		if (doubleMove2 == 0) {
			printf("У противника осталось:\n"); delay(1000);
			printf("%i четырёхпалубных кораблей\n", count4palub); delay(500);
			printf("%i трёхпалубных кораблей\n", count3palub); delay(500);
			printf("%i двухпалубных кораблей\n", count2palub); delay(500);
			printf("%i однопалубных кораблей\n", count1palub); delay(500);
			poleVyvod(pole2secret); delay(1000);
			printf("Введите номер клетки в том же формате: ");
			scanf("\n%c%c", &stolbets, &stroka);
			if (charToInt(stolbets) == -1) {
				printf("Вы ввели неверную букву.\n"); delay(2000);
				printf("Убедитесь, что вы вводите английские буквы из тех, что расположены над первой строкой поля, и попробуйте ещё раз.\n"); delay(2000);
			}
			else {
				shipBegin = (stroka - '0') * 10 + charToInt(stolbets);
				if (pole2secret[shipBegin] != '0') {
					printf("Вы уже стреляли в эту клетку. Попробуйте ещё раз.\n"); delay(500);
					doubleMove1 = 1;
				}
				else if (POLE2[shipBegin] == '0') {
					printf("Промах!\n"); delay(2000);
					pole2secret[shipBegin] = 'X';
					doubleMove1 = 0;
				}
				else if (POLE2[shipBegin] == 'T') {
					if (ban2[shipBegin] == 1) {
						pole2secret[shipBegin] = '#';
						printf("\nВы уничтожили корабль!\n"); delay(2000);
						doubleMove1 = 1;
						count1palub = count1palub - 1;
					}
					else if (ban2[shipBegin] == 2) {
						if (ifKilled(shipBegin, 2, 'T', pole2secret) == 1000) {
							pole2secret[shipBegin] = 'T';
							printf("\nПопадание!\n"); delay(2000);
							doubleMove1 = 1;
						}
						else if (ifKilled(shipBegin, 2, 'T', pole2secret) >= 0) {
							printf("\nВы уничтожили корабль!\n"); delay(2000);
							i = ifKilled(shipBegin, 2, 'T', pole2secret);
							pole2secret[i] = '#';
							pole2secret[i + 1] = '#';
							doubleMove1 = 1;
							count2palub = count2palub - 1;
						}
						else if (ifKilled(shipBegin, 2, 'T', pole2secret) < 0) {
							if (ifKilled(shipBegin, 2, 'T', pole2secret) == -1000) {
								printf("\nВы уничтожили корабль!\n"); delay(2000);
								pole2secret[0] = '#';
								pole2secret[10] = '#';
								doubleMove1 = 1;
								count2palub = count2palub - 1;
							}
							else {
								printf("\nВы уничтожили корабль!\n"); delay(2000);
								i = ifKilled(shipBegin, 2, 'T', pole2secret);
								pole2secret[-i] = '#';
								pole2secret[-i + 10] = '#';
								doubleMove1 = 1;
								count2palub = count2palub - 1;
							}
						}
					}
					else if (ban2[shipBegin] == 3) {
						if (ifKilled(shipBegin, 3, 'T', pole2secret) == 1000) {
							pole2secret[shipBegin] = 'T';
							printf("\nПопадание!\n"); delay(2000);
							doubleMove1 = 1;
						}
						else if (ifKilled(shipBegin, 3, 'T', pole2secret) >= 0) {
							printf("\nВы уничтожили корабль!\n"); delay(2000);
							i = ifKilled(shipBegin, 3, 'T', pole2secret);
							pole2secret[i] = '#';
							pole2secret[i + 1] = '#';
							pole2secret[i + 2] = '#';
							doubleMove1 = 1;
							count3palub = count3palub - 1;
						}
						else if (ifKilled(shipBegin, 3, 'T', pole2secret) < 0) {
							if (ifKilled(shipBegin, 3, 'T', pole2secret) == -1000) {
								printf("\nВы уничтожили корабль!\n"); delay(2000);
								pole2secret[0] = '#';
								pole2secret[10] = '#';
								pole2secret[20] = '#';
								doubleMove1 = 1;
								count3palub = count3palub - 1;
							}
							else {
								printf("\nВы уничтожили корабль!\n"); delay(2000);
								i = ifKilled(shipBegin, 3, 'T', pole2secret);
								pole2secret[-i] = '#';
								pole2secret[-i + 10] = '#';
								pole2secret[-i + 20] = '#';
								doubleMove1 = 1;
								count3palub = count3palub - 1;
							}
						}
					}
					else if (ban2[shipBegin] == 4) {
						if (ifKilled(shipBegin, 4, 'T', pole2secret) == 1000) {
							pole2secret[shipBegin] = 'T';
							printf("\nПопадание!\n"); delay(2000);
							doubleMove1 = 1;
						}
						else if (ifKilled(shipBegin, 4, 'T', pole2secret) >= 0) {
							printf("\nВы уничтожили корабль!\n"); delay(2000);
							i = ifKilled(shipBegin, 4, 'T', pole2secret);
							pole2secret[i] = '#';
							pole2secret[i + 1] = '#';
							pole2secret[i + 2] = '#';
							pole2secret[i + 3] = '#';
							doubleMove1 = 1;
							count4palub = count4palub - 1;
						}
						else if (ifKilled(shipBegin, 4, 'T', pole2secret) < 0) {
							if (ifKilled(shipBegin, 4, 'T', pole2secret) == -1000) {
								printf("\nВы уничтожили корабль!\n"); delay(2000);
								pole2secret[0] = '#';
								pole2secret[10] = '#';
								pole2secret[20] = '#';
								pole2secret[30] = '#';
								doubleMove1 = 1;
								count4palub = count4palub - 1;
							}
							else {
								printf("\nВы уничтожили корабль!\n"); delay(2000);
								i = ifKilled(shipBegin, 4, 'T', pole2secret);
								pole2secret[-i] = '#';
								pole2secret[-i + 10] = '#';
								pole2secret[-i + 20] = '#';
								pole2secret[-i + 30] = '#';
								doubleMove1 = 1;
								count4palub = count4palub - 1;
							}
						}
					}
				}
			}
		}
		if (doubleMove1 == 0) {
			if (close != -1) {
				if (close % 10 <= 8) {
					if ((POLE[close + 1] == '0') || (POLE[close + 1] == 'T')) {
						shipBegin = close + 1;
						newShot = 1;
					}
				}
				if ((newShot == 0) && (close <= 89)) {
					if ((POLE[close + 10] == '0') || (POLE[close + 10] == 'T')) {
						shipBegin = close + 10;
						newShot = 1;
					}
				}
				if ((newShot == 0) && (close % 10 >= 1)) {
					if ((POLE[close - 1] == '0') || (POLE[close - 1] == 'T')) {
						shipBegin = close - 1;
						newShot = 1;
					}
				}
				if ((newShot == 0) && (close >= 10)) {
					if ((POLE[close - 10] == '0') || (POLE[close - 10] == 'T')) {
						shipBegin = close - 10;
						newShot = 1;
					}
				}
				else { close = -1; }
			}
			else { shipBegin = rand() % 100; }
			if ((POLE[shipBegin] == 'X') || (POLE[shipBegin] == '#')) {
				doubleMove2 = 1;
				newShot = 0;
			}
			else if (POLE[shipBegin] == '0') {
				stolbets = intToChar(shipBegin % 10);
				printf("Соперник стреляет в клетку %c%i и промахивается.\n", stolbets, shipBegin / 10); delay(2000);
				POLE[shipBegin] = 'X';
				doubleMove2 = 0;
				poleVyvod(POLE);
				newShot = 0;
			}
			else if (POLE[shipBegin] == 'T') {
				if (ifKilled(shipBegin, ban[shipBegin], '#', POLE) == 1000) {
					stolbets = intToChar(shipBegin % 10);
					POLE[shipBegin] = '#';
					close = shipBegin;
					printf("Соперник стреляет в клетку %c%i и попадает!\n", stolbets, shipBegin / 10); delay(2000);
					poleVyvod(POLE);
					newShot = 0;
					doubleMove2 = 1;
				}
				if (ifKilled(shipBegin, ban[shipBegin], '#', POLE) != 1000) {
					stolbets = intToChar(shipBegin % 10);
					POLE[shipBegin] = '#';
					printf("Соперник стреляет в клетку %c%i и уничтожает корабль!\n", stolbets, shipBegin / 10); delay(2000);
					poleVyvod(POLE);
					close = -1;
					newShot = 0;
					doubleMove2 = 1;
					myShip = myShip - 1;
				}
			}
		}
	}
	if (count4palub + count3palub + count2palub + count1palub == 0) {
		printf("\nПоздравляю!\n"); delay(2000);
		printf("Вы победили!\n"); delay(2000);
		printf("Спасибо за игру.\n"); delay(2000);
		printf("\nАвтор: GreenPotatoShow\n"); delay(2000);
	}
	if (myShip != 0) {
		printf("\nК сожалению, вы проиграли.\n"); delay(2000);
		printf("Не расстраивайтесь, попробуйте сыграть ещё раз.\n"); delay(2000);
		printf("В любом случае, спасибо за игру!\n"); delay(2000);
		printf("\nАвтор: GreenPotatoShow\n"); delay(2000);
	}
	return 0;
}
