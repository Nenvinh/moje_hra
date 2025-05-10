#include <iostream>
#include <cstdlib> // knihovna pro random
#include <ctime> // knihovna pro unique num
using namespace std;
void player_defeat(int player_life);
void manual();

int main (){
//player
struct{
    string jmeno;
    float life = 20;
    float attack = 10;
    float heavy_attack = attack * 2;
    int ammo = 50;
    int ammo_usage = 10;
    int ammo_usage_heavy = 15;
    int level = 1;
    float armour = 1;
    float heal_upgrade = 1;
    float life_upgrade = 1;
    float damage_upgrade = 1;
    float price = 1;
    int cash = 5;
    float cash_gain = 1;
    int inventory[3]{0, 0, 0};
}player;

//opfor
struct{
    string final_boss = " Andres 'Ascendrax' Dragan ";
    string mini_boss_1 = "place_holder_name1";
    string mini_boss_2 = "place_holder_name2";
    float life = 30;
    int damage = 10;
    float level = 1;
}opfor;


//parametry
bool opakovani = false;
int fumble = 0;
do{
    cout << "-------------------------------------------------------FRIENDLY ACTIONS-------------------------------------------------";
    do{
    bool opakovani = false;
    int fumble = 0;
    string utok;
    cout << "Player stats: \n";
    cout << "Player life: " << player.life << " hp" << endl;
    cout << "Player ammo: " << player.ammo << endl;
    cout << "Player attack: " << player.attack << " dmg" << endl;
    cout << "\n";
    cout << "OPFOR stats: \n";
    cout << "OPFOR life: " << opfor.life << " hp" << endl;
    cout << "OPFOR attack: " << opfor.damage << " dmg" << endl;
    cout << "\n";
    manual();
    cout << "Vyber si akci (spray, aim, reload, heal): ";
    cin >> utok;
    if (utok == "spray"){
      opfor.life = opfor.life - player.attack;
      cout << "\n";
      cout << "Zacal jsi strilet na nepritele.\n";
      opakovani = true;
    }
    else if(utok == "aim"){
        opfor.life = opfor.life - player.heavy_attack;
        cout << "\n";
        cout << "Zamiril jsi na nepritele a strilel\n";
        opakovani = true;
    }
    else if(utok == "reload"){
        player.ammo = player.ammo + 20;
        cout << "\n";
        cout << "Prebij jsi zasobnik\n";
        opakovani = true;
    }
    else if(utok == "heal"){
        player.life = player.life + 5;
        cout << "\n";
        cout << "Vylecil ses\n";
        opakovani = true;
    }
    else {
        player.life = player.life * 0.5;
        cout << "\n";
        cout << "Zpanikaril jsi, a nepritel te zasahl. -" << player.life << "hp.";
        opakovani = true;
    }

    }while(opakovani = false);
    cout << "OPFOR life: " << opfor.life << endl;
    cout << "--------------------------------------------------------ENEMY ACTIONS---------------------------------------------------";
    if (opfor.life >0){
    cout << "Proti utok.\n";
    player.life = player.life - opfor.damage;
    cout << "- " << opfor.damage << " hp\n";
    }

}while(player.life>0&&opfor.life>0);
player_defeat(player.life);
return 0;
}
void manual(){
cout << "Manual: \n";
cout << "Spray - zakladni utok bez mireni. Vystrelis 10 kulek a budes doufat, ze neco zasahnes. (- 10 ammo, 10 damage) \n";
cout << "Aim - zakladni utok s mireni. Vystrelis 20 kulek a zasadis nepriteli dvojnasobek ran. (- 20 ammo, 2 X 10 damage) \n";
cout << "Heal - zakladni leceni. Vytahnes lekarnicku a vylecis se. (+ 10 health points) \n";
cout << "Reload - zakladni prebiti. Prebijes si zasobnik. (+ 10 ammo) \n";
cout << "\n";
}
void player_defeat(int player_life){
    if (player_life<=0){
        cout << endl;
        cout << "Srdecni puls: 0 BPM \n";
        cout << "Nenalezena zadna mozkova aktivita.\n";
        cout << "Uzivatel mrtev, cekani na reset.\n";
    }
    else {
        cout << "OPFOR byl porazen.\n";
    }
}
