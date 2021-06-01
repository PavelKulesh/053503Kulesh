//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ChangeExpense.h"
#include "Ext.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEditExpense *EditExpense;
//---------------------------------------------------------------------------
__fastcall TEditExpense::TEditExpense(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TEditExpense::DoneClick(TObject *Sender)
{
	if (CheckBox1->Checked == true && ComboBox1->Text == "")
	{
		ShowMessage("Выберите категорию!");
		return;
	}
	if (CheckBox2->Checked == true && Edit1->Text == "")
	{
		ShowMessage("Введите наименование!");
		return;
	}
	if (CheckBox3->Checked == true)
	{
		try
		{
			StrToFloat(Edit2->Text);
		}
		catch (EConvertError &ex)
		{
			ShowMessage("Некорректное значение суммы!");
			return;
		}
	}
	if (CheckBox5->Checked == true && Edit3->Text == "")
	{
		ShowMessage("Введите комментарий!");
		return;
	}
	if (ComboBox1->Enabled == true)
	{
		Expenses[index2[selectrow2-1]].Category = ComboBox1->Text;
	}
	if (Edit1->Enabled == true)
	{
		Expenses[index2[selectrow2-1]].Name = Edit1->Text;
	}
	if (Edit2->Enabled == true)
	{
		Expenses[index2[selectrow2-1]].Sum = StrToFloat(Edit2->Text);
	}
	if (DateTimePicker1->Enabled == true)
	{
		Expenses[index2[selectrow2-1]].Date = DateTimePicker1->Date;
	}
	if (Edit3->Enabled == true)
	{
		Expenses[index2[selectrow2-1]].Comment = Edit3->Text;
	}
	CheckBox1->Checked = false;
	CheckBox2->Checked = false;
	CheckBox3->Checked = false;
	CheckBox4->Checked = false;
	CheckBox5->Checked = false;
	ComboBox1->ItemIndex = -1;
	Edit1->Clear();
	Edit2->Clear();
	DateTimePicker1->Date = Date();
	Edit3->Clear();
	flag = 3;
	EditExpense->Close();
}
//---------------------------------------------------------------------------

void __fastcall TEditExpense::Timer1Timer(TObject *Sender)
{
	if (CheckBox1->Checked == false)
	{
		ComboBox1->ItemIndex = -1;
		ComboBox1->Enabled = false;
	}
	else
	{
		ComboBox1->Enabled = true;
	}
	if (CheckBox2->Checked == false)
	{
		Edit1->Clear();
		Edit1->Enabled = false;
	}
	else
	{
		Edit1->Enabled = true;
	}
	if (CheckBox3->Checked == false)
	{
		Edit2->Clear();
		Edit2->Enabled = false;
	}
	else
	{
		Edit2->Enabled = true;
	}
	if (CheckBox4->Checked == false)
	{
		DateTimePicker1->Date = Date();
		DateTimePicker1->Enabled = false;
	}
	else
	{
		DateTimePicker1->Enabled = true;
	}
	if (CheckBox5->Checked == false)
	{
		Edit3->Clear();
		Edit3->Enabled = false;
	}
	else
	{
		Edit3->Enabled = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TEditExpense::FormClose(TObject *Sender, TCloseAction &Action)
{
	CheckBox1->Checked = false;
	CheckBox2->Checked = false;
	CheckBox3->Checked = false;
	CheckBox4->Checked = false;
	CheckBox5->Checked = false;
	ComboBox1->ItemIndex = -1;
	Edit1->Clear();
	Edit2->Clear();
	DateTimePicker1->Date = Date();
	Edit3->Clear();
}
//---------------------------------------------------------------------------

