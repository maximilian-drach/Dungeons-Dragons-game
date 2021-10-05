#ifndef BATTLEMANAGER_HPP_
#define BATTLEMANAGER_HPP_

#include "Player.hpp"
#include "Enemy.hpp"
#include <random>
using namespace std;

class Monster_stats{
    private:
        vector<int> st;//contains the vector of the Enemy stats
        vector<string> names;
        int rand_attack, rand_def, rand_MaxHP, rand_speed, rand_MaxSP;//random values for the enemy stats
    public:
        void MonsterStats();//creates the random values for that stats and enters them into the vector
        vector<int> getMonsterStats();//returns the monster stats int values
        string getName(int i);
};

class Player_stats{
    private:
        vector<int> st;//contains the vector of the Enemy stats
        int rand_attack, rand_def, rand_magicAttack, rand_magicDef, rand_MaxHP, speed, MaxSP;
        int rand_special_ability;
    public:
        void Player_Creation(Job job);//creates the range-random values for that stats and enters them into the vector
        vector<int> getPlayerStats();//returns the Player stats value
        string DamageType_switcher(DamageType dtype);


};

class Battle{

    public:
        int ability_int;
        void ability_checker(int i, vector<Ability*> abilities);//checkers if the ability is all good
        vector<Ability*> Player_abilities(vector<Ability*> abil);
        void winner_lister(string name);//puts the winners in a txt file
};

#endif