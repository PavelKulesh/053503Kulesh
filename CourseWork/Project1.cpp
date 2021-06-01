//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Main.cpp", ExpenseManager);
USEFORM("SearchExpense.cpp", FindExpense);
USEFORM("StatIncome.cpp", StatisticsIncome);
USEFORM("StatExpense.cpp", StatisticsExpense);
USEFORM("SearchIncome.cpp", FindIncome);
USEFORM("Expense.cpp", AddExpense);
USEFORM("ChangeIncome.cpp", EditIncome);
USEFORM("ChangeExpense.cpp", EditExpense);
USEFORM("Income.cpp", AddIncome);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TExpenseManager), &ExpenseManager);
		Application->CreateForm(__classid(TFindExpense), &FindExpense);
		Application->CreateForm(__classid(TFindIncome), &FindIncome);
		Application->CreateForm(__classid(TAddExpense), &AddExpense);
		Application->CreateForm(__classid(TAddIncome), &AddIncome);
		Application->CreateForm(__classid(TEditIncome), &EditIncome);
		Application->CreateForm(__classid(TEditExpense), &EditExpense);
		Application->CreateForm(__classid(TStatisticsIncome), &StatisticsIncome);
		Application->CreateForm(__classid(TStatisticsExpense), &StatisticsExpense);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
