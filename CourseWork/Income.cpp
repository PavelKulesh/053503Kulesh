//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Income.h"
#include "Ext.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAddIncome *AddIncome;
//---------------------------------------------------------------------------
__fastcall TAddIncome::TAddIncome(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAddIncome::DoneClick(TObject *Sender)
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
		ShowMessage("Некорректное значение суммы!");
		return;
	}
	if (StrToFloat(Edit2->Text <= 0))
	{
		ShowMessage("Некорректное значение суммы!");
		return;
	}
	Income *Temp1 = new Income[numInc];
	for (int i = 0; i < numInc; i++)
	{
		Temp1[i].Category = Incomes[i].Category;
		Temp1[i].Name = Incomes[i].Name;
		Temp1[i].Sum = Incomes[i].Sum;
		Temp1[i].Date = Incomes[i].Date;
		Temp1[i].Comment = Incomes[i].Comment;
	}
	numInc++;
	Incomes = new Income[numInc];
	for (int i = 0; i < numInc-1; i++)
	{
		Incomes[i].Category = Temp1[i].Category;
		Incomes[i].Name = Temp1[i].Name;
		Incomes[i].Sum = Temp1[i].Sum;
		Incomes[i].Date = Temp1[i].Date;
		Incomes[i].Comment = Temp1[i].Comment;
	}
	Incomes[numInc-1].Category = ComboBox1->Text;
	Incomes[numInc-1].Name = Edit1->Text;
	Incomes[numInc-1].Sum = StrToFloat(Edit2->Text);
	Incomes[numInc-1].Date = DateTimePicker1->Date;
	Incomes[numInc-1].Comment = Edit3->Text;
	delete[] Temp1;
	ComboBox1->ItemIndex = -1;
	Edit1->Clear();
	Edit2->Clear();
	DateTimePicker1->Date = Date();
	Edit3->Clear();
	flag = 1;
	AddIncome->Close();
}
//---------------------------------------------------------------------------

void __fastcall TAddIncome::OnCloseClick(TObject *Sender, TCloseAction &Action)
{
	ComboBox1->ItemIndex = -1;
	Edit1->Clear();
	Edit2->Clear();
	DateTimePicker1->Date = Date();
	Edit3->Clear();
    flag = 1;
}
//---------------------------------------------------------------------------

