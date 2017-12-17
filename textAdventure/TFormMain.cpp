//---------------------------------------------------------------------------
//   textAdventure
// copyright futurerave.uk
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TFormMain.h"
#include "TFormItems.h"
#include "TFormQuest.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
:
	TForm(Owner),
	m_Action(jaStanding),
	m_Room(0)
{
	m_Rooms.resize(4);
	m_Rooms[0].Set(0, "FLAT", "you are in your flat. the door to the street is to your west. (type 'leave', or type 'go west')");
	m_Rooms[1].Set(1, "ALLEY", "you are in the alleyway next to your flat. the club lies to the west. your flat is to the east. a wheelie bin is in front of you.");
	m_Rooms[2].Set(2, "BIN", "you are in the bin.");
	m_Rooms[3].Set(3, "CLUBFRONT", "you are at the front of the club. your flat lies to the east.");



	m_Verbs.resize(10);
	m_Verbs[0].Set("go");
	m_Verbs[1].Set("use");
	m_Verbs[2].Set("take", "lift", "get");
	m_Verbs[3].Set("drop");
	m_Verbs[4].Set("hide in");
	m_Verbs[5].Set("talk to");
	m_Verbs[6].Set("open");
	m_Verbs[7].Set("close");
	m_Verbs[8].Set("leave");
	m_Verbs[9].Set("eat");
	for (DWORD i = 0; i < m_Verbs.size(); i++)
		m_Verbs[i].SetID(i);

	m_Items.resize(1);
	m_Items[0].Set("pizzas", "pizza");
	for (DWORD i = 0; i < m_Items.size(); i++)
		m_Items[i].SetID(i);

	m_NPCs.resize(2);
	m_NPCs[0].Set("bouncer");
	m_NPCs[1].Set("girls", "girl");
	for (DWORD i = 0; i < m_NPCs.size(); i++)
		m_NPCs[i].SetID(i);

	//----
	AddScenic("welcome to scott brown joey riot text adventure!");
	AddScenic("in this game dj scott brown has been jailed for being scottish. playing joey riot, his friend, you have to attempt to free scott from jail!");
	AddScenic("you need to raIse £500 to free scott - the money pays for voice retraining to have a english accent, via irish, then welsh.");
	AddScenic("beware that you are also scottish. try to conceal that in the game.");
	AddScenic("you are starting off in your bare flat. there is no furniture.");
	AddScenic("try not to spend too much cash. bye!!");
	AddScenic("play!");
	AddBlank();
	AddScenic(m_Rooms[m_Room].GetLocationText());

	//----
	randomize();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::AppEventsMessage(tagMSG &Msg, bool &Handled)
{
	if ((Msg.hwnd == Prompt->Handle) &&
										(Msg.message==WM_LBUTTONDOWN || Msg.message==WM_LBUTTONUP || Msg.message==WM_LBUTTONDBLCLK ||
										 Msg.message==WM_RBUTTONUP))
	{
		Handled = true;
		Prompt->SetFocus();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Shape1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
	if (PauseIndicator->Brush->Color == clGray)
	{
		PauseIndicator->Brush->Color = clLime;
		Prompt->ReadOnly = true;
		Timer25s->Enabled = false;
	}
	else
	{
		PauseIndicator->Brush->Color = clGray;
		Prompt->ReadOnly = false;
		Prompt->SetFocus();
		Timer25s->Enabled = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::PromptKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	// ignore these buttons
	if (Key==VK_LEFT || Key==VK_RIGHT || Key==VK_UP || Key==VK_DOWN ||
		Key==VK_PRIOR || Key==VK_NEXT || Key==VK_END || Key==VK_HOME)
	{
		Key = 0;
	}
	// process lines
	if (Key==VK_RETURN)
	{
		ProcessLine();
	}
	// show/hide quest form
	if (Key==VK_F12 && Shift.Contains(ssShift))
	{
		FormQuest->Visible = !FormQuest->Visible;
		SetFocus();
	}
	// show/hide items form
	if (Key==VK_F11 && Shift.Contains(ssShift))
	{
		FormItems->Visible = !FormItems->Visible;
		SetFocus();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::PromptKeyPress(TObject *Sender, char &Key)
{
	if ((Key==0x03) || (Key==0x16) || (Key==0x18)) //ctrl-c, ctrl-v, ctrl-x
	{
		Key = 0; //ignore key press
	}
}
//---------------------------------------------------------------------------
String TFormMain::FindVerb(String S, String &Remainder)
{
	for (DWORD i = 0; i < m_Verbs.size(); i++)
	{
		String r, tmp;
		tmp = m_Verbs[i].FindInString(S, r);

		if (tmp.Length() > 0) {
			Remainder = r;
			return tmp;
		}
	}
	Remainder = S;
	return "";
}
//---------------------------------------------------------------------------
void TFormMain::AddScenic(String Line)
{
	Prompt->SelAttributes->Color = clWhite;
	Prompt->SelText = "> ";
	Prompt->SelAttributes->Color = static_cast<TColor>(0xCC6600);
	Prompt->SelText = Line + "\n";
}
//---------------------------------------------------------------------------
void TFormMain::AddBlank()
{
	Prompt->SelText = "\n";
}
//---------------------------------------------------------------------------
void TFormMain::ProcessLine()
{
	const String line = Prompt->Lines->Strings[Prompt->Lines->Count-1].LowerCase().Trim();

	//----
	String r, verb;
	verb = FindVerb(line, r);

	Prompt->Lines->Strings[Prompt->Lines->Count-1] = "";
	Prompt->SelAttributes->Color = static_cast<TColor>(0x0606F8);
	Prompt->SelText = verb + " ";
	Prompt->SelAttributes->Color = clWhite;
	Prompt->SelText = r + " ";
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Timer25sTimer(TObject *Sender)
{
	m_Action = static_cast<TJoeyAction>(random(5));

	switch(m_Action)
	{
	case jaStanding:
		LabelAction->Caption = "standing";
		break;
	case jaDancing:
		LabelAction->Caption = "dancing";
		break;
	case jaMCing:
		LabelAction->Caption = "mcing";
		break;
	case jaSmiling:
		LabelAction->Caption = "smiling";
		break;
	case jaJumping:
		LabelAction->Caption = "jumping";
		break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormResize(TObject *Sender)
{
	Prompt->Repaint();	
}
//---------------------------------------------------------------------------

