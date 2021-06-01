//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Expense.h"
#include "Ext.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAddExpense *AddExpense;
//---------------------------------------------------------------------------
__fastcall TAddExpense::TAddExpense(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAddExpense::DoneClick(TObject *Sender)
{
	if (ComboBox1->Text=="")
	{
		ShowMessage("Выберите категорию!");
		return;
	}
	if (Edit1->Text=="")
	{
		ShowMessage("Введите наименование!");
		return;
	}
	try
	{
		StrToFloat(Edit2->Text);
	}
	catch (EConvertError &ex)
	{
		ShowMessage("Некорректное значение стоимости!");
		return;
	}
	if (StrToFloat(Edit2->Text <= 0))
	{
		ShowMessage("Некорректное значение суммы!");
		return;
	}
	Expense *Temp2 = new Expense[numExp];
	for (int i = 0; i < numExp; i++)
	{
		Temp2[i].Category = Expenses[i].Category;
		Temp2[i].Name = Expenses[i].Name;
		Temp2[i].Sum = Expenses[i].Sum;
		Temp2[i].Date = Expenses[i].Date;
		Temp2[i].Comment = Expenses[i].Comment;
	}
	numExp++;
	Expenses = new Expense[numExp];
	for (int i = 0; i < numExp-1; i++)
	{
		Expenses[i].Category = Temp2[i].Category;
		Expenses[i].Name = Temp2[i].Name;
		Expenses[i].Sum = Temp2[i].Sum;
		Expenses[i].Date = Temp2[i].Date;
		Expenses[i].Comment = Temp2[i].Comment;
	}
	Expenses[numExp-1].Category = ComboBox1->Text;
	Expenses[numExp-1].Name = Edit1->Text;
	Expenses[numExp-1].Sum = StrToFloat(Edit2->Text);
	Expenses[numExp-1].Date = DateTimePicker1->Date;
	Expenses[numExp-1].Comment = Edit3->Text;
	delete[] Temp2;
	ComboBox1->ItemIndex = -1;
	Edit1->Clear();
	Edit2->Clear();
	DateTimePicker1->Date = Date();
	Edit3->Clear();
    flag = 1;
	AddExpense->Close();
}
//---------------------------------------------------------------------------

void __fastcall TAddExpense::OnCloseClick(TObject *Sender, TCloseAction &Action)
{
	ComboBox1->ItemIndex = -1;
	Edit1->Clear();
	Edit2->Clear();
	DateTimePicker1->Date = Date();
	Edit3->Clear();
	flag = 1;
}
//---------------------------------------------------------------------------

