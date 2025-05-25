#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

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
    "Jakbym jadla watê cukrow¹ posypan¹ dŸwiêkiem techno.",
    "Mniam jak pierwsze piwo na klatce schodowej!",
    "Jeszcze! I jeszcze! I moze byc z plastikiem nawet!",
    "Cukierek jak sen na dopalaczach – ale legalny.",
    "Czujê, ¿e wraca mi wiara w ludzkoœæ. I w s³odycze."
};
        string srednia_reakcje[] = {
    "No nie wiem, jakby miêtowa pasta do zêbów udawala lizaka.",
    "Jest okej... ale bez dreszczy.",
    "Smakuje jak herbata u cioci: ani z³a, ani dobra, po prostu jest.",
    "To chyba z tych cukierków, co siê je z grzecznoœci.",
    "Jakby ktoœ rozpuœci³ marzenie w chlorowanej wodzie.",
    "Taki smak 'meh', ale przynajmniej nie kopie jak gaz z kaloryfera.",
    "Jakbym jadla watê, co le¿a³a za szaf¹, ale z cukrem."
};
        string zla_reakcje[] = {
    "Fuj! Smakuje jak sen o zepsutym jogurcie!",
    "To jest przestepstwo przeciwko kubkom smakowym.",
    "Czy to... guma do zucia po babci?",
    "Mam wrazenie, ¿e zjadlam zapach klatki schodowej.",
    "To nie jest cukierek, to trauma w folii.",
    "Smak jak z autobusu linii 145 w lipcu – bez klimy.",
    "Wypluj mnie, blagam – krzyczy moj jezyk.",
    "Czuje sie jakbym zdradzi³a swoj¹ diete i swoja godnosc."
};

        //losowanie imienia, nazwiska i historyjki
        imie = imiona[rand() % 5];
        nazwisko = nazwiska[rand() % 5];
        historyjka = historyjki[rand() % 5];
        historyjka = historyjki[rand() % 5];
        dobra_reakcja = dobra_reakcje[rand() % 5];
        srednia_reakcja = srednia_reakcje[rand() % 5];
        zla_reakcja = zla_reakcje[rand() % 5];
    }

    void zareaguj(bool poprawne) {
        if (poprawne)
            cout << dobra_reakcja << endl;
        else
             cout << zla_reakcja << reakcja << endl;
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

    void start() {
        srand(time(0)); //funkcja potrzebna do losowania

        klient.losuj();
        receptura.ustawMojito();

        cout << "--------------------------------\n";

        klient.pokaz();
        cout << "Zamowienie do wykonania: ";
        receptura.pokaz(); //f do wystwietlania receptury ktora sie wylosowala - odkomentuj zeby zobaczyc czy program dzia³a dobrze
        cout << "--------------------------------\n";
        Skladnik::wyswietlSklep(); // to jest funkcja statyczna wiec mozna j¹ wywo³aæ poprzez "::" klasa::nazwa_funkcji
        cout << "--------------------------------\n";
        cout << "\nDodaj 3 skladniki (nazwa + malo/duzo):\n";
        for (int i = 0; i < 3; ++i) {
            cout << "Skladnik #" << (i + 1) << ": ";
            getline(cin, wybor[i].nazwa);
            cout << endl;
            cout << "  Ilosc (malo/duzo): ";
            getline(cin, wybor[i].ilosc);
        }

        bool trafione = porownaj(); // tu trzeba jakos zrobic ten scoring? póki co sprawdza tylko czy receptura git czy nie. Mo¿e w klasie jakas funkcje z scoringiem trzeba?
        klient.zareaguj(trafione);
    }

    bool porownaj() {
        for (int i = 0; i < 3; ++i) {
            if (
                wybor[i].nazwa != receptura.skladniki[i].nazwa ||
                wybor[i].ilosc != receptura.skladniki[i].ilosc
            ) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Gra gra;
    gra.start();
    return 0;
}
