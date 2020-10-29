#include "Visualisation.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ofstream fout;
ifstream fin;

Visualisation::Visualisation()
{
	n = 0;
	m = 0;
	int** tab = new int* [n];
	for (int i = 0; i < n; i++)
		tab[i] = new int[m];
}

Visualisation::Visualisation(int** tabb, int n, int m)
{
	this->n = n;
	this->m = m;
	int** tab = new int* [n];
	for (int i = 0; i < n; i++)
		tab[i] = new int[m];
	srand(time(0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tab[i][j] = rand() % 10;
}


int Visualisation::fillTable(int** tab)
{
	srand(time(0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tab[i][j] = rand() % 10;
	return**tab;
}

void Visualisation::putIntoFile(int** tab) {
	fout.open("forTable.txt");
	fout << "x,y\n";
	for (int i = 0; i < n; i++)
	{
		fout << tab[i][0] << ",";
		fout << tab[i][1] << "|\n";
	}
	fout.close();
}

void Visualisation::outOfFile(string str, int** tab)
{
	char* buffer = new char[(n + 1) * 4];
	string i;
	fin.open(str + ".txt");
	for (int i = 0; i <= n; i++)
	{
		fin.getline(buffer, 4, '|');
		if (i == 0) continue;
		tab[]

	}
}

Visualisation::~Visualisation()
{
	delete[] tab;
}