// NN_BOOLEN_FUN.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <ctime>
#include <string>
using namespace std;

int Target(vector<double> ex)
{
	//if ((ex[1] == 1.) and (ex[2] == 0.3))
		//return 1;
	//if ((ex[1] == 0.4) and (ex[2] == 0.5))
		//return 1;
	//if ((ex[1] == 0.7) and (ex[2] == 0.8))
		//return 0;
	//AND function
	if ((ex[1] == 1.) and (ex[2] == 1.))
		return 1;
	else
		return 0;
}

int Predict(vector<double> ex, vector<double> w)
{
	double sum;
	sum = 0;
	for (unsigned int j = 0; j < ex.size(); j++)
	{
		sum += ex[j] * w[j];
	}
	//cout << "SUM" << sum << endl;
	if (sum > 0.)
		return 1;
	else
		return 0;
}

void calc(vector<vector <double>> ex, vector<double> w)
{
	bool perfect = false;
	double predict;
	double target;
	int counter = 0;
	while (perfect == false)
	{
		counter++;
		perfect = true;
		for (unsigned int i = 0; i < ex.size(); i++)
		{
			predict = Predict(ex[i], w);
			target = Target(ex[i]);
			//cout << "PREDICT" << predict << endl;
			//cout << "TARGET" << Target(ex[i]) << endl;
			//for (unsigned i = 0; i < w.size(); i++)
				//cout << w[i] << " ";
			//cout << endl;
			if (predict != target) {
				perfect = false;
				if (predict == 0) {
					for (unsigned int j = 0; j < ex[i].size(); j++)
					{
						w[j] = w[j] + 0.05*ex[i][j];
						//w[j] = w[j] + 0.05;
						
					}
				}
				else
				{
					for (unsigned int j = 0; j < ex[i].size(); j++)
					{
						w[j] = w[j] - 0.05*ex[i][j];
						//w[j] = w[j] - 0.05;
					}
				}
			}
			
		}
		if (counter == 100000) {
			for (unsigned i = 0; i < w.size(); i++)
				cout << w[i];
			cout << endl;
			counter = 0;
		}
	}
	for (unsigned i = 0; i < w.size(); i++)
		cout << w[i];
}


int main()
{
	vector<vector<double>> ex = { { 1.,1., 1. }, { 1., 1., 0. }, { 1., 0., 1. }, {1., 0., 0.} };
	vector<double> test = { 1., 1, 1 };
	//vector<vector<double>> ex = { {1., 1., 0.3 }, { 1., 0.4, 0.5 }, {1., 0.7, 0.8 } };
	vector<double> w = {0., 1.,1.};
	//ex[0] = { 1., 0.3 };
	//ex[1] = { 0.4, 0.5 };
	//ex[2] = { 0.7, 0.8 };
	
	calc(ex, w );

	cout << "test" << Predict(test, w);
	
	return 0;
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
