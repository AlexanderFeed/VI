#include <iostream>
using namespace std;

int l = 5;
bool* visited = new bool[l];

void DFS(int st, string **graph)
{
	int r;
	cout << st + 1 << " ";
	visited[st] = true;
	for (r = 0; r <= l; r++)
		if ((graph[st][r] != "") && (!visited[r]))
			DFS(r, graph);
}


int main()
{

	setlocale(LC_ALL, "RUS");
	int n, m;
	string graph[100][100];
	string q;
	cout << "Число субъектов" << endl;
	cin >> n;
	cout << "Число объектов" << endl;
	cin >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	cout << "Вывод матрицы A" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << graph[i][j] << ' ';
		}
		cout << endl;
	}

	int start;
	cout << "Матрица смежности графа: " << endl;
	for (int i = 0; i < l; i++)
	{
		visited[i] = false;
		for (int j = 0; j < l; j++)
			cout << " " << graph[i][j];
		cout << endl;
	}
	cout << "Стартовая вершина >> "; cin >> start;
	//массив посещенных вершин
	bool* vis = new bool[n];
	cout << "Порядок обхода: ";
	DFS(start - 1, );
	delete[]visited;
	system("pause>>void");
}
