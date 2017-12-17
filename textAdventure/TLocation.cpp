//---------------------------------------------------------------------------
//   textAdventure
// copyright futurerave.uk
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TLocation.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
TLocation::TLocation()
:
	m_ID(0)
{
}
//---------------------------------------------------------------------------
void TLocation::Set(int ID, String TextName, String MainText)
{
	m_ID = ID;
	m_TextName = TextName;
	m_MainText = MainText;
}
//---------------------------------------------------------------------------
void TLocation::AddItem(int ItemID)
{
	m_ItemIDs.push_back(ItemID);
}
//---------------------------------------------------------------------------
void TLocation::AddNPC(int NPCID)
{
	m_NPCIDs.push_back(NPCID);
}
//---------------------------------------------------------------------------
void TLocation::TakeItem(int ItemID)
{
	m_ItemIDs.remove(ItemID);
}
//---------------------------------------------------------------------------
String TLocation::GetLocationText()
{
	return m_MainText;
}
//---------------------------------------------------------------------------

