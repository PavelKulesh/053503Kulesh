#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <malloc.h>

int inputInt()
{
	int i = 0, result = 0;
	char str[255];
	fgets(str, 255, stdin);
	if (str[0] == '0')
	{
		return -1;
	}
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += (str[i] - '0');
			i++;
		}
		else
			return-1;
	}
	return result;
}

int **create(int m, int n)
{
	int i;
	int** matrix = (int**)malloc(m * sizeof(int*));
	for (i = 0; i < m; i++)
	{
		matrix[i] = (int*)malloc(n * sizeof(int));
	}
	return matrix;
}

int main()
{
	srand((unsigned)time(NULL));
	int m, n, sizeofzeromatrix, i, j, x, y, a, b, q, p;
	printf("Dimension:\n");
	printf("m = ");
	m = inputInt();
	while (m <= 0)
	{
		printf("Incorrect Value! Try again!\n");
		m = inputInt();
	}
	printf("n = ");
	n = inputInt();
	while (n <= 0)
	{
		printf("Incorrect Value! Try again!\n");
		n = inputInt();
	}
	int **matrix = create(m, n);
	printf("Matrix:\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			matrix[i][j] = rand() % 2;
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("Size of zero matrix:\n");
	sizeofzeromatrix = inputInt();
	while (sizeofzeromatrix <= 0)
	{
		printf("Incorrect Value! Try again!\n");
		sizeofzeromatrix = inputInt();
	}
	x = n - sizeofzeromatrix;
	y = m - sizeofzeromatrix;
	p = 0;
	for (b = 0; b < y + 1; b++)
	{
		for (a = 0; a < x + 1; a++)
		{
			q = 0;
			for (i = b; i < sizeofzeromatrix + b; i++)
			{
				for (j = a; j < sizeofzeromatrix + a; j++)
				{
					if (i < m && j < n)
					{
						if (matrix[i][j] == 0)
						{
							q++;
						}
					}
				}
			}
			if (q == sizeofzeromatrix * sizeofzeromatrix)
			{
				p++;
				printf("Case:%d\n", p);
				for (x = 0; x < m; x++)
				{
					for (y = 0; y < n; y++)
					{
						if (((x >= b) && (x < i)) && ((y >= a) && (y < j)))
						{

							printf("%d ", matrix[x][y]);
						}
						else
						{
							printf("%d ", matrix[x][y]);
						}
					}
					printf("\n");
				}
			}
		}
	}
	for (i = 0; i < m; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
	system("pause");
	return 0;
}