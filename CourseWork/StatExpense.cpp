//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StatExpense.h"
#include "Ext.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStatisticsExpense *StatisticsExpense;
float q1 = 0, q2 = 0, q3 = 0, q4 = 0, q5 = 0, q6 = 0;
//---------------------------------------------------------------------------
__fastcall TStatisticsExpense::TStatisticsExpense(TComponent* Owner)
	: TForm(Owner)
{
	for (int i = 0; i < numExp; i++)
	{
		if (Expenses[i].Category == "Продукты")
		{
			q1+=Expenses[i].Sum;
		}
		if (Expenses[i].Category == "Коммунальные услуги")
		{
			q2+=Expenses[i].Sum;
		}
		if (Expenses[i].Category == "Одежда")
		{
			q3+=Expenses[i].Sum;
		}
		if (Expenses[i].Category == "Учёба")
		{
			q4+=Expenses[i].Sum;
		}
		if (Expenses[i].Category == "Здоровье")
		{
			q5+=Expenses[i].Sum;
		}
		if (Expenses[i].Category == "Прочее" || Expenses[i].Category == "Автомобиль" || Expenses[i].Category == "Транспорт" || Expenses[i].Category == "Еда для питомцев" || Expenses[i].Category == "Техника" || Expenses[i].Category == "Бытовая техника" || Expenses[i].Category == "Мебель" || Expenses[i].Category == "Отдых" || Expenses[i].Category == "Спорт" || Expenses[i].Category == "Развлечения" || Expenses[i].Category == "Транспорт" || Expenses[i].Category == "Банк" || Expenses[i].Category == "Долги")
		{
			q6+=Expenses[i].Sum;
		}
	}
	Series1->Clear();
	Series1->Add(q1, "Продукты", clRed);
	Series1->Add(q2, "Коммуналка", clYellow);
	Series1->Add(q3, "Одежда", clBlue);
	Series1->Add(q4, "Учёба", clPurple);
	Series1->Add(q5, "Здоровье", clWhite);
	Series1->Add(q6, "Прочее", clBlack);
}
//---------------------------------------------------------------------------


void __fastcall TStatisticsExpense::DoneClick(TObject *Sender)
{
	q1 = 0; q2 = 0; q3 = 0; q4 = 0; q5 = 0; q6 = 0;
	for (int i = 0; i < numExp; i++)
	{
		if (Expenses[i].Date >= DateTimePicker1->Date && Expenses[i].Date <= DateTimePicker2->Date)
		{
			if (Expenses[i].Category == "Продукты")
			{
				q1+=Expenses[i].Sum;
			}
			if (Expenses[i].Category == "Коммунальные услуги")
			{
				q2+=Expenses[i].Sum;
			}
			if (Expenses[i].Category == "Одежда")
			{
				q3+=Expenses[i].Sum;
			}
			if (Expenses[i].Category == "Учёба")
			{
				q4+=Expenses[i].Sum;
			}
			if (Expenses[i].Category == "Здоровье")
			{
				q5+=Expenses[i].Sum;
			}
			if (Expenses[i].Category == "Прочее" || Expenses[i].Category == "Автомобиль" || Expenses[i].Category == "Транспорт" || Expenses[i].Category == "Еда для питомцев" || Expenses[i].Category == "Техника" || Expenses[i].Category == "Бытовая техника" || Expenses[i].Category == "Мебель" || Expenses[i].Category == "Отдых" || Expenses[i].Category == "Спорт" || Expenses[i].Category == "Развлечения" || Expenses[i].Category == "Транспорт" || Expenses[i].Category == "Банк" || Expenses[i].Category == "Долги")
			{
				q6+=Expenses[i].Sum;
			}
		}
	}
	Series1->Clear();
	Series1->Add(q1, "Продукты", clRed);
	Series1->Add(q2, "Коммуналка", clYellow);
	Series1->Add(q3, "Одежда", clBlue);
	Series1->Add(q4, "Учёба", clPurple);
	Series1->Add(q5, "Здоровье", clWhite);
	Series1->Add(q6, "Прочее", clBlack);
}
//---------------------------------------------------------------------------

