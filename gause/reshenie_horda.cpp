
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

double function(double x);
double dihotomia(double x1, double x2);

int main() {

	double a = dihotimia(-10; 10);
	cout << "Answer dihotomia" << a << endl;
	return 0;
}

double function(double x) {

	return exp(x);
}

double dihotomia(double x0, double x1)
{
	double x2 = (x1 + x0)/2;
	const double exp = 0.01;
	double f0 = function(x0);
	double f1 = function(x1);
	double f2 = function(x2);
	if (f2 < exp) return x2;
	if (x2 < 2*exp) return x2;
	if (sign(f0) != sign(f2)) {

		return dihotomia(x0, x2);
	}
	if (sign(f1) != sign(f2))
	{
		return dihotomia(x1, x2);
	}
	cout << "Error";
}