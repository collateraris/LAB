#include <iostream>
#include <cmath>
using namespace std;

double function(double x)
{
	double y;
	y = sin(x);
	return y;
}

double step(double x1, double x2, double h)
{
	double y;
	y = (function(x1) + function(x2)) / 2 * h;
//	cout << "y "<< y << endl;
	return y;
	
}

double derivative(double x1)
{
//	return ( function(x1+h) - function(x1-h) ) / (2*h);
	return cos(x1);
}

double Eiler_edit(int num_step, double h, double a, double b)
{	
	double st = (double) num_step;
	return  h*h  / 12 * (derivative(b) - derivative(a));
}

double integral(int num_step, double a, double b)
{
	double h;
	double sum;
	double x1, x2;
	double n_step = (double) num_step;
	sum = 0;
	x1 = a;
	
	h = (double) (b - a)/n_step;
//	cout << "h "<< h << endl;
	for(int ix = 0; ix < num_step; ix++)
	{
		x1  = h*ix;
		x2  = h*(ix+1);
//		cout << "x1 "<< x1 << endl;
//		cout << "x2 "<< x2 << endl;
		sum = sum + step(x1,x2,h);
	}
	return sum;	
}

double integral2(int num_step, double a, double b)
{
	double h =  (b - a)/num_step;
	double result =   integral( num_step, a, b) - Eiler_edit(num_step, h, a, b);
	return result;
}

double intergralNew(double a, double b)
{
	return (-cos(b) - (-cos(a)) );
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	int iteration;
	double a = 0.;
	double b = 3.14;
	double righ_result;
	cout << "Введите количество итераций"<< endl;
	fflush(stdin);
	cin  >> iteration;
//	cout << "Введите А" << endl;
//	fflush(stdin);
//	cin  >> a;
//	cout << "Введите В" << endl;
//	fflush(stdin);
//	cin  >> b;
//	cout << "Введите правильный результат" << endl;
//	fflush(stdin);
//	cin  >> righ_result;
	righ_result = intergralNew( a, b);
	cout << "Правильный результат" << intergralNew( a, b) << endl;
	double I1 = integral( iteration, a, b);
	double IE = integral2( iteration, a, b);
	double er1 = abs(I1-righ_result);
	double er2 = abs(IE-righ_result);
	cout << "Площадь 1 способ " << integral( iteration, a, b) << endl;
	cout << "Площадь с поправкой Эйлера " << integral2( iteration, a, b) << endl;
	cout << "1-ая погрешность " << er1 << endl;
	cout << "2-ая погрешность " << er2 << endl;
	return 0;
}
