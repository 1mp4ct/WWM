#include <string>
#include <iostream>
#include <sstream>
//#include <Windows.h>
#include <cstdlib>
#include <time.h>
using namespace std;
void a1()
{
string frage1 = "bla";
string a1 = "a1) falsch1";
string a2 = "a2) falsch2";
string a3 = "a3) falsch3";
string a4 = "a4) richtig";

cout << frage1 << endl;
cout << a1 << endl;
cout << a2 << endl;
cout << a3 << endl;
cout << a4 << endl;
}
bool antwort = true;

string eingabe ;
void a2(){
string frage2 = "blup";
string a1 = "falsch1";
string a2 = "falsch2";
string a3 = "falsch3";
string a4 = "richtig";

cout << frage2 << endl;
cout << a1 << endl;
cout << a2 << endl;
cout << a3 << endl;
cout << a4 << endl;
}

int a3(){
string frage2 = "blaaaaaa";
string a1 = "falsch1";
string a2 = "falsch2";
string a3 = "falsch3";
string a4 = "richtig";

cout << frage2 << endl;
cout << a1 << endl;
cout << a2 << endl;
cout << a3 << endl;
cout << a4 << endl;
}
int main(){

    while(antwort == true){

    for(int i=1; i<=20; i++)
            {
                cout << "a" << i << endl;


            }

cout << a3() <<endl;
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