/*
Maximilian Drach
CSCI 135
Esteban Mundo
Project 3
Ability.cpp

list the abilities from a tsv file
Project_3_Abilities.tsv
*/
#include "Ability.hpp"
#include "utils.hpp"

Ability::Ability(string n, int d, int c, DamageType dt, Job j){
            name = n;
            damage = d;
            cost = c;
            type = dt;
            job_specific = j;
}
Ability::Ability(const string & tsv_line){
    //useful when you need to place the data in to which container
    
    stringstream line (tsv_line);
    //line >> name; // the name can have a space,hennce use get line
    getline(line, name, '\t'); //gets the name from the line

    line >> damage;
    //getline(line, damage, '\t'); 
    //stream doesnt restart, it start at the next
    line >> cost;
    //getline(line, cost, '\t');

    string dtype;
    line >> dtype;
    type = stringToDamage(dtype);
    
    int job;
    line >> job;
    job_specific = stringToJob(job);
  
    //line >> name >> damage >> cost >> dtype >> job;
    
}
string Ability::getName() const{
    return name;
}
int Ability::getCost() const{
    return cost;
}
int Ability::getDamage() const{
    return damage;
}
DamageType Ability::getDamageType() const{
    return type;
}
Job Ability::getJob() const{
    return job_specific;
}
int Ability::calculateDamage(int attack, int defense){
    if(type == healing){
        defense = 0;
    }
    return ((attack + damage)-defense);
}

//https://www.geeksforgeeks.org/enum-classes-in-c-and-their-advantage-over-enum-datatype/
// Initialisation
//DamageType job = DamageType::healing;