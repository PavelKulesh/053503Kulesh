//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Income.h"
#include "Expense.h"
#include "SearchIncome.h"
#include "SearchExpense.h"
#include "ChangeIncome.h"
#include "ChangeExpense.h"
#include "StatIncome.h"
#include "StatExpense.h"
#include "Ext.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TExpenseManager *ExpenseManager;
int numInc = 0;
int numExp = 0;
Income *Incomes;
Expense *Expenses;
int flag = 0;
//---------------------------------------------------------------------------
__fastcall TExpenseManager::TExpenseManager(TComponent* Owner)
	: TForm(Owner)
{
	IncomeTable->Cells[0][0] = "Категория";
	IncomeTable->Cells[1][0] = "Наименование";
	IncomeTable->Cells[2][0] = "Сумма(BYN)";
	IncomeTable->Cells[3][0] = "Дата";
	IncomeTable->Cells[4][0] = "Комментарий";
	ExpenseTable->Cells[0][0] = "Категория";
	ExpenseTable->Cells[1][0] = "Наименование";
	ExpenseTable->Cells[2][0] = "Стоимость(BYN)";
	ExpenseTable->Cells[3][0] = "Дата";
	ExpenseTable->Cells[4][0] = "Комментарий";
	TFileStream *tfile1 = new TFileStream("Income.txt",fmOpenReadWrite);
	TStringList *open1 =new TStringList();
	open1->LoadFromStream(tfile1);
	numInc = (open1->Count)/5;
	Incomes = new Income[numInc];
	for (int i = 0, j = 0; j < numInc; i+=5, j++)
	{
		Incomes[j].Category = open1->Strings[i];
		Incomes[j].Name = open1->Strings[i+1];
		Incomes[j].Sum = StrToFloat(open1->Strings[i+2]);
		Incomes[j].Date = open1->Strings[i+3];
		Incomes[j].Comment = open1->Strings[i+4];
	}
	delete open1;
	delete tfile1;
	if (numInc!=0)
	{
		for (int i = 1; i <= numInc; i++)
		{
			IncomeTable->Cells[0][i] = Incomes[i-1].Category;
			IncomeTable->Cells[1][i] = Incomes[i-1].Name;
			IncomeTable->Cells[2][i] = Incomes[i-1].Sum;
			IncomeTable->Cells[3][i] = DateTimeToStr(Incomes[i-1].Date);
			IncomeTable->Cells[4][i] = Incomes[i-1].Comment;
		}
	}
	TFileStream *tfile2 = new TFileStream("Expense.txt",fmOpenReadWrite);
	TStringList *open2 =new TStringList();
	open2->LoadFromStream(tfile2);
	numExp = (open2->Count)/5;
	Expenses = new Expense[numExp];
	for (int i = 0, j = 0; j < numExp; i+=5, j++)
	{
		Expenses[j].Category = open2->Strings[i];
		Expenses[j].Name = open2->Strings[i+1];
		Expenses[j].Sum = StrToFloat(open2->Strings[i+2]);
		Expenses[j].Date = open2->Strings[i+3];
		Expenses[j].Comment = open2->Strings[i+4];
	}
	delete open2;
	delete tfile2;
	if (numExp!=0)
	{
		for (int i = 1; i <= numExp; i++)
		{
			ExpenseTable->Cells[0][i] = Expenses[i-1].Category;
			ExpenseTable->Cells[1][i] = Expenses[i-1].Name;
			ExpenseTable->Cells[2][i] = Expenses[i-1].Sum;
			ExpenseTable->Cells[3][i] = DateTimeToStr(Expenses[i-1].Date);
			ExpenseTable->Cells[4][i] = Expenses[i-1].Comment;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TExpenseManager::IncomeAddClick(TObject *Sender)
{
	IncomeTable->RowCount++;
	AddIncome->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TExpenseManager::ExpenseAddClick(TObject *Sender)
{
	ExpenseTable->RowCount++;
	AddExpense->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TExpenseManager::Find1Click(TObject *Sender)
{
	FindIncome->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TExpenseManager::Find2Click(TObject *Sender)
{
	FindExpense->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TExpenseManager::IncomeStatisticsClick(TObject *Sender)
{
	StatisticsIncome->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TExpenseManager::ExpenseStatisticsClick(TObject *Sender)
{
	StatisticsExpense->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TExpenseManager::Timer1Timer(TObject *Sender)
{
	if (flag == 1)
	{
		if (numInc==0)
		{
			for(int i = 0; i < IncomeTable->ColCount; i++)
			{
				for(int j = 1; j < IncomeTable->RowCount; j++)
				{
					IncomeTable->Cells[i][j] = "";
				}
			}
		}
		else
		{
			for(int i = 0; i < IncomeTable->ColCount; i++)
			{
				for(int j = 1; j < IncomeTable->RowCount; j++)
				{
					IncomeTable->Cells[i][j] = "";
				}
			}
			for (int i = 1; i <= numInc; i++)
			{
				IncomeTable->Cells[0][i] = Incomes[i-1].Category;
				IncomeTable->Cells[1][i] = Incomes[i-1].Name;
				IncomeTable->Cells[2][i] = Incomes[i-1].Sum;
				IncomeTable->Cells[3][i] = DateTimeToStr(Incomes[i-1].Date);
				IncomeTable->Cells[4][i] = Incomes[i-1].Comment;
			}
		}
		if (numExp==0)
		{
			for(int i = 0; i < ExpenseTable->ColCount; i++)
			{
				for(int j = 1; j < ExpenseTable->RowCount; j++)
				{
					ExpenseTable->Cells[i][j] = "";
				}
			}
		}
		else
		{
			for(int i = 0; i < ExpenseTable->ColCount; i++)
			{
				for(int j = 1; j < ExpenseTable->RowCount; j++)
				{
					ExpenseTable->Cells[i][j] = "";
				}
			}
			for (int i = 1; i <= numExp; i++)
			{
				ExpenseTable->Cells[0][i] = Expenses[i-1].Category;
				ExpenseTable->Cells[1][i] = Expenses[i-1].Name;
				ExpenseTable->Cells[2][i] = Expenses[i-1].Sum;
				ExpenseTable->Cells[3][i] = DateTimeToStr(Expenses[i-1].Date);
				ExpenseTable->Cells[4][i] = Expenses[i-1].Comment;
			}
		}
		flag = 0;
	}
}
//---------------------------------------------------------------------------


void __fastcall TExpenseManager::Sort1Click(TObject *Sender)
{
	String What;
	String AscDesc;
	What = ComboBox1->Text;
	AscDesc = ComboBox3->Text;
	if (What == "" || AscDesc == "")
	{
		return;
	}
	else
	{
		if (AscDesc == "Возрастание")
		{
			if (What == "Категория")
			{
				Incomes->SortUpCat(Incomes, numInc);
				if (numInc!=0)
				{
					for (int i = 1; i <= numInc; i++)
					{
						IncomeTable->Cells[0][i] = Incomes[i-1].Category;
						IncomeTable->Cells[1][i] = Incomes[i-1].Name;
						IncomeTable->Cells[2][i] = Incomes[i-1].Sum;
						IncomeTable->Cells[3][i] = DateTimeToStr(Incomes[i-1].Date);
						IncomeTable->Cells[4][i] = Incomes[i-1].Comment;
					}
				}
			}
			else if (What == "Наименование")
			{
				Incomes->SortUpName(Incomes, numInc);
				if (numInc!=0)
				{
					for (int i = 1; i <= numInc; i++)
					{
						IncomeTable->Cells[0][i] = Incomes[i-1].Category;
						IncomeTable->Cells[1][i] = Incomes[i-1].Name;
						IncomeTable->Cells[2][i] = Incomes[i-1].Sum;
						IncomeTable->Cells[3][i] = DateTimeToStr(Incomes[i-1].Date);
						IncomeTable->Cells[4][i] = Incomes[i-1].Comment;
					}
				}
			}
			else if (What == "Сумма(BYN)")
			{
				Incomes->SortUpSum(Incomes, numInc);
				if (numInc!=0)
				{
					for (int i = 1; i <= numInc; i++)
					{
						IncomeTable->Cells[0][i] = Incomes[i-1].Category;
						IncomeTable->Cells[1][i] = Incomes[i-1].Name;
						IncomeTable->Cells[2][i] = Incomes[i-1].Sum;
						IncomeTable->Cells[3][i] = DateTimeToStr(Incomes[i-1].Date);
						IncomeTable->Cells[4][i] = Incomes[i-1].Comment;
					}
				}
			}
			else if (What == "Дата")
			{
				Incomes->SortUpDate(Incomes, numInc);
				if (numInc!=0)
				{
					for (int i = 1; i <= numInc; i++)
					{
						IncomeTable->Cells[0][i] = Incomes[i-1].Category;
						IncomeTable->Cells[1][i] = Incomes[i-1].Name;
						IncomeTable->Cells[2][i] = Incomes[i-1].Sum;
						IncomeTable->Cells[3][i] = DateTimeToStr(Incomes[i-1].Date);
						IncomeTable->Cells[4][i] = Incomes[i-1].Comment;
					}
				}
			}
		}
		else if (AscDesc == "Убывание")
		{
			if (What == "Категория")
			{
				Incomes->SortDownCat(Incomes, numInc);
				if (numInc!=0)
				{
					for (int i = 1; i <= numInc; i++)
					{
						IncomeTable->Cells[0][i] = Incomes[i-1].Category;
						IncomeTable->Cells[1][i] = Incomes[i-1].Name;
						IncomeTable->Cells[2][i] = Incomes[i-1].Sum;
						IncomeTable->Cells[3][i] = DateTimeToStr(Incomes[i-1].Date);
						IncomeTable->Cells[4][i] = Incomes[i-1].Comment;
					}
				}
			}
			else if (What == "Наименование")
			{
				Incomes->SortDownName(Incomes, numInc);
				if (numInc!=0)
				{
					for (int i = 1; i <= numInc; i++)
					{
						IncomeTable->Cells[0][i] = Incomes[i-1].Category;
						IncomeTable->Cells[1][i] = Incomes[i-1].Name;
						IncomeTable->Cells[2][i] = Incomes[i-1].Sum;
						IncomeTable->Cells[3][i] = DateTimeToStr(Incomes[i-1].Date);
						IncomeTable->Cells[4][i] = Incomes[i-1].Comment;
					}
				}
			}
			else if (What == "Сумма(BYN)")
			{
				Incomes->SortDownSum(Incomes, numInc);
				if (numInc!=0)
				{
					for (int i = 1; i <= numInc; i++)
					{
						IncomeTable->Cells[0][i] = Incomes[i-1].Category;
						IncomeTable->Cells[1][i] = Incomes[i-1].Name;
						IncomeTable->Cells[2][i] = Incomes[i-1].Sum;
						IncomeTable->Cells[3][i] = DateTimeToStr(Incomes[i-1].Date);
						IncomeTable->Cells[4][i] = Incomes[i-1].Comment;
					}
				}
			}
			else if (What == "Дата")
			{
				Incomes->SortDownDate(Incomes, numInc);
				if (numInc!=0)
				{
					for (int i = 1; i <= numInc; i++)
					{
						IncomeTable->Cells[0][i] = Incomes[i-1].Category;
						IncomeTable->Cells[1][i] = Incomes[i-1].Name;
						IncomeTable->Cells[2][i] = Incomes[i-1].Sum;
						IncomeTable->Cells[3][i] = DateTimeToStr(Incomes[i-1].Date);
						IncomeTable->Cells[4][i] = Incomes[i-1].Comment;
					}
				}
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TExpenseManager::Sort2Click(TObject *Sender)
{
	String What;
	String AscDesc;
	What = ComboBox2->Text;
	AscDesc = ComboBox4->Text;
	if (What == "" || AscDesc == "")
	{
		return;
	}
	else
	{
		if (AscDesc == "Возрастание")
		{
			if (What == "Категория")
			{
				Expenses->SortUpCat(Expenses, numExp);
				if (numExp!=0)
				{
					for (int i = 1; i <= numExp; i++)
					{
						ExpenseTable->Cells[0][i] = Expenses[i-1].Category;
						ExpenseTable->Cells[1][i] = Expenses[i-1].Name;
						ExpenseTable->Cells[2][i] = Expenses[i-1].Sum;
						ExpenseTable->Cells[3][i] = DateTimeToStr(Expenses[i-1].Date);
						ExpenseTable->Cells[4][i] = Expenses[i-1].Comment;
					}
				}
			}
			else if (What == "Наименование")
			{
				Expenses->SortUpName(Expenses, numExp);
				if (numExp!=0)
				{
					for (int i = 1; i <= numExp; i++)
					{
						ExpenseTable->Cells[0][i] = Expenses[i-1].Category;
						ExpenseTable->Cells[1][i] = Expenses[i-1].Name;
						ExpenseTable->Cells[2][i] = Expenses[i-1].Sum;
						ExpenseTable->Cells[3][i] = DateTimeToStr(Expenses[i-1].Date);
						ExpenseTable->Cells[4][i] = Expenses[i-1].Comment;
					}
				}
			}
			else if (What == "Стоимость(BYN)")
			{
				Expenses->SortUpSum(Expenses, numExp);
				if (numExp!=0)
				{
					for (int i = 1; i <= numExp; i++)
					{
						ExpenseTable->Cells[0][i] = Expenses[i-1].Category;
						ExpenseTable->Cells[1][i] = Expenses[i-1].Name;
						ExpenseTable->Cells[2][i] = Expenses[i-1].Sum;
						ExpenseTable->Cells[3][i] = DateTimeToStr(Expenses[i-1].Date);
						ExpenseTable->Cells[4][i] = Expenses[i-1].Comment;
					}
				}
			}
			else if (What == "Дата")
			{
				Expenses->SortUpDate(Expenses, numExp);
				if (numExp!=0)
				{
					for (int i = 1; i <= numExp; i++)
					{
						ExpenseTable->Cells[0][i] = Expenses[i-1].Category;
						ExpenseTable->Cells[1][i] = Expenses[i-1].Name;
						ExpenseTable->Cells[2][i] = Expenses[i-1].Sum;
						ExpenseTable->Cells[3][i] = DateTimeToStr(Expenses[i-1].Date);
						ExpenseTable->Cells[4][i] = Expenses[i-1].Comment;
					}
				}
			}
		}
		else if (AscDesc == "Убывание")
		{
			if (What == "Категория")
			{
				Expenses->SortDownCat(Expenses, numExp);
				if (numExp!=0)
				{
					for (int i = 1; i <= numExp; i++)
					{
						ExpenseTable->Cells[0][i] = Expenses[i-1].Category;
						ExpenseTable->Cells[1][i] = Expenses[i-1].Name;
						ExpenseTable->Cells[2][i] = Expenses[i-1].Sum;
						ExpenseTable->Cells[3][i] = DateTimeToStr(Expenses[i-1].Date);
						ExpenseTable->Cells[4][i] = Expenses[i-1].Comment;
					}
				}
			}
			else if (What == "Наименование")
			{
				Expenses->SortDownName(Expenses, numExp);
				if (numExp!=0)
				{
					for (int i = 1; i <= numExp; i++)
					{
						ExpenseTable->Cells[0][i] = Expenses[i-1].Category;
						ExpenseTable->Cells[1][i] = Expenses[i-1].Name;
						ExpenseTable->Cells[2][i] = Expenses[i-1].Sum;
						ExpenseTable->Cells[3][i] = DateTimeToStr(Expenses[i-1].Date);
						ExpenseTable->Cells[4][i] = Expenses[i-1].Comment;
					}
				}
			}
			else if (What == "Стоимость(BYN)")
			{
				Expenses->SortDownSum(Expenses, numExp);
				if (numExp!=0)
				{
					for (int i = 1; i <= numExp; i++)
					{
						ExpenseTable->Cells[0][i] = Expenses[i-1].Category;
						ExpenseTable->Cells[1][i] = Expenses[i-1].Name;
						ExpenseTable->Cells[2][i] = Expenses[i-1].Sum;
						ExpenseTable->Cells[3][i] = DateTimeToStr(Expenses[i-1].Date);
						ExpenseTable->Cells[4][i] = Expenses[i-1].Comment;
					}
				}
			}
			else if (What == "Дата")
			{
				Expenses->SortDownDate(Expenses, numExp);
				if (numExp!=0)
				{
					for (int i = 1; i <= numExp; i++)
					{
						ExpenseTable->Cells[0][i] = Expenses[i-1].Category;
						ExpenseTable->Cells[1][i] = Expenses[i-1].Name;
						ExpenseTable->Cells[2][i] = Expenses[i-1].Sum;
						ExpenseTable->Cells[3][i] = DateTimeToStr(Expenses[i-1].Date);
						ExpenseTable->Cells[4][i] = Expenses[i-1].Comment;
					}
				}
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TExpenseManager::fgbf1Click(TObject *Sender)
{
	TStringList* ListForSaving3 = new TStringList;
	ListForSaving3->Clear();
	ListForSaving3->SaveToFile("Income.txt");
	delete ListForSaving3;
	delete[] Incomes;
	numInc = 0;
	Incomes = new Income[numInc];
	TStringList* ListForSaving4 = new TStringList;
	ListForSaving4->Clear();
	ListForSaving4->SaveToFile("Income.txt");
	delete ListForSaving4;
	delete[] Expenses;
	numExp = 0;
	Expenses = new Expense[numExp];
    flag = 1;
}
//---------------------------------------------------------------------------


void __fastcall TExpenseManager::N1Click(TObject *Sender)
{
	TStringList* ListForSaving1 = new TStringList;
	for (int i = 1; i <= numInc; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			ListForSaving1->Add(IncomeTable->Cells[j][i]);
		}
	}
	ListForSaving1->SaveToFile("Income.txt");
	ListForSaving1->Clear();
	delete ListForSaving1;
	TStringList* ListForSaving2 = new TStringList;
	for (int i = 1; i <= numExp; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			ListForSaving2->Add(ExpenseTable->Cells[j][i]);
		}
	}
	ListForSaving2->SaveToFile("Expense.txt");
	ListForSaving2->Clear();
	delete ListForSaving2;
}
//---------------------------------------------------------------------------

