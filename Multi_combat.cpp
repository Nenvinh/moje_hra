#include <iostream>
#include <cstdlib> // knihovna pro random
#include <ctime> // knihovna pro unique num
#include <windows.h> // knihovna pro barvy textu
using namespace std;

void player_defeat(int player_life, int opfor_life);
void manual(bool promena = true);
int random_num();
void nastavBarvu(int barva);
bool enough(int ammo_usage, int ammo_count);
void market(string jmeno, int life, int ammo_gain, int armour, int heal, int attack, int level, int max_ammo);
int take_money(int cena, int penize);
void status_check(int life, int attack, int armour, int reload, int heal, int level, string jmeno);

int main (){
//player
struct{
    string jmeno = "Random_placeholder_name";

    string schopnosti;
    int life = 240;
    int max_life = 24;
    int attack = 10; // all attack

    int heavy_attack = attack * 2;

    int ammo = 300;
    int max_ammo = 30;
    int ammo_usage = 10;
    int ammo_usage_heavy = ammo_usage * 1.5;
    int ammo_gain = 10;
    int armour = 0;

    int heal = 5;
    int level = 1;
    int cash = 220;
    string nakup;
    int price = 0;

    int inventory[3]{0, 0, 0};
}player;

//opfor
struct{
    string final_boss = " Andres 'Ascendrax' Dragan ";
    string mini_boss_1 = "place_holder_name1";
    string mini_boss_2 = "place_holder_name2";

    float life = 30;
    int damage = 10;

    float life_2 = 40;
    int damage_2 = 10;

    float life_3 = 50;
    int damage_3 = 10;

    float level = 1;

    string jmena[4]{"Bandita", "Ostrelovac", "Bandita s brokovnici", "Bandita"};
}opfor;

//standart combat
//parametry
bool opakovani = false;
int fumble = 0;
int pocet_nepratel = 3;
int multi_combat = 0;
do{
    nastavBarvu(10);
    cout << "-------------------------------------------------------"<< player.jmeno << " STATS-------------------------------------------------"<<endl;
    string utok;
    cout << "Player stats: \n";
    cout << "Player life: " << player.life << " hp" << endl;
    cout << "Player ammo: " << player.ammo << endl;
    cout << "Player attack: " << player.attack << " dmg" << endl;
    cout << "\n";
    nastavBarvu(4);
    cout << "-------------------------------------------------------OPFOR STATS-------------------------------------------------"<<endl;
    cout << "OPFOR stats: \n";
    cout << "OPFOR life: " << opfor.life << " hp" << endl;
    cout << "OPFOR attack: " << opfor.damage << " dmg" << endl;
    cout << "\n";
    if (pocet_nepratel == 2){
    cout << "OPFOR_2* stats: \n";
    cout << "OPFOR life: " << opfor.life_2 << " hp" << endl;
    cout << "OPFOR attack: " << opfor.damage_2 << " dmg" << endl;
    cout << "\n";
    }
    else if(pocet_nepratel == 3){
    cout << "OPFOR_2 stats: \n";
    cout << "OPFOR life: " << opfor.life_2 << " hp" << endl;
    cout << "OPFOR attack: " << opfor.damage_2 << " dmg" << endl;
    cout << "\n";
    cout << "OPFOR_3 stats: \n";
    cout << "OPFOR life: " << opfor.life_3 << " hp" << endl;
    cout << "OPFOR attack: " << opfor.damage_3 << " dmg" << endl;
    cout << "\n";
    }
    nastavBarvu(7);
    manual();
    nastavBarvu(10);
    cout << "-------------------------------------------------------"<< player.jmeno << " ACTIONS-------------------------------------------------"<<endl;
    nastavBarvu(7);
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
    switch(pocet_nepratel){
        case 1:
            player.ammo = player.ammo - player.ammo_usage;
            opfor.life = opfor.life - player.attack;
            cout << "\n";
            cout << "Zacal jsi strilet na nepritele, - " << player.attack << " dmg.\n";
            cout << "Vyuzil jsi: " << "- " << player.ammo_usage << " naboju.\n";
            i = 3;
        break;

        case 2:
            cout << "Cile: \n";
            cout << "1. OPFOR_1 hp: " << opfor.life << endl;
            cout << "2. OPFOR_2 hp: " << opfor.life_2 << endl;
            cout << "Smer strebly: \n";
            cin >> multi_combat;
            if(multi_combat = 1){
                player.ammo = player.ammo - player.ammo_usage;
                opfor.life = opfor.life - player.attack;
                cout << "\n";
                cout << "Zacal jsi strilet na nepritele, - " << player.attack << " dmg.\n";
                cout << "Vyuzil jsi: " << "- " << player.ammo_usage << " naboju.\n";
                i = 3;
            }
            else if(multi_combat = 2){
                player.ammo = player.ammo - player.ammo_usage;
                opfor.life_2 = opfor.life_2 - player.attack;
                cout << "\n";
                cout << "Zacal jsi strilet na nepritele, - " << player.attack << " dmg.\n";
                cout << "Vyuzil jsi: " << "- " << player.ammo_usage << " naboju.\n";
                i = 3;
            }
            else{
                cout << "Neplatny cil.\n";
            }
        break;

        case 3:
            cout << "Cile: \n";
            cout << "1. OPFOR_1 hp: " << opfor.life << endl;
            cout << "2. OPFOR_2 hp: " << opfor.life_2 << endl;
            cout << "3. OPFOR_3 hp: " << opfor.life_3 << endl;
            cout << "Smer strebly: ";
            cin >> multi_combat;
            if(multi_combat == 1){
                player.ammo = player.ammo - player.ammo_usage;
                opfor.life = opfor.life - player.attack;
                cout << "\n";
                cout << "Zacal jsi strilet na nepritele, - " << player.attack << " dmg.\n";
                cout << "Vyuzil jsi: " << "- " << player.ammo_usage << " naboju.\n";
                i = 3;
            }
            else if(multi_combat == 2){
                player.ammo = player.ammo - player.ammo_usage;
                opfor.life_2 = opfor.life_2 - player.attack;
                cout << "\n";
                cout << "Zacal jsi strilet na nepritele, - " << player.attack << " dmg.\n";
                cout << "Vyuzil jsi: " << "- " << player.ammo_usage << " naboju.\n";
                i = 3;
            }
            else if(multi_combat == 3){
                player.ammo = player.ammo - player.ammo_usage;
                opfor.life_3 = opfor.life_3 - player.attack;
                cout << "\n";
                cout << "Zacal jsi strilet na nepritele, - " << player.attack << " dmg.\n";
                cout << "Vyuzil jsi: " << "- " << player.ammo_usage << " naboju.\n";
                i = 3;
            }
            else{
                cout << "Neplatny cil.\n";
            }
        }
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

        switch(pocet_nepratel){
        case 1:
            player.ammo = player.ammo - player.ammo_usage_heavy;
            opfor.life = opfor.life - player.heavy_attack;
            cout << "\n";
            cout << "Zamiril jsi na nepritele a strilel, - " << player.heavy_attack << " dmg.\n";
            cout << "Vyuzil jsi: " << "- " << player.ammo_usage_heavy << " naboju.\n";
            i = 3;
        break;

        case 2:
            cout << "Cile: \n";
            cout << "1. OPFOR_1 hp: " << opfor.life << endl;
            cout << "2. OPFOR_2 hp: " << opfor.life_2 << endl;
            cout << "Smer strebly: \n";
            cin >> multi_combat;
            if(multi_combat == 1){
                player.ammo = player.ammo - player.ammo_usage_heavy;
                opfor.life = opfor.life - player.heavy_attack;
                cout << "\n";
                cout << "Zamiril jsi na nepritele a strilel, - " << player.heavy_attack << " dmg.\n";
                cout << "Vyuzil jsi: " << "- " << player.ammo_usage_heavy << " naboju.\n";
                i = 3;
            }
            else if(multi_combat == 2){
                player.ammo = player.ammo - player.ammo_usage_heavy;
                opfor.life_2 = opfor.life_2 - player.heavy_attack;
                cout << "\n";
                cout << "Zamiril jsi na nepritele a strilel, - " << player.heavy_attack << " dmg.\n";
                cout << "Vyuzil jsi: " << "- " << player.ammo_usage_heavy << " naboju.\n";
                i = 3;
            }
            else{
                cout << "Neplatny cil.\n";
            }
        break;

        case 3:
            cout << "Cile: \n";
            cout << "1. OPFOR_1 hp: " << opfor.life << endl;
            cout << "2. OPFOR_2 hp: " << opfor.life_2 << endl;
            cout << "3. OPFOR_3 hp: " << opfor.life_3 << endl;
            cout << "Smer strebly: ";
            cin >> multi_combat;
            if(multi_combat == 1){
                player.ammo = player.ammo - player.ammo_usage_heavy;
                opfor.life = opfor.life - player.heavy_attack;
                cout << "\n";
                cout << "Zamiril jsi na nepritele a strilel, - " << player.heavy_attack << " dmg.\n";
                cout << "Vyuzil jsi: " << "- " << player.ammo_usage_heavy << " naboju.\n";
                i = 3;
            }
            else if(multi_combat == 2){
                player.ammo = player.ammo - player.ammo_usage_heavy;
                opfor.life_2 = opfor.life_2 - player.heavy_attack;
                cout << "\n";
                cout << "Zamiril jsi na nepritele a strilel, - " << player.heavy_attack << " dmg.\n";
                cout << "Vyuzil jsi: " << "- " << player.ammo_usage_heavy << " naboju.\n";
                i = 3;
            }
            else if(multi_combat == 3){
                player.ammo = player.ammo - player.ammo_usage_heavy;
                opfor.life_3 = opfor.life_3 - player.heavy_attack;
                cout << "\n";
                cout << "Zamiril jsi na nepritele a strilel, - " << player.heavy_attack << " dmg.\n";
                cout << "Vyuzil jsi: " << "- " << player.ammo_usage_heavy << " naboju.\n";
                i = 3;
            }
            else{
                cout << "Neplatny cil.\n";
            }
        }
        break;


        player.ammo = player.ammo - player.ammo_usage_heavy;
        opfor.life = opfor.life - player.heavy_attack;
        cout << "\n";
        cout << "Zamiril jsi na nepritele a strilel, - " << player.heavy_attack << " dmg.\n";
        cout << "Vyuzil jsi: " << "- " << player.ammo_usage_heavy << " naboju.\n";
        i = 3;
        break;
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
    cout << "--------------------------------------------------------ENEMY ACTIONS---------------------------------------------------"<<endl;
    if (opfor.life >0){
    cout << "Nepritel na tebe zautocil.\n";
    player.life = player.life - (opfor.damage - player.armour);
    cout << "- " << opfor.damage << " hp\n";
    }
    if(opfor.life_2 >0){
    cout << "Nepritel na tebe zautocil.\n";
    player.life = player.life - (opfor.damage - player.armour);
    cout << "- " << opfor.damage << " hp\n";
    }
    if(opfor.life_3 >0){
    cout << "Nepritel na tebe zautocil.\n";
    player.life = player.life - (opfor.damage - player.armour);
    cout << "- " << opfor.damage << " hp\n";
    }

}while(player.life>0 && (opfor.life>0 || opfor.life_2>0 || opfor.life_3>0));
player_defeat(player.life, opfor.life);

return 0;
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
    srand(time(0));  // Inicializace genertoru
    int random = rand() % 100 + 1;  // slo v rozmez 1-100
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
cout << "Max. ammo: \n";
cout << "Reload: + " << reload << " ammo\n";
cout << "Leceni: + " << heal << " hp\n";
}
