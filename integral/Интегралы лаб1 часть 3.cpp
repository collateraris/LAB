#include <iostream>
#include <cmath>
const double EPSILON = 0.000001;
using namespace std;


float function(float x);

float step(float x1, float x2, float h, int degree);

float derivative(float x1, float h, int degree);

float Eiler_edit(int num_step, float h, float a, float b);

float integral(int num_step, float a, float b, int degree);

float integral2(int num_step, float a, float b);

float integral_acc(int num_step, float a, float b);

float integral_acc_Eiler(int num_step, float a, float b);

float answer(int num_step, float a, float b, float right_res, int p);

float porydok(int num_step, float a, float b, float right_result, int p, int dev);

int main()
{
	setlocale(LC_CTYPE, "rus");
	int iteration;
	float a,b;
	float p;
	float right_result;
	cout << "Введите количество итераций"<< endl;
	fflush(stdin);
	cin  >> iteration;
	cout << "Введите А" << endl;
	fflush(stdin);
	cin  >> a;
	cout << "Введите В" << endl;
	fflush(stdin);
	cin  >> b;
	cout << "Введите порядок точности" << endl;
	fflush(stdin);
	cin  >> p;
	cout << "Введите правильный результат" << endl;
	fflush(stdin);
	cin  >> right_result;
	answer(iteration,  a,  b, right_result, p );
	return 0;
}

float function(float x)
{
	float y;
	y = sin(x);
	return y;
}

float step(float x1, float x2, float h, int degree)
{
	float y;
	if (degree == 0)
	{
		y = (function(x1) + function(x2)) / 2 * h;	
	}
	else
	{
		y = (derivative(x1, h, degree) + derivative(x2, h, degree)) / 2 * h;	
	}
	
	return y;
	
}

float derivative(float x1, float h, int degree)
{	
	float a;
	if (degree  <= 1) 
	{
		return ( function(x1+h) - function(x1-h) ) / 2*h;
	} 
	else 
	{
		a = derivative(a, h, degree);
		degree--;
		return derivative(a, h, degree);
	}
}

float Eiler_edit(int num_step, float h, float a, float b)
{	
	float st = (float) num_step;
	return  (( h*h )  / (12)) * (derivative(b,h,1) - derivative(a,h,1));
}

float integral(int num_step, float a, float b, int degree)
{
	float h;
	float sum;
	float x1, x2;
	sum = 0;
	x1 = a;
	
	h = (b - a)/num_step;
//	cout << "h "<< h << endl;
	for(int ix = 0; ix < num_step; ix++)
	{
		x1  = h*ix;
		x2  = h*(ix+1);
//		cout << "x1 "<< x1 << endl;
//		cout << "x2 "<< x2 << endl;
		sum += step(x1,x2,h, degree);
	}
	return sum;	
}

float integral2(int num_step, float a, float b)
{
	float h =  (b - a)/num_step;
	float result =   integral( num_step, a, b, 0) - Eiler_edit(num_step, h, a, b);
	return result;
}

float integral_acc(int num_step, float a, float b)
{
	float h = (b - a)/num_step;
	return integral( num_step, a, b, 0) + h*h * integral( num_step, a, b, 2)/ 12 - pow(h,4) * integral( num_step, a, b, 4)/720;
}

float integral_acc_Eiler(int num_step, float a, float b)
{
	float h = (b - a)/num_step;
	return integral_acc( num_step, a, b) - Eiler_edit(num_step, h, a, b);
}

float answer(int num_step, float a, float b, float right_result, int p)
{
	int dev;
	dev = porydok(num_step, a, b, right_result,  p,  0);
	dev = pow(2, dev + 1);
	cout << "Степень " << dev << endl;

}

float porydok(int num_step, float a, float b, float right_result, int p, int dev)
{
	float por = 1/ (pow(2,p) - 1);
	float ans = por * abs(integral_acc( num_step * pow(2,dev), a, b) - integral_acc( num_step * pow(2,dev+1), a, b));
	if (ans <= EPSILON)  return dev;
	dev++;
	return porydok(num_step, a, b, right_result,  p,  dev);
}
