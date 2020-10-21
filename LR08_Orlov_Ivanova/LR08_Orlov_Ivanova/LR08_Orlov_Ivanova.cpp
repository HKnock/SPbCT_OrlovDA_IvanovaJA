/*Орлов Д.А. и Иванова Ю.А. 
гр. 591*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	double s, t;
	double x, y, z;
	cout << "Введите x: ";
	cin >> x;
	cout << "Введите y: ";
	cin >> y;
	cout << "Введите z: ";
	cin >> z;
	cout << "Рассчёт s:" << endl;
	s = abs(pow(x, x / y) - pow(x / y, 1 / 5));
	cout << s << endl;
	cout << "Расчёт t:" << endl;
	t = (x - y) * (sin(x + y) - tan(y - x) * z) / (1 + pow(x - y, 2));
	cout << t;
}