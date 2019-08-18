/*Петкин Михаил
сделал: все  кроме цифровой
не сделал цифровую*/
#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstdlib> // содержит srand() и rand()
#include <ctime>
#include <string>
#include <vector>
#include <chrono>
using namespace std;

int* BubbleSort(int* a, int len)
{
	int z;
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				z = a[j];
				a[j] = a[j + 1];
				a[j + 1] = z;
			}
		}
	}
	return a;

}

int* ModBubbleSort(int* a, int len)
{
	bool f;
	int z;
	for (int i = 0; i < len - 1; ++i)
	{
		f = false;
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				z = a[j];
				a[j] = a[j + 1];
				a[j + 1] = z;
				f = true;
			}
		}
		if (!f) break;
	}
	return a;

}
int* Mod2BubbleSort(int* a, int len)
{
	int t;
	int bound = len - 1;
	int z;
	for (int i = 0; i < len; ++i)
	{
		t = -1;
		for (int j = 0; j < bound; ++j)
		{
			if (a[j] > a[j + 1])
			{
				z = a[j];
				a[j] = a[j + 1];
				a[j + 1] = z;
				t = j;
			}
		}
		if (t == -1) break;
		else
		{
			bound = t;
		}
	}
	return a;

}
int* InsertSort(int* a, int len)
{
	int j;
	int b;
	for (int i = 1; i < len; ++i)
	{
		b = a[i];
		j = i - 1;
		while (true)
		{
			if (j >= 0 && a[j] > b)
			{
				a[j + 1] = a[j];
				--j;
			}
			else
			{
				a[j + 1] = b;
				break;
			}
		}
	}
	return a;
}
int binSearch(vector<int> a, int len, int key)
{
	int l = -1;
	int r = len;
	int m;
	while (l < r - 1)
	{
		m = (l + r) / 2;
		if (a[m] < key)
			l = m;
		else
			r = m;
	}
	return r;
}

int* BinInsertSort(int* a, int len)
{
	int j;
	int b;
	int k;
	vector<int> v;
	v.push_back(a[0]);
	for (int i = 1; i < len; ++i)
	{
		b = a[i];
		if (b > v[i - 1]) v.push_back(b);
		else
		{
			k = binSearch(v, i - 1, b);
			v.insert(v.begin() + k, b);
		}
	}
	copy(v.begin(), v.end(), a);
	return a;
}

int* StableCountingSort(int* a, int len)
{
	int* b = new int[len];
	int k;
	int z;
	int max = a[0];
	int min = a[0];
	for (int i = 1; i < len; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	if (min < 0)
	{
		min = -min;
		k = min + max + 1;
		int* c = new int[k];
		for (int i = 0; i < k; ++i)
		{
			c[i] = 0;
		}
		for (int i = 0; i < len; ++i)
		{
			++c[a[i] + min];
		}
		for (int i = 1; i < k; ++i)
		{
			c[i] += c[i - 1];
		}
		for (int i = len - 1; i >= 0; --i)
		{
			--c[a[i] + min];
			z = c[a[i] + min];
			b[z] = a[i];
		}
		return b;
	}
	else
	{
		k = max + 1;
		int* c = new int[k];
		for (int i = 0; i < k; ++i)
		{
			c[i] = 0;
		}
		for (int i = 0; i < len; ++i)
		{
			++c[a[i]];
		}
		for (int i = 1; i < k; ++i)
		{
			c[i] += c[i - 1];
		}
		for (int i = len - 1; i >= 0; --i)
		{
			--c[a[i]];
			z = c[a[i]];
			b[z] = a[i];
		}
		return b;
	}
}

int* Generate1()
{
	int* res = new int[11000];
	srand(time(NULL));
	for (int i = 0; i < 11000; i++)
	{
		res[i] = rand() % 6;
	}
	return res;
}

int* Generate2()
{
	int* res = new int[11000];
	srand(time(NULL));
	for (int i = 0; i < 11000; i++)
	{
		res[i] = rand() % 11001;
	}
	return res;
}

int* Generate3()
{
	int k;
	int v;
	int z;
	int* res = new int[11000];
	srand(time(NULL));
	for (int i = 0; i < 11000; i++)
	{
		res[i] = i;
	}
	int n = (rand() % 10) + 2;//колличество пар [2..10)
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < n; j++)
		{
			k = rand() % 1000;
			v = rand() % 1000;
			z = res[k];
			res[k] = res[v];
			res[v] = z;
		}
	}
	return res;
}
int* Generate4()
{
	int* res = new int[11000];
	for (int i = 0; i < 11000; i++)
	{
		res[i] = 11000 - i;
	}
	return res;
}

int main()
{
	//массив указателей на метод сортировки
	int* (*methodsort[6])(int*, int);
	methodsort[0] = &BubbleSort;
	methodsort[1] = &ModBubbleSort;
	methodsort[2] = &Mod2BubbleSort;
	methodsort[3] = &InsertSort;
	methodsort[4] = &BinInsertSort;
	methodsort[5] = &StableCountingSort;

	//Массив указателей на методы генерации массивов
	int* (*methodsgenerate[4])();
	methodsgenerate[0] = &Generate1;
	methodsgenerate[1] = &Generate2;
	methodsgenerate[2] = &Generate3;
	methodsgenerate[3] = &Generate4;

	int* a;
	int* b;
	long long res;
	fstream fout;
	fout.open("output.csv");
	string s1 = "Массив случайных чисел 0..5";
	string s2 = "Массив случайных чисел 0..11000";
	string s3 = "Почти отсортированный массив";
	string s4 = "Массив {11000,10999..1}";
	string s = "пузырек;пузырек с у. А. 1;пузырек с у. А. 1 + 2;простых вставок;бинарных вставок;подсчетом(устойчивая);цифровая";
	int sec = 0;
	fout << ";" + s1 + ";;;;;;;" + s2 + ";;;;;;;" + s3 + ";;;;;;;" + s4 + ";;;;;;;\n";
	fout << ";" + s + ";" + s + ";" + s + ";" + s + "\n";
	for (int n = 5000; n <= 11000; n = n + 1000)//по размеру массива
	{
		fout << n << ";";

		for (int i = 0; i < 4; ++i) //цикл по типам массива
		{

			a = methodsgenerate[i]();
			b = new int[n];
			for (int j = 0; j < 7; ++j) //по типу сортировки
			{
				if (j == 6)
				{
					fout << ";";
					break;
				}
				res = 0;
				for (int y = 0; y < 12; ++y) //колличество измерений
				{
					if (y < 2) continue;
					copy(a, a + n, b);
					auto start = std::chrono::high_resolution_clock::now();
					int* sorta = methodsort[j](b, n);
					auto elapsed = std::chrono::high_resolution_clock::now() - start;
					long long nanoseconds = chrono::duration_cast<chrono::nanoseconds>(elapsed).count();
					res += nanoseconds;
				}

				fout << res / 10 << ";";
			}
		}
		fout << "\n";
	}

	fout.close();

}



