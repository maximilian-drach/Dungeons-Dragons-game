#include "BattleManager.hpp"
using namespace std;

int main(){//g++ Ability.cpp AbilityDB.cpp BattleManager.cpp Enemy.cpp Entity.cpp main.cpp Player.cpp utils.cpp
    string name;
    int j, ability_num, boss_number=0;//tell which boss is on
    Job job;


    cout << "Welcome to Maximilian's D&D !!" << endl << endl;
    

    cout << "What is your name? " ;
    getline(cin, name);
    cout << endl;
    cout << "warrior (0) \n cleric (1) \n bard (2) \n wizard (3)" << endl;
    cout << "Enter the number asociated with the job would you like: ";
    cin >> j;
    job = stringToJob(j);
    cout << endl <<"If you want to quit the program in the middle of a battle, type -1" << endl;
    cout << "Starting........." << endl << endl << endl;
    
   //creates player
    Player_stats ps;
    ps.Player_Creation(job);//creats the player random stats
    Player p(name, ps.getPlayerStats(), job);//enters player into system
    p.setCurrentHP(p.getMaxHP());//enters the HP
    Battle b;

    while(boss_number < 5){
        int num = 0;
        Monster_stats ms;//creates a new monster every time, round
        ms.MonsterStats();//creates monstes random stats
        Enemy e(ms.getName(boss_number), ms.getMonsterStats(), 0);
        e.setCurrentHP(e.getMaxHP());//enters in monsters hp

        cout << "You are Fighting " << e.getName() << ", Welcome to Monster round " << boss_number + 1 << endl;//says the name of monster
        cout << "Monster HP Level: " << e.getCurrentHP() << endl << endl;//tells the monster curren HP
        int round_counter = 1;

        
        while(e.getCurrentHP() > 0 && p.getCurrentHP() > 0){
            cout << p.getName() << " HP: " << p.getCurrentHP() << endl;
            vector<Ability*> battle_ab = b.Player_abilities(p.listAbilities());//gets the battle abilites, ie the best ability doesnt always appear
            
            for(int i=0; i< battle_ab.size(); i++){//list the abilities given
                cout << "("<< i << ")   " << battle_ab[i]->getName() << "      " << ps.DamageType_switcher(battle_ab[i]->getDamageType()) << endl;   //<<"    +" << battle_ab[i]->getDamage() << endl;
            }
            //for(int i=0; i<p.listAbilities().size(); i++){//list the abilities given
                //cout << "("<< i << ")   " << p.listAbilities()[i]->getName() << "      " << ps.DamageType_switcher(p.listAbilities()[i]->getDamageType()) <<"    +" << p.listAbilities()[i]->getDamage() << endl;
            //}

            cout << "Enter Your Ability(Integer): ";// after the options are listed
            cin >> ability_num;
            if(ability_num == -1){//allows the player to quit the b
                break;
            }
            b.ability_checker(ability_num, battle_ab);//checks that the int entered is valid
            cout << endl;

            p.attackEnemyWithSkill(e, battle_ab[b.ability_int]);//does the ability to the enemy
            e.attackPlayerWithSkill(p, e.listAbilities()[rand() % 4]);// the monster does a random ability back

            cout << "************************************************************************************************" << endl;
            cout << "Round " << round_counter << endl;
            cout << "************************************************************************************************" << endl << endl << endl;
            round_counter ++;
        }
        if(e.getCurrentHP() <= 0){
            cout << "You WON!!!!!" << endl;
            cout << "Type -1 if you want to quit or any integer to CONTINUE FIGHTING: ";
            cin >> num;
        }
        else{
            cout << "You lost :(" << endl;
            cout << "Type -1 if you want to quit or any integer to FIGHT AGAIN: ";
            cin >> num;
            boss_number --;//decrease boss_number so to stay on the same level
        }
        if(num == -1 || boss_number == 5){
            break;
        }
        else{
            cout << endl << "+ 5 MaxHP, so you can fight another day!" << endl;
            p.setStat(0, p.getMaxHP() + 5);//increase the Max HP after every battle
            p.setCurrentHP(p.getMaxHP());//adds 5 max hp after every game
            boss_number++;//increments the number so to create and fight a new boss
            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
            cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << "************************************************************************************************************************************" << endl;
            cout << endl <<  " GET READY FOR BATTLE!!!......." << endl << endl;
            cout << "************************************************************************************************************************************" << endl;
            cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << "************************************************************************************************************************************" << endl;
        }
        
    }
    if(boss_number == 5){
        cout << "Congrats you won the game" << endl;
        b.winner_lister(p.getName());
    }
    
    cout << endl << "Thanks for Playing, come again next time." << endl << endl << endl;

    //(1)creates an Enemy with the stats and a name and including setHP
    //(2)list the players abilities to attack, then takes in the input of the attack as an integer
    //(3)has a random number generator that is assiciated with the counter attack from the enemy
    //(4)Keeps going till either monster or player has HP less than or equal to 0
    //(5) Gives option to quit, by -1 or go on, 
    //      if the enemy lost then create a new enemy with the stats and set plays HP by to max ammount + 5
    //      if player lost then repeat

    //(6) this keeps going for 5 enemies and then the player wins by default, and quits the while loop
    //(7) then the players name is recorded in the winners text
    
    //when battling return the health

    
}