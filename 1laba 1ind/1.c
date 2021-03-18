#include <stdio.h>
#include <stdlib.h>

int main()
{
	float n;
    int summ, i;
	printf("Enter a number: ");
	scanf("%f", &n);
    if (n<=6)
    {
        printf("There are no perfect numbers");
    }
    else
    {
        for (i = 6; i < n; i++)
        {
            summ = 0;
            for (int j = 1; j < i; j++)
                if (i % j == 0)
                    summ += j;
            if (summ == i)
                printf("%d\n", i);
        }
    }
    system("pause");
}