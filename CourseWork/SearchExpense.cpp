//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SearchExpense.h"
#include "ChangeExpense.h"
#include "Ext.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFindExpense *FindExpense;
int* index2 = new int[numExp];
int selectrow2 = 0;
//---------------------------------------------------------------------------
__fastcall TFindExpense::TFindExpense(TComponent* Owner)
	: TForm(Owner)
{
	SearchExpenseTable->Cells[0][0] = "Категория";
	SearchExpenseTable->Cells[1][0] = "Наименование";
	SearchExpenseTable->Cells[2][0] = "Стоимость(BYN)";
	SearchExpenseTable->Cells[3][0] = "Дата";
	SearchExpenseTable->Cells[4][0] = "Комментарий";
	ComboBox1->Enabled = false;
	Edit1->Enabled = false;
	Edit2->Enabled = false;
	DateTimePicker1->Enabled = false;
	Edit3->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TFindExpense::ChangeClick(TObject *Sender)
{
	EditExpense->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFindExpense::Timer1Timer(TObject *Sender)
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
	if (selectrow2!=0 && SearchExpenseTable->Cells[0][selectrow2] != "")
	{
		Change->Enabled = true;
	}
	else
	{
		Change->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFindExpense::SearchClick(TObject *Sender)
{
	for(int i = 0; i < SearchExpenseTable->ColCount; i++)
	{
		for(int j = 1; j < SearchExpenseTable->RowCount; j++)
		{
			SearchExpenseTable->Cells[i][j] = "";
		}
	}
	int count1=0;
	int count2=0;
	Expense Temp;
	if (ComboBox1->Enabled == true && ComboBox1->Text == "")
	{
		ShowMessage("Выберите категорию!");
		return;
	}
	if (Edit1->Enabled == true && Edit1->Text == "")
	{
		ShowMessage("Введите наименование!");
		return;
	}
	Temp.Category = ComboBox1->Text;
	Temp.Name = Edit1->Text;
	if (Edit2->Enabled == true)
	{
		try
		{
			Temp.Sum = StrToFloat(Edit2->Text);
		}
		catch (EConvertError &ex)
		{
			ShowMessage("Некорректное значение стоимости!");
			return;
		}
	}
	Temp.Date = DateTimePicker1->Date;
	if (Edit3->Enabled == true && Edit3->Text == "")
	{
		ShowMessage("Введите комментарий!");
		return;
	}
	Temp.Comment = Edit3->Text;
	if (ComboBox1->Enabled == true)
	{
		count1++;
	}
	if (Edit1->Enabled == true)
	{
		count1++;
	}
	if (Edit2->Enabled == true)
	{
		count1++;
	}
	if (DateTimePicker1->Enabled == true)
	{
		count1++;
	}
	if (Edit3->Enabled == true)
	{
		count1++;
	}
	for (int i = 0, j = 1; i < numExp; i++)
	{
		if (ComboBox1->Enabled == true)
		{
			if (Expenses[i].Category == ComboBox1->Text)
			{
				count2++;
			}
		}
		if (Edit1->Enabled == true)
		{
			if (Expenses[i].Name == Edit1->Text)
			{
				count2++;
			}
		}
		if (Edit2->Enabled == true)
		{
			if (Expenses[i].Sum == StrToFloat(Edit2->Text))
			{
				count2++;
			}
		}
		if (DateTimePicker1->Enabled == true)
		{
			if (Expenses[i].Date == DateTimePicker1->Date)
			{
				count2++;
			}
		}
		if (Edit3->Enabled == true)
		{
			if (Expenses[i].Comment == Edit3->Text)
			{
				count2++;
			}
		}
		if (count1 == count2)
		{
			SearchExpenseTable->Cells[0][j] = Expenses[i].Category;
			SearchExpenseTable->Cells[1][j] = Expenses[i].Name;
			SearchExpenseTable->Cells[2][j] = Expenses[i].Sum;
			SearchExpenseTable->Cells[3][j] = Expenses[i].Date;
			SearchExpenseTable->Cells[4][j] = Expenses[i].Comment;
			index2[j-1] = i;
			j++;
		}
		count2 = 0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFindExpense::FormClose(TObject *Sender, TCloseAction &Action)
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
	for(int i = 0; i < SearchExpenseTable->ColCount; i++)
	{
		for(int j = 1; j < SearchExpenseTable->RowCount; j++)
		{
			SearchExpenseTable->Cells[i][j] = "";
		}
	}
	delete[] index2;
	flag = 1;
}
//---------------------------------------------------------------------------

void __fastcall TFindExpense::DeleteClick(TObject *Sender)
{
	int temp = 0;
	if ((SearchExpenseTable->Cells[0][selectrow2] != "" || SearchExpenseTable->Cells[1][selectrow2] != "" || SearchExpenseTable->Cells[2][selectrow2] != "" || SearchExpenseTable->Cells[3][selectrow2] != "" || SearchExpenseTable->Cells[4][selectrow2] != "") && selectrow2 != 0)
	{
		Expense* Temp2 = new Expense[numExp-1];
		for (int i = 0, j = 0; i < numExp; i++)
		{
			if (Expenses[i].Category == Expenses[index2[selectrow2-1]].Category)
			{
				if (Expenses[i].Name == Expenses[index2[selectrow2-1]].Name)
				{
					if (Expenses[i].Sum == Expenses[index2[selectrow2-1]].Sum)
					{
						if (Expenses[i].Date == Expenses[index2[selectrow2-1]].Date)
						{
							if (Expenses[i].Comment == Expenses[index2[selectrow2-1]].Comment)
							{
								temp--;
								continue;
							}
						}
					}
				}
			}
			Temp2[j] = Expenses[i];
			j++;
		}
		numExp+=temp;
		Expenses = new Expense[numExp];
		for (int i = 0; i < numExp; i++)
		{
			Expenses[i] = Temp2[i];
		}
		delete[] Temp2;
	}
	if (temp < 0)
	{
		SearchExpenseTable->Cells[0][selectrow2] = "";
		SearchExpenseTable->Cells[1][selectrow2] = "";
		SearchExpenseTable->Cells[2][selectrow2] = "";
		SearchExpenseTable->Cells[3][selectrow2] = "";
		SearchExpenseTable->Cells[4][selectrow2] = "";
	}
	flag = 1;
}
//---------------------------------------------------------------------------

void __fastcall TFindExpense::SearchExpenseTableSelectCell(TObject *Sender, int ACol,
		  int ARow, bool &CanSelect)
{
	selectrow2 = ARow;
}
//---------------------------------------------------------------------------

void __fastcall TFindExpense::Timer2Timer(TObject *Sender)
{
	if (flag == 3)
	{
		SearchExpenseTable->Cells[0][selectrow2] = "";
		SearchExpenseTable->Cells[1][selectrow2] = "";
		SearchExpenseTable->Cells[2][selectrow2] = "";
		SearchExpenseTable->Cells[3][selectrow2] = "";
		SearchExpenseTable->Cells[4][selectrow2] = "";
		SearchExpenseTable->Cells[0][selectrow2] = Expenses[index2[selectrow2-1]].Category;
		SearchExpenseTable->Cells[1][selectrow2] = Expenses[index2[selectrow2-1]].Name;
		SearchExpenseTable->Cells[2][selectrow2] = Expenses[index2[selectrow2-1]].Sum;
		SearchExpenseTable->Cells[3][selectrow2] = Expenses[index2[selectrow2-1]].Date;
		SearchExpenseTable->Cells[4][selectrow2] = Expenses[index2[selectrow2-1]].Comment;
		flag = 1;
	}
}
//---------------------------------------------------------------------------

