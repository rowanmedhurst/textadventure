//---------------------------------------------------------------------------
//   textAdventure
// copyright futurerave.uk
//---------------------------------------------------------------------------
#ifndef TLocationH
#define TLocationH
//---------------------------------------------------------------------------
#include <list>
//---------------------------------------------------------------------------
using std::list;
//---------------------------------------------------------------------------
class TLocation
{
public:
	TLocation();
	void Set(int ID, String TextName, String MainText);
	void AddItem(int ItemID);
	void AddNPC(int NPCID);
	void TakeItem(int ItemID);
	String GetLocationText();

private:
	int m_ID;
	String m_TextName;
	String m_MainText;
	list<int> m_ItemIDs;
	list<int> m_NPCIDs;
};

//---------------------------------------------------------------------------
#endif
