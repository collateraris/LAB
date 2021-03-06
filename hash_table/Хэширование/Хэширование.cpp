// Хэширование.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <random>
#include <string>
#include <malloc.h>
#include <stdlib.h>
#include <memory>
#include <vector>
#include <set>
#include <list>
using namespace std;

struct hashelement
{
	int key;
	string value;
};


class HashTable
{

	vector<list<pair<int,string>>> t;
	int size_hash_t = 100;
	int hash_f(int key);
public:
	HashTable()
	{
		
		for (int i = 0; i < 100; i ++)
		{
			list<pair<int, string>> he;
			t.push_back(he);
		}
	}
	bool _delete(int key);
	bool _insert(int key, string value);
	string operator [] (int key)
	{

			int index  = hash_f(key);
			for (auto i: t[index])
			{
				if (i.first == key)
				{
					return i.second;
				}
			}
			return "";

	}

};

int HashTable::hash_f(int key)
{
	return key % 100;
}

bool HashTable::_insert(int key,string value)
{
	int index = hash_f(key);
	for (auto i : t[index])
	{
		if (i.first == key) return false;
	}
	pair<int, string> a;
	a.first = key;
	a.second = value;
	t[index].push_back(a);
	return true;
}

bool HashTable::_delete(int key)
{
	int index = hash_f(key);
	for (auto i : t[index])
	{
		if (i.first == key)
		{
			t[index].remove(i);
			return true;
		}

	}
	return false;
}


int main()
{
	int mode = 1;
	HashTable ht;

	switch (mode)
	{
		case 1 :
			cout << ht[100] << endl;
			ht._insert(100, "kaka");
			cout << ht[100] << endl;
			ht._insert(1000, "kakashka");
			cout << ht[100] << endl;
			cout << ht[1000] << endl;
		break;


	default:
		break;
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
