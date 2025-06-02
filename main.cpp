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
    
    
    void menu() {
            cout << "╔═══════════════════════════════════════════════╗\n";
            cout << "╠═════════════════ WITAJ W GRZE ════════════════╣\n";
            cout << "║═════════════════ SŁODKI TRIP! ════════════════║\n";
            cout << "╠═══════════════════════════════════════════════╣\n";
            cout << "║        W grze wcielasz się w cukiermana,      ║\n";
            cout << "║     który przygotowuje zamówienia klientów.   ║\n";
            cout << "║     Twoim celem jest jak najlepiej spełnić    ║\n";
            cout << "║           ich słodkie oczekiwania!            ║\n";
            cout << "╠═══════════════════════════════════════════════╣\n";
            cout << "║               1. Zagraj                       ║\n";
            cout << "╚═══════════════════════════════════════════════╝\n";
            cout << "║               2. Jak grać                     ║\n";
            cout << "╚═══════════════════════════════════════════════╝\n";
            cout << "║               3. Tabela wyników               ║\n";
            cout << "╚═══════════════════════════════════════════════╝\n";
            cout << "║               4. Wyjście z gry                ║\n";
            cout << "╚═══════════════════════════════════════════════╝\n";
        
        cout<<endl;
                   cout << "WYBIERZ OPCJĘ: ";
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
    
   
        
    // Zapis stałej wartości score do pliku
    void zapiszScoring() {
        int score = 100;  // tymczasowa stała wartość scoringu

            ofstream plik("score.txt", ios::app); // dopisywanie
            if (plik.is_open()) {
                plik << score << endl;
                plik.close();
            }
    }

    // Odczyt scoringu z pliku
    void odczytajScoring() {
            ifstream plik("score.txt");
            int score;
            int licznik = 1;
            if (plik.is_open()) {
                cout << "╔═════════════════════════════════════╗\n";
                cout << "║     T A B E L A   W Y N I K Ó W     ║\n";
                cout << "╚═════════════════════════════════════╝\n";
                cout << "Lp." <<"         " << "Wynik\n";
                       cout << "══════════════════════════════\n";
                while (plik >> score) {
                    cout << licznik << ".          " << score << endl;
                    licznik++;
                }
                cout << "══════════════════════════════\n";
                plik.close();
            } else {
                cout << " ----Brak wyników do wyświetlenia.----\n";
            }
    }

    
    void start() {
        
        menu();
        int opcja;
        
        cin >> opcja;
        cin.ignore(); // czyści bufor przed użyciem getline w klasie Gra
        
        if (opcja == 1) {
            
            start:
            
            srand(time(0)); //funkcja potrzebna do losowania
            
            klient.losuj();
            receptura.ustawMojito();
            
            cout << "--------------------------------\n";
            
            klient.pokaz();
            cout << "Zamowienie do wykonania: ";
            receptura.pokaz(); //f do wystwietlania receptury ktora sie wylosowala - odkomentuj zeby zobaczyc czy program działa dobrze
            cout << "--------------------------------\n";
            Skladnik::wyswietlSklep(); // to jest funkcja statyczna wiec mozna ją wywołać poprzez "::" klasa::nazwa_funkcji
            cout << "--------------------------------\n";
            cout << "\nDodaj 3 skladniki (nazwa + malo/duzo):\n";
            for (int i = 0; i < 3; ++i) {
                cout << "Skladnik #" << (i + 1) << ": ";
                getline(cin, wybor[i].nazwa);
                cout << endl;
                cout << "  Ilosc (malo/duzo): ";
                getline(cin, wybor[i].ilosc);
            }
            
            zapiszScoring(); // po skonczonej grze zapis scoringu - na razie jest sztywno na 100 ustawiony
            
            bool grajDalej = true;
            while (grajDalej) {
                string wybor;
                cout << "\nCzy chcesz zagrać jeszcze raz? (tak/nie): ";
                cin >> wybor;
                if (wybor == "tak" && wybor == "TAK" && wybor == "Tak") {
                    goto start;
                }
                else {
                    cout << "\nDziękujemy za grę! Do zobaczenia!\n";
                }
            }
        }
        
        if (opcja == 2){
    
            cout << "╔════════════════════════════════════════════════════════╗\n";
            cout << "║              ➤ Twórz zwariowane cukierki!              ║\n";
            cout << "║════════════════════════════════════════════════════════║\n";
            cout << "║                ➤ Mieszaj 5 składników:                 ║\n";
            cout << "║                     - składnik1                        ║\n";
            cout << "║                     - składnik2                        ║\n";
            cout << "║                     - składnik3                        ║\n";
            cout << "║                     - składnik4                        ║\n";
            cout << "║                     - składnik5                        ║\n";
            cout << "║════════════════════════════════════════════════════════║\n";
            cout << "║           ➤ Wybierz proporcje: mało / dużo             ║\n";
            cout << "║           ➤ Traf w przepis lub stwórz nowy!            ║\n";
            cout << "║           ➤ Śledź reakcje klientów!                    ║\n";
            cout << "║════════════════════════════════════════════════════════║\n";
            cout << "║          Cel: Zdobądź tytuł Mistrza Słodyczy!          ║\n";
            cout << "╠════════════════════════════════════════════════════════╣\n";
            cout << "║           Wciśnij dowolny znak oraz ENTER              ║\n";
            cout << "║                          i                             ║\n";
            cout << "║            zacznij zanim klient ucieknie!              ║\n";
            cout << "╚════════════════════════════════════════════════════════╝\n";
                char znak;
                   cin >> znak;
            goto start;
            }
           
        
        
        if (opcja == 3){
           odczytajScoring();
        }
        else {
            cout << "\n";
                cout << "╔══════════════════════════════════════╗\n";
                cout << "║                                      ║\n";
                cout << "║   DZIĘKUJEMY ZA GRĘ! DO ZOBACZENIA!  ║\n";
                cout << "║                                      ║\n";
                cout << "╚══════════════════════════════════════╝\n";
                cout << "\n";
        }
        
        
        
        bool trafione = porownaj(); // tu trzeba jakos zrobic ten scoring? póki co sprawdza tylko czy receptura git czy nie. Może w klasie jakas funkcje z scoringiem trzeba?
        klient.zareaguj(trafione);
    }

};

int main() {
    Gra gra;
    gra.start();
    return 0;
}

