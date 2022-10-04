//Title: Vegetable.cpp
//Author: Toni Olafunmiloye
//Date: 4/15/2021
//Description: Function definitions for Vegetable.h


#include "Vegetable.h"

Vegetable::Vegetable():AgItem() {
    SetSize(0);
}

int Vegetable::Harvest() {
    //If the vegetable is harvestable (fully mature), returns size to increase farm's food
    int size = GetSize();
    if(GetIsHarvestable()) { 
        return size;
    }
    return 0;
}

void Vegetable::Tick(bool tick) {
    //If the size is less than the maximum vegetable size, increases size
    if(GetSize() < MAX_VEG_SIZE && tick) {
        SetSize(GetSize() + 1);
    } else {
        SetIsHarvestable(true);
    }
}

string Vegetable::GetType() {
    string type = "Vegetable";
    return type;
}

ostream& Vegetable::operator<<(ostream& output) {
    string harvest;
    if(GetIsHarvestable()) {
        harvest = "Harvestable";
    } else {
        harvest = "Not Harvestable";
    }
    output << GetType() << CONCAT << harvest << CONCAT << Veg_Size[GetSize()];;
    return output;
}
