#include "structs.h"

Card::Card(const Card& card)
{
	m_card = card.m_card;
}

Card::Card(cardColor color, cardType type)
{
	m_card = color | type;
}

cardType Card::getType()
{
	return m_card & TypeMask;
}

cardColor Card::getColor()
{
	return m_card & ColorMask;
}

bool Card::operator<(Card& card)
{
	cardType selfType = getType();
	cardType cardType = card.getType();

	return selfType == cardType ? getColor() < card.getColor() : selfType < cardType;
}

bool Card::operator==(Card& card)
{
	return getColor() == card.getColor() && getType() == card.getType();
}

Card::~Card() {}

CardSet::CardSet()
{
	m_cards.clear();
}

CardSet::~CardSet() {}

void CardSet::sort()
{
	std::sort(m_cards.begin(), m_cards.end());
}

void CardSet::push(Card card)
{
	m_cards.push_back(card);
}

void CardSet::remove(Card card)
{
	for (auto it = m_cards.begin(); it != m_cards.end(); ++it)
		if (*it == card)
		{
			m_cards.erase(it);
			return;
		}
}

void CardSet::remove(int index)
{
	remove(getCard(index));
}

void CardSet::swap(int indexA, int indexB)
{
	assert(indexA >= 0 && indexA < m_cards.size());
	assert(indexB >= 0 && indexB < m_cards.size());
	std::swap(m_cards[indexA], m_cards[indexB]);
}

Card CardSet::getCard(int index)
{
	assert(index >= 0 && index < m_cards.size());
	return m_cards[index];
}

int CardSet::cardCount()
{
	return m_cards.size();
}
