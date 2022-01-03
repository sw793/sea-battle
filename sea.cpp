#include <iostream>
using namespace std;
int main() {
	int player; 
	int x; 
	int y;
	int sum0 = 0; 
	int sum1 = 0; 
	int k;
	cout << "⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣴⠾⠿⣶⣄⠄⠄⠄⠄⠄⠄⠄⠄⠄" << endl << "⠄⠄⠄⠄⠄⠄⠄⠄⠄⣿⡇⠄⠄⠈⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄" << endl 
		 << "⠄⠄⠄⠄⠄⠄⠄⠄⠄⠙⣷⣤⣤⣾⠟⠄⠄⠄⠄⠄⠄⠄⠄⠄" << endl << "⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣿⣿⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄" << endl 
		 << "⠄⠄⠄⠄⠄⠈⠉⠉⠉⠉⢹⣿⣿⡏⠉⠉⠉⠉⠁⠄⠄⠄⠄⠄" << endl << "⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢸⣿⣿⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄" << endl 
		 << "⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢸⣿⣿⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄" << endl << "⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢸⣿⣿⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄" << endl 
		 << "⠄⢠⣧⠄⠄⠄⠄⠄⠄⠄⢸⣿⣿⡇⠄⠄⠄⠄⠄⠄⠄⢠⣷⡀" << endl << "⢠⣿⣿⣧⠄⠄⠄⠄⠄⠄⢸⣿⣿⡇⠄⠄⠄⠄⠄⠄⣠⣿⣿⣇" << endl 
		 << "⣸⢿⣿⣏⠁⠄⠄⠄⠄⠄⣼⣿⣿⣧⠄⠄⠄⠄⠄⠘⢻⣿⡿⣿" << endl << "⠄⠄⢻⣿⣦⣀⠄⠄⢀⣰⣿⣿⣿⣿⣄⠄⠄⠄⢀⣴⣿⣿⠄⠄" << endl 
		 << "⠄⠄⠄⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠄⠄" << endl << "⠄⠄⠄⠄⠄⠙⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠋⠄⠄⠄⠄" << endl 
		 << "⠄⠄⠄⠄⠄⠄⠄⠄⠉⠙⠿⣿⣿⡿⠟⠉⠁⠄⠄⠄⠄⠄⠄⠄" << endl << "⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠙⠟⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄";

	cout << endl << endl << "С кем вы хотите играть? С человеком (1) или машиной (2)?" << endl;
	cin >> player;

	if(player == 1){
		


		system("clear");
		int Number_Of_Cells_0 = 0; //количество ячеек, занятых кораблями игрока
		int Number_Of_Cells_1 = 0;
		int arr[2][10][10];

		//Расстановка кораблей игроками
		for (int human = 0; human < 2; human++) {
			
			//первый игрок
			if (human == 0) {
				cout << "Стоит напомнить, что на поле размещаются:" << endl << 
						"1 корабль — ряд из 4 клеток («четырёхпалубный»)"<< endl <<
						"2 корабля — ряд из 3 клеток («трёхпалубные»)" << endl <<
						"3 корабля — ряд из 2 клеток («двухпалубные»; эсминцы)" << endl <<
						"4 корабля — 1 клетка («однопалубные»; торпедные катера)" << endl << endl;
				cout << "Корабли расставляет первый игрок:" << endl;
				for (int i = 0; i < 10; i++){
					for (int j = 0; j < 10; j++){
						cin >> arr[human][i][j];
						if ((human == 0) && (arr[human][i][j] == 1)) Number_Of_Cells_0++;
						if ((human == 1) && (arr[human][i][j] == 1)) Number_Of_Cells_1++;
					}
				}
				if (Number_Of_Cells_0 != 20){
					do{
						Number_Of_Cells_0 = 0;
						cout << endl << endl << "Вы поставили не всё или ваши корабли пересекаются, попробуйте еще:" << "     " << human << endl;
						for (int i = 0; i < 10; i++){
							for (int j = 0; j < 10; j++){
								cin >> arr[human][i][j];
								if (arr[human][i][j] == 1) Number_Of_Cells_0++;
							}
						}
					}while (Number_Of_Cells_0 != 20);
				}
			}

			//второй игрок
			if (human == 1){
				system("clear");
				cout << "Стоит напомнить, что на поле размещаются:" << endl << 
						"1 корабль — ряд из 4 клеток («четырёхпалубный»)"<< endl <<
						"2 корабля — ряд из 3 клеток («трёхпалубные»)" << endl <<
						"3 корабля — ряд из 2 клеток («двухпалубные»; эсминцы)" << endl <<
						"4 корабля — 1 клетка («однопалубные»; торпедные катера)" << endl << endl;
				cout << "Корабли расставляет второй игрок:" << endl;
				for (int i = 0; i < 10; i++){
					for (int j = 0; j < 10; j++){
						cin >> arr[human][i][j];
						if ((human == 1) && (arr[human][i][j] == 1)) Number_Of_Cells_1++;
					}
				}
				if (Number_Of_Cells_1 != 20){
					do{
						Number_Of_Cells_1 = 0;
						cout << endl << endl << "Вы поставили не всё или ваши корабли пересекаются, попробуйте еще:" << "     " << human << endl;
						for (int i = 0; i < 10; i++){
							for (int j = 0; j < 10; j++){
								cin >> arr[human][i][j];
								if ((human == 1) && (arr[human][i][j] == 1)) Number_Of_Cells_1++;
							}
						}   
					} while (Number_Of_Cells_1 != 20);
				}
			}

		}

		//процесс игры
		do {
			system("clear");
			int we = 0;
			
			//первый игрок
			do {

				//вывод поля
				for (int i = -1; i < 10; i++) {
					if (i == -1)
						cout << "";
					else
						cout << i;
					for (int j = -1; j < 10; j++) {
						if (i == -1) {
							if (j != -1) {
								cout << j << " ";
							} else
								cout << "  ";
						}
						if ((i != -1) && (j != -1)) {
							if ((arr[1][i][j] == 0) || (arr[1][i][j] == 1))
								cout << "  ";
							if (arr[1][i][j] == 2) cout << " +";
							if (arr[1][i][j] == 3) cout << " .";
						}
					}
					cout << endl;
				}

				cout << "Ход первого: " << endl;
				cin >> x >> y; // x - столбик, y - строчка
				if ((arr[1][y][x] == 2) || (arr[1][y][x] == 3)){
					system("clear");
					cout << "Вы уже ходили по этим координатам, приудмайте другие ;-)" << endl; 
				}  
				if (arr[1][y][x] == 0) arr[1][y][x] = 3;
				if (arr[1][y][x] == 1) {
					system("clear");
					cout << "Подбит"<< endl;
					Number_Of_Cells_0--;
					arr[1][y][x] = 2;
				}
				
			} while (arr[1][y][x] != 3);




			//второй
			do {
				system("clear");

				//вывод поля
				for (int i = -1; i < 10; i++) {
					if (i == -1)
						cout << "";
					else
						cout << i;
					for (int j = -1; j < 10; j++) {
						if (i == -1) {
							if (j != -1) {
								cout << j << " ";
							} else
								cout << "  ";
						}
						if ((i != -1) && (j != -1)) {
							if ((arr[0][i][j] == 0) || (arr[0][i][j] == 1))
								cout << "  ";
							if (arr[0][i][j] == 2) cout << " +";
							if (arr[0][i][j] == 3) cout << " .";
						}
					}
					cout << endl;
				}

				cout << "Ход второго: " << endl;
				cin >> x >> y; // x - столбик, y - строчка
				if (arr[0][y][x] == 2) {
					system("clear");
					cout << "Вы уже ходили по этим координатам, приудмайте другие ;-)" << endl;
				}
				if (arr[0][y][x] == 0) arr[0][y][x] = 3;
				if (arr[0][y][x] == 1) {
					system("clear");
					cout << "Подбит"<< endl;
					Number_Of_Cells_0--;
					arr[0][y][x] = 2;
				}
			} while (arr[0][y][x] != 3);

		} while((Number_Of_Cells_0 != 0) || (Number_Of_Cells_1 != 0));
	}

	if (player == 2){
		cout << "Выберите уровень сложности компьютера:" << endl;
		cout << "1 — легкий, бьет в случайную клетку" << endl; 
		cout << "2 — нормальный, после попадания бьет в соседнюю точку по горизонтали или вертикали" << endl;
		cout << "3 — cложный, добивает без промахов корабль, в который попал" << endl;
		cin >> player;
		if (player == 3){
			cout << "Удачи.";
		}
	}
	return 0;
}
