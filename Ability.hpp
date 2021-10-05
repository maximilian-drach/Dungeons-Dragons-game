#ifndef ABILITY_HPP_
#define ABILITY_HPP_

#include "utils.hpp"
#include <iostream>
#include <sstream>
using namespace std;


class Ability{
    private:
        string name;//the name of the ability, it could includepunctuation, space, andother characters with the exception of ‘\t’. Example“Ram’s Voice”
        int damage;//a non-negative integer that stores thedamage an ability deals.
        int cost;//an integer that stores the cost of an ability.
        DamageType type;//The type of damage it deals, could be “physical”,“magical”, or “healing”
        Job job_specific;//Should be either: “warrior” “cleric”,“bard”,“wizard”, or“monster”
    public:
        Ability(string n, int d, int c, DamageType dt, Job j);
        Ability(const string & tsv_line);
        string getName() const;
        int getCost() const;
        int getDamage() const;
        DamageType getDamageType() const;//physical, magical, healing
        Job getJob() const;//warrior, cleric, wizard, bard, monster
        int calculateDamage(int attack, int defense);
};

#endif