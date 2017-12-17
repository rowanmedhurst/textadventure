//---------------------------------------------------------------------------
//   textAdventure
// copyright futurerave.uk
//---------------------------------------------------------------------------
#ifndef TMultiPhraseH
#define TMultiPhraseH
//---------------------------------------------------------------------------
#include <vector>
//---------------------------------------------------------------------------
using std::vector;
//---------------------------------------------------------------------------
class TMultiPhrase
{
public:
	TMultiPhrase();
	void Set(String S);
	void Set(String S1, String S2);
	void Set(String S1, String S2, String S3);
	void SetID(int ID);
	String FindInString(String Input, String &Remainder);

private:
	vector<String> m_StrVec;
	int m_ID;
};


//---------------------------------------------------------------------------
#endif
