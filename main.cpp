#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <fstream>
#include <cmath>
#include <algorithm> 
#include <cctype>    
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
    int index;

    static bool uzyteHistoryjki[15]; // Do śledzenia użytych historyjek

    static void resetujUzycie() {
        for (int i = 0; i < 6; ++i)
            uzyteHistoryjki[i] = false;
    }

    void losuj() {
        string imiona[] = { "Anna", "Jan", "Ola", "Tomek", "Zosia" };
        string nazwiska[] = { "Nowak", "Kowalski", "Wisniewski", "Kaczmarek", "Dabrowska" };
        string historyjki[] = {
        "Hej, słyszałem o Tobie od mojego kolegi! Podobno masz najlepsze cukierki w mieście! To prawda, że pierwszy za darmo?",
        "Wiem, że wiszę Ci trochę kasy za ostatnie cukierki, ale co powiesz na wymianę. Mogę oddać Ci moją mamę…",
        "Mój chłopak to prawdziwy romantyk. Poznaliśmy się na spotkaniu anonimowych miłośników cukierków! Siedzieliśmy w kółku i opowiadaliśmy o naszych ulubionych smakach! To nasza druga randka. Możesz coś dla nas przygotować?😊",
        "No siema. Potrzebuję małej pomocy. Mój przyjaciel nie je cukierków już od kilku tygodni. Wiem, że strasznie je lubi, ale chyba wstydzi się tego przyznać. Na pewno będzie mu miło po małym prezencie!",
        "Potrzebuję wsparcia. Jutro mam zawody sportowe i myślę, że mały cukierek mógłby okazać się nieocenioną pomocą! Nie, nie nazywam się Karaś!",
        "Przyśnił mi się sen. Beata Kozidrak przybiła mi piątkę, a potem podwiozła mnie na przystanek tramwajowy. Po drodze mieliśmy wypadek – patrzę, a jestem w szpitalu… Co? Oj, faktycznie mam wenflon w łapie…",
        "Zamknąłem brata w lodówce, bo zabrał mi ostatniego cukierka. No trudno, przynajmniej nie zgnije. Swoją drogą – nie potrzebujesz może nerki?",
        "Moja babcia biega po mieszkaniu i krzyczy, że jest beretem. Nie do końca rozumiem co to znaczy, wydawało mi się, że jest moherem.",
        "Nie uwierzysz w tę historię! Wychodzę wczoraj po chleb, a wracam z taczką pełną Rumunów. I co ja teraz z nimi zrobię? Przecież nie hoduję na balkonie żadnych róż! Przecież to nie Wrocław!",
        "Ej, słyszałeś ten huk? A, w takim razie musiało mi się tylko przesłyszeć…",
        "Ręce trzęsą mi się od dziecka, a teraz i tak jest dużo lepiej! Kiedyś złamałem nos nauczycielowi. Nie, te historie nie są powiązane…",
        "Próbowałeś kiedyś przykręcić koło bananem? To znacznie łatwiejsze niż się wydaje. Potrzeba tylko dużo cierpliwości i dwa słoiki masła orzechowego!",
        "Jestem zrozpaczony. Nie dostałem się na ASP. To chyba znak od losu, że pora zająć się polityką…",
        "Zawsze mam przy sobie łyżeczkę, bo piję dużo kawy i brzydzę się cudzych sztućców. A zapalniczka leżała na drodze…",
        "Oglądałeś Matrixa? Którą tabletkę byś wybrał? Ja obie."
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
        index = 0;
        int proby = 0;
        do {
            index = rand() % 15;
            proby++;
        } while (uzyteHistoryjki[index] && proby < 15);
        uzyteHistoryjki[index] = true;
        historyjka = historyjki[index];

        // losowanie reakcji
        dobra_reakcja = dobra_reakcje[rand() % 8];
        srednia_reakcja = srednia_reakcje[rand() % 7];
        zla_reakcja = zla_reakcje[rand() % 8];
    }

  

    void pokaz() {
        cout << "Klient: " << imie << " " << nazwisko << endl;
        cout << "Historyjka: " << historyjka << endl;
    }
};
bool Klient::uzyteHistoryjki[15] = { false };


class Skladnik {
public:
    string nazwa;
    string ilosc; // "malo" lub "duzo"

     static void wyswietlSklep() {

        string listaSkladnikow[] = {
    "Cukier puder",
    "Susz owocowy",
    "Tęczowy barwnik",
    "Miód waniliowy",
    "Witamina C",
    "Cynamon"
};

        cout << "=== SKLADNIKI DO WYBORU ===" << endl;
        for (int i = 0; i < 6; ++i) {
            cout << "- " << listaSkladnikow[i] << " (malo / duzo)" << endl;
        }
        cout << "=======================" << endl;
    }
};

class Receptura {
public:
    string nazwa;
    string wskazowka;
    Skladnik skladniki[3];

    void ustawRecepture1() {
    nazwa = "Koka Kola";
    wskazowka = "Słodkość na poziomie kompotu babci!\nOwoce są zdrowe. Ale ja nie lubię, jak jest zbyt zdrowo.\nMiodzio. Ej, nie przesadzasz trochę?";
    skladniki[0] = { "Cukier puder", "duzo" };
    skladniki[1] = { "Susz owocowy", "malo" };
    skladniki[2] = { "Miod waniliowy", "malo" };
}

void ustawRecepture2() {
    nazwa = "KRAKoski sprint";
    wskazowka = "Słodkość na poziomie kompotu babci!\nChce poczuć, jak moja odporność eksploduje!\n Walnij tyle, żeby kaszlnąć od zapachu!";
    skladniki[0] = { "Cukier puder", "duzo" };
    skladniki[1] = { "Witamina C", "duzo" };
    skladniki[2] = { "Cynamon", "duzo" };
}

void ustawRecepture3() {
    nazwa = "Kwasna podroz";
    wskazowka =  "Chcę, żeby ten cukierek krzyczał kolorami!\nKocham owoce! W każdej formie!\nChcę poczuć, jak moja odporność eksploduje!";
    skladniki[0] = { "Teczowy barwnik", "duzo" };
    skladniki[1] = { "Susz owocowy", "duzo" };
    skladniki[2] = { "Witamina C", "duzo" };
}

void ustawRecepture4() {
    nazwa = "Przygoda HERAklesa";
    wskazowka = "Chcę poczuć, jak moja odporność eksploduje!\nOwoce są zdrowe. Ale ja nie lubię, jak jest zbyt zdrowo.\nMiodzio. Ej, nie przesadzasz trochę?";
    skladniki[0] = { "Witamina C", "duzo" };
    skladniki[1] = { "Susz owocowy", "malo" };
    skladniki[2] = { "Miod waniliowy", "malo" };
}

void ustawRecepture5() {
    nazwa = "Amsterdamski Przysmak";
    wskazowka = "Kocham owoce! W każdej formie!\nLubię, jak zęby mi się kleją!\nZdrowo, ale bez apteki w ustach.";
    skladniki[0] = { "Susz owocowy", "duzo" };"
    skladniki[1] = { "Miod waniliowy", "duzo" };
    skladniki[2] = { "Witamina C", "malo" };
}

void ustawRecepture6() {
    nazwa = "Krysztalki";
    wskazowka = "Słodkość na poziomie kompotu babci!\nKolor? Nie, nie przeszkadza mi.\nChcę poczuć, jak moja odporność eksploduje!";
    skladniki[0] = { "Cukier puder", "duzo" };
    skladniki[1] = { "Teczowy barwnik", "malo" };
    skladniki[2] = { "Witamina C", "duzo" };
}

void ustawRecepture7() {
    nazwa = "Ale Xandra!";
    wskazowka = "Lubię, jak zęby mi się kleją!\nKocham owoce! W każdej formie!\nWalnij tyle, żeby kaszlnąć od zapachu!";
    skladniki[0] = { "Miod waniliowy", "duzo" };
    skladniki[1] = { "Susz owocowy", "duzo" };
    skladniki[2] = { "Cynamon", "duzo" };
}

void ustawRecepture8() {
    nazwa = "O, piosenka Idy!";
    wskazowka = "Lubię, jak zęby mi się kleją!\nKocham owoce! W każdej formie!\nSzczypta – tyle co dałbyś na szarlotkę.";
    skladniki[0] = { "Miod waniliowy", "duzo" };
    skladniki[1] = { "Susz owocowy", "duzo" };
    skladniki[2] = { "Cynamon", "malo" };
}

void ustawRecepture9() {
    nazwa = "#";
    wskazowka = "Kocham owoce! W każdej formie!\nWalnij tyle, żeby kaszlnąć od zapachu!\nKolor? Nie, nie przeszkadza mi.";
    skladniki[0] = { "Susz owocowy", "duzo" };
    skladniki[1] = { "Cynamon", "duzo" };
    skladniki[2] = { "Teczowy barwnik", "malo" };
}

void ustawRecepture10() {
    nazwa = "Lekko-Strawny Deser";
    wskazowka = "Chcę, żeby ten cukierek krzyczał kolorami!\nWalnij tyle, żeby kaszlnąć od zapachu!\nChcę poczuć, jak moja odporność eksploduje!";
    skladniki[0] = { "Teczowy barwnik", "duzo" };
    skladniki[1] = { "Cynamon", "duzo" };
    skladniki[2] = { "Witamina C", "duzo" };
}

void ustawRecepture11() {
    nazwa = "Krokodyl";
    wskazowka = "Słodkość na poziomie kompotu babci!\nChcę poczuć, jak moja odporność eksploduje!\nWalnij tyle, żeby kaszlnąć od zapachu!";
    skladniki[0] = { "Cukier puder", "duzo" };
    skladniki[1] = { "Witamina C", "duzo" };
    skladniki[2] = { "Cynamon", "duzo" };
}

void ustawRecepture12() {
    nazwa = "Jamajska zielen";
    wskazowka = "Kocham owoce! W każdej formie!\nKolor? Nie, nie przeszkadza mi.\nSzczypta – tyle co dałbyś na szarlotkę.";
    skladniki[0] = { "Susz owocowy", "duzo" };
    skladniki[1] = { "Teczowy barwnik", "malo" };
    skladniki[2] = { "Cynamon", "malo" };
}

void ustawRecepture13() {
    nazwa = "Specjalnosc Pablo!";
    wskazowka = "Słodkość na poziomie kompotu babci!\nZdrowo, ale bez apteki w ustach.\nKolor? Nie, nie przeszkadza mi.";
    skladniki[0] = { "Cukier puder", "duzo" };
    skladniki[1] = { "Witamina C", "malo" };
    skladniki[2] = { "Teczowy barwnik", "malo" };
}

void ustawRecepture14() {
    nazwa = "Meskykanska Fala!";
    wskazowka = "Słodkość na poziomie kompotu babci!\nLubię, jak zęby mi się kleją!\nZdrowo, ale bez apteki w ustach.";
    skladniki[0] = { "Cukier puder", "duzo" };
    skladniki[1] = { "Miod waniliowy", "duzo" };
    skladniki[2] = { "Witamina C", "malo" };
}

void ustawRecepture15() {
    nazwa = "Miekie, Delikatne Mega-Apetyczne";
    wskazowka = "Chcę poczuć, jak moja odporność eksploduje!\nKocham owoce! W każdej formie!\nSzczypta – tyle co dałbyś na szarlotkę.";
    skladniki[0] = { "Witamina C", "duzo" };
    skladniki[1] = { "Susz owocowy", "duzo" };
    skladniki[2] = { "Cynamon", "malo" };
}


    void pokaz() {
        cout << "Zamowienie: " << nazwa << endl;
        cout<<"Przechodząc do rzeczy - oto moje najskryszte pragnienia: "<<endl;
        cout << wskazowka;
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
    string normalizuj(string s) {
    // Usuń spacje z przodu i końca
    s.erase(0, s.find_first_not_of(" \t\n\r"));
    s.erase(s.find_last_not_of(" \t\n\r") + 1);
    // Zamień na małe litery
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

    double ScoreTrack(Skladnik wybor[]) {
        cout<<"Wywołano SCORE TRAKC------------"<<endl;
        cout << "DEBUG: Porównuję:\n";
for (int i = 0; i < 3; i++) {
    cout << "- [" << wybor[i].nazwa << "] vs [" << receptura.skladniki[i].nazwa << "]\n";
    cout << "- [" << wybor[i].ilosc << "] vs [" << receptura.skladniki[i].ilosc << "]\n";
}
        double scoring = 0;
        for (int i = 0; i < 3; i++) {
            string nazwaU = normalizuj(wybor[i].nazwa);
            string nazwaR = normalizuj(receptura.skladniki[i].nazwa);
            string iloscU = normalizuj(wybor[i].ilosc);
            string iloscR = normalizuj(receptura.skladniki[i].ilosc);
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
    
    void losoweZdarzenie(double &scoring) {
    int zdarzenie = rand() % 5; 

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
                //cout<<"Index: "<<klient.index<<endl;
                //tu ustawiamy recepture 
                
                switch (klient.index) {
        case 1:  receptura.ustawRecepture1();  break;
        case 2:  receptura.ustawRecepture2();  break;
        case 3:  receptura.ustawRecepture3();  break;
        case 4:  receptura.ustawRecepture4();  break;
        case 5:  receptura.ustawRecepture5();  break;
        case 6:  receptura.ustawRecepture6();  break;
        case 7:  receptura.ustawRecepture7();  break;
        case 8:  receptura.ustawRecepture8();  break;
        case 9:  receptura.ustawRecepture9();  break;
        case 10: receptura.ustawRecepture10(); break;
        case 11: receptura.ustawRecepture11(); break;
        case 12: receptura.ustawRecepture12(); break;
        case 13: receptura.ustawRecepture13(); break;
        case 14: receptura.ustawRecepture14(); break;
        case 15: receptura.ustawRecepture15(); break;
        default: break;
    }

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

                double wynik = ScoreTrack(wybor);
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
