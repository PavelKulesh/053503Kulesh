//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StatIncome.h"
#include "Ext.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStatisticsIncome *StatisticsIncome;
float x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0;
//---------------------------------------------------------------------------
__fastcall TStatisticsIncome::TStatisticsIncome(TComponent* Owner)
	: TForm(Owner)
{
	for (int i = 0; i < numInc; i++)
	{
		if (Incomes[i].Category == "Зарплата")
		{
			x1+=Incomes[i].Sum;
		}
		if (Incomes[i].Category == "Бизнес")
		{
			x2+=Incomes[i].Sum;
		}
		if (Incomes[i].Category == "Акции")
		{
			x3+=Incomes[i].Sum;
		}
		if (Incomes[i].Category == "Банк")
		{
			x4+=Incomes[i].Sum;
		}
		if (Incomes[i].Category == "Подработка")
		{
			x5+=Incomes[i].Sum;
		}
		if (Incomes[i].Category == "Прочее")
		{
			x6+=Incomes[i].Sum;
		}
	}
	Series1->Clear();
	Series1->Add(x1, "Зарплата", clRed);
	Series1->Add(x2, "Бизнес", clYellow);
	Series1->Add(x3, "Акции", clBlue);
	Series1->Add(x4, "Банк", clPurple);
	Series1->Add(x5, "Подработка", clWhite);
	Series1->Add(x6, "Прочее", clBlack);
}
//---------------------------------------------------------------------------
void __fastcall TStatisticsIncome::DoneClick(TObject *Sender)
{
	x1 = 0; x2 = 0; x3 = 0; x4 = 0; x5 = 0; x6 = 0;
	for (int i = 0; i < numInc; i++)
	{
		if (Incomes[i].Date >= DateTimePicker1->Date && Incomes[i].Date <= DateTimePicker2->Date)
		{
			if (Incomes[i].Category == "Зарплата")
			{
				x1+=Incomes[i].Sum;
			}
			if (Incomes[i].Category == "Бизнес")
			{
				x2+=Incomes[i].Sum;
			}
			if (Incomes[i].Category == "Акции")
			{
				x3+=Incomes[i].Sum;
			}
			if (Incomes[i].Category == "Банк")
			{
				x4+=Incomes[i].Sum;
			}
			if (Incomes[i].Category == "Подработка")
			{
				x5+=Incomes[i].Sum;
			}
			if (Incomes[i].Category == "Прочее")
			{
				x6+=Incomes[i].Sum;
			}
		}
	}
	Series1->Clear();
	Series1->Add(x1, "Зарплата", clRed);
	Series1->Add(x2, "Бизнес", clYellow);
	Series1->Add(x3, "Акции", clBlue);
	Series1->Add(x4, "Банк", clPurple);
	Series1->Add(x5, "Подработка", clWhite);
	Series1->Add(x6, "Прочее", clBlack);
}
//---------------------------------------------------------------------------

