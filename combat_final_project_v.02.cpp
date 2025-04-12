#include <iostream>
#include <cstdlib> // knihovna pro random
#include <ctime> // knihovna pro unique num
using namespace std;
/*int ammo_count(int zaklad_ammo, int vyuziti_ammo, int zbyvajici_ammo){


return;
}
int heavy_attack(){

}
int light_attack(){

}*/







int main (){

//random
srand(time(0));
int random = rand() % 2;

//parametry
int player_life = 30, player_attack = 10, player_ammo = 50;
int opfor_life = 30, opfor_attack = 3;
string utok;
do{
    cout << "Zadej utok (spray, aim, hide, heal): ";
    cin >> utok;
    if (utok == "spray"){
        opfor_life = opfor_life - player_attack;
        player_ammo = player_ammo - 5;
        cout << "Zautocil jsi na nepritele.\n";
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
    cout << "OPFOR life: " << opfor_life << endl;
    cout << "Proti utok.\n";
    player_life = player_life - opfor_attack;
    cout << "Player life: " << player_life << endl;
    cout << "Player ammo: " << player_ammo << endl;
}while(player_life>0&&opfor_life>0);
cout << "OPFOR byl porazen.";






return 0;
}
