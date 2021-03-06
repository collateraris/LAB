// sistema_neutona_lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// CalculateMathLab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

unsigned int column_max(vector<vector <double>>  A, int column_number)
{
	double MAX;
	unsigned int max_place;
	int start = column_number;
	int end = A.size();


	for (unsigned i = start; i < end; i++)
	{
		if (i == start)
		{
			MAX = A[i][column_number];
			max_place = i;
		}
		if (MAX < A[i][column_number])
		{
			MAX = A[i][column_number];
			max_place = i;
		}
	}
	cout << "MAX: " << MAX << endl;
	return max_place;
}

void printVector(vector<vector <double>>  A, vector<double> y)
{
	for (unsigned i = 0; i < A.size(); i++) {
		cout << endl;
		for (unsigned j = 0; j < A[i].size(); j++) {
			cout << A[i][j] << " ";
		}
		cout << "  " << y[i];
	}
	cout << endl << endl;
}

int vectorSwap(vector<vector <double>>  &A, vector<double> &y, int pos_1, int pos_2)
{
	int size_vector = A.size();
	int size_vector2 = y.size();
	double tmp;
	if (size_vector != size_vector2)
	{
		return 0;
	}
	if (((pos_1 > -1) and (pos_1 < size_vector)) and
		((pos_2 > -1) and (pos_2 < size_vector)))
	{
		A[pos_1].swap(A[pos_2]);
		tmp = y[pos_1];
		y[pos_1] = y[pos_2];
		y[pos_2] = tmp;
		return 1;
	}
	return 0;
}

void find_max_n_swap(vector<vector <double>>  &A, vector<double> &y, int cur_pos)
{
	int max_pos = column_max(A, cur_pos);
	if (cur_pos != max_pos) {
		vectorSwap(A, y, cur_pos, max_pos);
	}

}

void multy_vector(vector <double>  &A, double &y, double alpha)
{
	for (unsigned i = 0; i < A.size(); i++)
	{
		A[i] *= alpha;
	}
	y *= alpha;
}

void subtraction_vector(vector <double>  &A, double &y, vector <double>  Am, double ym, double alpha)
{
	multy_vector(Am, ym, alpha);
	for (unsigned i = 0; i < A.size(); i++)
	{
		A[i] -= Am[i];
	}
	y -= ym;
}

void replace_op(vector<vector <double>>  &A, vector<double> &y, int cur_pos)
{

	double alpha;
	alpha = A[cur_pos][cur_pos];
	alpha = 1 / alpha;
	multy_vector(A[cur_pos], y[cur_pos], alpha);
	for (unsigned i = cur_pos + 1; i < A.size(); i++)
	{
		alpha = A[i][cur_pos];
		subtraction_vector(A[i], y[i], A[cur_pos], y[cur_pos], alpha);
	}

}

void printAnswer(vector<double> x) {
	cout << endl;
	for (unsigned i = 0; i < x.size(); i++) {
		cout << "  " << x[i];
	}
}

void answer(vector<vector <double>>  A, vector<double> y)
{
	vector<double> x = A[0];
	int start = A.size() - 1;
	int end = start;
	cout << "Start" << start << endl;
	for (int i = start; i >= 0; i--) {
		x[i] = y[i];
		//cout << "X" << x[i];
		for (int j = i + 1; j < end + 1; j++)
		{
			//		cout << " A " << A[i][j];
			x[i] -= A[i][j] * x[j];
		}
		if (x[i] < 0.001) x[i] = 0.;
		//	cout << " " << x[i] << endl;
	}
	printAnswer(x);
}

void use_method(vector<vector <double>>  A, vector<double> y) {
	for (unsigned i = 0; i < A.size(); i++) {
		find_max_n_swap(A, y, i);
		printVector(A, y);
		replace_op(A, y, i);
		printVector(A, y);
	}
	answer(A, y);
}

int main()
{
	vector<vector <double>>  A = {
		{ 1., 2., 3.,  4.  },
		{ 3., 5., 1.,  7.  },
		{ 8., 2., 0., -2.  },
		{ 6., 6., 6.,  9.  }
	};

	vector<double>  y = { 22., 38., 16., 60. };
	use_method(A, y);

	return 0;
}

 
