//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TExpenseManager : public TForm
{
__published:	// IDE-managed Components
	TButton *ExpenseAdd;
	TLabel *Label1;
	TLabel *Label2;
	TStringGrid *ExpenseTable;
	TButton *Find1;
	TStringGrid *IncomeTable;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TLabel *Label3;
	TLabel *Label4;
	TButton *Sort1;
	TButton *Sort2;
	TComboBox *ComboBox3;
	TComboBox *ComboBox4;
	TButton *Find2;
	TButton *IncomeStatistics;
	TButton *ExpenseStatistics;
	TButton *IncomeAdd;
	TTimer *Timer1;
	TMainMenu *MainMenu1;
	TMenuItem *fgbf1;
	TMenuItem *N1;
	TMenuItem *N2;
	void __fastcall ExpenseAddClick(TObject *Sender);
	void __fastcall Find1Click(TObject *Sender);
	void __fastcall Find2Click(TObject *Sender);
	void __fastcall IncomeAddClick(TObject *Sender);
	void __fastcall IncomeStatisticsClick(TObject *Sender);
	void __fastcall ExpenseStatisticsClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Sort1Click(TObject *Sender);
	void __fastcall Sort2Click(TObject *Sender);
	void __fastcall fgbf1Click(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TExpenseManager(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TExpenseManager *ExpenseManager;
//---------------------------------------------------------------------------
#endif
