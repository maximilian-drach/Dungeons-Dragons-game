/*
Maximilian Drach
CSCI 135
Esteban Mundo
Project 3
Entity.cpp

sets the entity values
*/
#include "Entity.hpp"
using namespace std;

Entity::Entity(){
    name_ ="";
    for(int i=0; i < 7; i++){
        stats[i] = 0;
    }
    for(int i=0; i < 2; i++){
        current[i] = 0;
    }
}

int Entity::getMaxHP() const{
    return stats[0];
}
int Entity::getMaxSP() const{
    return stats[1];
}
int Entity::getAttackStat(DamageType stat) const{
    if(stat == physical){
        return stats[2];
    }
    else{
        return stats[3];
    }
}
int Entity::getDefenseStat(DamageType stat) const{
    if(stat == physical){
        return stats[4];
    }
    
    else{
        return stats[5];
    }
}
int Entity::getSpeed() const{
    return stats[6];
}
int Entity::getCurrentHP() const{
    return current[0];
}
int Entity::getCurrentSP() const{
    return current[1];
}
string Entity::getName() const{
    return name_;
}
void Entity::setName(string name){
    name_ = name;
}
void Entity::setStat(int id, int value){
    stats[id] = value;
}
void Entity::setStat(vector <int> values){
    for(int i=0; i < values.size(); i++){
        if(values[i] == -1){
            continue;
        }
        else{
            stats[i] = values[i];
        }
    }
}
void Entity::setCurrentHP(int values){
    current[0] = values;
}
void Entity::setCurrentSP(int values){
    current[1] = values;
}
