//---------------------------------------------------------------------------
//   textAdventure
// copyright futurerave.uk
//---------------------------------------------------------------------------
#ifndef TFormMainH
#define TFormMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <AppEvnts.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include "TMultiPhrase.h"
#include <vector>
#include "TLocation.h"
//---------------------------------------------------------------------------
using std::vector;
//---------------------------------------------------------------------------
enum TJoeyAction { jaStanding, jaDancing, jaMCing, jaSmiling, jaJumping };
//---------------------------------------------------------------------------

class TFormMain : public TForm
{
__published:
	TPanel *Panel1;
	TLabel *LabelAction;
	TShape *PauseIndicator;
	TApplicationEvents *AppEvents;
	TLabel *Label2;
	TRichEdit *Prompt;
	TShape *Shape1;
	TTimer *Timer25s;
	void __fastcall PromptKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall AppEventsMessage(tagMSG &Msg, bool &Handled);
	void __fastcall PromptKeyPress(TObject *Sender, char &Key);
	void __fastcall Shape1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall Timer25sTimer(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);

private:
	void AddScenic(String Line);
	void AddBlank();
	void ProcessLine();
	String FindVerb(String S, String &Remainder);

	vector<TLocation> m_Rooms;
	int m_Room;
	vector<TMultiPhrase> m_Verbs;
	vector<TMultiPhrase> m_Items;
	vector<TMultiPhrase> m_NPCs;
	TJoeyAction m_Action;

public:
	__fastcall TFormMain(TComponent* Owner);
};


//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
