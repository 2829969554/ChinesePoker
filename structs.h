#pragma once
/*

该文件中实现扑克牌的表示

扑克牌中共有54张牌（四种花色各十三张牌，及大小王）

用八位（即char）即可表示一张扑克牌
其中后四位表示牌型（3,4,5...K,A,2,小王,大王 分别对应1-15）
前四位对应花色（0001梅花，0010黑桃，0100h方块，1000红桃）

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