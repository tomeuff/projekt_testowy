#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Telefon
{
    //Pola klasy
private:
    string numer;
    string data;
    string godz_pocz;
    string godz_kon;

public:
    char rodzaj;
    int czas_w_sek;

    //Konstruktor klasy
public:
    Telefon(string numer_i, string data_i, string godz_pocz_i, string godz_kon_i);

    //Pozostałe metody
    string PodajNumer();

    string PodajDate();

    string PodajGodzRozp();

    string PodajGodzZak();

};

Telefon::Telefon(string numer_i, string data_i, string godz_pocz_i, string godz_kon_i)
{
    numer = numer_i;

    data = data_i;

    godz_pocz = godz_pocz_i;

    godz_kon = godz_kon_i;

    if (numer.length() == 7)
        rodzaj = 's';
    else if (numer.length() == 8)
        rodzaj = 'k';
    else rodzaj = 'z';

    int poczatek = stoi(godz_pocz.substr(0, 2)) * 60 + stoi(godz_pocz.substr(3, 2)) + stoi(godz_pocz.substr(6, 2)) / 60;
    int koniec = stoi(godz_kon.substr(0, 2)) * 60 + stoi(godz_kon.substr(3, 2)) + stoi(godz_kon.substr(6, 2)) / 60;

    czas_w_sek = koniec - poczatek;
}

string Telefon::PodajNumer()
{
    return numer;
}

string Telefon::PodajDate()
{
    return data;
}

string Telefon::PodajGodzRozp()
{
    return godz_pocz;
}

string Telefon::PodajGodzZak()
{
    return godz_kon;
}

int main()
{
    vector<Telefon> Polaczenia;
    fstream plik("telefony.txt");

    int i = 0;
    string numer, data, godz_pocz, godz_kon;

    while (!plik.eof())
    {
        plik >> numer >> data >> godz_pocz >> godz_kon;
        Polaczenia.push_back(Telefon(numer, data, godz_pocz, godz_kon));
    }

    return 0;
}
