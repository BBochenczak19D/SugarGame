#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <fstream>

using namespace std;

class Klient {
public:
    string imie;
    string nazwisko;
    string reakcja;
    string historyjka;
    string dobra_reakcja;
    string srednia_reakcja;
    string zla_reakcja;

    void losuj() {
        string imiona[] = { "Anna", "Jan", "Ola", "Tomek", "Zosia" };
        string nazwiska[] = { "Nowak", "Kowalski", "Wisniewski", "Kaczmarek", "Dabrowska" };
        string historyjki[] = {
            "Wyszedlem tylko po chleb, a wrocilem z wata cukrowa, trzema krasnalami i nowym tatuazem z napisem 'Slodycz to bunt'. Mama nie uwierzyla, ale babcia tak.",
            "Zakochalam sie w cukierniku. Robil landrynki, ale byl niemowa i porozumiewal sie przez dzwiek dzwoneczkow. Porwali go hipsterzy i zmusili do robienia krowek z tofu.",
            "Moj sasiad siedzi w szafie i krzyczy, ze jest batonem. Policja juz byla, ale dali mu mleko i poszli. Tez czasem czuje sie jak Prince Polo.",
            "Babcia mowi, ze w PRL-u cukierki smakowaly jak wspomnienie niedzieli i smog. Dzis dzieci jedza zelki i nie wiedza, co to ostatni Michalek.",
            "Kiedys zjadlam worek cukierkow i uslyszalam glosy. To byla reklama z radia sasiada, ale przysiegam: mowila do mnie landrynka. Miala glos Dody.",
            "Moj chlopak pracuje w fabryce lizakow. Kazdy smak to emocja. Jagodowy to wstyd, truskawkowy to trauma, a coli nie robia, bo to bylby manifest."
        };

        string dobra_reakcje[] = {
    "Smakuje jak wakacje w Radomiu z 2003!",
    "O kurde, jakby mi ktos wlal szczescie do ust.",
    "To lepsze niz darmowe próbki w Biedrze!",
    "Jakbym jadla watę cukrową posypaną dźwiękiem techno.",
    "Mniam jak pierwsze piwo na klatce schodowej!",
    "Jeszcze! I jeszcze! I moze byc z plastikiem nawet!",
    "Cukierek jak sen na dopalaczach – ale legalny.",
    "Czuję, że wraca mi wiara w ludzkość. I w słodycze."
};
        string srednia_reakcje[] = {
    "No nie wiem, jakby miętowa pasta do zębów udawala lizaka.",
    "Jest okej... ale bez dreszczy.",
    "Smakuje jak herbata u cioci: ani zła, ani dobra, po prostu jest.",
    "To chyba z tych cukierków, co się je z grzeczności.",
    "Jakby ktoś rozpuścił marzenie w chlorowanej wodzie.",
    "Taki smak 'meh', ale przynajmniej nie kopie jak gaz z kaloryfera.",
    "Jakbym jadla watę, co leżała za szafą, ale z cukrem."
};
        string zla_reakcje[] = {
    "Fuj! Smakuje jak sen o zepsutym jogurcie!",
    "To jest przestepstwo przeciwko kubkom smakowym.",
    "Czy to... guma do zucia po babci?",
    "Mam wrazenie, że zjadlam zapach klatki schodowej.",
    "To nie jest cukierek, to trauma w folii.",
    "Smak jak z autobusu linii 145 w lipcu – bez klimy.",
    "Wypluj mnie, blagam – krzyczy moj jezyk.",
    "Czuje sie jakbym zdradziła swoją diete i swoja godnosc."
};

        //losowanie imienia, nazwiska i historyjki
        imie = imiona[rand() % 5];
        nazwisko = nazwiska[rand() % 5];
        historyjka = historyjki[rand() % 5];
        dobra_reakcja = dobra_reakcje[rand() % 5];
        srednia_reakcja = srednia_reakcje[rand() % 5];
        zla_reakcja = zla_reakcje[rand() % 5];
    }

    void zareaguj(bool poprawne) {
        if (poprawne)
            cout << dobra_reakcja << endl;
        else
             cout << zla_reakcja << endl;
    }

    void pokaz() {
        cout << "Klient: " << imie << " " << nazwisko << endl;
        cout << "Historyjka: " << historyjka << endl;
    }
};

class Skladnik {
public:
    string nazwa;
    string ilosc; // "malo" lub "duzo"

     static void wyswietlSklep() {

        string listaSkladnikow[] = { "woda z kaloryfera",
    "cukier z PRL-u",
    "aromat biedy",
    "mleko w proszku 3.0",
    "cola turbo light",
    "syrop z melancholii",
    "smog malinowy",
    "gluten syntetyczny",
    "kofeina uliczna",
    "mieta z kebaba",
    "popiol z papierosa mentolowego",
    "olejek disco polo",
    "parowka waniliowa",
    "brokat z bazaru",
    "sok z dramatyzmu",
    "margaryna wspomnien",
    "piana z energetyka",
    "aromat porazki" };
        cout << "=== SKLADNIKI DO WYBORU ===" << endl;
        for (int i = 0; i < 8; ++i) {
            cout << "- " << listaSkladnikow[i] << " (malo / duzo)" << endl;
        }
        cout << "=======================" << endl;
    }
};

class Receptura {
public:
    string nazwa;
    Skladnik skladniki[3];

    void ustawMojito() {
        nazwa = "Mojito";
        skladniki[0] = { "woda", "duzo" };
        skladniki[1] = { "rum", "duzo" };
        skladniki[2] = { "mieta", "malo" };
    }

    void pokaz() {
        cout << "Zamowienie: " << nazwa << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "- " << skladniki[i].nazwa << ": " << skladniki[i].ilosc << endl;
        }
    }
};

class Gra {
public:
    Klient klient;
    Receptura receptura;
    Skladnik wybor[3];

    bool porownaj() {
        // Sprawdzamy, czy podane składniki zgadzają się z recepturą (nazwa i ilość)
        for (int i = 0; i < 3; ++i) {
            bool znaleziono = false;
            for (int j = 0; j < 3; ++j) {
                if (wybor[i].nazwa == receptura.skladniki[j].nazwa &&
                    wybor[i].ilosc == receptura.skladniki[j].ilosc) {
                    znaleziono = true;
                    break;
                }
            }
            if (!znaleziono) return false; // jeśli któryś składnik nie pasuje, zwróć false
        }
        return true; // jeśli wszystkie pasują, zwróć true
    }

    void start() {
        srand(time(0)); // inicjalizacja losowania

        klient.losuj();
        receptura.ustawMojito();

        cout << "--------------------------------\n";

        klient.pokaz();
        cout << "Zamowienie do wykonania: ";
        receptura.pokaz();
        cout << "--------------------------------\n";
        Skladnik::wyswietlSklep();
        cout << "--------------------------------\n";

        cout << "\nDodaj 3 skladniki (nazwa + malo/duzo):\n";
        for (int i = 0; i < 3; ++i) {
            cout << "Skladnik #" << (i + 1) << ": ";
            getline(cin, wybor[i].nazwa);
            cout << "  Ilosc (malo/duzo): ";
            getline(cin, wybor[i].ilosc);
        }

        bool trafione = porownaj();
        klient.zareaguj(trafione);

        // zapis do pliku
        ofstream plik("wyniki.txt", ios::app);
        if (plik.is_open()) {
            plik << "Klient: " << klient.imie << " " << klient.nazwisko << endl;
            plik << "Historyjka: " << klient.historyjka << endl;
            plik << "Zamówienie (właściwe):" << endl;
            for (int i = 0; i < 3; ++i) {
                plik << "- " << receptura.skladniki[i].nazwa << ": " << receptura.skladniki[i].ilosc << endl;
            }
            plik << "Twoje składniki:" << endl;
            for (int i = 0; i < 3; ++i) {
                plik << "- " << wybor[i].nazwa << ": " << wybor[i].ilosc << endl;
            }
            plik << "Ocena klienta: ";
            if (trafione) {
                plik << klient.dobra_reakcja;
            } else {
                plik << klient.zla_reakcja;
            }
            plik << "\n---------------------------\n";
            plik.close();
        } else {
            cout << "Nie udało się otworzyć pliku do zapisu!" << endl;
        }
    }
};
int main() {
    Menu menu;
    menu.uruchom(); // odpala menu i ewentualnie grę
    return 0;
}
