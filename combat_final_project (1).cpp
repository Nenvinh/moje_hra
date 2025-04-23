#include <iostream>
#include <cstdlib> // knihovna pro random
#include <ctime> // knihovna pro unique num
using namespace std;
//PLAYER PART

//player ammo
bool is_enough_ammo (int current_ammo, int ammo_usage){
if (current_ammo - ammo_usage < 0){
    is_enough_ammo = false;
}

else if (current_ammo - ammo_usage >= 0){
    is_enough_ammo = true;
}

}

int ammo_count(int current_ammo, int ammo_usage){
if (is_enough_ammo == true){
    current_ammo = current_ammo - ammo_usage;
    return current_ammo;
}

else if (is_enough_ammo == false){
    cout << "Nedostatek munice.\n";
}

}

//player health
float player_health(float current_player_life, float dealt_damage, float class_advantages = 1, float upgrade_advantages = 1,){

}

//player damage
float player_damage(){

}

//OPFOR PART


//OPFOR life
float opfor_life(){

}

//OPFOR damage
float opfor_damage(){

}





int main (){

//random
srand(time(0));
int random = rand() % 2;

//parametry
float vylepseni_attack = 1, vylepseni_health = 1, vylepseni_obrana = 1;
float player_life = 20, player_attack = 10, player_ammo = 50;
float opfor_life = 100, opfor_attack = 10;
string utok;
do{
    cout << "-------------------------------------------------------FRIENDLY ACTIONS-------------------------------------------------";
    cout << "Player life: " << player_life << endl;
    cout << "Player ammo: " << player_ammo << endl;
    cout << "Zadej utok (spray, aim, hide, heal): ";
    cin >> utok;
    if (utok == "spray"){
        is_enough_ammo(player_ammo, 10);
        switch (is_enough_ammo){
        case true:
            ammo_count(is_enough_ammo, player_ammo, 10);
            break;
        case false:

            break;
        default:
            cout << "Bullet count error.\n";
        }
        opfor_life = opfor_life - player_attack;

        cout << "Zautocil jsi na nepritele. (spray'n'pray)\n";
    }
    else if(utok == "aim"){
        player_attack = 2 * player_attack;
        opfor_life = opfor_life - player_attack;
        cout << "Zamiril jsi na nepritele a strilel\n";
    }
    else if(utok == "hide"){
        player_ammo = player_ammo + 20;
        cout << "Prebij jsi zasobnik\n";
    }
    else if(utok == "heal"){
        player_life = player_life + 5;
        cout << "Vylecil ses\n";
    }
    else {
        player_life = player_life * 0.5;
        cout << "Zpanikaril jsi, a nepritel te zasahl. -" << player_life << "hp.";
    }
    cout << "--------------------------------------------------------ENEMY ACTIONS---------------------------------------------------";
    cout << "Proti utok.\n";
    player_life = player_life - opfor_attack;
    cout << "OPFOR life: " << opfor_life << endl;
}while(player_life>0&&opfor_life>0);
if (player_life <= 0){
    cout << "GAME OVER";
}
else if(opfor_life <= 0){
    cout << "OPFOR byl porazen.";
}





return 0;
}
