/*

该文件实现扑克牌的表示

扑克牌中共有54张牌（四种花色各十三张牌，及大小王）

用八位（即char）即可表示一张扑克牌
其中后四位表示牌型（3,4,5...K,A,2,小王,大王 分别对应1-15）
前四位对应花色（0001梅花，0010黑桃，0100h方块，1000红桃）

*/

#ifndef STRUCTS_H
#define STRUCTS_H
#include <string>
#include <assert.h>
typedef unsigned char Card;

// 牌的花色
const Card CLUB = 0x10;
const Card SPADE = 0x20;
const Card DIAMOND = 0x40;
const Card HEART = 0x80;

// 牌的种类
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

// 遮罩
const Card ColorMask = 0xf0;
const Card TypeMask = 0x0f;


inline Card getColor(const Card card);

inline Card getType(const Card card);

// 返回牌所对应的字符串，如“黑桃2”，“梅花K”，“小王”。
// 在调试模式下非法牌将报错，如“黑桃小王”。
std::string CardToString(const Card card);

#endif