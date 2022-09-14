// Safty 1 lab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include<vector>
#include <charconv>
using namespace std;
int main()
{
    int i,j,q;
    char buther;
    string msg, buf, kolvo, ono,prov;
    ifstream input("in.txt");
    ofstream output("out.txt");
    getline(input, kolvo);
    int n = atoi(kolvo.c_str());
    vector<string> vec(n);
    vector<int> otv(n);
    for (i = 0; i < n; i++) {
        getline(input, buf);
        vec[i] = buf;
    }
    getline(input, msg);
    vector<int> chisla(20);
    for (i = 1;i < 26;i++)
    {
        for (j = 0; j < n; j++)
        {
            buf = vec[j];
            for (q = 0; q < vec[j].length(); q++)
            {
                chisla[q] = buf[q];
                chisla[q] += i;
                if (chisla[q] > 90) {
                    chisla[q] -= 26;
                    if (chisla[q] == 64) chisla[q] = 32;
                }
                buther = chisla[q];
                ono+=buther;
            }
            for (q = 0; q < (msg.length() - vec[j].length()); q++)
            {
                prov = msg.substr(q, ono.length());
                if (prov == ono) otv.push_back(i);
            }
            ono.clear();
        }
    }
    
}
