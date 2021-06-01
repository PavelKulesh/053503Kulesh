//---------------------------------------------------------------------------

#ifndef IncomeH
#define IncomeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TAddIncome : public TForm
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
	TButton *Done;
	TEdit *Edit3;
	void __fastcall DoneClick(TObject *Sender);
	void __fastcall OnCloseClick(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TAddIncome(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAddIncome *AddIncome;
//---------------------------------------------------------------------------
#endif
