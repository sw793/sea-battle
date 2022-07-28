

// beta


#include <iostream>
using namespace std;
int main() {
	int player; // какой игрок
	int x; // координата икс
	int y; // координата игрик
	int sum0 = 0; // сумма очков первого игрока
	int sum1 = 0; // сумма очков второго игрока
	cout << endl << endl << "Do you want play with human (1) or robot (2)?" << endl;
	cin >> player;

	if (player == 1){
		system("clear");
		int Number_Of_Cells[2] = {0, 0}; //кол-во ячеек, занятых кораблями игроков
		int field[2][10][10]; // массив с игровыми полями

		//Расстановка кораблей игроками
		for (int human = 0; human < 2; human++) {
			/*cout << "Стоит напомнить, что на поле размещаются:" << endl << 
					"1 корабль — ряд из 4 клеток («четырёхпалубный»)"<< endl <<
					"2 корабля — ряд из 3 клеток («трёхпалубные»)" << endl <<
					"3 корабля — ряд из 2 клеток («двухпалубные»; эсминцы)" << endl <<
					"4 корабля — 1 клетка («однопалубные»; торпедные катера)" << endl << endl;*/
			if (human == 0) cout << "First player is seting ships:" << endl;
			else cout << "Second player is seting ships:" << endl;
			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++){
					cin >> field[human][i][j];
					if (field[human][i][j] == 1) Number_Of_Cells[human]++;
				}
			if (Number_Of_Cells[human] != 20){
				do{
					Number_Of_Cells[human] = 0;
					cout << endl << endl << "You do not set all ships. Try again:" << "     " << endl;
					for (int i = 0; i < 10; i++){
						for (int j = 0; j < 10; j++){
							cin >> field[human][i][j];
							if (field[human][i][j] == 1) Number_Of_Cells[human]++;
						}
					}
				}while (Number_Of_Cells[human] != 20);
			}
		}

		//процесс игры
		do {
			system("clear");
			int human; // игрок
			
			//первый игрок
			for (int human = 0; human < 2; human++) {
				do {
					//вывод поля
					for (int i = -1; i < 10; i++) {
						if (i == -1) cout << "";
						else cout << i;
						for (int j = -1; j < 10; j++) {
							if (i == -1) {
								if (j != -1) cout << j << " ";
								else cout << "  ";
							}
							if ((i != -1) && (j != -1)) {
								if ((field[human][i][j] == 0)  (field[human][i][j] == 1)) cout << "  ";
								if (field[human][i][j] == 2) cout << " +";
								if (field[human][i][j] == 3) cout << " .";
							}
						}
						cout << endl;
					}

					if (human == 0) cout << "First player's move': " << endl;
					else cout << "Second player's move': " << endl;
					cin >> x >> y; // x - столбик, y - строчка
					if ((field[human][y][x] == 2)  (field[human][y][x] == 3)) {
						system("clear");
						cout << "You have alredy shut this cordinats, try difirent place ;-)" << endl;
					}
					if (field[human][y][x] == 0) field[human][y][x] = 3;
					if (field[human][y][x] == 1) {
						system("clear");
						cout << "wounded (podbit)" << endl;
						Number_Of_Cells[human]--;
						field[human][y][x] = 2;
					}

				} while (field[human][y][x] != 3);
			}
		} while((Number_Of_Cells[0] != 0) || (Number_Of_Cells[1] != 0));
	}

	if (player == 2){
		/*cout << "Выберите уровень сложности компьютера:" << endl;
		cout << "1 — Легкий. Каждый раз бьет в случайную клетку" << endl; 
		cout << "2 — нормальный. После попадания бьет в соседнюю точку по горизонтали или вертикали" << endl;
		cout << "3 — Сложный. Добивает без промахов корабль, в который попал" << endl;*/
		cout << "beta test";
		cin >> player;
		if (player == 3){
			cout << "Good luck.";
		}
	}
	return 0;
}
