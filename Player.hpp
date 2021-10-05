#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Entity.hpp"
using namespace std;

class Enemy;
class Player : public Entity{
    private:
        Job job; //The Job the player belongs to.
        int level; //The level of the Player
        int currentXP;//Stores how much experience Player iscurrently holding.
        int nextLevel;//Stores how much experience is needed until the Playerlevels up.
        vector<Ability*> abilities;//Stores all the ability IDs the Player has. By default,the vector should have all the skills pertaining to that Job.
    public:
        Player(string n, vector<int> st, Job j);//Parameterized constructor for the playerclass. Contains name, stats, and whichjob the Player is.
        vector<Ability*> listAbilities();//Returns a vector of IDs belonging to theskills.
        int getCurrentXP() const;//Returns currentXP.
        int getnextLevelXP() const;//Returns nextLevel;
        bool gainXP(int value);//Adds xp to currentXP. If they level up,currentXP and nextLevel should beupdated to reflect. Returns true if thePlayer has leveled up.
        void attackEnemyWithSkill(Enemy &target, Ability* ab);
        /*Uses specified Ability using its ID fromthe AbilityDB on target Enemy. 
        If the ID is-1 or not an ability “learned” by the player or valid, it should perform a “normal”attack, where it decrements the target'shealth by (attack - defense). 
        Like phase01 calculateDamage, if the damage< 0, it should not decrement health.*/
        //void attackPlayerWithSkill(Player &target, Ability* ab);
        /*Uses specified Ability using its ID fromthe AbilityDB on target Player.
        If the ID is-1 or not an ability “learned” by the playeror valid, it should perform a “normal”attack, where it decrements the target'shealth by (attack - defense). 
        Like phase01 calculateDamage, if the damage< 0, it should not decrement health.*/
};
#endif