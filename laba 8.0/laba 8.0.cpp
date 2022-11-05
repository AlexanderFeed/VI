
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
    int n, m;
    string A[100][100];
	string q;
	cout << "Число субъектов" << endl;
	cin >> n;
	cout << "Число объектов" << endl;
	cin >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
		}
	}

	cout << "Вывод матрицы A" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}
	int a;
	while (true) {
		cout << "Выберите операцию: " << endl << "1) Редактирование" << endl << "2) Добавление" << endl << "3) Удаление" << endl << "4) Процент заполненности" << endl << "5) Список субъектов к одному объекту" << endl << "6) Вывод матрицы" << endl;
		cin >> a;
		switch (a) {
		case(1):
			cout << "Введите номер субъекта и объекта." << endl;
			int s, d;
			cin >> s >> d;
			cout << "Какое право доступа ставим?" << endl;
			cin >> q;
			A[s][d] = q;
			break;
		case(2):
			cout << "Имеем матрицу 100 на 100." << endl << "Какую ячейку добавляем?" << endl;
			int t, y;
			cin >> t >> y;
			cout << "Роль?"<< endl;
			cin >> q;
			A[t][y] = q;
			break;
		case(3):
			cout << "Введите номер субъекта и объекта." << endl;
			int i, j;
			cin >> i >> j;
			A[i][j] = ' ';
			break;
		case(4):
			int g;
			g = 0;
			for (int i = 0; i < 100; i++) {
				for (int j = 0; j < 100; j++) {
					if (A[i][j] == "R" || A[i][j] == "W" || A[i][j] == "RW") g++;
				}
			}
			cout << g << " процента." << endl;
			break;
		case(5):
			cout << "Введите номер объекта."<< endl;
			cin >> i;
			g = 0;
			for (int j = 0; j < 100; j++) {
				if (A[i][j] == "R" || A[i][j] == "W" || A[i][j] == "RW") cout << i<<" "<< j<<" "<< A[i][j] << endl;
			}
			break;
		case(6):
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << A[i][j] << ' ';
				}
				cout << endl;
			}
			break;
		}
	}
}

