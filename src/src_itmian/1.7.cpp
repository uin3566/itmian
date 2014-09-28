#include "stdafx.h"

#define M 3 //ÐÐ
#define N 4 //ÁÐ

void ResetRow(int Matrix[][N], int nRow)
{
	for (int j = 0; j < N; j++)
	{
		Matrix[nRow][j] = 0;
	}
}

void ResetColumn(int Matrix[][N], int nCol)
{
	for (int i = 0; i < M; i++)
	{
		Matrix[i][nCol] = 0;
	}
}

void ClearRowAndColWhichIncludeZero(int Matrix[][N])
{
	int arrayRows[M] = {0};
	int arrayCols[N] = {0};

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Matrix[i][j] == 0)
			{
				arrayRows[i]++;
				arrayCols[j]++;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		if (arrayRows[i] != 0)
		{
			ResetRow(Matrix, i);
		}
	}
	for (int j = 0; j < N; j++)
	{
		if (arrayCols[j] != 0)
		{
			ResetColumn(Matrix, j);
		}
	}
}

// void main()
// {
// 	int arrayMatrix[M][N] = {1, 2, 3, 0, 5, 6, 7, 0, 9, 10, 11, 12};
// 	ClearRowAndColWhichIncludeZero(arrayMatrix);
// }