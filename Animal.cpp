//Title: Animal.cpp
//Author: Toni Olafunmiloye
//Date: 4/15/2021
//Description: Function definitions for Animal.h


#include "AgItem.h"
#include "Animal.h"

Animal::Animal():AgItem() {
    SetSize(0);
}

void Animal::Tick(bool isFed) {
    //Animal is fed and size increases (not max yet)
    if(isFed) {
        m_IsHungry = false;
        if(GetSize() < ANIMAL_MAX_SIZE) {
            SetSize(GetSize() + 1);
            //Animal is fed hits max size and is made harvestable
        } else if(GetSize() >= ANIMAL_MAX_SIZE) {
            SetIsHarvestable(true);
        }
    } else {
        //Animal is not fed. Size does not increase. If second no feed, is harvested (small).
        if(m_IsHungry) {
            SetIsHarvestable(true);
        }
    }
}

int Animal::Harvest() {
    //If the animal is harvestable (adult), returns worth * size to increase farm's money
    if(GetIsHarvestable()) { 
        return GetWorth() * GetSize();
    }
    return 0;
}

string Animal::GetType() {
    string type = "Animal";
    return type;
}

ostream& Animal::operator<<(ostream& output) {
    string harvest = "Harvestable";
    string fed = "Fed";

    if(GetIsHarvestable()) {
        harvest = "Harvestable";
    } else {
        harvest = "Not Harvestable";
    }

    if(m_IsHungry) {
        fed = "Not Fed";
    } else {
        fed = "Fed";
    }
    output << GetType() << CONCAT << " Chicken " << CONCAT << harvest << CONCAT << ANIMAL_SIZE[GetSize()] << CONCAT << fed;
    return output;
}