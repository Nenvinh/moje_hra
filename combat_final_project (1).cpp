#include <iostream>
#include <cstdlib> // knihovna pro random
#include <ctime> // knihovna pro unique num
#include <windows.h>
using namespace std;

void player_defeat(int player_life, int opfor_life);
void manual(bool promena = true);
int random_num();
void nastavBarvu(int barva);
bool enough(int ammo_usage, int ammo_count);

int main (){
//player
struct{
    string jmeno;

    string schopnosti;
    int life = 24 + life_upgrade;
    int attack = 10 + attack_upgrade; // all attack

    int heavy_attack = attack * 2;

    int ammo = 50 + ammo_upgrade;
    int ammo_usage = 10;
    int ammo_usage_heavy = ammo_usage * 1.5;
    int ammo_gain = 10;
    int armour = 0;

    int heal = 5;
    int level = 1;
    int attack_upgrade = 0;
    int life_upgrade = 0;
    int ammo_upgrade = 0;

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
    int pocet = 1;
}opfor;


//parametry
bool opakovani = false;
int fumble = 0;
do{
    nastavBarvu(10);
    cout << "-------------------------------------------------------FRIENDLY ACTIONS-------------------------------------------------"<<endl;
    string utok;
    cout << "Player stats: \n";
    cout << "Player life: " << player.life << " hp" << endl;
    cout << "Player ammo: " << player.ammo << endl;
    cout << "Player attack: " << player.attack << " dmg" << endl;
    cout << "\n";
    nastavBarvu(4);
    cout << "OPFOR stats: \n";
    cout << "OPFOR life: " << opfor.life << " hp" << endl;
    cout << "OPFOR attack: " << opfor.damage << " dmg" << endl;
    cout << "\n";
    nastavBarvu(7);
    manual();
    for (int i = 1; i<=3; i++){
    cout << "Vyber si akci (spray, aim, reload, heal): ";
    cin >> utok;
    if (utok == "spray"){
        switch(enough(player.ammo_usage, player.ammo)){
        case 0:
            cout << "\n";
            nastavBarvu(4);
            cout << "Stiskl jsi spoust a zbran nevystrelila, nemas dostatek munice.\n";
            nastavBarvu(7);
            cout << "\n";
            break;
        case 1:
            //kdyz je dostatek naboju
            player.ammo = player.ammo - player.ammo_usage;
            opfor.life = opfor.life - player.attack;
            cout << "\n";
            cout << "Zacal jsi strilet na nepritele, - " << player.attack << " dmg.\n";
            cout << "Vyuzil jsi: " << "- " << player.ammo_usage << " naboju.\n";
            i = 3;
            break;
        default:
            cout << "Error - spray_switch line 83.\n";
            break;

    };
    }
    else if(utok == "aim"){
        switch(enough(player.ammo_usage_heavy, player.ammo)){
        case 0:
            cout << "\n";
            nastavBarvu(4);
            cout << "Zamiril jsi a stiskl spoust, zjistil jsi, ze nemas dostatek munice\n";
            nastavBarvu(7);
            cout << "\n";
            break;
        case 1:
        //pokud je dostatek munice
        player.ammo = player.ammo - player.ammo_usage_heavy;
        opfor.life = opfor.life - player.heavy_attack;
        cout << "\n";
        cout << "Zamiril jsi na nepritele a strilel, - " << player.heavy_attack << " dmg.\n";
        cout << "Vyuzil jsi: " << "- " << player.ammo_usage_heavy << " naboju.\n";
        i = 3;
        };
    }
    else if(utok == "reload"){
        player.ammo = player.ammo + player.ammo_gain;
        cout << "\n";
        cout << "Prebij jsi zasobnik, + " << player.ammo_gain << " munice\n";
        i = 3;
    }
    else if(utok == "heal"){
        player.life = player.life + player.heal;
        cout << "\n";
        cout << "Vylecil ses, + " << player.heal << " hp\n";
        i = 3;
    }
    else {
        player.life = player.life * 0.5;
        cout << "\n";
        cout << "Zpanikaril jsi a nepritel te zasahl, - " << player.life << " hp.\n";
        i = 3;
    }
    }


    cout << "OPFOR life: " << opfor.life << endl;

    nastavBarvu(4);
    if (opfor.life >0){
    cout << "--------------------------------------------------------ENEMY ACTIONS---------------------------------------------------"<<endl;
    cout << "Nepritel na tebe zautocil.\n";
    player.life = player.life - (opfor.damage - player.armour);
    cout << "- " << opfor.damage << " hp\n";
    }

}while(player.life>0&&opfor.life>0);
player_defeat(player.life, opfor.life);


return 0;
}

void manual(bool promena){
    if (promena = true){
        cout << "Manual: \n";
        cout << "Spray - zakladni utok bez mireni. Stisknes spoust a budes doufat, ze neco zasahnes. (- 10 ammo, 10 damage) \n";
        cout << "Aim - zakladni utok s mireni. Vystrelis 20 kulek a zasadis nepriteli dvojnasobek ran. (- 20 ammo, 2 X 10 damage) \n";
        cout << "Heal - zakladni leceni. Vytahnes lekarnicku a vylecis se. (+ 10 health points) \n";
        cout << "Reload - zakladni prebiti. Prebijes si zasobnik. (+ 10 ammo) \n";
        cout << "\n";
    }
}

void player_defeat(int player_life, int opfor_life){
    if (player_life<=0){
        nastavBarvu(4);
        cout << endl;
        cout << "Srdecni puls: 0 BPM \n";
        cout << "Nenalezena zadna mozkova aktivita.\n";
        cout << "Uzivatel mrtev, cekani na reset.\n";
    }
    else if (opfor_life<0){
        nastavBarvu(7);
        cout << "\n";
        cout << "OPFOR byl porazen, zbylo z neho jen kaluz krve.\n";
        cout << "\n";
    }
    else {
        nastavBarvu(7);
        cout << "OPFOR byl porazen.\n";
    }
}

void nastavBarvu(int barva) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, barva);
}

int random_num(){
    srand(time(0));  // Inicializace generátoru
    int random = rand() % 100 + 1;  // Èíslo v rozmezí 1-100
    return random;
}

bool enough(int ammo_usage, int ammo_count){
bool pokracovani;
ammo_count = ammo_count - ammo_usage;
if (ammo_count>=0){
  pokracovani = true;
}
else{
    pokracovani = false;
}
return pokracovani;
}


