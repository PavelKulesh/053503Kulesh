//---------------------------------------------------------------------------

#ifndef StatIncomeH
#define StatIncomeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
//---------------------------------------------------------------------------
class TStatisticsIncome : public TForm
{
__published:	// IDE-managed Components
	TDateTimePicker *DateTimePicker1;
	TDateTimePicker *DateTimePicker2;
	TLabel *Label1;
	TButton *Done;
	TLabel *Label2;
	TLabel *Label3;
	TChart *Chart1;
	TPieSeries *Series1;
	void __fastcall DoneClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TStatisticsIncome(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TStatisticsIncome *StatisticsIncome;
//---------------------------------------------------------------------------
#endif
