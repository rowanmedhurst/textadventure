//---------------------------------------------------------------------------
//   textAdventure
// copyright futurerave.uk
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TMultiPhrase.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
TMultiPhrase::TMultiPhrase()
:
	m_ID(0)
{
}
//---------------------------------------------------------------------------
void TMultiPhrase::Set(String S)
{
	m_StrVec.clear();
	m_StrVec.push_back(S);
}
//---------------------------------------------------------------------------
void TMultiPhrase::Set(String S1, String S2)
{
	m_StrVec.clear();
	m_StrVec.push_back(S1);
	m_StrVec.push_back(S2);
}
//---------------------------------------------------------------------------
void TMultiPhrase::Set(String S1, String S2, String S3)
{
	m_StrVec.clear();
	m_StrVec.push_back(S1);
	m_StrVec.push_back(S2);
	m_StrVec.push_back(S3);
}
//---------------------------------------------------------------------------
void TMultiPhrase::SetID(int ID)
{
	m_ID = ID;
}
//---------------------------------------------------------------------------
String TMultiPhrase::FindInString(String Input, String &Remainder)
{
	for (DWORD i = 0; i < m_StrVec.size(); i++)
	{
		int pos = Input.Pos(m_StrVec[i]);

		if (pos)
		{
			Remainder = Input.SubString(m_StrVec[i].Length() + 2, Input.Length() - m_StrVec[i].Length() - 1);
			return m_StrVec[i];
		}
	}
	return "";
}
//---------------------------------------------------------------------------

