// 1 Спосіб --- "Ітераційний"
#include <iostream>
#include <Windows.h>
#include <iomanip>

void matriz_create(int** matriz, const int line, const int column, const int Low, const int High);
void matriz_print(int** matriz, const int line, const int column);
int matriz_sum(int** matriz, const int line, const int column);
int matriz_ymova(int** matriz, const int line, const int column);
void sort_matriz(int** matriz, const int line, const int column);

int main(void)
{
	srand((unsigned)time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	using std::cout;
	using std::endl;

	const int line = 8;
	const int column = 6;

	int** matriz = new int* [line];
	for (int index = 0; index < line; index++)
		matriz[index] = new int[column];

	int High = 97;
	int Low = 16;
	matriz_create(matriz, line, column, Low, High);
	cout << "Сформований масив: " << endl;
	matriz_print(matriz, line, column);

	sort_matriz(matriz, line, column);
	cout << "Модифікований масив: " << endl;
	matriz_print(matriz, line, column);

	int suma = matriz_sum(matriz, line, column);
	cout << "Сума елементів матриці за вказаним критерієм: " << suma << endl;
	cout << endl;

	int kilk_elements = matriz_ymova(matriz, line, column);
	cout << "Кількість елементів за вказаним критерієм: " << kilk_elements << endl;
	cout << endl;

	cout << "Модифікований масив: " << endl;
	matriz_print(matriz, line, column);

	return 0;
}

void matriz_create(int** matriz, const int line, const int column, const int Low, const int High)
{
	for (int index = 0; index < line; index++)
		for (int index_j = 0; index_j < column; index_j++)
			matriz[index][index_j] = Low + rand() % (High - Low + 1);
}

void matriz_print(int** matriz, const int line, const int column)
{
	using std::cout;
	using std::endl;
	cout << endl;
	for (int index = 0; index < line; index++)
	{
		for (int index_j = 0; index_j < column; index_j++)
			cout << std::setw(4) << matriz[index][index_j];
		cout << endl;
	}
	cout << endl;
}

int matriz_sum(int** matriz, const int line, const int column)
{
	int sum = 0;
	for (int index = 0; index < line; index++)
	{
		for (int index_j = 0; index_j < column; index_j++)
		{
			if ((matriz[index][index_j] % 7 == 0) || ((index % 2 != 0) || (index_j % 2 != 0)))
				sum += matriz[index][index_j];
			else;
		}
	}
	return sum;
}

int matriz_ymova(int** matriz, const int line, const int column)
{
	int kilk_elements = 0;
	for (int index = 0; index < line; index++)
	{
		for (int index_j = 0; index_j < column; index_j++)
		{
			if ((matriz[index][index_j] % 7 == 0) || ((index % 2 != 0) || (index_j % 2 != 0)))
			{
				matriz[index][index_j] = 0;
				kilk_elements++;
			}
			else;
		}
	}
	return kilk_elements;
}

void sort_matriz(int** matriz, const int line, const int column)
{
	int index1, index2;
	bool ask = FALSE;
	bool ask1 = FALSE;
	for (int index = 0; index < line; index++)
	{

		int max = matriz[index][0];
		int i_max = index;
		for (int index_j = index + 1; index_j < line; index_j++)
		{
			if (max < matriz[index_j][0])
			{
				max = matriz[index_j][0];
				i_max = index_j;
			}

		}
		for (int index_j = 0; index_j < column; index_j++)
		{
			int tmp = matriz[index][index_j];

			matriz[index][index_j] = matriz[i_max][index_j];

			matriz[i_max][index_j] = tmp;
		}

	}
	for (int index = 0; index < line; index++)
	{
		for (index1 = 0; index1 < line; index1++)
		{
			for (index2 = index1 + 1; index2 < line; index2++)
			{
				if (matriz[index1][0] == matriz[index2][0])
				{
					ask = TRUE;
					index1 = line;
					index2 = line;
				}
			}
		}
		if (ask == TRUE)
		{
			int min = matriz[index][1];
			int i_min = index;
			for (int index_j = index + 1; index_j < line; index_j++)
			{
				if (min > matriz[index_j][1])
				{
					min = matriz[index_j][1];
					i_min = index_j;
				}
			}
			for (int index_j = 0; index_j < column; index_j++)
			{
				int tmp = matriz[index][index_j + 1];

				matriz[index][index_j + 1] = matriz[i_min][index_j + 1];

				matriz[i_min][index_j + 1] = tmp;
			}
		}
	}
	for (int index = 0; index < line; index++)
	{
		for (index1 = 0; index1 < line; index1++)
		{
			for (index2 = index1 + 1; index2 < line; index2++)
			{
				if (matriz[index1][0] == matriz[index2][1])
				{
					ask1 = TRUE;
					index1 = line;
					index2 = line;
				}
			}
		}
		if (ask1 == TRUE)
		{
			for (int index = 0; index < line; index++)
			{

				int max = matriz[index][2];
				int i_max = index;
				for (int index_j = index + 1; index_j < line; index_j++)
				{
					if (max < matriz[index_j][2])
					{
						max = matriz[index_j][2];
						i_max = index_j;
					}

				}
				for (int index_j = 0; index_j < column; index_j++)
				{
					int tmp = matriz[index][index_j + 2];

					matriz[index][index_j + 2] = matriz[i_max][index_j + 2];

					matriz[i_max][index_j + 2] = tmp;
				}

			}
		}
	}
}
