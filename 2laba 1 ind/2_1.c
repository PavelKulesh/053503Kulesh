#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <locale.h>

int inputInt();
float inputFloat();
void menu();

int main()
{
	char *locale = setlocale(LC_ALL, "");
	menu();
    system("pause");
	return 0;
}

void menu()
{
	int temp, flag = 0;
	float radius, k;
	do
	{	
		if (flag == 0)
		{
			printf("1. Ввод радиуса шара\n");
			printf("2. Информация о версии и авторе программы\n");
			printf("3. Выход из программы\n");
			temp = inputInt();
			while (temp < 1 || temp>3)
			{
				system("cls");
				printf("Вы ввели неверное значение! Попробуйте ещё раз.\n");
				printf("1. Ввод радиуса шара\n");	
				printf("2. Информация о версии и авторе программы\n");
				printf("3. Выход из программы\n");
				temp = inputInt();
			}
			switch (temp)
			{
				case 1: 
					system("cls");
					printf("Введите радиус:\n");
					radius = inputFloat();
					while (radius <= 0)
					{
						system("cls");
						printf("Вы ввели некорректное значение радиуса! Попробуйте ещё раз.\n");
						radius = inputFloat();
					}
					flag++;
					break;
				case 2:
					system("cls");
					printf("Программа разработана студентом БГУИР Кулешом Павлом(КСИС, ИИТП, 053503).\nVersoin 1.0\n");
					break;
				case 3:
					return;
					break;
			}
		}
		else
		{
			printf("1. Ввод иного радиуса шара\n");
			printf("2. Вывод площади поверхности шара\n");
			printf("3. Вывод объёма шара\n");
			printf("4. Вывод длины ребра вписанного тетраэдра\n");
			printf("5. Вывод площади сечения, проведённого на расстоянии k от центра шара\n");
			printf("6. Информация о версии и авторе программы\n");
			printf("7. Выход из программы\n");
			temp = inputInt();
			while (temp < 1 || temp>7)
			{
				system("cls");
				printf("Вы ввели неверное значение! Попробуйте ещё раз.\n");
				printf("1. Ввод иного радиуса шара\n");
				printf("2. Вывод площади поверхности шара\n");
				printf("3. Вывод объёма шара\n");
				printf("4. Вывод длины ребра вписанного тетраэдра\n");
				printf("5. Вывод площади сечения, проведённого на расстоянии k от центра шара\n");
				printf("6. Информация о версии и авторе программы\n");
				printf("7. Выход из программы\n");
				temp = inputInt();
			}
			switch (temp)
			{
			case 1:
				system("cls");
				printf("Введите радиус:\n");
				radius = inputFloat();
				while (radius <= 0)
				{
					system("cls");
					printf("Вы ввели некорректное значение радиуса! Попробуйте ещё раз.\n");
					radius = inputFloat();
				}
				flag++;
				break;
			case 2:
				system("cls");
				printf("Площадь боковой поверхности шара S=%.2f\n", (4. * 22./7. * radius * radius));
				break;
			case 3:
				system("cls");
				printf("Объем шара V=%.2f\n", (4. / 3. * 22./7. * radius * radius * radius));
				break;
			case 4:
				system("cls");
				printf("Длина ребра вписанного тетраэдра a=%.2f\n",4.*radius/sqrt(6));
				break;
			case 5:
				system("cls");
				printf("Введите расстояние от центра шара(k):\n");
				k = inputFloat();
				while (k > radius || k < 0)
				{
					system("cls");
					printf("Вы ввели некорректное расстояние от центра шара(k)! Попробуйте ещё раз.\n");
					k = inputFloat();
				}
				printf("Площадь сечения, проведённого на расстоянии k от центра шара S=%.2f\n", ((radius * radius) - (k * k)) * 22. / 7.);
				break;
			case 6:
				system("cls");
				printf("Программа разработана студентом БГУИР Кулешом Павлом(КСИС, ИИТП, 053503).\nVersoin 1.0\n");
				break;
			case 7:
				return;
				break;
			}
		}
	} while (1);
}

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

float inputFloat()
{
	int i = 0, flag = 0, step = 10;
	float result = 0;
	char str[255];
	fgets(str, 255, stdin);
	if (str[0] == '0' && (str[1] == '\0' || str[1] == '\n'))
		return 0;
	if ((str[0] == '0' && (str[1] != ',' && str[1] != '.')) || (str[0] == ',' || str[0] == '.'))
		return -1;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] == ',' || str[i] == '.')
		{
			flag++;
			i++;
		}
		if (flag == 0)
		{
			if (str[i] < '0' || str[i]>'9')
				return -1;
			else
				result = result * 10 + (str[i] - '0');
		}
		if (flag == 1)
		{
			if (str[i] < '0' || str[i]>'9')
				return -1;
			else
			{
				result += (float)(str[i] - '0') / step;
				step *= 10;
			}
		}
		if (flag > 1)
			return -1;
		i++;
	}
	return result;
}