// Matrix_Gause.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// CalculateMathLab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

unsigned int column_max(vector<vector <double>>  A, int column_number);

void printVector(vector<vector <double>>  A);

int vectorSwap(vector<vector <double>>  &A, vector<vector <double>> &E, int pos_1, int pos_2);

void find_max_n_swap(vector<vector <double>>  &A, vector<vector <double>> &E, int cur_pos);

void multy_vector(vector <double>  &A, vector <double> &E, double alpha);

void subtraction_vector(vector <double>  &A, vector <double> &E, vector <double>  Am, vector <double> Em, double alpha);

void replace_op(vector<vector <double>>  &A, vector<vector <double>> E, int cur_pos);

void replace_op(vector<vector <double>>  &A, vector<vector <double>> E, int cur_pos);

void init_E(vector<vector <double>> E);

void inverse_matrix(vector<vector <double>>  A, vector<vector <double>> E);

void reverse_walk(vector<vector <double>>  &A, vector<vector <double>> &E);



int main()
{
	//vector<vector <double>>  A = {
	//	{ 1., 2., 3.,  4.  },
	//	{ 3., 5., 1.,  7.  },
	//	{ 8., 2., 0., -2.  },
	//	{ 6., 6., 6.,  9.  }
	//};

	//vector<vector <double>> E = {
	//	{ 1., 0., 0.,  0.  },
	//	{ 0., 1., 0.,  0.  },
	//	{ 0., 0., 1.,  0.  },
	//	{ 0., 0., 0.,  1.  }
	//};;

	vector<vector <double>> A = {
		{1., 1., 0.},
		{0., 1., 1.},
		{0., 0., 1.}
	};

	vector<vector <double>> E = {
		{1., 0., 0.},
		{0., 1., 0.},
		{0., 0., 1.}
	};

	inverse_matrix(A, E);

	return 0;
}

void inverse_matrix(vector<vector <double>>  A, vector<vector <double>> E) {

	init_E(E);
	for (unsigned i = 0; i < A.size(); i++) {
		find_max_n_swap(A, E, i);
		replace_op(A, E, i);
	}
	printVector(A);
	printVector(E);

	reverse_walk(A, E);

	printVector(A);
	printVector(E);
}
void reverse_walk(vector<vector <double>>  &A, vector<vector <double>> &E) {

	int start = A.size() - 1;
	int j = start - 1;
	double alpha;
	for (int i = start; i > 0; i--, j--) {	
		for (int k = i - 1; k >= 0; k--)
			{
			    cout << "A" << A[k][i] << "k,i" << k << " " << i << endl;
			    alpha = A[k][i];
				subtraction_vector(A[k], E[k], A[i], E[i], alpha);
			}
	}
}

void init_E(vector<vector <double>> E) {

	for (unsigned i = 0; i < E.size(); i++) {
		for (unsigned j = 0; j < E[i].size(); j++) {
			if (i == j) {
				E[i][j] = 1.;
			}
			else {
				E[i][j] = 0.;
			}
		}
	}
}

void printVector(vector<vector <double>>  A)
{
	for (unsigned i = 0; i < A.size(); i++) {
		cout << endl;
		for (unsigned j = 0; j < A[i].size(); j++) {
			cout << A[i][j] << " ";
		}
	}
	cout << endl << endl;
}

void replace_op(vector<vector <double>>  &A, vector<vector <double>> E, int cur_pos)
{

	double alpha;
	alpha = A[cur_pos][cur_pos];
	alpha = 1 / alpha;
	multy_vector(A[cur_pos], E[cur_pos], alpha);
	for (unsigned i = cur_pos + 1; i < A.size(); i++)
	{
		alpha = A[i][cur_pos];
		subtraction_vector(A[i], E[i], A[cur_pos], E[cur_pos], alpha);
	}

}
void subtraction_vector(vector <double>  &A, vector <double> &E, vector <double>  Am, vector <double> Em, double alpha)
{
	multy_vector(Am, Em, alpha);
	
	for (unsigned i = 0; i < A.size(); i++)
	{
		A[i] -= Am[i];
		E[i] -= Em[i];
	}
	
}

void multy_vector(vector <double>  &A, vector <double> &E, double alpha)
{
	for (unsigned i = 0; i < A.size(); i++)
	{
		A[i] *= alpha;
		E[i] *= alpha;
	}
	
}

int vectorSwap(vector<vector <double>>  &A, vector<vector <double>> &E, int pos_1, int pos_2)
{
	int size_vector  = A.size();
	int size_vector2 = E.size();
	double tmp;
	if (size_vector != size_vector2)
	{
		return 0;
	}
	if (((pos_1 > -1) and (pos_1 < size_vector)) and
		((pos_2 > -1) and (pos_2 < size_vector)))
	{
		A[pos_1].swap(A[pos_2]);
		E[pos_1].swap(E[pos_2]);
		return 1;
	}
	return 0;
}
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

void find_max_n_swap(vector<vector <double>>  &A, vector<vector <double>> &E, int cur_pos)
{
	int max_pos = column_max(A, cur_pos);
	if (cur_pos != max_pos) {
		vectorSwap(A, E, cur_pos, max_pos);
	}
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


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
