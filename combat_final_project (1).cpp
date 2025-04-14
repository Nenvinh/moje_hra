#include <iostream>
#include <cstdlib> // knihovna pro random
#include <ctime> // knihovna pro unique num
using namespace std;
int ammo_count(int vyuziti_ammo){
int base_ammo_count = 50;
return base_ammo_count - vyuziti_ammo;
}

float player_health(){

}

float player_damage(){

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
        opfor_life = opfor_life - player_attack;
        ammo_count(5);
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
