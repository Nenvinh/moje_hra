#include <iostream>
#include <cstdlib> // knihovna pro random
#include <ctime> // knihovna pro unique num
#include <windows.h> // knihovna pro barvy textu
//funkce
void vyber_class();
void player_defeat(int player_life, int opfor_life);
void manual(bool promena = true);
int random_num();
void nastavBarvu(int barva);
bool enough(int ammo_usage, int ammo_count);
void market(string jmeno, int life, int ammo_gain, int armour, int heal, int attack, int level, int max_ammo);
int take_money(int cena, int penize);
void status_check(int life, int attack, int armour, int reload, int heal, int level, string jmeno);

using namespace std;

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
cout << "\n";
string opakovani_class;
do{
    vyber_class();
    cout << "Rozhodnuti: ";
    cin >> player.player_class;
    cout << "Jsi jisty? (ano/ne): ";
    cin >> opakovani_class;
}while (opakovani_class != "ano");

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
string tutorial;
cout << "System: Detekovan novy uzivatel. Budete chtit zapnout tutorial? (ano/ne): ";
cin >> tutorial;
cout << "\n";
if (tutorial == "ano"){
//tutorial
while (tutorial == "ano"){

//reset veci
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

bool opakovani = false;
int fumble = 0;
//combat kod
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
        if (player.ammo<=player.max_ammo){
            cout << "\n";
            cout << "Prebij jsi zasobnik, + " << player.ammo_gain << " munice\n";
            i = 3;
        }
        else{
            cout << "\n";
            cout << "Mas dostatek munice, nedokazes nest vice munice.\n";
            player.ammo = player.ammo - player.ammo_gain;
            cout << "\n";
        }
    }
    else if(utok == "heal"){
        player.life = player.life + player.heal;
        if(player.life <= player.max_life){
            cout << "\n";
            cout << "Vylecil ses, + " << player.heal << " hp\n";
            i = 3;
        }
        else{
            player.life = player.life - player.heal;
            cout << "\n";
            cout << "Nejsi zraneni, nemuzes se vylecit.\n";
            cout << "\n";
        }
    }
    else if(utok == "skip"){
        opfor.life = 0;
        i = 3;
        cout << "                                                  Skipping fight\n";
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
cout << "Zopakovat tutorial? (ano/ne): ";
cin >> tutorial;
}

}
else{
    cout << player.jmeno << " pripraven do boje. Vysilam do oblasti MCZ-256.\n";
    cout << "Mise 'Modra': Zajmout nebo zabit Andres 'Ascendrax' Dragan.\n";
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

}


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

void market(string jmeno, int life, int ammo_gain, int armour, int heal, int attack, int level, int max_ammo){
cout << "\n";
cout << "Dostupna nabidka:\n";
cout << "   life: ";
switch(life){
case 24:
    cout << "Leky proti bolesti (24 + 10 hp), cena: 12k $\n";
    break;
case 34:
    cout << "Adrenalin (24 + 15 hp), cena: 16k $\n";
    break;
case 39:
    cout << "4EA1 - experimental (24 + 20 hp), cena: 20k $\n";
    break;
case 44:
    cout << "Vsechny vylepseni zakoupeny.\n";
    break;
}
cout << "   reload: ";
switch(ammo_gain){
case 10:
    cout << "Mag extention (+ 15 munice pri reload), cena: 8k $\n";
    break;
case 15:
    cout << "Drum Mag (+ 20 munice pri reload), cena: 16k $\n";
    break;
case 20:
    cout << "Ammo box (+ 25 munice pri reload), cena: 24k $\n";
    break;
case 25:
    cout << "Vsechny vylepseni zakoupeny.\n";
    break;
}
cout << "   ammo: ";
switch (max_ammo)
{
case 30:
    cout << "Standarni webbing (zvyseni max. kapacity munice na 40), cena: 4k $\n";
    break;
case 40:
    cout << "Machine gunner webbing (zvyseni max. kapacity munice na 50), cena: 8k $\n";
    break;
case 50:
    cout << "Special forces webbing (zvyseni max. kapacity munice na 60), cena: 12k $\n";
    break;
case 60:
    cout << "Vsechny vylepseni zakoupeny.\n";
    break;
}
cout << "   armour: ";
switch(armour){
case 0:
    cout << "Neprustrelna vesta I. tridy (dmg obdrzeny od nepritele snizeny - 10), cena: 15k $\n";
    break;
case 10:
    cout << "Neprustrelna vesta II. tridy (dmg obdrzeny od nepritele snizeny - 20), cena: 28k $\n";
    break;
case 20:
    cout << "Neprustrelna vesta III. tridy (dmg obdrzeny od nepritele snizeny - 30), cena: 36k $\n";
    break;
case 30:
    cout << "Vsechny vylepseni zakoupeny.\n";
    break;
}
cout << "   heal: ";
switch(heal){
case 5:
    cout << "Field manual 0856: Zaklady osetrovatelstvi (+ 10 hp pri heal), cena: 8k $\n";
    break;
case 10:
    cout << "Field manual 0857: Osetrovatelstvi pro vojenske lekare (+ 15 hp pri heal), cena: 14k $\n";
    break;
case 15:
    cout << "Field manual 0858: Osetrovatelstvi pro vojenske chirurky (+ 20 hp pri heal), cena: 20k $\n";
    break;
case 20:
    cout << "Vsechny vylepseni zakoupeny.\n";
    break;
}
cout << "   damage: ";
switch(attack){
case 10:
    cout << "MP5k [laser sight, laser] (25 dmg, - 20 ammmo), cena: 10k $\n";
    break;
case 25:
    cout << "M4A1 [laser sight, flash hider, vertical grip] (40 dmg, - 30 ammmo), cena: 25k $\n";
    break;
case 40:
    cout << "Barrett M82 [laser, flash hider, 8x scope, vertical grip] (50 dmg, - 40 ammmo), cena: 40k $\n";
    break;
case 50:
    cout << "Vsechny vylepseni zakoupeny.\n";
    break;
}

cout << "Odejit - Odejdes ze zakladny.\n";
}

void manual(bool promena){
    if (promena = true){
        cout << "Manual: \n";
        cout << "Spray - zakladni utok bez mireni. Stisknes spoust a budes doufat, ze neco zasahnes. \n";
        cout << "Aim - zakladni utok s mireni. Vystrelis 20 kulek a zasadis nepriteli dvojnasobek ran. \n";
        cout << "Heal - zakladni leceni. Vytahnes lekarnicku a vylecis se. \n";
        cout << "Reload - zakladni prebiti. Prebijes si zasobnik. \n";
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
        nastavBarvu(7);
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

int random_num(){
    srand(time(0));  // Inicializace gener�toru
    int random = rand() % 100 + 1;  // ��slo v rozmez� 1-100
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

int take_money(int cena, int penize){
penize = penize - cena;
return penize;
}

void status_check(int life, int attack, int armour, int reload, int heal, int level, string jmeno){
cout << "Tvoje vylepseni.\n";
cout << "Jmeno: " << jmeno << endl;
cout << "Uroven: " << level << endl;
cout << "Zivoty: " << life << " hp\n";
cout << "Sila utoku: - " << attack << " dmg\n";
cout << "Neprustrelna vesta: " << armour << " dmg\n";
cout << "Reload: + " << reload << " ammo\n";
cout << "Leceni: + " << heal << " hp\n";
}

