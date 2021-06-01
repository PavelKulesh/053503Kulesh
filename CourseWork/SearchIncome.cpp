//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SearchIncome.h"
#include "ChangeIncome.h"
#include "Ext.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFindIncome *FindIncome;
int* index1 = new int[numInc];
int selectrow1 = 0;
//---------------------------------------------------------------------------
__fastcall TFindIncome::TFindIncome(TComponent* Owner)
	: TForm(Owner)
{
	SearchIncomeTable->Cells[0][0] = "Категория";
	SearchIncomeTable->Cells[1][0] = "Наименование";
	SearchIncomeTable->Cells[2][0] = "Сумма(BYN)";
	SearchIncomeTable->Cells[3][0] = "Дата";
	SearchIncomeTable->Cells[4][0] = "Комментарий";
	ComboBox1->Enabled = false;
	Edit1->Enabled = false;
	Edit2->Enabled = false;
	DateTimePicker1->Enabled = false;
	Edit3->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TFindIncome::ChangeClick(TObject *Sender)
{
	EditIncome->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFindIncome::Timer1Timer(TObject *Sender)
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
	if (selectrow1!=0 && SearchIncomeTable->Cells[0][selectrow1] != "")
	{
		Change->Enabled = true;
	}
	else
	{
		Change->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFindIncome::SearchClick(TObject *Sender)
{
	for(int i = 0; i < SearchIncomeTable->ColCount; i++)
	{
		for(int j = 1; j < SearchIncomeTable->RowCount; j++)
		{
			SearchIncomeTable->Cells[i][j] = "";
		}
	}
	int count1=0;
	int count2=0;
	Income Temp;
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
			ShowMessage("Некорректное значение суммы!");
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
	for (int i = 0, j = 1; i < numInc; i++)
	{
		if (ComboBox1->Enabled == true)
		{
			if (Incomes[i].Category == ComboBox1->Text)
			{
				count2++;
			}
		}
		if (Edit1->Enabled == true)
		{
			if (Incomes[i].Name == Edit1->Text)
			{
				count2++;
			}
		}
		if (Edit2->Enabled == true)
		{
			if (Incomes[i].Sum == StrToFloat(Edit2->Text))
			{
				count2++;
			}
		}
		if (DateTimePicker1->Enabled == true)
		{
			if (Incomes[i].Date == DateTimePicker1->Date)
			{
				count2++;
			}
		}
		if (Edit3->Enabled == true)
		{
			if (Incomes[i].Comment == Edit3->Text)
			{
				count2++;
			}
		}
		if (count1 == count2)
		{
			SearchIncomeTable->Cells[0][j] = Incomes[i].Category;
			SearchIncomeTable->Cells[1][j] = Incomes[i].Name;
			SearchIncomeTable->Cells[2][j] = Incomes[i].Sum;
			SearchIncomeTable->Cells[3][j] = Incomes[i].Date;
			SearchIncomeTable->Cells[4][j] = Incomes[i].Comment;
			index1[j-1] = i;
			j++;
		}
		count2 = 0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFindIncome::FormClose(TObject *Sender, TCloseAction &Action)
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
	for(int i = 0; i < SearchIncomeTable->ColCount; i++)
	{
		for(int j = 1; j < SearchIncomeTable->RowCount; j++)
		{
			SearchIncomeTable->Cells[i][j] = "";
		}
	}
	delete[] index1;
	flag = 1;
}
//---------------------------------------------------------------------------

void __fastcall TFindIncome::DeleteClick(TObject *Sender)
{
	int temp = 0;
	if ((SearchIncomeTable->Cells[0][selectrow1] != "" || SearchIncomeTable->Cells[1][selectrow1] != "" || SearchIncomeTable->Cells[2][selectrow1] != "" || SearchIncomeTable->Cells[3][selectrow1] != "" || SearchIncomeTable->Cells[4][selectrow1] != "") && selectrow1 != 0)
	{
		Income* Temp1 = new Income[numInc-1];
		for (int i = 0, j = 0; i < numInc; i++)
		{
			if (Incomes[i].Category == Incomes[index1[selectrow1-1]].Category)
			{
				if (Incomes[i].Name == Incomes[index1[selectrow1-1]].Name)
				{
					if (Incomes[i].Sum == Incomes[index1[selectrow1-1]].Sum)
					{
						if (Incomes[i].Date == Incomes[index1[selectrow1-1]].Date)
						{
							if (Incomes[i].Comment == Incomes[index1[selectrow1-1]].Comment)
							{
								temp--;
								continue;
							}
						}
					}
				}
			}
			Temp1[j] = Incomes[i];
			j++;
		}
		numInc+=temp;
		Incomes = new Income[numInc];
		for (int i = 0; i < numInc; i++)
		{
			Incomes[i] = Temp1[i];
		}
		delete[] Temp1;
	}
	if (temp < 0)
	{
		SearchIncomeTable->Cells[0][selectrow1] = "";
		SearchIncomeTable->Cells[1][selectrow1] = "";
		SearchIncomeTable->Cells[2][selectrow1] = "";
		SearchIncomeTable->Cells[3][selectrow1] = "";
		SearchIncomeTable->Cells[4][selectrow1] = "";
	}
	flag = 1;
}
//---------------------------------------------------------------------------

void __fastcall TFindIncome::SearchIncomeTableSelectCell(TObject *Sender, int ACol,
		  int ARow, bool &CanSelect)
{
	selectrow1 = ARow;
}
//---------------------------------------------------------------------------

void __fastcall TFindIncome::Timer2Timer(TObject *Sender)
{
	if (flag == 2)
	{
		SearchIncomeTable->Cells[0][selectrow1] = "";
		SearchIncomeTable->Cells[1][selectrow1] = "";
		SearchIncomeTable->Cells[2][selectrow1] = "";
		SearchIncomeTable->Cells[3][selectrow1] = "";
		SearchIncomeTable->Cells[4][selectrow1] = "";
		SearchIncomeTable->Cells[0][selectrow1] = Incomes[index1[selectrow1-1]].Category;
		SearchIncomeTable->Cells[1][selectrow1] = Incomes[index1[selectrow1-1]].Name;
		SearchIncomeTable->Cells[2][selectrow1] = Incomes[index1[selectrow1-1]].Sum;
		SearchIncomeTable->Cells[3][selectrow1] = Incomes[index1[selectrow1-1]].Date;
		SearchIncomeTable->Cells[4][selectrow1] = Incomes[index1[selectrow1-1]].Comment;
		flag = 1;
	}
}
//---------------------------------------------------------------------------

