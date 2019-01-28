#include <iostream>
#include <cmath>
using namespace std;

float function(float x);

float step(float x1, float x2, float h, int degree);

float derivative(float x1, float h, int degree);

float Eiler_edit(int num_step, float h, float a, float b);

float integral(int num_step, float a, float b, int degree);

float integral2(int num_step, float a, float b);

float integral_acc(int num_step, float a, float b);

float integral_acc_Eiler(int num_step, float a, float b);

float answer(int num_step, float a, float b, float right_res);

int main()
{
	setlocale(LC_CTYPE, "rus");
	int iteration;
	float a,b;
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
	cout << "Введите правильный результат" << endl;
	fflush(stdin);
	cin  >> right_result;
	answer(iteration,  a,  b, right_result);
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
//	float a;
//	if (degree <= 1) 
//	{
//		return ( function(x1+h) - function(x1-h) ) / 2*h;
//	} 
//	else 
//	{
//		a = ( function(x1+h) - function(x1-h) ) / 2*h;
//		degree--;
//		return derivative(a, h, degree);
//	}
	return cos(x1);;
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
//	return integral( num_step, a, b, 0) + h*h * integral( num_step, a, b, 2)/ 12 - pow(h,4) * integral( num_step, a, b, 4)/720;
//	return integral( num_step, a, b, 0) + h*h * integral22( num_step, a, b, 2)/ 12 - pow(h,4) * integral44( num_step, a, b, 4)/720;
}

float integral_acc_Eiler(int num_step, float a, float b)
{
	float h = (b - a)/num_step;
	return integral_acc( num_step, a, b) - Eiler_edit(num_step, h, a, b);
}

float answer(int num_step, float a, float b, float right_result)
{
	float h   = (b - a)/num_step;
	float I1  = integral( num_step, a, b);
	float I12 = integral( num_step*2, a, b);
	float IE  = integral_Eiler( num_step, a, b);
	float IE2 = integral_Eiler( num_step*2, a, b);
	float er1  = abs(I1-right_result);
	float er12 = abs(I12-right_result);
	float er2  = abs(IE-right_result);
	float er22 = abs(IE2-right_result);
	float ac1  = pow(h,2) * integral( num_step, a, b, 2) / 12;
	float ac12  = pow(h,2) * integral( num_step, a, b, 2) / 12*4;
	cout << "Cоотношение I1 / I12 " << I1 / I12 << endl;
	cout << "Cоотношение ac1 / ac12 " << ac1/ ac12 << endl;
	cout << "Cоотношение IE / IE2 " << IE / IE2 << endl;
	cout << "Cоотношение ac1 / ac12 " << ac1/ ac12 << endl;
}
