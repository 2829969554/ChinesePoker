/*

该文件实现扑克牌的表示

扑克牌中共有54张牌（四种花色各十三张牌，及大小王）

用八位（即char）即可表示一张扑克牌
其中后四位表示牌型（3,4,5...K,A,2,小王,大王 分别对应1-15）
前四位对应花色（0001梅花，0010黑桃，0011h方块，0100红桃）
拓展：第一位可以用来表示是否为癞子牌
*/

#ifndef STRUCTS_H
#define STRUCTS_H
#include <string>
#include <vector>
#include <assert.h>
#include <algorithm>
typedef char cardColor;
typedef char cardType;
class Card
{
public:
	// 牌的花色
	const static cardColor JOKER = 0x00;
	const static cardColor CLUB = 0x10;
	const static cardColor SPADE = 0x20;
	const static cardColor DIAMOND = 0x30;
	const static cardColor HEART = 0x40;
	// 牌的种类
	const static cardType _3 = 1;
	const static cardType _4 = 2;
	const static cardType _5 = 3;
	const static cardType _6 = 4;
	const static cardType _7 = 5;
	const static cardType _8 = 6;
	const static cardType _9 = 7;
	const static cardType _10 = 8;
	const static cardType _J = 9;
	const static cardType _Q = 10;
	const static cardType _K = 11;
	const static cardType _A = 12;
	const static cardType _2 = 13;
	const static cardType _SMALL = 14;
	const static cardType _BIG = 15;
private:
	// 遮罩
	const static cardColor ColorMask = 0x70;
	const static cardType TypeMask = 0x0f;
	char m_card;

public:
	Card() = delete;
	Card(const Card& card);
	Card(cardColor color, cardType type);
	cardType getType();
	cardColor getColor();
	bool operator<(Card& card);
	bool operator==(Card& card);
	~Card();
};

class CardSet {
private:
	std::vector<Card> m_cards;
public:
	CardSet();
	~CardSet();
	void sort();
	void push(Card card);
	void remove(Card card);
	void remove(int index);
	Card getCard(int index);
	int cardCount();
};

#endif