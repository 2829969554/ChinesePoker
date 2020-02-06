#include "helper.h"

std::string toString(Card card)
{
	// 完全可以打表实现，日后再改进
	std::string s = "";
	cardColor color = card.getColor();
	cardType type = card.getType();

	switch (color)
	{
	case Card::DIAMOND: s += "方块"; break;
	case Card::HEART: s += "红桃"; break;
	case Card::SPADE: s += "黑桃"; break;
	case Card::CLUB: s += "梅花"; break;
	case Card::JOKER: s += ""; break;
	default:
		assert(false);
	}

	switch (type)
	{
	case Card::_3: s += "3"; break; case Card::_4: s += "4"; break; case Card::_5: s += "5"; break;
	case Card::_6: s += "6"; break; case Card::_7: s += "7"; break; case Card::_8: s += "8"; break;
	case Card::_9: s += "9"; break; case Card::_10: s += "10"; break; case Card::_J: s += "J"; break;
	case Card::_Q: s += "Q"; break; case Card::_K: s += "K"; break; case Card::_A: s += "A"; break;
	case Card::_2: s += "2"; break;
	case Card::_SMALL:
		assert(s == ""); //大小王不得有花色
		s += "小王";
		break;
	case Card::_BIG:
		assert(s == ""); //大小王不得有花色
		s += "大王";
		break;
	}
	assert(s != ""); // 是否为无效牌
	return s;
}
std::string toString(CardSet& cardset)
{
	std::string s = "";
	int n = cardset.cardCount();
	for (int i = 0; i < n; ++i)
	{
		s += toString(cardset.getCard(i));
		s += ", ";
	}
	return s;
}