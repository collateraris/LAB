// lin_urav_lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

double function(double x);
double dihotomia(double x1, double x2);
double neuton(double x, int &count);
double chorda(double x1, double x2, int &count);

int main() {

	//double a = dihotomia(0.1, 1.);
	//double a = dihotomia(-1., 1.);
	//cout << "Answer dihotomia " << a << endl;
	//a = neuton(1., c1);
	int c1 = 0;
	double a = neuton(4., c1);
	//double a = neuton(1., c1);
    cout << "Answer neuton " << a << endl;
   // a = chorda(2., 3., c2);
	int c2 = 0;
	//a = chorda(3., 8., c2);
	a = chorda(0.1, 4., c2);
	//a = chorda(-2., 1., c2);
	cout << "Answer chorda " << a << endl;
	return 0;
}
double chorda(double x1, double x2, int &count) {

	double x3;
	const double exp = 0.001;
	//cout << "Chorda x1" << x1 << endl;
	count++;
	cout << "CH i " ;
	//cout << "N Fun rez" << function(x1) << endl;
	cout << " [ai " << ";bi] " ;
	cout << "|ai - bi|" << endl;
	cout << "" << count;
	cout << "    [" << x1 << " ; " << x2 << "]" ;
	cout << "     " << abs(x1 - x2) << endl;
	if (abs(x1 - x2) < exp ) return x1;
	double a = ( function(x1)* (x2 - x1) ) / (function(x2) - function(x1));
	//cout << "Chorda a" << a << endl;
//	if (abs(a) < exp) return x1;
	x3 = x1 - a;
	//cout << function(x3) << endl;
	if (abs(function(x3)) < exp) return x3;
	if (count > 30) return x3;
	
	return chorda( x3,  x2, count);

}


double function(double x) {

//	return 5*x -  6 * log(x) - 7; //ответ 2,5 и 0.45
	return sin(x);
//	return x * x - 10;
//	return pow(x, 3) - 18 * x - 83; //ответ 5.7

}
double derivative(double x) {

//	return 5 - 6/x;
	return cos(x);
//	return 2 * x;
//	return pow(x, 2)*3 - 18;
}

double dihotomia(double x0, double x2)
{
	double x1 = (x2 + x0) / 2;
	const double exp = 0.0001;
	double f0 = function(x0);
	double f1 = function(x1);
	double f2 = function(x2);
	cout << "F0  " << f0 << endl;
	cout << "F1  " << f1 << endl;
	cout << "F2  " << f2 << endl;
	if (abs(f1) < exp) return x1;
	if (abs(x1 - x0 ) < 2 * exp) return x1;
	if (f0 * f1 < 0) {

		return dihotomia(x0, x1);
	}
	if (f2 * f1 < 0)
	{
		return dihotomia(x1, x2);
	}
	return x1;
}

double neuton(double x, int &count) {
	
	double f = function(x);
	double d = derivative(x);
	double x1 = x - f / d;
	count++;
	cout << "N i "  ;
	cout << "f(xi) "  ;
	cout << "xi " ;
	cout << "|xi - xi+1| " << endl;
	cout << "" << count;
	cout << "       " << function(x1);
	cout << "      " << x1 ;
	cout << "     " << abs(x - x1) << endl;
	if (abs(function(x1)) < 0.001) return x1;
	return neuton(x1, count);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
