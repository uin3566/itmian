#include "stdafx.h"

#define WIDTH 3

enum EnumRotateDirection
{
	enum_rotate_left = 0,
	enum_rotate_right
};

int** CreateMatrix(int nWidth = WIDTH)
{
	int** ppMatrix = NULL;
	ppMatrix = new int*[nWidth];
	for (int i = 0; i < nWidth; i++)
	{
		ppMatrix[i] = new int[nWidth];
	}
	return ppMatrix;
}

void ReleaseMatrix(int** ppMatrix, int nWidth)
{
	if (ppMatrix == NULL || nWidth <= 0)
	{
		goto Exit0;
	}
	for (int i = 0; i < nWidth; i++)
	{
		delete[] ppMatrix[i];
		ppMatrix[i] = NULL;
	}
	delete[] ppMatrix;

Exit0:
	return;
}

void RotateLeft(int Matrix[][WIDTH])
{
	int nTmp = 0;
	int** ppMatrix = NULL;
	if (Matrix == NULL)
	{
		goto Exit0;
	}

	ppMatrix = CreateMatrix(WIDTH);
	if (ppMatrix == NULL)
	{
		goto Exit0;
	}

	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			ppMatrix[i][j] = Matrix[i][j];
		}
	}

	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			Matrix[WIDTH - 1 - j][i] = ppMatrix[i][j];
		}
	}
	ReleaseMatrix(ppMatrix, WIDTH);
	ppMatrix = NULL;

Exit0:
	return;
}

void RotateRight(int Matrix[][WIDTH])
{
	int nTmp = 0;
	int** ppMatrix = NULL;
	if (Matrix == NULL)
	{
		goto Exit0;
	}

	ppMatrix = CreateMatrix(WIDTH);
	if (ppMatrix == NULL)
	{
		goto Exit0;
	}

	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			ppMatrix[i][j] = Matrix[i][j];
		}
	}

	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			Matrix[j][WIDTH - 1 - i] = ppMatrix[i][j];
		}
	}
	ReleaseMatrix(ppMatrix, WIDTH);
	ppMatrix = NULL;

Exit0:
	return;
}

void RotateImage(int Matrix[][WIDTH], EnumRotateDirection direction)//占用额外存储空间
{
	if (Matrix == NULL)
	{
		goto Exit0;
	}

	switch(direction)
	{
	case enum_rotate_left:
		RotateLeft(Matrix);
		break;
	case enum_rotate_right:
		RotateRight(Matrix);
		break;
	default:
		break;
	}

Exit0:
	return;
}

void Rotateleft2(int Matrix[][WIDTH])
{
	int nLoop = 0;
	int nFirst = 0;
	int nLast = 0;
	int nOffset = 0;
	int nTop = 0;
	if (Matrix == NULL)
	{
		goto Exit0;
	}

	nLoop = WIDTH / 2;
	for (int i = 0; i < nLoop; i++)
	{
		nFirst = i;
		nLast = WIDTH - 1 - nFirst;
		for (int j = nFirst; j < nLast; j++)
		{
			nOffset = j - nFirst;
			nTop = Matrix[i][j];
			Matrix[i][j] = Matrix[i + nOffset][nLast];
			Matrix[i + nOffset][nLast] = Matrix[nLast][nLast - nOffset];
			Matrix[nLast][nLast - nOffset] = Matrix[nLast - nOffset][nFirst];
			Matrix[nLast - nOffset][nFirst] = nTop;
		}
	}

Exit0:
	return;
}

void RotateRight2(int Matrix[][WIDTH])
{
	int nLoop = 0;
	int nFirst = 0;
	int nLast = 0;
	int nOffset = 0;
	int nTop = 0;
	if (Matrix == NULL)
	{
		goto Exit0;
	}

	nLoop = WIDTH / 2;
	for (int i = 0; i < nLoop; i++)
	{
		nFirst = i;
		nLast = WIDTH - 1 - nFirst;
		for (int j = nFirst; j < nLast; j++)
		{
			nOffset = j - nFirst;
			nTop = Matrix[i][j];
			Matrix[i][j] = Matrix[nLast - nOffset][nFirst];
			Matrix[nLast - nOffset][nFirst] = Matrix[nLast][nLast - nOffset];
			Matrix[nLast][nLast - nOffset] = Matrix[i + nOffset][nLast];
			Matrix[i + nOffset][nLast] = nTop;
		}
	}

Exit0:
	return;
}

void RotateImage2(int Matrix[][WIDTH], EnumRotateDirection direction)//不占用额外存储空间，按层次旋转
{
	if (Matrix == NULL)
	{
		goto Exit0;
	}

	switch(direction)
	{
	case enum_rotate_left:
		Rotateleft2(Matrix);
		break;
	case enum_rotate_right:
		RotateRight2(Matrix);
		break;
	default:
		break;
	}

Exit0:
	return;
}

// void main()
// {
// 	int arrayMatrix[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
// 	RotateImage(arrayMatrix, enum_rotate_left);
// }