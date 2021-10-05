#ifndef ABILITYDB_HPP_
#define ABILITYDB_HPP_

#include "Ability.hpp"
#include <vector>
#include <fstream>
using namespace std;

class AbilityDB{
    private:
        vector<Ability*> abilities;
    public:
        AbilityDB(string tsv_file);
        Ability* getAbilityByID(int id);//Returns an Ability* of the specified ID. In this case, the ID is the index of the vector.
        Ability* getAbilityByName(string name);//Returns an Ability* with the specified name
        vector<Ability*> getAbilitiesByClass(Job job);//Returns a vector of Ability* with the specified Job.
};

#endif