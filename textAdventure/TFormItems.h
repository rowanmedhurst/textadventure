//---------------------------------------------------------------------------
//   textAdventure
// copyright futurerave.uk
//---------------------------------------------------------------------------
#ifndef TFormItemsH
#define TFormItemsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormItems : public TForm
{
__published:
	TMemo *Report;

private:
	void AddLine(String Line);

public:
	__fastcall TFormItems(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TFormItems *FormItems;
//---------------------------------------------------------------------------
#endif
