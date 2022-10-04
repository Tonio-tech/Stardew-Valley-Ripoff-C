//Title: Tree.cpp
//Author: Toni Olafunmiloye
//Date: 4/15/2021
//Description: Function definitions for Tree.h


#include "Tree.h"

Tree::Tree():AgItem() {
    SetSize(0);
    m_age = 0;
}

Tree::~Tree() {
    if(m_fruit.size()) {
        for(unsigned int i = 0; i < m_fruit.size(); i++) {
            //All fruit is purged from tree.
            delete m_fruit.at(i);
        }
    }
}

void Tree::Tick(bool tick) {
    //Tree is not Mature yet and ages. Every 4 seasons, size increases til age 12 when fruits
    if(m_age < SEASONS_TO_FRUIT) {
        if(m_age % SEASONS_TO_SIZE == 0 && GetSize() < 3) {
            SetSize(GetSize() + 1);
        }
    }

    //Tree is Mature and grows a one fruit a season. Fruit is harvested every season.
    if(m_age > SEASONS_TO_FRUIT && tick) { //LEAKING MEMORY
        Fruit *fptr = new Fruit;
        m_fruit.push_back(fptr);
    }
    
    //Tree is 60 seasons old and is cut down (IsHarvesteable)
    if(m_age >= SEASONS_TO_HARVEST) {
        SetIsHarvestable(true);
    }
    
    m_age++;
}

int Tree::Harvest() {
    //If there is fruit, removes last fruit and returns 1. 
    if(!m_fruit.empty()) {
        delete m_fruit.at(m_fruit.size() - 1);
        m_fruit.pop_back();
        return 1;
    }

    //If 60 seasons old aka its harvetsbale, returns 0
    if(GetIsHarvestable()) {
        return 0;
    }

    return 0;
}

string Tree::GetType() {
    string name = "Tree";
    return name;
}

ostream& Tree::operator<<(ostream& output) {
    string harvest;
    string fruiting;

    //if it is harvetable, print harvestable
    if(GetIsHarvestable()) {
        harvest = "Harvestable";
    } else {
        harvest = "Not Harvestable";
    }

    //if the tree is at the fruiting age, print fruiting
    if(m_age > SEASONS_TO_FRUIT) {
        fruiting = "Fruiting";
    } else {
        fruiting = "Not Friuiting";
    }
    
    output << GetType() << CONCAT << TREE_SIZE[GetSize()] << CONCAT << harvest << CONCAT << fruiting << CONCAT << "Fruit Count: " << m_fruit.size();
    // Tree  | Seedling | Not Harvestable | Not Fruiting | Fruit Count: 0
    return output;
}