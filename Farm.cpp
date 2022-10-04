//Title: Farm.cpp
//Author: Toni Olafunmiloye
//Date: 4/15/2021
//Description: Function definitions for Farm.h, manages the simulation


#include "Farm.h"

Farm::Farm() {
    m_food = SIX;
    m_money = 0;
    m_season = ONE;
}

Farm::~Farm() {
    // delete each pointer in the vector
    for(unsigned int i = 0; i < m_farm.size(); i++) {
        delete m_farm.at(i);
    }
}

int Farm::ChooseItem() {
    //user choose either 1 (animal), 2 (vegetable), or 3 (tree) (reprompts for anything else)
    int choice;

    cout << "Which agricultural item are you interested in? " << endl;
    cout << "1. Animal " << endl << "2. Vegetable " << endl << "3. Tree " << endl;
    cin >> choice;

    while(choice > THREE || choice < ONE) {
        cout << "Which agricultural item are you interested in? " << endl;
        cout << "1. Animal " << endl << "2. Vegetable " << endl << "3. Tree " << endl;
        cin >> choice;
    }

    return choice;
}

void Farm::AddItem(int type, int quantity) { 
    // if they choose one add an animal
    if(type == ONE) {
        for(int i = 0; i < quantity; i++) {
            Animal *aptr = new Animal();
            m_farm.push_back(aptr);
            cout << "New Animal added to the farm" << endl;
        }
    }
    
    // if they choose two add an vegetable
    if(type == TWO) {
        for(int i = 0; i < quantity; i++) {
            Vegetable *vptr = new Vegetable();
            m_farm.push_back(vptr);
            cout << "New Vegetable added to the farm" << endl;
        }
    }

    // if they choose three add an tree
    if(type == THREE) {
        for(int i = 0; i < quantity; i++) {
            Tree *tptr = new Tree();
            m_farm.push_back(tptr);
            cout << "New Tree added to the farm" << endl;
        }
    }
}

void Farm::Tick(int tick) { 
    int size = 0;

    for(int i = 0; i < tick; i++) {
        if(!m_farm.empty()) {
            for(vector<AgItem*>::iterator it = m_farm.begin() ; it != m_farm.end(); ++it) {

                if((*it)->GetType() == "Vegetable") {
                    (*it)->Tick(true);
                    size = (*it)->Harvest();
                    m_food += size;
                    if((*it)->GetIsHarvestable()) {
                        cout << "The " << (*it)->GetType() << " was harvested in SEASON " << m_season << endl;
                        //delete and remove the harvested item from the farm
                        delete *it;
                        m_farm.erase(it--);
                    }
                }

                else if((*it)->GetType() == "Tree") {
                    (*it)->Tick(true);
                    size = (*it)->Harvest();
                    m_food += size;
                    if((*it)->GetIsHarvestable()) {
                        cout << "The " << (*it)->GetType() << " was harvested in SEASON " << m_season << endl;
                        //delete and remove the harvested item from the farm
                        delete *it;
                        m_farm.erase(it--);
                    }
                }

                else if((*it)->GetType() == "Animal") {
                    //if theres no food, animals cant eat
                    if(m_food <= 0) {
                        (*it)->Tick(false);
                    } else {
                        (*it)->Tick(true);
                        // once animals eat, the food decreases
                        m_food--;
                        size = (*it)->Harvest();
                        m_money += size;
                        if((*it)->GetIsHarvestable()) {
                            cout << "The " << (*it)->GetType() << " was harvested in SEASON " << m_season << endl;
                            //delete and remove the harvested item from the farm
                            delete *it;
                            m_farm.erase(it--);
                        }

                    }
                }
            }
        }
        Status();
        m_season++;
    }
}

int Farm::Menu() { 
    int choice = 0;
    int item = 0;
    int season = 0;
    do {
        cout << "1. Add Item to Farm" << endl <<
                "2. Add Two of Each Item to Farm" << endl <<
                "3. Simulate Time" << endl <<
                "4. Farm Status" << endl <<
                "5. Quit " << endl;
        cin >> choice;

        while(choice > 5 || choice < 1) {
            cout << "1. Add Item to Farm" << endl <<
                    "2. Add Two of Each Item to Farm" << endl <<
                    "3. Simulate Time" << endl <<
                    "4. Farm Status" << endl <<
                    "5. Quit " << endl;
            cin >> choice;
        }

        if(choice == ONE) {
            item = ChooseItem();
            AddItem(item, ONE); 
        }

        if(choice == TWO) {
            //animal 
            AddItem(ONE, TWO);
            //vegetable
            AddItem(TWO, TWO);
            //tree 
            AddItem(THREE, TWO);
        }      

        if(choice == THREE) {
            cout << "How many seasons to simulate? " << endl;
            cin >> season;
            cout << endl;
            Tick(season); 
        }  

        if(choice == FOUR) {
            Status();
        } 

    } while(choice != FIVE);

    return choice;
}

void Farm::StartSimulation() { 
    //Manages the introduction, menu, and quitting
    //as long as 5 isnt pressed, keeps running
    int choice = 0; 
    cout << endl << endl;
    cout << "Welcome to the Stardew Valley Simulator!" << endl;
    choice = Menu();
    while(choice != FIVE) {
        Menu();
    }

}

void Farm::Status() {
    //Displays farm food, money, season, and each agricultural item
    cout << "SEASON: " << m_season << endl;
    cout << "**** Farm Status ****" << endl << endl;

    cout << "Food: " << m_food << endl;
    cout << "Money: " << m_money << endl;
    cout << "Season: " << m_season << endl << endl;

    cout << "Agricultural Items: " << endl;
    //if there are no items in the farm, display None
    if(m_farm.size() == 0) { 
            cout << "None" << endl;
    }
    for(unsigned int i = 0; i < m_farm.size(); i++) {
        *m_farm.at(i) << cout << endl;
    }
    cout << endl << endl;
}
