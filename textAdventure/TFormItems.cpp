//---------------------------------------------------------------------------
//   textAdventure
// copyright futurerave.uk
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TFormItems.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormItems *FormItems;
//---------------------------------------------------------------------------
__fastcall TFormItems::TFormItems(TComponent* Owner)
:
	TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TFormItems::AddLine(String Line)
{
	Report->Lines->Add(Line);
}
//---------------------------------------------------------------------------

