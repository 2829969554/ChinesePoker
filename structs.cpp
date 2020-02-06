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
	// 完全可以打表实现，日后再改进
	std::string s = "";
	Card color = getColor(card);
	Card type = getType(card);

	switch (color)
	{
	case DIAMOND: s += "方块"; break;
	case HEART: s += "红桃"; break;
	case SPADE: s += "黑桃"; break;
	case CLUB: s += "梅花"; break;
	}

	switch (type)
	{
	case _3: s += "3"; break; case _4: s += "4"; break; case _5: s += "5"; break;
	case _6: s += "6"; break; case _7: s += "7"; break; case _8: s += "8"; break;
	case _9: s += "9"; break; case _10: s += "10"; break; case _J: s += "J"; break;
	case _Q: s += "Q"; break; case _K: s += "K"; break; case _A: s += "A"; break;
	case _2: s += "2";
	case JOKER_SMALL:
		assert(s == ""); //大小王不得有花色
		s += "小王";
		break;
	case JOKER_BIG:
		assert(s == ""); //大小王不得有花色
		s += "大王";
		break;
	}
	assert(s != ""); // 是否为无效牌
	return s;
}