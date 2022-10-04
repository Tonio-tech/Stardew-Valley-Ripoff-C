//Title: AgItem.cpp
//Author: Toni Olafunmiloye
//Date: 4/15/2021
//Description: Function definitions for AgItem.h, the parent class of Animal, Tree, and Vegetable


#include "AgItem.h"

AgItem::AgItem() {
    SetSize(0);
    SetWorth(BASE_WORTH);
    SetIsHarvestable(false);
}

AgItem::AgItem(int size, int worth, bool harvest) {
    m_size = size;
    m_worth = worth;
    m_isHarvestable = harvest;
}

AgItem::~AgItem() {
    m_size = 0;
    m_worth = 0;
    m_isHarvestable = true;
}

int AgItem::GetSize() {return m_size;}

int AgItem::GetWorth() {return m_worth;}

bool AgItem::GetIsHarvestable() {return m_isHarvestable;}

void AgItem::SetSize(int size) {m_size = size;}

void AgItem::SetIsHarvestable(bool harvest) {m_isHarvestable = harvest;}

void AgItem::SetWorth(int worth) {m_worth = worth;}


