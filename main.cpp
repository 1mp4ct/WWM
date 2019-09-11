#include <string>
#include <iostream>
#include <sstream>
#include <Windows.h>
#include <cstdlib>
#include <time.h>
using namespace std;
string frage1 = "bla";
string a1 = "a1) falsch1";
string a2 = "a2) falsch2";
string a3 = "a3) falsch3";
string a4 = "a4) richtig";
bool antwort = true;

string eingabe ;

string frage2 = "blup";
string a5 = "falsch1";
string a6 = "falsch2";
string a7 = "falsch3";
string a8 = "richtig";

int main(){

    while(antwort == true){
        cout << frage1 << endl;
        cout << a1 << endl;
        cout << a2 << endl;
        cout << a3 << endl;
        cout << a4 << endl;
        cin >> eingabe;

        if(eingabe == "a4"){
            cout << "Richtige Antwort" <<endl;
        }
        else {
            cout << "Falsche Antwort" << endl;
            antwort = false;
        }

   }

}
