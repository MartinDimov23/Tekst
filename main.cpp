#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

void enkripcija(int kluc); void dekripcija(int kluc);

int count_digit(int number) {
   return int(log10(number) + 1);
}

int main()
{
    int broj,kluc,brojNaCifri,najgolemaCifra,n,r,sd;
    string izbor;

    cout<<"Vnesete pozitiven broj ne pogolem od 6 cifri: ";
    cin>>broj;
    brojNaCifri = count_digit(broj);
    n = broj;
    najgolemaCifra = 0;

    while (n > 0) {
        r = n % 10;
        if (najgolemaCifra < r) {
            najgolemaCifra = r;
        }
        n = n / 10;
    }

    kluc = abs(brojNaCifri-najgolemaCifra); //Apsolutna vrednost od razlikata na brojot na cifri i najgolemata cifra



    if (broj < 1000000) {

    } else {
        cout<<"Vnesovte broj pogolem od 6 cifri!"<<endl;
        }

    cout<<"Izbere enkripcija ili dekripcija: ";
    cin>>izbor;
    if (izbor == "enkripcija") {
        cin.ignore();
        enkripcija(kluc);
    }

    if (izbor == "dekripcija") {
        cin.ignore();
        dekripcija(kluc);
    }


    return 0;
}

//Funkcija za enkripcija

void enkripcija (int kluc) {

    string text;
    int asciiText[300];
    int shiftedASCII[300];

    cin.clear();
    cout<<"Vnesi tekst: ";
    getline(cin, text);
    if (text.size() < 300) {
        for(unsigned int i = 0; i<text.size(); i++)
        {
            asciiText[i] = (int)text.at(i);
        }

        cout<<endl;

        for(unsigned int i = 0; i<text.size(); i++)
        {
            shiftedASCII[i] = asciiText[i]+kluc; //So ovaa linija kod se enkriptira ASCII kodot
        }

        for(unsigned int i = 0; i<text.size(); i++)
        {
            cout<<(char) shiftedASCII[i];
        }

        cout<<endl<<endl;
    }
}

//Funkcija za dekripcija

void dekripcija (int kluc) {

    string text;
    int asciiText[300];
    int shiftedASCII[300];

    cout<<"Vnesi tekst"<<endl;
    getline(cin, text);
    if (text.size() < 300) {
        for(unsigned int i = 0; i<text.size(); i++)
        {
            asciiText[i] = (int)text.at(i);
        }

        cout<<endl;

        for(unsigned int i = 0; i<text.size(); i++)
        {
            shiftedASCII[i] = asciiText[i]-kluc; //So ovaa linija kod se dekriptira ASCII kodot
        }

        for(unsigned int i = 0; i<text.size(); i++)
        {
            cout<<(char) shiftedASCII[i];
        }
    }
}