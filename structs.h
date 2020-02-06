/*

���ļ�ʵ���˿��Ƶı�ʾ

�˿����й���54���ƣ����ֻ�ɫ��ʮ�����ƣ�����С����

�ð�λ����char�����ɱ�ʾһ���˿���
���к���λ��ʾ���ͣ�3,4,5...K,A,2,С��,���� �ֱ��Ӧ1-15��
ǰ��λ��Ӧ��ɫ��0001÷����0010���ң�0100h���飬1000���ң�

*/

#ifndef STRUCTS_H
#define STRUCTS_H
#include <string>
#include <assert.h>
typedef unsigned char Card;

// �ƵĻ�ɫ
const Card CLUB = 0x10;
const Card SPADE = 0x20;
const Card DIAMOND = 0x40;
const Card HEART = 0x80;

// �Ƶ�����
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

// ����
const Card ColorMask = 0xf0;
const Card TypeMask = 0x0f;


inline Card getColor(const Card card);

inline Card getType(const Card card);

// ����������Ӧ���ַ������硰����2������÷��K������С������
// �ڵ���ģʽ�·Ƿ��ƽ������硰����С������
std::string CardToString(const Card card);

#endif