//---------------------------------------------------------------------------

#ifndef SearchIncomeH
#define SearchIncomeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFindIncome : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label1;
	TLabel *Label5;
	TLabel *Label4;
	TEdit *Edit1;
	TDateTimePicker *DateTimePicker1;
	TComboBox *ComboBox1;
	TEdit *Edit2;
	TButton *Search;
	TEdit *Edit3;
	TStringGrid *SearchIncomeTable;
	TButton *Delete;
	TButton *Change;
	TLabel *Label6;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TCheckBox *CheckBox5;
	TTimer *Timer1;
	TTimer *Timer2;
	void __fastcall ChangeClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall SearchClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall DeleteClick(TObject *Sender);
	void __fastcall SearchIncomeTableSelectCell(TObject *Sender, int ACol, int ARow,
		  bool &CanSelect);
	void __fastcall Timer2Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFindIncome(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFindIncome *FindIncome;
//---------------------------------------------------------------------------
#endif
