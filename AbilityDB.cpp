/*
Maximilian Drach
CSCI 135
Esteban Mundo
Project 3
Ability.cpp

list the abilities from a tsv file
Project_3_Abilities.tsv
*/
#include "AbilityDB.hpp"

AbilityDB::AbilityDB(string tsv_file){

    ifstream fin(tsv_file);
    
    if (fin.fail()) {//check the if the file is open
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file
    }
    
    string junk;
    getline(fin, junk);//takes out the first junk line
    
    string data;
    while(getline(fin, data)){
        Ability* a = new Ability(data);
        abilities.push_back(a);
    }

    /*
    getline(fin, data)
    Ability* a = new Ability(data);
    abilities.push_back(a);*/
}
Ability* AbilityDB::getAbilityByID(int id){
    return abilities[id];

}
Ability* AbilityDB::getAbilityByName(string name){
    int i=0;
    while(abilities[i]->getName() != name){
        i++;
    }
    return abilities[i];
}
vector<Ability*> AbilityDB::getAbilitiesByClass(Job job){
    vector<Ability*> job_abil;
    for(int i=0; i<abilities.size();i++){
        if(abilities[i]->getJob() == job){
            //return abilities[i];
            job_abil.push_back(abilities[i]);
        }
    }
    return job_abil;
}


