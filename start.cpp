#include <iostream>
using namespace std;
#include <cstdlib> // knihovna pro random
#include <ctime> // knihovna pro unique num
#include <windows.h> // knihovna pro barvy textu
//funkce
void vyber_class();
void nastavBarvu(int barva);



int main (){

struct{
    string jmeno = "Random_placeholder_name";
    int player_class;

    string schopnosti;
    int life = 24;
    int max_life = 24;
    int attack = 10; // all attack

    int heavy_attack = attack * 2;

    int ammo = 30;
    int max_ammo = 30;
    int ammo_usage = 10;
    int ammo_usage_heavy = ammo_usage * 1.5;
    int ammo_gain = 10;
    int armour = 0;

    int heal = 5;
    int level = 1;
    int cash = 120;
    string nakup;
    int price = 0;

    int inventory[3]{0, 0, 0};
}player;

struct{
    string final_boss = " Andres 'Ascendrax' Dragan ";
    string mini_boss_1 = "place_holder_name1";
    string mini_boss_2 = "place_holder_name2";
    float life = 30;
    int damage = 10;
    float level = 1;
    int pocet = 1;
}opfor;
int jazyk;
string souhlas = "ne";
string souhlas_en = "no";



nastavBarvu(10);
//Font Name: 3d
cout  << " ********              **              *******             ********   " << endl;
cout  << "/**/////              ****            /**////**           **//////    " << endl;
cout  << "/**                  **//**           /**   /**          /**          " << endl;
cout  << "/*******            **  //**          /*******           /*********   " << endl;
cout  << "/**////            **********         /**///**           ////////**   " << endl;
cout  << "/**       **      /**//////** **      /**  //**  **             /** **" << endl;
cout  << "/********/**      /**     /**/**      /**   //**/**       ******** /**" << endl;
cout  << "//////// //       //      // //       //     // //       ////////  // " << endl;
cout  << "Electronic action recording system" << endl;
cout  << "Ver: 1.53" << endl;
cout  << "Vyvijeno spolecnosti Miliware" << endl;
cout << "\n";
nastavBarvu(7);

cout << "1 - Cestina\n";
cout << "2 - English\n";
cout << "Vyberte si jazyk: ";
cin >> jazyk;
while (souhlas == "ne" && souhlas_en == "no"){
switch (jazyk){
    case 1:
        cout << "Jste si jisty (ano/ne): ";
        cin >> souhlas;
        if (souhlas == "ne"){
            cout << "Eng. file failed to load, try later.\n";
            cout << "Jazyk nastaven na cestinu.\n";
            souhlas = "ano";
        }
        break;
    case 2:
        cout << "Eng. file failed to load, try later.\n";
        cout << "Jazyk nastaven na cestinu.\n";
        souhlas = "ano";
        break;
    default:
        cout << "Opakjute znovu vyber jazyka: ";
        cin >> jazyk;
        while (jazyk != 1 && jazyk !=2){
        cout << "Opakjute znovu vyber jazyka: ";
        cin >> jazyk;
        }
        if (jazyk == 2){
        cout << "Eng. file failed to load, try later.\n";
        cout << "Jazyk nastaven na cestinu.\n";
        souhlas = "ano";
        }
        if (jazyk == 1){
            cout << "Jazyk nastaven na Cestinu.\n";
            souhlas = "ano";
        }
        break;
}
}
cout << "Vitejte uzivateli: ";
cin >> player.jmeno;
cout << player.jmeno;
string opakovani_class;
do{
vyber_class();
cout << "Rozhodnuti: ";
cin >> player.player_class;
//
switch(player.player_class){
    //rifleman
    case 1:
        player.life = 24;
        player.max_life = 24;
        player.attack = 10;
        player.ammo = 30;
        player.max_ammo = 30;
        player.ammo_gain = 10;
        player.armour = 0;
        player.heal = 5;
        player.cash = 10;
    break;
    //medic
    case 2:
        player.life = 24;
        player.max_life = 24;
        player.attack = 10;
        player.ammo = 30;
        player.max_ammo = 30;
        player.ammo_gain = 10;
        player.armour = 0;
        player.heal = 10;
        player.cash = 5;
    break;
    //juggernaut
    case 3:
        player.life = 24;
        player.max_life = 24;
        player.attack = 10;
        player.ammo = 30;
        player.max_ammo = 30;
        player.ammo_gain = 10;
        player.armour = 10;
        player.heal = 5;
        player.cash = 5;
    break;
    //scout
    case 4:
        player.life = 24;
        player.max_life = 24;
        player.attack = 10;
        player.ammo = 30;
        player.max_ammo = 30;
        player.ammo_gain = 15;
        player.armour = 0;
        player.heal = 5;
        player.cash = 5;
    break;
    //machine gunner
    case 5:
        player.life = 24;
        player.max_life = 24;
        player.attack = 10;
        player.ammo = 40;
        player.max_ammo = 40;
        player.ammo_gain = 10;
        player.armour = 0;
        player.heal = 5;
        player.cash = 5;
    break;
    //Special forces
    case 6:
        player.life = 24;
        player.max_life = 24;
        player.attack = 25;
        player.ammo = 30;
        player.max_ammo = 30;
        player.ammo_gain = 10;
        player.armour = 0;
        player.heal = 5;
        player.cash = 5;
    break;
    //comander
    case 7:
        player.life = 34;
        player.max_life = 34;
        player.attack = 10;
        player.ammo = 30;
        player.max_ammo = 30;
        player.ammo_gain = 10;
        player.armour = 0;
        player.heal = 5;
        player.cash = 5;
    break;
}
}while (opakovani_class != "ano");


return 0;
}

void vyber_class(){
cout << "Vyber si zamereni: \n";
cout << "   1. Rifle man: \n";
cout << "       life: 24 hp, attack: 10 dmg, ammo: 30, reload: 10, armour: - 0 dmg, heal: 5 hp, money: 10k $ \n";
cout << "   2. Medic: \n";
cout << "       life: 24 hp, attack: 10 dmg, ammo: 30, reload: 10, armour: - 0 dmg, heal: 10 hp, money: 5k $  \n";
cout << "   3. Juggernaut: \n";
cout << "       life: 24 hp, attack: 10 dmg, ammo: 30, reload: 10, armour: - 10 dmg, heal: 5 hp, money: 5k $  \n";
cout << "   4. Scout: \n";
cout << "       life: 24 hp, attack: 10 dmg, ammo: 30, reload: 15, armour: - 0 dmg, heal: 5 hp, money: 5k $  \n";
cout << "   5. Machine gunner: \n";
cout << "       life: 24 hp, attack: 10 dmg, ammo: 40, reload: 10, armour: - 0 dmg, heal: 10 hp, money: 5k $  \n";
cout << "   6. Special forces: \n";
cout << "       life: 24 hp, attack: 25 dmg, ammo: 40, reload: 10, armour: - 0 dmg, heal: 10 hp, money: 5k $  \n";
cout << "   7. Commander: \n";
cout << "       life: 34 hp, attack: 10 dmg, ammo: 40, reload: 10, armour: - 0 dmg, heal: 10 hp, money: 5k $  \n";
}

void nastavBarvu(int barva) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, barva);
}