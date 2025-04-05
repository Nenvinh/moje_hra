#include <iostream>
#include <cstdlib> // knihovna pro random
#include <ctime> // knihovna pro unique num
using namespace std;
int main (){
srand(time(0));
int random = rand() % 2;
int player_life = 30, player_attack = 10;
int opfor_life = 30, opfor_attack = 3;
string utok;
do{
    cout << "Zadej utok: ";
    cin >> utok;
    if (utok == "utok"){
        opfor_life = opfor_life - player_attack;
    }
    cout << "OPFOR life: " << opfor_life << endl;
    cout << "Proti utok.\n";
    player_life = player_life - opfor_attack;
    cout << "Player life: " << player_life << endl;
}while(player_life>0&&opfor_life>0);






return 0;
}
