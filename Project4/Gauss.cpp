#include<iostream>
#include "Gauss.h"

using namespace std;

int main()
{
	int i = 0, j = 0, k = 0, n = 0;
	float** mat = NULL;
	float d = 0.0;

	cout << "Cuantas Variables para tu matriz? ";
	cin >> n;
	cout << endl;


	mat = new float* [2 * n];
	for (i = 0; i < 2 * n; ++i)
	{
		mat[i] = new float[2 * n]();
	}

	cout << "Ingrese las coeficientes:" << endl;

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			cin >> mat[i][j];
		}
	}

	cout << endl << "matrix:" << endl;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < 2 * n; ++j)
		{
			if (j == (i + n))
			{
				mat[i][j] = 1;
			}
		}
	}


	for (i = n; i > 1; --i)
	{
		if (mat[i - 1][1] < mat[i][1])
		{
			for (j = 0; j < 2 * n; ++j)
			{
				d = mat[i][j];
				mat[i][j] = mat[i - 1][j];
				mat[i - 1][j] = d;
			}
		}
	}
	cout << endl;


	cout << " solucion " << endl;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < 2 * n; ++j)
		{
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;


	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < 2 * n; ++j)
		{
			if (j != i)
			{
				d = mat[j][i] / mat[i][i];
				for (k = 0; k < n * 2; ++k)
				{
					mat[j][k] -= mat[i][k] * d;
				}
			}
		}
	}
	cout << endl;

	for (i = 0; i < n; ++i)
	{
		d = mat[i][i];
		for (j = 0; j < 2 * n; ++j)
		{
			mat[i][j] = mat[i][j] / d;
		}
	}
	cout << "Matriz:" << endl;
	for (i = 0; i < n; ++i)
	{
		for (j = n; j < 2 * n; ++j)
		{
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}