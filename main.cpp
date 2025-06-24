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
        string imiona[] = {  "Amelia", "Miki", "Waldek", "Jerzy", "Janek", "Gustwa", "Cyprian", "Szaweł", "Konrad", "Tosiek", "Paweł", "Leszek", "Krzysiu", "Misiek", "Witka", "Brygida", "Majka", "Kornelia", "Ryszard", "Leszek", "Bogdan", "Piotr", "Aniela", "Weronika"};
        string nazwiska[] = {"Winodom", "Tytus", "Biały", "Różowy", "Głębia", "Frędzel", "Racicki", "Dobromski", "Kobejn", "Górski", "Szczotkowski", "Wałęsowski", "Krawiecki", "Wiśnia", "Hougowicz", "Włócznia", "Sajros", "Miłek", "Jakubowski", "Majewski", "Barbarski", "Witczak", "Bogusz", "Sowa" };
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
            "Cukierek jak łyk benzyny prosto z dystrybutora - paliwo na cały dzień!.",
            "Czuję, że wraca mi wiara w ludzkość. I w słodycze.",
            "Eksplozja smaku spowodowała zwarcie neuronów. Już nigdy nie będę taki sam.",
            "Czuję, że to najlepszy cukierek w moim życiu. Aż chce mi się krzyczyć. AAAAAAAAAAAAA",
            "Niczym wygrana Sobieskiego pod Wiedniem - epicka!",
            "Za taki przysmak podbiłbym Galię dla Cezara... Poniosło mnie?",
            "Po takim cukierku to nawet Pudzian byłby pierwszy w kulach! Polska Gurom!"
        };

        string srednia_reakcje[] = {
            "No nie wiem, jakby miętowa pasta do zębów udawała lizaka.",
            "Jest okej... ale bez dreszczy.",
            "Smakuje jak herbata u cioci: ani zła, ani dobra, po prostu jest.",
            "To chyba jeden z tych cukierków, co się je z grzeczności.",
            "Jakby ktoś rozpuścił marzenie w chlorowanej wodzie.",
            "Taki smak 'meh', ale przynajmniej nie kopie jak gaz z kaloryfera.",
            "Jakbym jadła watę, co leżała za szafą, ale za to z brązowym cukrem.",
            "Smakuje jak niedoprawiona zupa pomidorowa. Niby bez smaku, ale kto nie lubi pomidorówki?",
            "Trochę jak obiad z mikrofalówki. Talerz gorący, jedzenie zimne.",
            "Niczym Bolesław V Wstydliwy - niby król Polski, ale nie kojarzysz...",
            "Nie, nie przybiję ci piątki. Zasłużyłeś na żółwika.",
            "Spoko. Nic dodać, nic ująć. Warte ceny."
        };

        string zla_reakcje[] = {
            "Fuj! Smakuje jak sen o zepsutym jogurcie!",
            "To jest przestępstwo przeciwko kubkom smakowym.",
            "Czy to... guma do żucia po babci?",
            "Mam wrażenie, że zjadłam zapach klatki schodowej.",
            "To nie jest cukierek, to trauma w folii.",
            "Smak jak z tramwaju linii 52 w lipcu. Bez klimy...",
            "'Wypluj mnie, błagam' – krzyczy mój język.",
            "Czuję się jakbym zdradziła swoją dietę i swoją godność.",
            "CHCIAŁEŚ MNIE OTRUĆ?! CZŁOWIEKU, DZWONIĘ PO SANEPID!",
            "Masz jakąś siekierę? Nie, nie ciebie. Język chce odciąć.",
            "Nie wiem czy kwas solny usunie mi z ust ten paskudny smak.",
            "Wiesz co? Właśnie straciłeś klienta! Dam ci jedną gwiazdkę na google!",
            "Jak atak Niemców na Polskę w 39' - dramat!",
            "Nie dałbym tego nawet szczurom na trutkę!"
        };

        // losowanie imienia i nazwiska
        imie = imiona[rand() % 24];
        nazwisko = nazwiska[rand() % 24];

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
        dobra_reakcja = dobra_reakcje[rand() % 13];
        srednia_reakcja = srednia_reakcje[rand() % 12];
        zla_reakcja = zla_reakcje[rand() % 14];
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
            "> cukier puder",
            "> susz owocowy",
            "> teczowy barwnik",
            "> miod waniliowy",
            "> witamina c",
            "> cynamon"
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
    wskazowka = "Słodkość na poziomie kompotu babci!\nOwoce są zdrowe. Ale ja nie lubię, jak jest zbyt zdrowo.\nMiodzio. Ej, nie przesadzasz trochę?\n";
    skladniki[0] = { "cukier puder", "duzo" };
    skladniki[1] = { "susz owocowy", "malo" };
    skladniki[2] = { "miod waniliowy", "malo" };
}

void ustawRecepture2() {
    nazwa = "KRAKoski sprint";
    wskazowka = "Słodkość na poziomie kompotu babci!\nChce poczuć, jak moja odporność eksploduje!\n Walnij tyle, żeby kaszlnąć od zapachu!\n";
    skladniki[0] = { "cukier puder", "duzo" };
    skladniki[1] = { "witamina c", "duzo" };
    skladniki[2] = { "cynamon", "duzo" };
}

void ustawRecepture3() {
    nazwa = "Kwasna (!sic) podroz";
    wskazowka =  "Chcę, żeby ten cukierek krzyczał kolorami!\nKocham owoce! W każdej formie!\nChcę poczuć, jak moja odporność eksploduje!\n";
    skladniki[0] = { "teczowy barwnik", "duzo" };
    skladniki[1] = { "susz owocowy", "duzo" };
    skladniki[2] = { "witamina c", "duzo" };
}

void ustawRecepture4() {
    nazwa = "Przygoda HERAklesa";
    wskazowka = "Chcę poczuć, jak moja odporność eksploduje!\nOwoce są zdrowe. Ale ja nie lubię, jak jest zbyt zdrowo.\nMiodzio. Ej, nie przesadzasz trochę?\n";
    skladniki[0] = { "witamina c", "duzo" };
    skladniki[1] = { "susz owocowy", "malo" };
    skladniki[2] = { "miod waniliowy", "malo" };
}

void ustawRecepture5() {
    nazwa = "Amsterdamski Przysmak";
    wskazowka = "Kocham owoce! W każdej formie!\nLubię, jak zęby mi się kleją!\nZdrowo, ale bez apteki w ustach.\n";
    skladniki[0] = { "susz owocowy", "duzo" };
    skladniki[1] = { "miod waniliowy", "duzo" };
    skladniki[2] = { "witamina C", "malo" };
}

void ustawRecepture6() {
    nazwa = "Krysztalki";
    wskazowka = "Słodkość na poziomie kompotu babci!\nKolor? Nie, nie przeszkadza mi.\nChcę poczuć, jak moja odporność eksploduje!\n";
    skladniki[0] = { "cukier puder", "duzo" };
    skladniki[1] = { "Teczowy barwnik", "malo" };
    skladniki[2] = { "witamina C", "duzo" };
}

void ustawRecepture7() {
    nazwa = "Ale Xandra!";
    wskazowka = "Lubię, jak zęby mi się kleją!\nKocham owoce! W każdej formie!\nWalnij tyle, żeby kaszlnąć od zapachu!\n";
    skladniki[0] = { "miod waniliowy", "duzo" };
    skladniki[1] = { "susz owocowy", "duzo" };
    skladniki[2] = { "cynamon", "duzo" };
}

void ustawRecepture8() {
    nazwa = "O, piosenka Idy!";
    wskazowka = "Lubię, jak zęby mi się kleją!\nKocham owoce! W każdej formie!\nSzczypta – tyle co dałbyś na szarlotkę.\n";
    skladniki[0] = { "miod waniliowy", "duzo" };
    skladniki[1] = { "susz owocowy", "duzo" };
    skladniki[2] = { "cynamon", "malo" };
}

void ustawRecepture9() {
    nazwa = "#";
    wskazowka = "Kocham owoce! W każdej formie!\nWalnij tyle, żeby kaszlnąć od zapachu!\nKolor? Nie, nie przeszkadza mi.\n";
    skladniki[0] = { "susz owocowy", "duzo" };
    skladniki[1] = { "cynamon", "duzo" };
    skladniki[2] = { "teczowy barwnik", "malo" };
}

void ustawRecepture10() {
    nazwa = "Lekko-Strawny Deser";
    wskazowka = "Chcę, żeby ten cukierek krzyczał kolorami!\nWalnij tyle, żeby kaszlnąć od zapachu!\nChcę poczuć, jak moja odporność eksploduje!\n";
    skladniki[0] = { "teczowy barwnik", "duzo" };
    skladniki[1] = { "cynamon", "duzo" };
    skladniki[2] = { "witamina C", "duzo" };
}

void ustawRecepture11() {
    nazwa = "Krokodyl";
    wskazowka = "Słodkość na poziomie kompotu babci!\nChcę poczuć, jak moja odporność eksploduje!\nWalnij tyle, żeby kaszlnąć od zapachu!\n";
    skladniki[0] = { "cukier puder", "duzo" };
    skladniki[1] = { "witamina c", "duzo" };
    skladniki[2] = { "cynamon", "duzo" };
}

void ustawRecepture12() {
    nazwa = "Jamajska zielen";
    wskazowka = "Kocham owoce! W każdej formie!\nKolor? Nie, nie przeszkadza mi.\nSzczypta – tyle co dałbyś na szarlotkę.\n";
    skladniki[0] = { "susz owocowy", "duzo" };
    skladniki[1] = { "teczowy barwnik", "malo" };
    skladniki[2] = { "cynamon", "malo" };
}

void ustawRecepture13() {
    nazwa = "Specjalnosc Pablo!";
    wskazowka = "Słodkość na poziomie kompotu babci!\nZdrowo, ale bez apteki w ustach.\nKolor? Nie, nie przeszkadza mi.\n";
    skladniki[0] = { "cukier puder", "duzo" };
    skladniki[1] = { "witamina c", "malo" };
    skladniki[2] = { "teczowy barwnik", "malo" };
}

void ustawRecepture14() {
    nazwa = "Meskykanska Fala!";
    wskazowka = "Słodkość na poziomie kompotu babci!\nLubię, jak zęby mi się kleją!\nZdrowo, ale bez apteki w ustach.\n";
    skladniki[0] = { "cukier puder", "duzo" };
    skladniki[1] = { "miod waniliowy", "duzo" };
    skladniki[2] = { "witamina c", "malo" };
}

void ustawRecepture15() {
    nazwa = "Miekkie, Delikatne Mega-Apetyczne\n";
    wskazowka = "Chcę poczuć, jak moja odporność eksploduje!\nKocham owoce! W każdej formie!\nSzczypta – tyle co dałbyś na szarlotkę.\n";
    skladniki[0] = { "witamina c", "duzo" };
    skladniki[1] = { "susz owocowy", "duzo" };
    skladniki[2] = { "cynamon", "malo" };
}


    void pokaz() {
        cout << "Zamowienie: " << nazwa << endl;
        cout<<"Przechodząc do rzeczy - oto moje najskryszte pragnienia: "<<endl;
        cout<<endl;
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
        /*cout<<"Wywołano SCORE TRACK------------"<<endl;
        cout << "DEBUG: Porównuję:\n";
        for (int i = 0; i < 3; i++) {
        cout << "- [" << wybor[i].nazwa << "] vs [" << receptura.skladniki[i].nazwa << "]\n";
        cout << "- [" << wybor[i].ilosc << "] vs [" << receptura.skladniki[i].ilosc << "]\n";
        }*/
        
        double scoring = 0;
        for (int i = 0; i < 3; i++) {
            string nazwaU = normalizuj(wybor[i].nazwa);
            string nazwaR = normalizuj(receptura.skladniki[i].nazwa);
            string iloscU = normalizuj(wybor[i].ilosc);
            string iloscR = normalizuj(receptura.skladniki[i].ilosc);
            if (nazwaU == nazwaR) {
                scoring += 15;
            }
            if (iloscU == iloscR) {
                scoring += 10;
            }
        }
        return scoring;
    }

    void ReakcjaNaPunktacje(double scoring) {
        if (scoring > 140.00 ){
            cout<<endl;
            cout<<"Widzisz jak dusza opuszcza ciało klienta, a następnie powoli wznosi się w kierunku rozwartego nieba./nŚwięty Piotr macha Ci uśmiechnięty i słyszysz jak swoim ciepłym, kojącym głosem mówi:/n'Dobra robota synu. Jesteś prawdziwym Cukiermanem'.";
        } else if (scoring >= 70.00) {
            cout << "\n"<<klient.dobra_reakcja << endl;
        } else if (scoring >= 45.00) {
            cout << "\n"<<klient.srednia_reakcja << endl;
        } else if (scoring >= 10.00) {
            cout << "\n"<<klient.zla_reakcja << endl;
        } else {
            cout <<"\n"<< "Klient płacze... nawet nie da się tego opisać." << endl;
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

    
    void losoweZdarzenie(double &scoring) {
        int zdarzenie = rand() % 23; 
        switch (zdarzenie) {
        case 0:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Wpadła babcia z reklamówką cebuli i powiedziała, że 'cukierek nie karmi'.\n";
            cout << "Zaczęła częstować wszystkich smalcem i narzekać na młodzież.\n";
            scoring -= 9*sqrt(scoring-3);
            cout << "Klient się obraził. "<<" -"<<9*sqrt(scoring-3)<<" do punktów.\n\n";
            break;
        case 1:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Z wentylacji wyleciał gołąb z brokatem na skrzydłach i zrobił salto.\n";
            cout << "Klient zaniemówił, wzruszył się. 'To znak'- wyszeptał.\n";
            scoring += sqrt(scoring+4.2);
            cout << " +"<<sqrt(scoring+4.2) <<" do punktów za duchowość i brokat.\n\n";
            break;
        case 2:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Pojawił się lokalny raper PISZCZYK MC i zaczął freestyle'ować o Twoim cukierku.\n";
            cout << "Zwrotka była średnia, ale beat się zgadzał. Klient kiwał głową.\n";
            scoring += sqrt(scoring+12);
            cout << " +"<<sqrt(scoring+12)<<" do punktów za styl\n\n";
            break;
        case 3:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Ktoś z tyłu krzyknął: 'To nie jest prawdziwa wata cukrowa!'\n";
            cout << "Atmosfera zgęstniała jak budyń. Klient się zawahał.\n";
            
            scoring -= sqrt(scoring+2.5);
            cout <<" -"<<sqrt(scoring+2.5)<<" do punktów za społeczne napięcie.\n\n";
            break;
        case 4:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Z głośnika w rogu zaczęły lecieć 'Majteczki w kropeczki'.\n";
            cout << "Wszyscy udają, że to normalne.\n\n";
            break;
         case 5:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Z radia robrzmiał Mazurek Dąbrowskiego.\n";
            cout << "Wszyscy stanęli na baczność, a poświęcenie dla ojczyzny stało się nie tylko obowiązkiem, ale także celem.\n";
            
            scoring += 10;
            cout << "+10 do punktów za patriotyczne nastroje.\n\n";
            break;
        case 6:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Ziemia zadrżała, a z nieba robrzmiała siódma trąba Jerychońska. Koniec jest bliski.\n";
            cout << "Klienci nalegają, żeby kontynować pracę. Ten ostatni raz chcą jeszcze zjeść cukierka.\n";
            
            scoring = 0;
            cout <<"Koniec Świata. Za to nie ma punktów.\n\n";
            break;
        case 7:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Lech Wałęsa otwiera własny biznes stoczniowy.\n";
            cout << "Wypłaty dla pracowników w starych nominałach. Gospodarka szaleje\n";
            
            scoring -= 10;
            cout << "-10 do punktów za brak denominacji.\n\n";
            break;            
        case 8:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "'Husaria do boju!'\n";
            cout << "Spokojnie, to tylko kibice Wisły.\n";
            
            scoring -= 13;
            cout <<"-13 do punktów za ukrytą racę w plecaku.\n\n";
            break;
        case 9:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Ktoś próbował wymienić koło w samochodzie bananem!\n";
            cout << "Podobno to nie takie trudne. Wystarczą dwa słoiki masła orzechowego.\n";
            
            scoring -= 19;
            cout << "-19 do punktów za uczulenie na orzechy.\n\n";
            break;
        case 10:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Poznań miasto doznań\n";
            cout << "Kraków miasto ptaków.\n";
            
            cout <<"Co?\n\n";
            break;
        case 11:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "UJ donosi - nowe akademiki dla 400 studentów od roku 2026\n";
            cout << "A właściwie to nie akademiki tylko szafki na buty. I nie dla 400, ale 40 studentów. Nie od 2026, ale 2035.\n";
            
            scoring -= 14;
            cout << "-14 do punktów za pranie pieniędzy i gniew krakowskiej młodzieży.\n\n";
            break;
        case 12:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Ktoś przykrecił klamki w kobierzynie.\n";
            cout << "Pacjenci szpitala poszukiwani na terenie Krakowa.\n";
            
            scoring += 11;
            cout <<"+11 do punktów za patrole sąsiedzkie.\n\n";
            break;
        case 13:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Jakieś cwaniaczki obok otworzyły swoją budkę z cukierkami!\n";
            cout << "Wolny rynek. Klinci zainteresowali się nowym 'towarem' na mieście.\n";
            
            scoring -= scoring/2;
            cout << " -"<< scoring/2 <<" do punktów za mniejszy utarg.\n\n";
            break;
        case 14:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "EPI zaczęło sesję! Studenci codziennie przychodzą po paczkę cukierków!\n";
            cout << "Zainteresowanie jest tak wielkie, że wprowadzasz zniżkę dla ich kierunku!.\n";
            
            scoring += scoring*0.75;
            cout << " +"<<scoring*2<<" do punktów za pomocnych studentów.\n\n";
            break;
        case 15:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Pomyliłeś zamówienia i dałeś klientowi nie tego cukierka co trzeba.\n";
            cout << "Na twoich oczach wystrzeliło go z butów.\n";
            
            scoring += 22;
            cout <<"+22 do punktów za sprzedane buty\n\n";
            break;
        case 16:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Nietzche we własnej osobie przybył do twojej budki z cukierkami!\n";
            cout << "No a potem napisał, że Bóg umarł...\n";
            
            cout << " Ciężko stwierdzić, co to znaczy.\n\n";
            break;
        case 17:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Czy to ptak? Czy to samolot? Nie, to...\n";
            cout << "TOYOTA COROLLA?!\n";
            
            scoring -= 17;
            cout <<"-17 do punktów za to, że nadal nie wiesz jak znalazła się w powietrzu.\n\n";
            break;
        case 18:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Twój ojciec wrócił z mlekiem.\n";
            cout << "Rzucasz ten biznes. Właśnie wygrałeś życie.\n";
            
            scoring += 100;
            cout <<"+100 do punktów za tatę.\n\n";
            break;
        case 19:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "'Jestem tobą z przyszłości! Postaw wszystkie pieniądze na wygraną Polski w Euro 2032!'\n";
            cout << "Jeszcze 7 lat. To sobie poczekamy...\n";
            
            cout << "Za 7 lat może dostaniesz jakieś punkty.\n\n";
            break;
        case 20:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "Ktoś z tyłu krzyknął: 'Jestem przed tobą!'. Rozglądnąłeś się dookoła.\n";
            cout << "Pora przestać słuchać polskiego rapu. Rzuciło ci się na mózg.\n";
            
            scoring -= 69;
            cout <<"-69 do punktów za zryty beret.\n\n";
            break;
        case 21:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "A co jeśli wszyscy żyjemy w symulacji?\n";
            cout << "To, trzeba przyznać, całkiem realistyczna.\n";
            
            scoring += 4.20;
            cout <<"=4.20 do punktów za nadzieję i chęć do dalszej ciężkiej pracy.\n\n";
            break;
        case 22:
            cout << "\n✨ ZDARZENIE LOSOWE ✨\n";
            cout << "'Obywatelki i obywatele Polskiej Rzeczypospolitej Ludowej!Zwracam się dziś do Was jako żołnierz i jako szef rządu polskiego...'\n";
            cout << "Chyba musiało ci się przysnąć. Ale to tylko zły sen...\n";
            
            scoring += 33;
            cout <<"+33 do punktów za to, że jeszcze Polska nie zginęła!\n\n";
            break;
        
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
            cout<<endl;
            cin >> opcja;
            cout<<endl;
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
                cout<<endl;
                receptura.pokaz();
                cout<<endl;
                Skladnik::wyswietlSklep();
                cout<<endl;
                cout<<endl;

                cout << "\nDodaj 3 skladniki (nazwa + malo/duzo):\n";
                for (int i = 0; i < 3; ++i) {
                    cout << "Skladnik #" << (i + 1) << ": ";
                    getline(cin, wybor[i].nazwa);
                    cout << "  Ilosc (malo/duzo): ";
                    getline(cin, wybor[i].ilosc);
                }
                cout<<endl;
                cout<<endl;

                double wynik = ScoreTrack(wybor);
                
                //cout<< "- ------ test wyniku przed zdarzeniem: "<<wynik<<endl; 
                
                cout<<endl;
                
                losoweZdarzenie(wynik);  
                
                cout<<endl;
                
                zapiszScoring(wynik);
                
                ReakcjaNaPunktacje(wynik);
                
                cout<< "- ------ Twoj wynik: "<<wynik<<endl; 
                
                cout<<endl;
                cout<<endl;
                
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
                    cout << "║                     - składnik6                        ║\n";
                    cout << "║════════════════════════════════════════════════════════║\n";
                    cout << "║           ➤ Wybierz proporcje: mało / dużo            ║\n";
                    cout << "║           ➤ Traf w przepis lub stwórz nowy!           ║\n";
                    cout << "║           ➤ Śledź reakcje klientów!                   ║\n";
                    cout << "║════════════════════════════════════════════════════════║\n";
                    cout << "║          Cel: Zdobądź tytuł Cukiermana      !          ║\n";
                    cout << "╠════════════════════════════════════════════════════════╣\n";
                    cout << "║           Wciśnij dowolny znak oraz ENTER              ║\n";
                    cout << "║                          i                             ║\n";
                    cout << "║            zacznij zanim klient ucieknie!              ║\n";
                    cout << "╚════════════════════════════════════════════════════════╝\n";
                    cout<<endl;
                    cout<<endl;
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
