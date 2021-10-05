/*
Maximilian Drach
CSCI 135
Esteban Mundo
Project 3
Player.cpp

*/
#include "Player.hpp"
#include "Enemy.hpp"
using namespace std;

Player::Player(string n, vector<int> st, Job j){
    //string tsv = "Project_3_Abilities.tsv";
    //name tsv data
    AbilityDB ab("Project_3_Abilities.tsv");

    setName(n);
    setStat(st);
    
    /*Entity *e = new Entity;
    (*e).setName(n);
    (*e).setStat(st);
    //e->setStat(st);*/

    abilities = ab.getAbilitiesByClass(j);
    /*
    for (int i=0; i < ab.abilities.size(); i++){
        
        if(ab.abilities[i]->getJob() == j){
            abilities.push_back(ab.getAbilityByID(i));
        }
        /*else{
            abilities.push_back(NULL);
        }
    }*/
}
vector<Ability*> Player::listAbilities(){
    return abilities;
}
int Player::getCurrentXP() const{
    return currentXP;
}
int Player::getnextLevelXP() const{
    return nextLevel;
}
bool Player::gainXP(int value){
    currentXP += value;
    if(getCurrentXP() >= getnextLevelXP()){
        return true;
    }
    return false;
}

void Player::attackEnemyWithSkill(Enemy &target, Ability* ab){//switch to abilities, not id
    int damage;
    int player_damage = getAttackStat(ab->getDamageType());//gets players attack damage
    int enemy_defence = target.getAttackStat(ab->getDamageType());//gets enemy defense
    /*bool abil_avalible = false;
    for(int i=0; i<abilities.size(); i++){
        if(ab == abilities[i]){
            abil_avalible = true;
        }
    }*/

    if(ab->getDamageType() != healing){//for all attack abilities
        damage = (*ab).calculateDamage(player_damage, enemy_defence);
        int Enemy_hp = target.getCurrentHP();
        target.setCurrentHP(Enemy_hp - damage);
        
        cout << "Attacking Monster with " << ab->getName() << "   +" << ab->getDamage() << endl;
        cout << "--~~~=:>[XXXXXXXXX]>" << endl << endl;
        cout << "------------------------~~~=:>[XXXXXXXXX]>" << endl << endl;
        cout << "-------------------------------------------~~~=:>[XXXXXXXXX]>  +" << damage << endl << endl << endl;
    }
    else{//the output when you heal youself
        cout << "Healing Yourself with " << ab->getName() << "    +" << ab->getDamage() << endl;
        cout << "            ******       ******" << endl;
        cout << "          **********   **********" << endl;
        cout << "        ************* *************" << endl;
        cout << "        ***************************** " << endl;
        cout << "        ***************************** " << endl;
        cout << "        ***************************" << endl;
        cout << "          ***********************" << endl;
        cout << "            ******************* " << endl;
        cout << "               *************** " << endl;
        cout << "                 ***********" << endl;
        cout << "                   *******" << endl;
        cout << "                     ***" << endl;
        cout << "                      *" << endl;
        if(getCurrentHP() + ab->getDamage() - target.getAttackStat(physical) > getMaxHP()){
            setCurrentHP(getMaxHP());
        }
        else{
            setCurrentHP(getCurrentHP() + ab->getDamage() - target.getAttackStat(physical));
        }
        cout << "Healed by ++ " << ab->getDamage() - target.getAttackStat(physical) << endl;
        cout << "(Player) " << getName() << " HP: " << getCurrentHP() << endl << endl << endl;
    }


    //cout << (*ab).getDamage() << " -ability damage" << endl;
    //cout << player_damage << " -player damage" << endl;
    //cout << enemy_defence << " -enemy defence" << endl << endl;
    //cout << target.getCurrentHP();//gets speed == 100
    //cout << getAttackstat(ab->getDamageType()) << " & " << getCurrentHP() << endl;//gets attack damage stat
    //cout << getCurrentHP();
    //cout << getCurrentSP();

}
/*void Player::attackPlayerWithSkill(Player &target, Ability* ab){
    
    int ability_damage = (*ab).getDamage();
    int player_damage = Player.Player(e->getAttackstat(ab->getDamageType()));
    if(ab != NULL){
        target->Player()
    }
}*/
