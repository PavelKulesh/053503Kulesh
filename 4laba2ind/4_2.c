#include <stdio.h>
#include <windows.h>

int checkfileopen(FILE *myfile)
{
	if (myfile==NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int checkempty(char *str)
{
	int i, temp = 0;
	for (i = 0; str[i]; i++)
	{
		if (str[i]!='\0' && str[i]!=' ' && str[i]!='\n')
		{
			temp++;
		}
	}
	if (temp==0)
	{
		return 0;
	}
	else
	{
		return 1;
    }
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int j = 0, temp = 0, i, q, f;
	char slovo[100]="";
	char str[100]="";
	FILE *myfile;
	myfile = fopen("main.txt", "r");
	if (!checkfileopen(myfile))
	{
		printf("Unable to open the file!");
		system("pause");
		return 0;
	}
	fgets(str, 100, myfile);
	if (!checkempty(str))
	{
		printf("Unable to open the file!");
		system("pause");
		return 0;
	}
	for (i = 0; i!=strlen(str)+1; i++)
	{
		if (str[i] >= 'А' && str[i] <= 'я')
		{
			slovo[j] = str[i];
			j++;
		}
		else
		{
			for (q = 0; slovo[q]; q++)
			{
				if (slovo[q] == 'А' || slovo[q] == 'а')
				{
					temp++;
				}
				else if (slovo[q] == 'В' || slovo[q] == 'в')
				{
					temp++;
				}
				else if (slovo[q] == 'Е' || slovo[q] == 'е')
				{
					temp++;
				}
				else if (slovo[q] == 'К' || slovo[q] == 'к')
				{
					temp++;
				}
				else if (slovo[q] == 'М' || slovo[q] == 'м')
				{
					temp++;
				}
				else if (slovo[q] == 'Н' || slovo[q] == 'н')
				{
					temp++;
				}
				else if (slovo[q] == 'О' || slovo[q] == 'о')
				{
					temp++;
				}
				else if (slovo[q] == 'Р' || slovo[q] == 'р')
				{
					temp++;
				}
				else if (slovo[q] == 'С' || slovo[q] == 'с')
				{
					temp++;
				}
				else if (slovo[q] == 'Т' || slovo[q] == 'т')
				{
					temp++;
				}
				else if (slovo[q] == 'Х' || slovo[q] == 'х')
				{
					temp++;
				}
			}
			if (temp == strlen(slovo) && temp != 0)
			{
				printf("%s ", slovo);
			}
			for (f = 0; f < 100; f++)
			{
				slovo[f] = '\0';
			}
			j = 0;
			temp = 0;
		}
	}
	system("pause");
	return 0;
}
