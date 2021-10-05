#include "BattleManager.hpp"
#include <random>


void Monster_stats::MonsterStats(){
    rand_attack = rand() % 10 + 5;//attack & magic attack around max 10
    rand_def = rand() % 20;//defense, around max 10
    rand_MaxHP = rand() % 100 + 175;//range from 175 - 275 for max HP
    rand_speed = rand() % 100;//doesnt matter
    rand_MaxSP = rand() % 5;//doesnt matter
    st = {rand_MaxHP, rand_MaxSP, rand_attack, rand_attack, rand_def, rand_def, rand_speed};
    names = {"The Evil Pawn", "The Drogon", "The Beat", "The Lieutenant", "The Don"}; //has 5 monster names
}
vector<int> Monster_stats::getMonsterStats(){
    return st;
}
string Monster_stats::getName(int i){
    return names[i];
}

string Player_stats::DamageType_switcher(DamageType dtype){
    switch(dtype){
        case physical:{
            return "physical";
            break;
        }
        case magical:{
            return "magical";
            break;
        }
        default:{
            return "healing";
            break;
        }
    }
}

void Player_stats::Player_Creation(Job job){
    if(job != wizard){
        rand_attack = rand() % 15 + 1;//attack & magic attack around 1 - 16
        rand_magicAttack = rand() % 1;//crappy magic attack
        rand_def = rand() % 7 + 3;//defense, 3-10
        rand_magicDef = rand() % 1;//crapy magic defense
        if(job == cleric){
            rand_MaxHP = rand() % 50 + 30;//range from 25 - 75 for max HP
        }
        else{
            rand_MaxHP = rand() % 50 + 50;//range from 50 - 100 for max HP
        }
    }
    else{
        rand_attack = rand() % 4;//crappy attack 
        rand_magicAttack = rand() % 10 + 15;//magic attack 15- 25
        rand_def = rand() % 3;//defense is crap 0-3
        rand_magicDef = rand() % 8 + 10;//magic def 10 - 18
        rand_MaxHP = rand() % 25 + 75;//range from 75 - 100 for max HP
    }
    speed = 100;//doesnt matter
    MaxSP = 0;//doesnt matter
    st = {rand_MaxHP, MaxSP, rand_attack, rand_magicAttack, rand_def, rand_magicDef, speed};

}
vector<int> Player_stats::getPlayerStats(){
    return st;
}

void Battle::winner_lister(string name){
    ofstream outfile;
    outfile.open("Winners.txt");
    outfile << name << endl << endl;
    outfile.close();
}
void Battle::ability_checker(int i, vector<Ability*> abilities){
    while(i < 0 || i >= abilities.size()){
        cout << "Please enter a valid Ability Integer: ";
        cin >> i;
    }
    ability_int = i;
}
vector<Ability*> Battle::Player_abilities(vector<Ability*> abil){
    vector<Ability*> battle_abilities;

    for(int i=0; i<abil.size(); i++){//not all abilities will be listied
        if(abil[i]->getCost() >= 4){//special or high cost abilies wont always show up
            if(rand() % 4 == 0){//gives a 1/5 chance of getting special ability
               battle_abilities.push_back(abil[i]);
            }
        }
        else{
            battle_abilities.push_back(abil[i]);//gets regular or low value objects
        }    
    }
    return battle_abilities;
}