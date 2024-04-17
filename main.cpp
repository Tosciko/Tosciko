#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

char generznakspecjalny() {
    string znakspecjalny = "!@#$%^&*()-_=+[{]}|;:,<.>/?";
    return znakspecjalny[rand() % znakspecjalny.length()];
}

char generlitera() {
    string letera = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return letera[rand() % letera.length()];
}

char generatcyfr() {
    string cyfry = "0123456789";
    return cyfry[rand() % cyfry.length()];
}

string generhaslo(int length) {
    string haslo = "";
    for (int i = 0; i < length; ++i) {
    int choice = rand() % 3;
    switch (choice) {
    case 0:
    haslo += generznakspecjalny();
    break;
    case 1:
    haslo += generlitera();
    break;
    case 2:
    haslo += generatcyfr();
    break;
    }
    }
    return haslo;
}

int main()
{
    srand(time(0));
    int length =rand() % 9 + 10;
    int ilosc=100;
    string haslo;
    vector <string> tab;
    ofstream plik;
    plik.open("doodczytania.txt");
    for (int i = 0; i < ilosc; i++)
    {
        do {
          haslo = generhaslo(length);
        } while (find(tab.begin(), tab.end(), haslo) != tab.end());
        tab.push_back(haslo);
        plik << haslo << endl;
  }
    plik.close();
  for (int i = 0; i < ilosc; i++){
    cout << tab[i] << endl;
  }
    return 0;
}
