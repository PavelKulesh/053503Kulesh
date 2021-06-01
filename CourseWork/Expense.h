//---------------------------------------------------------------------------

#ifndef ExpenseH
#define ExpenseH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TAddExpense : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TLabel *Label2;
	TLabel *Label3;
	TDateTimePicker *DateTimePicker1;
	TLabel *Label1;
	TComboBox *ComboBox1;
	TEdit *Edit2;
	TLabel *Label5;
	TButton *Done;
	TLabel *Label4;
	TEdit *Edit3;
	void __fastcall DoneClick(TObject *Sender);
	void __fastcall OnCloseClick(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TAddExpense(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAddExpense *AddExpense;
//---------------------------------------------------------------------------
#endif
