#include <iostream>
using namespace std;

float function(float x)
{
	float y;
	y = x;
	return y;
}

float step(float x1, float x2, float h)
{
	float y;
	y = (function(x1) + function(x2)) / 2 * h;
//	cout << "y "<< y << endl;
	return y;
	
}

float derivative(float x1, float h)
{
	return ( function(x1+h) - function(x1-h) ) / 2*h;
}

float Eiler_edit(int num_step, float h, float a, float b)
{	
	float st = (float) num_step;
	return  (( h*h )  / (st * st)) * (derivative(b,h) - derivative(a,h));
}

float integral(int num_step, float a, float b)
{
	float h;
	float sum;
	float x1, x2;
	sum = 0;
	x1 = a;
	
	h = (b - a)/num_step;
	cout << "h "<< h << endl;
	for(int ix = 0; ix < num_step; ix++)
	{
		x1  = h*ix;
		x2  = h*(ix+1);
//		cout << "x1 "<< x1 << endl;
//		cout << "x2 "<< x2 << endl;
		sum += step(x1,x2,h);
	}
	return sum;	
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	cout << "Площадь " << integral( 20., 0., 10.);
	return 0;
}
