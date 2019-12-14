//
// Created by vladimir on 28.11.2019.
//
#include <iostream>
#include <ctime>


using namespace std;


enum ItemName{
    SWORD,
    BOW,
    SPELL
};


enum Element{
    Fire,
    Eatrh,
    Water,
    Air
};


struct Sword{
    int damage;
};


struct Bow{
    int  damage;
    int charge_time;
    double distance;
};


struct Spell{
    int damage;
    Element element;
    double distance;
};


struct  Item{
    ItemName item_name;
    union {
        Sword sword;
        Spell spell;
        Bow bow;
    };
};


Item getRandomItem(){
    Item res;

    res.item_name = static_cast<ItemName> (rand() % 3);

    switch (res.item_name){
        case SWORD:
            res.sword.damage = rand() % 100;

            break;

        case BOW:
            res.bow.damage = rand() % 100;
            res.bow.charge_time = rand() % 100;
            res.bow.distance = rand() % 1000 / 10.0;

            break;

        case SPELL:
            res.spell.damage = rand() % 100;
            res.spell.element = static_cast<Element> (rand() % 4);
            res.spell.distance = rand() % 1000 / 10.0;

            break;
    }
    return res;
}


void printItem(Item loot){
    switch (loot.item_name){
        case SWORD:
            cout << "---SWORD---" << endl;
            cout << "DAMAGE" << '\t' << loot.sword.damage << endl;

            break;

        case BOW:
            cout << "---BOW---" << endl;
            cout << "DAMAGE" << '\t' << loot.bow.damage << endl;
            cout << "CHARGE TIME" << '\t' << loot.bow.charge_time << endl;
            cout << "DISTANCE" << '\t' << loot.bow.distance << endl;


            break;
        case SPELL:

            cout << "---SPELL---" << endl;
            cout << "DAMAGE" << '\t' << loot.spell.damage << endl;
            cout << "DISTANCE" << '\t' << loot.spell.distance << endl;
            cout << "ELEMENT" << '\t';

            switch (loot.spell.element){
                case Air:
                    cout << "AIR";

                    break;

                case Eatrh:
                    cout << "EATRH";

                    break;

                case Water:
                    cout << "WATER";

                    break;

                case Fire:
                    cout << "FIRE";

                    break;
            }
            cout << endl;

            break;
    }
}


int main(){
    srand(time(NULL));

    printItem(getRandomItem());

    return 0;
}