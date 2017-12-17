//---------------------------------------------------------------------------
//   textAdventure
// copyright futurerave.uk
//---------------------------------------------------------------------------
#ifndef TFormQuestH
#define TFormQuestH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormQuest : public TForm
{
__published:
	TMemo *Memo;

private:

public:
	__fastcall TFormQuest(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TFormQuest *FormQuest;
//---------------------------------------------------------------------------
#endif
