#include "helper.h"

std::string toString(Card card)
{
	// ��ȫ���Դ��ʵ�֣��պ��ٸĽ�
	std::string s = "";
	cardColor color = card.getColor();
	cardType type = card.getType();

	switch (color)
	{
	case Card::DIAMOND: s += "����"; break;
	case Card::HEART: s += "����"; break;
	case Card::SPADE: s += "����"; break;
	case Card::CLUB: s += "÷��"; break;
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
		assert(s == ""); //��С�������л�ɫ
		s += "С��";
		break;
	case Card::_BIG:
		assert(s == ""); //��С�������л�ɫ
		s += "����";
		break;
	}
	assert(s != ""); // �Ƿ�Ϊ��Ч��
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