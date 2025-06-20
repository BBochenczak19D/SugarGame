#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <fstream>
#include <cmath>
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

    static bool uzyteHistoryjki[6]; // Do śledzenia użytych historyjek

    static void resetujUzycie() {
        for (int i = 0; i < 6; ++i)
            uzyteHistoryjki[i] = false;
    }

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
            "Jeszcze! I jeszcze! I może być z plastikiem nawet!",
            "Cukierek jak sen na dopalaczach – ale legalny.",
            "Czuję, że wraca mi wiara w ludzkość. I w słodycze."
        };

        string srednia_reakcje[] = {
            "No nie wiem, jakby miętowa pasta do zębów udawała lizaka.",
            "Jest okej... ale bez dreszczy.",
            "Smakuje jak herbata u cioci: ani zła, ani dobra, po prostu jest.",
            "To chyba z tych cukierków, co się je z grzeczności.",
            "Jakby ktoś rozpuścił marzenie w chlorowanej wodzie.",
            "Taki smak 'meh', ale przynajmniej nie kopie jak gaz z kaloryfera.",
            "Jakbym jadła watę, co leżała za szafą, ale z cukrem."
        };

        string zla_reakcje[] = {
            "Fuj! Smakuje jak sen o zepsutym jogurcie!",
            "To jest przestępstwo przeciwko kubkom smakowym.",
            "Czy to... guma do żucia po babci?",
            "Mam wrażenie, że zjadłam zapach klatki schodowej.",
            "To nie jest cukierek, to trauma w folii.",
            "Smak jak z autobusu linii 145 w lipcu – bez klimy.",
            "Wypluj mnie, błagam – krzyczy mój język.",
            "Czuję się jakbym zdradziła swoją dietę i swoją godność."
        };

        // losowanie imienia i nazwiska
        imie = imiona[rand() % 5];
        nazwisko = nazwiska[rand() % 5];

        // losowanie unikalnej historyjki
        int index = 0;
        int proby = 0;
        do {
            index = rand() % 6;
            proby++;
        } while (uzyteHistoryjki[index] && proby < 10);
        uzyteHistoryjki[index] = true;
        historyjka = historyjki[index];

        // losowanie reakcji
        dobra_reakcja = dobra_reakcje[rand() % 8];
        srednia_reakcja = srednia_reakcje[rand() % 7];
        zla_reakcja = zla_reakcje[rand() % 8];
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
bool Klient::uzyteHistoryjki[6] = { false };


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
    }

    double ScoreTrack() {
        double scoring = 0;
        for (int i = 0; i < 3; i++) {
            if (wybor[i].nazwa == receptura.skladniki[i].nazwa) {
                scoring += 15;
            }
            if (wybor[i].ilosc == receptura.skladniki[i].ilosc) {
                scoring += 10;
            }
        }
        return scoring;
    }

    void ReakcjaNaPunktacje(double scoring) {
        if (scoring > 70.00) {
            cout << klient.dobra_reakcja << endl;
        } else if (scoring >= 45.00) {
            cout << klient.srednia_reakcja << endl;
        } else if (scoring >= 10.00) {
            cout << klient.zla_reakcja << endl;
        } else {
            cout << "Klient płacze... nawet nie da się tego opisać." << endl;
        }
    }

    void zapiszScoring(int score) {
        ofstream plik("score.txt", ios::app);
        if (plik.is_open()) {
            plik << score << endl;
            plik.close();
        }
    }

    void odczytajScoring() {
        ifstream plik("score.txt");
        int score, licznik = 1;
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

    bool porownaj() {
        for (int i = 0; i < 3; ++i) {
            if (wybor[i].nazwa != receptura.skladniki[i].nazwa || wybor[i].ilosc != receptura.skladniki[i].ilosc) {
                return false;
            }
        }
        return true;
    }
    
    void losoweZdarzenie(int &scoring) {
    int zdarzenie = rand() % 5; // 0–4 (1 z 5 opcji), w tym brak zdarzenia

    switch (zdarzenie) {
        case 0:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Wpadła babcia z reklamówką cebuli i powiedziała, że 'cukierek nie karmi'.\n";
            cout << "Zaczęła częstować wszystkich smalcem i narzekać na młodzież.\n";
            scoring -= 9*sqrt(scoring-3);
            cout << "Klient się obraził. "<<scoring<<" do punktów.\n\n";
            break;
        case 1:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Z wentylacji wyleciał gołąb z brokatem na skrzydłach i zrobił salto.\n";
            cout << "Klient zaniemówił, wzruszył się. 'To znak', wyszeptał.\n";
            scoring += sqrt(scoring+4.2);
            cout << scoring<<" do punktów za duchowość i brokat.\n\n";
            break;
        case 2:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Pojawił się lokalny raper PISZCZYK MC i zaczął freestyle'ować o Twoim cukierku.\n";
            cout << "Zwrotka była średnia, ale beat się zgadzał. Klient kiwał głową.\n";
            scoring += sqrt(scoring+12);
            cout << scoring<<" do punktów za styl\n\n";
            break;
        case 3:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Ktoś z tyłu krzyknął: 'To nie jest prawdziwa wata cukrowa!'\n";
            cout << "Atmosfera zgęstniała jak budyń. Klient się zawahał.\n";
            
            scoring -= sqrt(scoring+2.5);
            cout << scoring<<" do punktów za społeczne napięcie.\n\n";
            break;
        case 4:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Z głośnika w rogu zaczęło lecieć 'Majteczki w kropeczki'.\n";
            cout << "Wszyscy udają, że to normalne.\n\n";
            break;
            
        //TU TRZEBA DODAC WIECEJ ZDARZEN LOSOWYCH (najelepiej z 20-30)
        // mozna tez stworzyc takie co nie wyplywaja na scoring
        
        default:
            // brak zdarzenia
            break;
    }
}


    void start() {
        Klient::resetujUzycie(); // Reset przed pierwszą grą
        int opcja;
        start:
        while (true) {
            menu();
            cin >> opcja;
            cin.ignore();
            if (opcja == 1) {
                
                klient.losuj();
                receptura.ustawMojito();

                klient.pokaz();
                receptura.pokaz();
                Skladnik::wyswietlSklep();

                cout << "\nDodaj 3 skladniki (nazwa + malo/duzo):\n";
                for (int i = 0; i < 3; ++i) {
                    cout << "Skladnik #" << (i + 1) << ": ";
                    getline(cin, wybor[i].nazwa);
                    cout << "  Ilosc (malo/duzo): ";
                    getline(cin, wybor[i].ilosc);
                }

                int wynik = ScoreTrack();
                losoweZdarzenie(wynik);  
                zapiszScoring(wynik);
                ReakcjaNaPunktacje(wynik);
                cout<< "- ------ test wyniku "<<wynik<<endl; 
                
                string again;
                cout << "\nZagrać jeszcze raz? (tak/nie): ";
                cin >> again;
                if (again != "tak" && again != "Tak" && again != "TAK") break;

            } else if (opcja == 2) {
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
            } else if (opcja == 3) {
                odczytajScoring();
            } else {
                cout << "\n";
                cout << "╔══════════════════════════════════════╗\n";
                cout << "║                                      ║\n";
                cout << "║   DZIĘKUJEMY ZA GRĘ! DO ZOBACZENIA!  ║\n";
                cout << "║                                      ║\n";
                cout << "╚══════════════════════════════════════╝\n";
                cout << "\n";
                break;
            }
        }
    }
};


int main() {
    srand(time(0));
    Gra gra;
    gra.start();
    return 0;
}