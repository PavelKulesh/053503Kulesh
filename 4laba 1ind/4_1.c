#include <stdio.h>
#include <windows.h>

int checkinput(char *input)
{
	if (input[0]!='\0' && input[0]!='\n')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int checkbrackets(char *input)
{
	int i, j;
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '(')
		{
			for (j = i; input[j]; j++)
			{
				if (input[j]==')')
				{
					return 1;
				}
			}
			return 0;
		}
	}
	return 0;
}

int main()
{
	char input[100] = "";
	char output[100] = "";
	int q = 0, temp = 0, count1 = 0, count2 = 0, i, j;
	printf("Enter a string:\n");
	fgets(input, 100, stdin);
	while(!checkinput(input) || !checkbrackets(input))
	{
		printf("You entered the wrong string! Try again!\n");
		fgets(input, 100, stdin);
	}
	for (i = 0; input[i]; i++)
	{
		if (input[i]!='(')
		{
			output[q] = input[i];
			q++;
		}
		else if (input[i]=='(')
		{
			output[q] = input[i];
			q++;
			count1++;
			for (j = i+1; input[j]; j++)
			{
				if (input[j]=='(')
				{
					output[q] = input[j];
					q++;
					count1++;
				}
				else if (input[j]==')')
				{
					output[q] = input[j];
					q++;
					count2++;
					temp = j;
				}
				if (count1==count2)
				{
					break;
				}
			}
			if (count2!=0)
			{
				i = temp;
			}
			count1=0;
			count2=0;
		}
	}
	printf("%s", output);
	system("pause");
	return 0;
}