#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include "Entity.hpp"
using namespace std;
class Player;
class Enemy : public Entity{
    private:
        int XP;//Contains the XP that Enemny
        vector<Ability*> abilities;//Stores all the ability IDsthe Enemy has. Bydefault, the vector should have any skills belongingto “monster”.
    public:
        //string n = string face
        Enemy(string face, vector<int> st, int xp);//Parameterized constructor for the Enemyclass. Similar to player, it contains thename, stats, and a set value of xp.
        vector<Ability*> listAbilities();
        int getXP();//Returns the value for XP.
        void attackPlayerWithSkill(Player &target, Ability* ab);
        /*Uses specified Ability using its ID fromthe AbilityDB on target Player. 
        If the ID is-1 or not an ability “learned” by the playeror valid, it should perform a “normal”attack, where it decrements the target'shealth by (attack - defense). 
        Like phase01 calculateDamage, if the damage< 0, it should not decrement health.*/
        //string getface();
};

#endif
