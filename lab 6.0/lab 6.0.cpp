#include <iostream>   
#include <vector>  
#include <string>
#include <ctime>
using namespace std;

string getRandomRule()
{
	if (rand() % 2 == 0)
		return "R";
	else
		return "W";
}


int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(0));
	int n, m;
	cout << "Число субъектов" << endl;
	cin >> n;
	cout << "Число объектов" << endl;
	cin >> m;

	vector <vector<string>> A(n, vector<string>(m));
	vector <int> LS(n);
	vector <int> LO(m);

	cout << "A:" << endl;
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

	cout << "LS" << endl;
	for (int i = 0; i < n; i++) {
		cin >> LS[i];
		cout << LS[i] << " ";
	}
	cout << endl;

	cout << "LO" << endl;
	for (int i = 0; i < m; i++) {
			cin >> LO[i];
		cout << LO[i] << " ";
	}
	cout << endl;

	bool isSecretNornal = true;
	bool prich = true;
	int LLS, LLO, BO, ii, jj;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//not write down                         
			if ((LS[i] < LO[j] && A[i][j] == "W")) {
				isSecretNornal = false;
				prich = true;
				LLS = LS[i];
				LLO = LO[i];
				ii = i;
				jj = j;
				break;
				goto m;
			}
			// not read up
			else if (LS[i] > LO[j] && A[i][j] == "R") {
				isSecretNornal = false;
				prich = false;
				LLS = LS[i];
				LLO = LO[i];
				ii = i;
				jj = j;
				goto m;
			}
			}
		}
	m:
	cout << "Критерию безопасности Белла - Лападулы";
	if (isSecretNornal) {
		cout << " есть" << endl;
	}
	else {
		if (prich == true) {
			cout << " не быть" << endl;
			cout << "Значение уровня допуска: " << LLS+1 << endl<< " Ошибка чтения. Значение уровня секретности: " << LLO+1 << endl << "Ошибка в ячейке: " << ii+1 << " " << jj+1 << endl << "Ошибка редактирования.";
		}
		else
		{
			cout << " быть" << endl;
			cout << "Значение уровня допуска : " << LLS+1 << endl<< "Ошибка чтения.Значение уровня секретности : " << LLO+1 << endl << "Ошибка в ячейке : " << ii+1 << " " << jj+1 << endl << "Ошибка чтения.";
		}
	}
}