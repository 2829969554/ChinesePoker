#pragma once
/*

���ļ���ʵ���˿��Ƶı�ʾ

�˿����й���54���ƣ����ֻ�ɫ��ʮ�����ƣ�����С����

�ð�λ����char�����ɱ�ʾһ���˿���
���к���λ��ʾ���ͣ�3,4,5...K,A,2,С��,���� �ֱ��Ӧ1-15��
ǰ��λ��Ӧ��ɫ��0001÷����0010���ң�0100h���飬1000���ң�

*/
#include <string>
#include <assert.h>
typedef unsigned char Card;

// CardColor
const Card CLUB = 0x10;
const Card SPADE = 0x20;
const Card DIAMOND = 0x40;
const Card HEART = 0x80;

// CardType
const Card _3 = 1;
const Card _4 = 2;
const Card _5 = 3;
const Card _6 = 4;
const Card _7 = 5;
const Card _8 = 6;
const Card _9 = 7;
const Card _10 = 8;
const Card _J = 9;
const Card _Q = 10;
const Card _K = 11;
const Card _A = 12;
const Card _2 = 13;
const Card JOKER_SMALL = 14;
const Card JOKER_BIG = 15;

// Masks
const Card ColorMask = 0xf0;
const Card TypeMask = 0x0f;


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