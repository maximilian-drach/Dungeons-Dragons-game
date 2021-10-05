/*
Maximilian Drach
CSCI 135
Esteban Mundo
Project 3
Enemy.cpp

*/
#include "Enemy.hpp"
#include "Player.hpp"
using namespace std;

Enemy::Enemy(string face, vector<int> st, int xp){//string n = string face
    //string tsv = "Project_3_Abilities.tsv";
    AbilityDB ab("Project_3_Abilities.tsv");
    

    setName(face);
    setStat(st);
    abilities = ab.getAbilitiesByClass(monster);
    XP = xp;
    /*for (int i=0; i < ab.getAbilitiesByClass(monster).size(); i++){
        abilities.push_back(ab.getAbilityByID(i));
    }*/

    //face = f;
}
vector<Ability*> Enemy::listAbilities(){
    return abilities;
}
int Enemy::getXP(){
    return XP;
}
void Enemy::attackPlayerWithSkill(Player &target, Ability* ab){
    int damage;//total damage
    int enemy_damage = getAttackStat(ab->getDamageType());//gets players attack damage
    int player_defence = target.getAttackStat(ab->getDamageType());//gets enemy defense
    

    damage = (*ab).calculateDamage(enemy_damage, player_defence);
    int Player_hp = target.getCurrentHP();
    target.setCurrentHP(Player_hp - damage);


    cout << "  _____   " << endl;
    cout << " /     \\  " << endl;
    cout << "| () () |" << endl;
    cout << " \\  ^  /" << endl;
    cout << "  |||||" << "    " << getName() << " HP: " << getCurrentHP() << endl;
    cout << "  |||||" << "    " << "Attacking Player with " << ab->getName() << "  +" << ab->getDamage() << endl;
    //cout << "Attacking Player with " << ab->getName() << "  +" << ab->getDamage() << endl;
    cout << "                                       <{XXXXXXXXX]<:=~~~--" << endl << endl;
    cout << "                   <[XXXXXXXXX]<:=~~~------------------------" << endl << endl;
    cout << "+" << damage << "   " << "<[XXXXXXXXX]<:=~~~-------------------------------------------" << endl << endl << endl;

}