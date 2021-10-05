#ifndef ENTITY_HPP_
#define ENTITY_HPP_

//.., goes back the pervios dir
#include "AbilityDB.hpp"
using namespace std;


class Entity{
    private:
        string name_;
        int stats[7];//the statistics of the Entity. The datais separated as{MaxHP, MaxSP, Attack, Magic, Defense, MagicDefense,Speed}
        int current[2];//Contains the {CurrentHP, and CurrentSP}of the Entity.
    public:
        Entity();//A base constructor class. Should set all values to empty string or 0.
        int getMaxHP() const;
        int getMaxSP() const;
        int getAttackStat(DamageType stat)const;//Returns either the Attack stat or Magic stat based on the DamageType specified
        int getDefenseStat(DamageType stat)const;//Returns either the Defense or MagicDefense stat based on theDamageType specified.
        int getSpeed() const;//Returns speed value.
        int getCurrentHP() const;//Returns CurrentHP.
        int getCurrentSP() const;//Returns CurrentSP.
        string getName() const;
        void setName(string name);//Sets the name of the entity.
        void setStat(int id, int value);//Based on the position of the stat, shouldchange it to set value.
        void setStat(vector<int> values);//Receives a vector of stats that would modify the stat. If the value is -1, itshould ignore that stat when setting thevalue. The vector size could also be lessthan the stats array.
        void setCurrentHP(int value);//Sets currentHP to value. health points.
        void setCurrentSP(int value);//Sets currentHP to SP, silver piece.

};
#endif