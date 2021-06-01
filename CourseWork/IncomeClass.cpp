//---------------------------------------------------------------------------

#pragma hdrstop

#include "IncomeClass.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Income* Income::SortUpCat(Income* Arr, int size)
{
	int left = 0;
	int right = size-1;
	int last_swap;
	while (left<right)
	{
		last_swap = 0;
		for (int i = left; i < right; i++)
		{
			if (Arr[i].Category > Arr[i+1].Category)
			{
				Income TempInc;
				TempInc = Arr[i];
				Arr[i] = Arr[i+1];
				Arr[i+1] = TempInc;
				last_swap = i;
			}
		}
		right = last_swap;
		for (int j = right; j > left; j--)
		{
			if (Arr[j].Category < Arr[j-1].Category)
			{
				Income TempInc;
				TempInc = Arr[j];
				Arr[j] = Arr[j-1];
				Arr[j-1] = TempInc;
				last_swap = j;
			}
		}
		left = last_swap;
	}
	return Arr;
}

Income* Income::SortUpName(Income* Arr, int size)
{
	int left = 0;
	int right = size-1;
	int last_swap;
	while (left<right)
	{
		last_swap = 0;
		for (int i = left; i < right; i++)
		{
			if (Arr[i].Name > Arr[i+1].Name)
			{
				Income TempInc;
				TempInc = Arr[i];
				Arr[i] = Arr[i+1];
				Arr[i+1] = TempInc;
				last_swap = i;
			}
		}
		right = last_swap;
		for (int j = right; j > left; j--)
		{
			if (Arr[j].Name < Arr[j-1].Name)
			{
				Income TempInc;
				TempInc = Arr[j];
				Arr[j] = Arr[j-1];
				Arr[j-1] = TempInc;
				last_swap = j;
			}
		}
		left = last_swap;
	}
	return Arr;
}

Income* Income::SortUpSum(Income* Arr, int size)
{
	int left = 0;
	int right = size-1;
	int last_swap;
	while (left<right)
	{
		last_swap = 0;
		for (int i = left; i < right; i++)
		{
			if (Arr[i].Sum > Arr[i+1].Sum)
			{
				Income TempInc;
				TempInc = Arr[i];
				Arr[i] = Arr[i+1];
				Arr[i+1] = TempInc;
				last_swap = i;
			}
		}
		right = last_swap;
		for (int j = right; j > left; j--)
		{
			if (Arr[j].Sum < Arr[j-1].Sum)
			{
				Income TempInc;
				TempInc = Arr[j];
				Arr[j] = Arr[j-1];
				Arr[j-1] = TempInc;
				last_swap = j;
			}
		}
		left = last_swap;
	}
	return Arr;
}

Income* Income::SortUpDate(Income* Arr, int size)
{
	int left = 0;
	int right = size-1;
	int last_swap;
	while (left<right)
	{
		last_swap = 0;
		for (int i = left; i < right; i++)
		{
			if (Arr[i].Date > Arr[i+1].Date)
			{
				Income TempInc;
				TempInc = Arr[i];
				Arr[i] = Arr[i+1];
				Arr[i+1] = TempInc;
				last_swap = i;
			}
		}
		right = last_swap;
		for (int j = right; j > left; j--)
		{
			if (Arr[j].Date < Arr[j-1].Date)
			{
				Income TempInc;
				TempInc = Arr[j];
				Arr[j] = Arr[j-1];
				Arr[j-1] = TempInc;
				last_swap = j;
			}
		}
		left = last_swap;
	}
	return Arr;
}

Income* Income::SortDownCat(Income* Arr, int size)
{
	int left = 0;
	int right = size-1;
	int last_swap;
	while (left<right)
	{
		last_swap = 0;
		for (int i = left; i < right; i++)
		{
			if (Arr[i].Category < Arr[i+1].Category)
			{
				Income TempInc;
				TempInc = Arr[i];
				Arr[i] = Arr[i+1];
				Arr[i+1] = TempInc;
				last_swap = i;
			}
		}
		right = last_swap;
		for (int j = right; j > left; j--)
		{
			if (Arr[j].Category > Arr[j-1].Category)
			{
				Income TempInc;
				TempInc = Arr[j];
				Arr[j] = Arr[j-1];
				Arr[j-1] = TempInc;
				last_swap = j;
			}
		}
		left = last_swap;
	}
	return Arr;
}

Income* Income::SortDownName(Income* Arr, int size)
{
	int left = 0;
	int right = size-1;
	int last_swap;
	while (left<right)
	{
		last_swap = 0;
		for (int i = left; i < right; i++)
		{
			if (Arr[i].Name < Arr[i+1].Name)
			{
				Income TempInc;
				TempInc = Arr[i];
				Arr[i] = Arr[i+1];
				Arr[i+1] = TempInc;
				last_swap = i;
			}
		}
		right = last_swap;
		for (int j = right; j > left; j--)
		{
			if (Arr[j].Name > Arr[j-1].Name)
			{
				Income TempInc;
				TempInc = Arr[j];
				Arr[j] = Arr[j-1];
				Arr[j-1] = TempInc;
				last_swap = j;
			}
		}
		left = last_swap;
	}
	return Arr;
}

Income* Income::SortDownSum(Income* Arr, int size)
{
	int left = 0;
	int right = size-1;
	int last_swap;
	while (left<right)
	{
		last_swap = 0;
		for (int i = left; i < right; i++)
		{
			if (Arr[i].Sum < Arr[i+1].Sum)
			{
				Income TempInc;
				TempInc = Arr[i];
				Arr[i] = Arr[i+1];
				Arr[i+1] = TempInc;
				last_swap = i;
			}
		}
		right = last_swap;
		for (int j = right; j > left; j--)
		{
			if (Arr[j].Sum > Arr[j-1].Sum)
			{
				Income TempInc;
				TempInc = Arr[j];
				Arr[j] = Arr[j-1];
				Arr[j-1] = TempInc;
				last_swap = j;
			}
		}
		left = last_swap;
	}
	return Arr;
}

Income* Income::SortDownDate(Income* Arr, int size)
{
	int left = 0;
	int right = size-1;
	int last_swap;
	while (left<right)
	{
		last_swap = 0;
		for (int i = left; i < right; i++)
		{
			if (Arr[i].Date < Arr[i+1].Date)
			{
				Income TempInc;
				TempInc = Arr[i];
				Arr[i] = Arr[i+1];
				Arr[i+1] = TempInc;
				last_swap = i;
			}
		}
		right = last_swap;
		for (int j = right; j > left; j--)
		{
			if (Arr[j].Date > Arr[j-1].Date)
			{
				Income TempInc;
				TempInc = Arr[j];
				Arr[j] = Arr[j-1];
				Arr[j-1] = TempInc;
				last_swap = j;
			}
		}
		left = last_swap;
	}
	return Arr;
}

