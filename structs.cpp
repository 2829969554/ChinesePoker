#include "structs.h"


inline Card getColor(const Card card)
{
	return card & ColorMask;
}

inline Card getType(const Card card)
{
	return card & TypeMask;
}

std::string CardToString(const Card card)
{
	// ��ȫ���Դ��ʵ�֣��պ��ٸĽ�
	std::string s = "";
	Card color = getColor(card);
	Card type = getType(card);

	switch (color)
	{
	case DIAMOND: s += "����"; break;
	case HEART: s += "����"; break;
	case SPADE: s += "����"; break;
	case CLUB: s += "÷��"; break;
	}

	switch (type)
	{
	case _3: s += "3"; break; case _4: s += "4"; break; case _5: s += "5"; break;
	case _6: s += "6"; break; case _7: s += "7"; break; case _8: s += "8"; break;
	case _9: s += "9"; break; case _10: s += "10"; break; case _J: s += "J"; break;
	case _Q: s += "Q"; break; case _K: s += "K"; break; case _A: s += "A"; break;
	case _2: s += "2";
	case JOKER_SMALL:
		assert(s == ""); //��С�������л�ɫ
		s += "С��";
		break;
	case JOKER_BIG:
		assert(s == ""); //��С�������л�ɫ
		s += "����";
		break;
	}
	assert(s != ""); // �Ƿ�Ϊ��Ч��
	return s;
}