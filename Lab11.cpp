// Lab11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void sort(int n, int* x, int* y)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n-1; ++j)
		{
			if (y[j] < y[j + 1])
			{
				int k = y[j];
				y[j] = y[j + 1];
				y[j + 1] = k;
				k = x[j];
				x[j] = x[j + 1];
				x[j + 1] = k;
			}
			if (y[j] == y[j + 1] && x[j] > x[j + 1])
			{
				int k = y[j];
				y[j] = y[j + 1];
				y[j + 1] = k;
				k = x[j];
				x[j] = x[j + 1];
				x[j + 1] = k;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;

	int* x = new int[3*n];
	int* y = new int[3*n];

	int* tx1 = new int[n];
	int* tx2 = new int[n];
	int* tx3 = new int[n];
	int* ty1 = new int[n];
	int* ty2 = new int[n];
	int* ty3 = new int[n];

	bool* b = new bool[3*n];
	
	for (int i = 0; i < 3*n; ++i)
	{
		cin >> x[i] >> y[i];
	}

	sort(3*n, x, y);

	for (int i = 0; i < 3 * n; ++i)
	{
		cout << "( " << x[i] << " , " << y[i] << " )\n";
	}
	cout << endl;

	for (int i = 0; i < n; ++i)
	{
		int k = 0, j = 0;
		while(k<4)
		{
			cout << 1 << endl;
			if (!b[j])
			{
				if (k < 3)
				{
					if (k == 1)
					{
						tx1[i] = x[j];
						ty1[i] = y[j];
					}
					else
					{
						tx2[i] = x[j];
						ty2[i] = y[j];
					}
					++k;
					b[j] = true;
				}
				else
				{
					if ((x[j] != tx1[i] || x[j] != tx2[i]) && (y[j] != ty1[i] || y[j] != ty2[i]))
					{
						tx3[i] = x[j];
						ty3[i] = y[j];
						++k;
						b[j] = true;
					}
				}
			}
			++j;
			if (j == 3 * n) break;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << "( " << tx1[i] << " , " << ty1[i] << " ) ; "<< "( " << tx2[i] << " , " << ty2[i] << " ) ; " << "( " << tx3[i] << " , " << ty3[i] << " )\n";
	}
	delete x, y, tx1, tx2, tx3, ty1, ty2, ty3, b;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file