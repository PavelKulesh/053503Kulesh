//---------------------------------------------------------------------------

#ifndef IncomeClassH
#define IncomeClassH
#include <vcl.h>
//---------------------------------------------------------------------------
#endif

class Income
{
	public:
	String Category;
	String Name;
	double Sum;
	TDateTime Date;
	String Comment;
	Income* SortUpCat(Income* Arr, int size);
	Income* SortUpName(Income* Arr, int size);
	Income* SortUpSum(Income* Arr, int size);
	Income* SortUpDate(Income* Arr, int size);
	Income* SortDownCat(Income* Arr, int size);
	Income* SortDownName(Income* Arr, int size);
	Income* SortDownSum(Income* Arr, int size);
	Income* SortDownDate(Income* Arr, int size);
};
