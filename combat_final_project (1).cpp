#include <iostream>
#include <cstdlib> // knihovna pro random
#include <ctime> // knihovna pro unique num
using namespace std;
int main (){

//parametry
float vylepseni_attack = 1, vylepseni_health = 1, vylepseni_obrana = 1;
bool opakovani = false;
int fumble = 0;
float player_life = 20, player_attack = 10, player_ammo = 50;
float opfor_life = 100, opfor_attack = 10;
string utok;
do{
    cout << "-------------------------------------------------------FRIENDLY ACTIONS-------------------------------------------------";
    do{
    bool opakovani = false;
    cout << "Player life: " << player_life << endl;
    cout << "Player ammo: " << player_ammo << endl;
    cout << "Zadej utok (spray, aim, hide, heal): ";
    cin >> utok;
    if (utok == "spray"){
        pokracovani(player_ammo, 5);
        switch(pokracovani){
            case 0:
            cout << "Nedostatek munice na utok.\n";
            fumble++;
            break;
            case 1:
            player_attack = 3 + player_attack;
            opfor_life = opfor_life - player_attack;
            cout << "Zautocil jsi na nepritele. (spray'n'pray)\n";
            opakovani = true;
            break;
            default:
            cout << "switch error. line 32\n";
        }
    }
    else if(utok == "aim"){
        player_attack = 2 * player_attack;
        opfor_life = opfor_life - player_attack;
        cout << "Zamiril jsi na nepritele a strilel\n";
        opakovani = true;
    }
    else if(utok == "hide"){
        player_ammo = player_ammo + 20;
        cout << "Prebij jsi zasobnik\n";
        opakovani = true;
    }
    else if(utok == "heal"){
        player_life = player_life + 5;
        cout << "Vylecil ses\n";
        opakovani = true;
    }
    else {
        player_life = player_life * 0.5;
        cout << "Zpanikaril jsi, a nepritel te zasahl. -" << player_life << "hp.";
        opakovani = true;
    }

    }while(opakovani = false);
    cout << "--------------------------------------------------------ENEMY ACTIONS---------------------------------------------------";
    cout << "Proti utok.\n";
    player_life = player_life - opfor_attack;
    cout << "OPFOR life: " << opfor_life << endl;
}while(player_life>0&&opfor_life>0);
if (player_life <= 0){
    cout << "Srdecni puls: 0 BPM \n";
    cout << "Nenalezena zadna mozkova aktivita.\n";
    cout << "Uzivatel mrtev, cekani na reset.\n";
}
else if(opfor_life <= 0){
    cout << "OPFOR byl porazen.";
}





return 0;
}
//SYSTEM PART

//pokracovani
bool pokracovani(int current_ammo, int ammo_usage){
    bool pokracovani = true;
    if (current_ammo - ammo_usage < 0){
        pokracovani = false;
    }
    else if (current_ammo - ammo_usage >= 0){
        pokracovani = true;
    }
    return pokracovani;
}

//PLAYER PART

//player ammo
int ammo_count(int current_ammo, int ammo_usage){

}



//player health
float player_health(float current_player_life, float dealt_damage, float class_advantages = 1, float upgrade_advantages = 1){

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

//Random

int random(){
srand(time(0));
int random = rand() % 2;
return random;
}



