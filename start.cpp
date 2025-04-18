#include <iostream>
using namespace std;
int main (){
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
int jazyk;
string souhlas = "ne";
string souhlas_en = "no";
string jmeno;
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
cin >> jmeno;
string opakovani_class;
do{

}while(opakovani_class != "ano");


return 0;
}
