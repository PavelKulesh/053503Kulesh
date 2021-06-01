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
		if (Expenses[i].Category == "��������")
		{
			q1+=Expenses[i].Sum;
		}
		if (Expenses[i].Category == "������������ ������")
		{
			q2+=Expenses[i].Sum;
		}
		if (Expenses[i].Category == "������")
		{
			q3+=Expenses[i].Sum;
		}
		if (Expenses[i].Category == "�����")
		{
			q4+=Expenses[i].Sum;
		}
		if (Expenses[i].Category == "��������")
		{
			q5+=Expenses[i].Sum;
		}
		if (Expenses[i].Category == "������" || Expenses[i].Category == "����������" || Expenses[i].Category == "���������" || Expenses[i].Category == "��� ��� ��������" || Expenses[i].Category == "�������" || Expenses[i].Category == "������� �������" || Expenses[i].Category == "������" || Expenses[i].Category == "�����" || Expenses[i].Category == "�����" || Expenses[i].Category == "�����������" || Expenses[i].Category == "���������" || Expenses[i].Category == "����" || Expenses[i].Category == "�����")
		{
			q6+=Expenses[i].Sum;
		}
	}
	Series1->Clear();
	Series1->Add(q1, "��������", clRed);
	Series1->Add(q2, "����������", clYellow);
	Series1->Add(q3, "������", clBlue);
	Series1->Add(q4, "�����", clPurple);
	Series1->Add(q5, "��������", clWhite);
	Series1->Add(q6, "������", clBlack);
}
//---------------------------------------------------------------------------


void __fastcall TStatisticsExpense::DoneClick(TObject *Sender)
{
	q1 = 0; q2 = 0; q3 = 0; q4 = 0; q5 = 0; q6 = 0;
	for (int i = 0; i < numExp; i++)
	{
		if (Expenses[i].Date >= DateTimePicker1->Date && Expenses[i].Date <= DateTimePicker2->Date)
		{
			if (Expenses[i].Category == "��������")
			{
				q1+=Expenses[i].Sum;
			}
			if (Expenses[i].Category == "������������ ������")
			{
				q2+=Expenses[i].Sum;
			}
			if (Expenses[i].Category == "������")
			{
				q3+=Expenses[i].Sum;
			}
			if (Expenses[i].Category == "�����")
			{
				q4+=Expenses[i].Sum;
			}
			if (Expenses[i].Category == "��������")
			{
				q5+=Expenses[i].Sum;
			}
			if (Expenses[i].Category == "������" || Expenses[i].Category == "����������" || Expenses[i].Category == "���������" || Expenses[i].Category == "��� ��� ��������" || Expenses[i].Category == "�������" || Expenses[i].Category == "������� �������" || Expenses[i].Category == "������" || Expenses[i].Category == "�����" || Expenses[i].Category == "�����" || Expenses[i].Category == "�����������" || Expenses[i].Category == "���������" || Expenses[i].Category == "����" || Expenses[i].Category == "�����")
			{
				q6+=Expenses[i].Sum;
			}
		}
	}
	Series1->Clear();
	Series1->Add(q1, "��������", clRed);
	Series1->Add(q2, "����������", clYellow);
	Series1->Add(q3, "������", clBlue);
	Series1->Add(q4, "�����", clPurple);
	Series1->Add(q5, "��������", clWhite);
	Series1->Add(q6, "������", clBlack);
}
//---------------------------------------------------------------------------

