#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

// zad 1. --- Napisati program koji učitava riječ i ispisuje prvo samoglasnike, a zatim suglasnike u 
//            datoj riječi.

bool jeSamoglasnik(char a) {
    a = tolower(a);
    return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}

void zad1() {

    string rijec;
    cin >> rijec;

    for(int i = 0; i < rijec.size(); i++) {
        if (jeSamoglasnik(rijec.at(i))) cout << rijec.at(i);
    }

    for(int i = 0; i < rijec.size(); i++) {
        if (!jeSamoglasnik(rijec.at(i))) cout << rijec.at(i);
    }

}

// zad 2. --- Napisati program koji učitava riječ i u njoj sva velika slova pretvara u mala i štampa 
//            dobijeni string.

void zad2() {

    string rijec;
    cin >> rijec;
    for(int i = 0; i < rijec.size(); i++) {
        if (rijec.at(i) >= 'A' && rijec.at(i) <= 'Z') {
            rijec.at(i) = rijec.at(i) + 32;
        }
    }

    cout << rijec << endl;
}

// zad 3. --- Napisati funkciju void velikaSlova(string& s) koja transformiše string s tako što između 
//            svaka dva uzastopna velika slova umetne karakter ‘_’. Na primjer, unijeti string s = 
//            "aBCDeF3GH", funkcija treba da transformiše u "aB_C_DeF3G_H".

void zad3() {

    string rijec;
    cin >> rijec;

    for (int i = 0; i < rijec.size() - 1; i++) {
        if (rijec.at(i) >= 'A' && rijec.at(i) <= 'Z' && rijec.at(i+1) >= 'A' && rijec.at(i+1) <= 'Z') {
            rijec.insert(i+1, "_");
        }
    }

    cout << rijec;

}

// zad 4. --- Napisati funkciju void umetniSlovo(string& s) koja transformiše string s tako što nakon 
//            svakog velikog slova u stringu umetne njemu odgovarajuće malo slovo. Na primjer, 
//            unijeti  string  S="ProGraMiraNje",  funkcija  treba  da  transformiše  u 
//            "PproGgraMmiraNnje".

void zad4() {

    string rijec;
    cin >> rijec;

    for(int i = 0; i < rijec.size(); i++) {
        if(rijec.at(i) >= 'A' && rijec.at(i) <= 'Z') {
            string slovo(1, tolower(rijec.at(i)));
            rijec.insert(i+1, slovo);
        }
    }

    cout << rijec << endl;
}

// zad 5. --- Napisati  funkciju  void  samoglasnici(string&  s)  koja  transformiše  string  s  tako  što 
//            između svaka dva uzastopna samoglasnika umetne karakter ‘-’. Na primjer, unijeti 
//            string s = "AbcEaoU7", funkcija treba da transformiše u "AbcE-a-o-U7".

void zad5() {

    string rijec;
    cin >> rijec;

    for (int i = 0; i < rijec.size()-1; i++) {
        if(jeSamoglasnik(rijec.at(i)) && jeSamoglasnik(rijec.at(i+1))) {
            rijec.insert(i+1, "-");
        }
    }

    cout << rijec << endl;
}

// zad 6. --- Napisati funkciju void cifre(string& s) koja transformiše string s tako što nakon svake 
//            parne cifre u stringu umetne slovo ‘P’, a nakon svake neparne cifre slovo ‘N’. Na 
//            primjer, unijeti string S="ab2cg3#1",  funkcija treba da transformiše u 
//            "ab2Pcg3N#1N"

void zad6() {
    int parne[] = {0,2,4,6,8};
    int neparne[] = {1,3,5,7,9};

    string rijec;
    cin >> rijec;

    for(int i = 0; i < rijec.size(); i++) {
        for(int j = 0; j < 5; j++) {
            if((rijec.at(i)-'0') == parne[j]) {
                rijec.insert(i+1, "P");
            }
        }
        for(int j = 0; j < 5; j++) {
            if((rijec.at(i)-'0') == neparne[j]) {
                rijec.insert(i+1, "N");
            }
        }
    }

    cout << rijec << endl;
}

// zad 7. --- Napisati funkciju void umetniCifru(string& s) koja transformiše taj string s tako što 
//            nakon svake cifre veće od 0 u stringu umetne cifru za jedan manju, a nakon cifre 0 
//            umetne cifru 9. Na primjer, unijeti string s = "ab2c9#03", funkcija treba da transformiše 
//            u "ab21c98#0932".

void zad7() {

    string rijec;
    cin >> rijec;

    int cifre[] = {0,1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < rijec.size(); i++) {
        if(rijec.at(i) == '0') {
            rijec.insert(i+1, "9");
            i++;
        } else {
            for(int j = 1; j < 10; j++) {
                if((rijec.at(i)-'0') == cifre[j]) {
                    string slovo = to_string((rijec.at(i)-'0')-1);
                    rijec.insert(i+1, slovo);
                    i++;
                }
            }
        }
        
    }

    cout << rijec << endl;
}

// zad 8. --- Napisati funkciju bool ciklicno(string s, string t, int k) koja provjerava da li se string t 
//            moze dobiti cikličnim pomjeranjem stringa s za k mjesta ulijevo ili udesno. 


// zad 9. --- Napisati funkciju string premjesti(string s) koja od stringa s pravi string u kojem su 
//            samoglasnici ispred suglasnika. Možete pretpostaviti da će se s sastojati samo od 
//            malih slova. 

void zad9() {

    string rijec;
    cin >> rijec;

    int l = 0;
    int r = rijec.size() - 1;
    while(l < r) {
        while(jeSamoglasnik(rijec[l])) l++;
        while(!jeSamoglasnik(rijec[r])) r--;
        if(l < r) {
            char temp = rijec[l];
            rijec[l] = rijec[r];
            rijec[r] = temp;
        }

    }

    cout << rijec << endl;
}

// zad 10. --- Napisati funkciju string saberi(string a, string b) koja sabira binarne brojeve a i b koji 
//             su zadati kao stringovi. Na primjer, ako je a=“111“ i b = “11”, rješenje je “1000”

void zad10() {
    string s1;
    string s2;
    cin >> s1 >> s2;

    if (s2.size() > s1.size()) {
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }

    string rez;
    rez.resize(s1.size()+1);
    char prenos = '0';
    int razlika = s1.size() - s2.size();
    int i;
    for(i = s2.size()-1; i >= 0; i--) {
        if(s1[i+razlika] == '1' && s2[i] == '1') {
            if(prenos == '1') {
                rez[i+razlika+1] = '1';
            } else {
                rez[i+razlika+1] = '0';
                prenos = '1';
            }
        } else if (s1[i+razlika] == '0' && s2[i] == '0'){
            if(prenos == '1') {
                prenos = '0';
                rez[i+razlika+1] = '1';
            } else {
                rez[i+razlika+1] = '0';
            }
        } else {
            if(prenos == '1') {
                prenos = '1';
                rez[i+razlika+1] = '0';
            } else {
                rez[i+razlika+1] = '1';
            }
        }
    }
    
    for(int j = razlika-1; j >= 0; j--) {
        if(prenos == '0') {
            rez[j+1] = s1[j];
        } else {
            if(s1[j] == '1') {
                rez[j+1] = '0';
            } else {
                rez[j+1] = 1;
                prenos = '0';
            }
        }
    }

    rez[0] = prenos;

    for(int j = 0; j < rez.size(); j++) {
        if(j==0 && rez[j] == '0') continue;
        cout << rez[j];
    }
    cout << endl;
   
}

// zad 11. --- Napisati program koji nalazi i štampa najduži zaajednički prefiks za dva stringa. Na 
//             primjer,  ukoliko  su  dati  stringovi  A=”programiranje  1”  i  B=”programski  jezik  C++”, 
//             najduži zajednički prefiks je “program”.

void zad11() {
    string s1;
    string s2;
    cin >> s1 >> s2;

    string rez = "";
    int i = 0;
    while(i < s1.size() && i < s2.size() && s1[i] == s2[i]) {
        rez += s1[i];
        i++;
    }

    cout << rez << endl;
}

// zad 12. --- Napisati program koji učitava dva stringa jednake dužine i od njih pravi treći string tako 
//             što u njemu naizmjenično postavlja slova iz jednog, pa drugog stringa. Na primjer, za 
//             stringove “pmf“ i “abc“ rezultat treba da bude “pambfc“. 

void zad12() {
   string s1;
   string s2;
   
   string s3 = "";
   cin >> s1 >> s2;
   for(int i = 0; i < s1.size(); i++) {
        s3 += s1[i];
        s3 += s2[i];
   }

   cout << s3 << endl;
}

// zad 13. --- Napisati  program  koji  provjerava  validnost  unijete  šifre.  Šifra  se  smatra  validnom 
//            ukoliko ima barem 8 karaktera i dodatno ispunjava sljedeće kriterijume 
//              Sadrži barem jedno veliko i barem jedno malo slovo abecede, 
//              Sadrži barem jednu cifru, 
//              Sadrži barem jedan od specijalnih karaktera iz skupa {$,#,@}.

void zad13() {
    string sifra;
    cin >> sifra;

    if(sifra.size() < 8) {
        cout << "Nije validna" << endl;
        return;       
    }

    bool veliko = false;
    bool malo = false;
    bool broj = false;
    bool special = false;

    for(int i = 0; i < sifra.size(); i++) {
        if(sifra[i] >= 'A' && sifra[i] <= 'Z') veliko = true;
        else if (sifra[i] >= 'a' && sifra[i] <= 'z') malo = true;
        else if (sifra[i] >= '0' && sifra[i] <= '9') broj = true;
        else if (sifra[i] == '$' || sifra[i] == '#' || sifra[i] == '@') special = true;
    }

    if(veliko && malo && broj && special) {
        cout << "Validna je" << endl;
    } else {
        cout << "Nije validna" << endl;
    }

}

// zad 14. --- Rimske  cifre  predstavljene  su  simbolima  I=1,  V=5,  X=10,  L=50,  C=100,  D=500, 
//             M=1000. Na primjer, broj 7 se rimskim ciframa piše kao “VII” (5+1+1), 63 kao “LXIII” 
//             (50+10+1+1+1), 2021 kao “MMXXI” (1000+1000+10+10+1) itd. Rimski brojevi pišu se 
//             od većih cifara ka manjim, osim u nekoliko posebnih slučajeva: 
//               I se može naći ispred V i X kako bi se dobili brojevi 4 i 9. 
//               X se može naći ispred L i C kako bi se dobili brojevi 40 i 90. 
//               C se može naći ispred D i M kako bi se dobili brojevi 400 i 900. 
//             Napisati program koji sa standardnog ulaza učitava string koji predstavlja rimski broj i 
//             izračunava i štampa njegovu vrijednost u dekadnom brojnom sistemu.

void zad14() {
    string s1;
    cin >> s1;

    int vrijednost = 0;
    for(int i = 0; i < s1.size(); i++) {
        if(i+1 < s1.size() && s1[i] == 'I' && s1[i+1] == 'V') {
            vrijednost += 4;
            i++;
        } else if (i+1 < s1.size() && s1[i] == 'I' && s1[i+1] == 'X') {
            vrijednost += 9;
            i++;
        } else if (i+1 < s1.size() && s1[i] == 'X' && s1[i+1] == 'L') {
            vrijednost += 40;
            i++;
        } else if (i+1 < s1.size() && s1[i] == 'X' && s1[i+1] == 'C') {
            vrijednost += 90;
            i++;
        } else if (i+1 < s1.size() && s1[i] == 'C' && s1[i+1] == 'D') {
            vrijednost += 400;
            i++;
        } else if (i+1 < s1.size() && s1[i] == 'C' && s1[i+1] == 'M') {
            vrijednost += 900;
            i++;
        } else if (s1[i] == 'I') {
            vrijednost += 1;
        } else if (s1[i] == 'V') {
            vrijednost += 5;
        } else if (s1[i] == 'X') {
            vrijednost += 10;
        } else if (s1[i] == 'L') {
            vrijednost += 50;
        } else if (s1[i] == 'C') {
            vrijednost += 100;
        } else if (s1[i] == 'D') {
            vrijednost += 500;
        } else if (s1[i] == 'M') {
            vrijednost += 1;
        }
    }

    cout << vrijednost << endl;
}

// zad 15. --- isti kao zadatak 14.
// zad 16. --- Napisati program koji sa standardnog ulaza učitava string koji predstavlja evidenciju 
//             o prisustvovanju studenta predavanjima. Ovaj string sastoji se iz karaktera P, O, L. 
//             Karakter P označava da je student prisustvovao času, karakter O da je student 
//             odsustvovao sa časa, a karakter L da je student zakasnio na čas. Program treba da 
//             provjeri da li će student dobiti poene za prisustvo i odštampa odgovarajuću poruku. 
//             Student će dobiti poene za prisustvo ukoliko nije odsustvovao sa više od dva časa 
//             uzastopno i ako nije zakasnio na više od tri uzastopna časa. Na primjer, ako je zapis 
//             prisustva “PPOOLLLOP”, student će dobiti poene za prisustvo, dok student sa 
//             sljedećim zapisom “PPOOLOOOP” neće dobiti poene za prisustvo.

void zad16() {
    string s1;
    cin >> s1;

    int i = 0;
    while(i < s1.size()) {
        int brojac = 0;

        while(i < s1.size() && s1[i] == 'O') {
            brojac++;
            i++;
        }

        if(brojac > 2) {
            cout << "Ne dobija bodove" << endl;
            return;
        }

        brojac = 0;
        while(i < s1.size() && s1[i] == 'L') {
            brojac++;
            i++;
        }
        

        if(brojac > 3) {
            cout << "Ne dobija bodove" << endl;
            return;
        }

        while(i < s1.size() && s1[i] == 'P') {
            i++;
        }
    }

    cout << "Dobija bodove" << endl;
}

// zad 17. ---  Lower camel case i snake case su konvencije za imenovanje funkcija i promjenljivih 
//              koje se koriste u programiranju. U lower camel case notaciji prvo slovo identifikatora 
//              je malo, a prvo slovo svake naredne riječi je veliko (npr. brojMobilnogTelefona, 
//              izracunajUkupnuSumu). U snake case notaciji su sva slova identifikatora mala, a 
//              riječi su razdvojene donjim crtama (npr. broj_mobilnog_telefona, 
//              izracunaj_ukupnu_sumu). Napisati program koji identifikator napisan u Lower camel 
//              case-u pretvara u identifikator u snake case-u.

void zad17() {
    string s1;
    cin >> s1;

    string s2 = "";
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] >= 'A' && s1[i] <= 'Z') {
            s2 += '_';
            s2 += tolower(s1[i]);
        } else {
            s2 += s1[i];
        }
    }

    cout << s2 << endl;
}

// zad 18. --- Napisati program koji učitava string koji predstavlja naziv Excel kolone. Program 
//             treba da odštampa redni broj unsene kolone. Na primjer: “A” → 1, “B” → 2, “C” → 
//             2,..., “Z” → 26, “AA” → 27, “AB” → 28, itd. 

void zad18() {
    string s1;
    cin >> s1;

    int broj = 0;
    for(int i = s1.size()-1; i >= 0; i--) {
        broj = broj * 26 + (s1[i] - 'A' + 1);   
    }

    cout << broj << endl;
}

// zad 19. --- Napisati program koji učitava prirodan broj koji predstavlja redni broj Excel kolone. 
//             Program treba da odštampa naziv unsene kolone. Na primjer: 1 → “A”, 2 → “B”, 2 → 
//             “C”,..., 26 → “Z”, 27 → “AA”, 28 → “AB”, itd. 

void zad19() {
    int broj;
    cin >> broj;

    string rez = "";

    int i = 0;
    while (broj != 0) {
        rez += 64 + (broj % 26);
        broj /= 26; 
    }

    for(int i = 0; i < rez.size()/2; i++) {
        char temp = rez[rez.size()-1-i];
        rez[rez.size()-1-i] = rez[i];
        rez[i] = temp;
    }
    cout << rez << endl;


}

// zad 20. --- Napisati program koji učitava string oblika “<naziv1><broj1>:<naziv2><broj2>” koji 
//             predstavlja  opseg  Excel  ćelija.  Djelovi  stringa  <naziv1>  i  <broj1>  određuju  naziv 
//             kolone i broj reda gornje lijeve ćelije iz opsega, a djelovi <naziv2> i <broj2> određuju 
//             naziv kolone i broj reda donje desne ćelije iz opsega. Program treba da odštampa 
//             koliko ukupno ćelija sadrži dati opseg. Nazivi Excel kolona se zadaju u sljedećem 
//             redosljedu “A”, “B”, “C”, ..., “Z”, “AA”, “AB”, “AC”, ..., “AZ”, “BA”, “BB”, itd. 
int konverzija(string &s1) {

    int broj = 0;
    for(int i = s1.size()-1; i >= 0; i--) {
        broj = broj * 26 + (s1[i] - 'A' + 1);   
    }

    return broj;
}

void zad20() {
    string s1;
    cin >> s1;

    string naziv1 = "";
    string naziv2 = "";
    string broj1 = "";
    string broj2 = "";

    int i = 0;
    while(s1[i] >= 'A' && s1[i] <= 'Z') {
        naziv1 += s1[i];
        i++;
    }
    while(s1[i] >= '0' && s1[i] <= '9') {
        broj1 += s1[i];
        i++;
    }
    i++;
    while(s1[i] >= 'A' && s1[i] <= 'Z') {
        naziv2 += s1[i];
        i++;
    }
    while(s1[i] >= '0' && s1[i] <= '9') {
        broj2 += s1[i];
        i++;
    }

    int kolona1 = konverzija(naziv1);
    int kolona2 = konverzija(naziv2);
    int red1 = stoi(broj1);
    int red2 = stoi(broj2);

    int brojPolja = 0;
    brojPolja = (kolona2-kolona1+1)*(red2-red1+1);
    cout << brojPolja << endl;

}

// zad 21. --- Napisati program koji učitava dvije niske karaktera koje predstavljaju elemente dva 
//             skupa. Skupovi nemaju više od 26 elemenata. Program treba da odredi i odštampa 
//             niske koje predstavljaju uniju, presjek i simetričnu razliku dva skupa. Elementi niski su 
//             mala slova engleske abecede.
void unija(string &s1, string &s2) {
    int niz[26] = {0};
    for(int i = 0; i < s1.size(); i++) {
        niz[s1[i]-97] = 1;
    }

    for(int i = 0; i < s2.size(); i++) {
        niz[s2[i]-97] = 1;
    }

    string rez = "";
    for(int i = 0; i < 26; i++) {
        if(niz[i] == 1) {
            rez += i+97;
        }
    }

    cout << "Unija: " << rez << endl;
}

void presjek(string &s1, string &s2) {
    int niz[26] = {0};
    for(int i = 0; i < s1.size(); i++) {
        niz[s1[i]-97] = 1;
    }

    for(int i = 0; i < s2.size(); i++) {
        if(niz[s2[i]-97] == 1) {
            niz[s2[i]-97] = 2;
        }
    }

    string rez = "";
    for(int i = 0; i < 26; i++) {
        if(niz[i] == 2) {
            rez += i+97;
        }
    }

    cout << "Presjek: " << rez << endl;
}

void razlika(string &s1, string &s2) {
    int niz[26] = {0};
    for(int i = 0; i < s1.size(); i++) {
        niz[s1[i]-97] = 1;
    }

    for(int i = 0; i < s2.size(); i++) {
        if(niz[s2[i]-97] == 0) {
            niz[s2[i]-97] = 1;
        } else {
            niz[s2[i]-97] = 0;
        }
        
    }

    string rez = "";
    for(int i = 0; i < 26; i++) {
        if(niz[i] == 1) {
            rez += (char)(i+97);
        }
    }

    cout << "Razlika: " << rez << endl;
}

void zad21() {
    string s1;
    string s2;

    cin >> s1 >> s2;

    unija(s1, s2);
    presjek(s1, s2);
    razlika(s1,s2);
    

}

// zad 22. --- Napisati program koji provjerava da li je unijeti string oblika 𝑎2n𝑏m𝑐2n za proizvoljne 
// prirodne brojeve m i n. Na primjer, aabcc i aaaabbcccc jesu riječi ovog oblika, dok 
// aaabccc nije.

void zad22() {
    int n,m;
    cin >> n >> m;

    string s1;
    cin >> s1;
    
    int i = 0;
    int brojac = 0;
    while(i < s1.size() && s1[i] == s1[i+1]) {
        brojac++;
        i++;
    }
    brojac++;
    i++;

    if(brojac != 2*n) {
        cout << "Nije" << endl;
        return;
    }

    brojac = 0;
    while(i < s1.size() && s1[i] == s1[i+1]) {
        brojac++;
        i++;
    }
    brojac++;
    i++;

    if (brojac != m) {
        cout << "Nije" << endl;
        return;
    }

    brojac = 0;
    while(i < s1.size() && s1[i] == s1[i+1]) {
        brojac++;
        i++;
    }
    brojac++;
    i++;

    if(brojac != 2*n) {
        cout << "Nije" << endl;
        return;
    }

    cout << "Jeste" << endl;

}

// zad 23. --- Napisati program koji sa standardnog ulaza učitava string S i transformiše dati string 
//             tako  što  okrene  redosljed  svih  slova,  a  ostale  karaktere  zadrži  na  postojećim 
//             pozicijama.

void zad23() {
    string s1;
    cin >> s1;

    int i = 0;
    int j = s1.size() - 1;
    while(i<j) {
        if(i < s1.size() && (!(s1[i] >= 'A' && s1[i] <= 'Z') && !(s1[i] >= 'a' && s1[i] <= 'z'))) i++;
        if(j >= 0 && (!(s1[j] >= 'A' && s1[j] <= 'Z') && !(s1[j] >= 'a' && s1[j] <= 'z'))) j--;

        if(i < j) {
            swap(s1[i],s1[j]);
            i++; j--;
        }
    }

    cout << s1 << endl;
}

// zad 24. ---  Napisati program koji sa standardnog ulaza učitava string S i transformiše dati string 
//              tako što okrene redosljed svih samoglasnika, a ostale karaktere zadrži na postojećim 
//              pozicijama.

void zad24() {
    string s1;
    cin >> s1;

    int i = 0;
    int j = s1.size()-1;
    while(i < j) {
        while(i < s1.size() && !jeSamoglasnik(s1[i])) i++;
        while(j >= 0 && !jeSamoglasnik(s1[j])) j--;

        if(i<j) {
            swap(s1[i], s1[j]);
            i++; j--;
        }
    }

    cout << s1 << endl;
}

// zad 25. --- Napisati program koji za data dva stringa S i T provjerava da li su jednaki kada se 
//             otkucaju  na  tastaturi.  Karakter  ‘#’  ima  specijalno  značenje  i  predstavlja  pritisak 
//             backspace dugmeta na tastaturi (brisanje karaktera ispred kursora). 

void zad25() {
    string s1;
    string s2;

    cin >> s1 >> s2;

    string rez1 = "";
    string rez2 = "";

    for(int i = 0; i < s1.size(); i++) {
        if (s1[i] == '#') {
            if(rez1.empty()) continue;
            rez1.pop_back();
        } else {
            rez1 += s1[i];
        }
    }

    for(int i = 0; i < s2.size(); i++) {
        if (s2[i] == '#') {
            if(rez2.empty()) continue;
            rez2.pop_back();
        } else {
            rez2 += s2[i];
        }
    }

    if(rez1 == rez2) {
        cout << "Jesu" << endl;
    } else {
        cout << "Nisu" << endl;
    }
}

// zad 26. --- Napisati funkciju string cezar(string s, int k) koja šifrira Cezarovom šifrom string s koji 
//             sadrži isključivo mala slova engleske abecede. Cezarovo šifriranje se vrši tako što se 
//             svako slovo ciklično pomjeri za k mjesta udesno po abecedi. 

void zad26() {
    string s;
    int k;
    cin >> s >> k;

    for(int i = 0; i < s.size(); i++) {
        s[i] = (s[i]-97+k)%26 + 97;
    }

    cout << s << endl;
}

// zad 28. ---  Napisati program koji sa standardnog ulaza učitava string genom koji se sastoji od 
//              velikih slova ’A’, ’C’, ’G’, ’T’ (skraćenice za 4 nukleotidne baze adenin, citozin, guanin 
//              i timin) i broj k. Vaš program treba da pronađe i odštampa sve podstringove stringa 
//              genom dužine k koji sadrže sva četiri slova. Ne štampati duplikate. 

bool validan(string &s) {
    int niz[4] = {0};
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'A') niz[0] = 1;
        if(s[i] == 'C') niz[1] = 1;
        if(s[i] == 'T') niz[2] = 1;
        if(s[i] == 'G') niz[3] = 1;

    }

    for(int i = 0; i < 4; i++) {
        if (niz[i] == 0) {
            return false;
        }
    }

    return true;
}

void zad28() {
    string s;
    int k;
    cin >> s >> k;

    for(int j = 0; j < s.size() - k + 1; j++) {
        string substr;
        substr = s.substr(j,k);

        if(validan(substr)) cout << substr << endl;
    }

}
 // zad 29. --- Napisati program koji sa standardnog ulaza učitava string genom koji se sastoji od 
//              velikih slova ’A’, ’C’, ’G’, ’T’ (skraćenice za 4 nukleotidne baze adenin, citozin, guanin 
//              i timin) i prirodan broj k. Vaš program treba da pronađe i odštampa sve podstringove 
//              stringa genom dužine k koji se u njemu javljaju više od jednom. Ne štampati duplikate.


void zad29() {
    string s;
    int k;
    cin >> s >> k;

    string rijeseni[100];
    for(int i = 0; i < s.size() - k + 1; i++) {
        string substring;
        substring = s.substr(i,k);

        for(int j=i; j < s.size() - k + 1; j++) {
            string substring2;
            substring2 = s.substr(j, k);

            if(substring == substring2){
                cout << substring << endl;
            }
        }
    }

}

// zad 30. --- Napisati program koji za učitani string nalazi i štampa najduži podstring datog stringa 
//             koji je palindrom

bool jePalindrom(string s) {
    for(int i = 0; i < s.size()/2; i++) {
        if(s[i] != s[s.size()-1-i]) {
            return false;
        }
    }
    return true;
}

void zad30() {
    string s;
    cin >> s;
    
    for(int i = s.size(); i >= 1; i--) {
        for(int j = 0; j < s.size()-i+1; j++) {
            string substr = s.substr(j, i);
            if(jePalindrom(substr)) {
                cout << substr << endl;
                return;
            }
        }
    }

    cout << "Nema palindroma" << endl;
}

// zad 31. --- Napisati funkciju bool anagram(string str1, string str2) kojom se provjerava da li su 
//             dva data stringa anagrami. Stringovi su anagrami ukoliko se jedan string može dobiti 
//             premještanjem  slova  drugog  stringa.  

void zad31() {
    string s1;
    string s2;

    cin >> s1 >> s2;

    int pojavljivanje1[26] = {0};
    int pojavljivanje2[26] = {0};

    for(int i = 0; i < s1.size(); i++) {
        pojavljivanje1[s1[i]-97]++; 
    }

    for(int i = 0; i < s2.size(); i++) {
        pojavljivanje2[s2[i]-97]++; 
    }

    for(int i = 0; i < 26; i++) {
        if(pojavljivanje1[i] != pojavljivanje2[i]) {
            cout << "Nije anagram" << endl;
            return;
        }
    }

    cout << "Jeste anagram" << endl;

}

// zad 33. ---  Napisati program koji sa  standardnog  ulaza učitava  dva  stringa A i B koji sadrže 
//              isključivo mala slova engleske abecede. Program treba da pronađe i odštampa slova 
//              po kojima se stringovi A i B razlikuju (da jedan sadrži određeno slovo a drugi ne). 
//              Svako ponavljanje određenog slova, posmatra se odvojeno.

void zad33() {
    string s1;
    string s2;

    cin >> s1 >> s2;

    int pojavljivanje1[26] = {0};
    int pojavljivanje2[26] = {0};

    for(int i = 0; i < s1.size(); i++) {
        pojavljivanje1[s1[i]-97]++;
    }

    for(int i = 0; i < s2.size(); i++) {
        pojavljivanje2[s2[i]-97]++;
    }

    for(int i = 0; i < 26; i++) {
        int brojac = abs(pojavljivanje1[i] - pojavljivanje2[i]);
        for(int j = 0; j < brojac; j++) {
            cout << (char)(i+97);
        }
    }
}

// zad 34. --- Napisati program koji sa standardnog ulaza učitava dva stringa A i B i provjerava da 
//             li  se  string  A  može  sastaviti  korišćenjem  isključivo  slova  iz  stringa  B. 

void zad34() {
    string s1;
    string s2;

    cin >> s1 >> s2;
    
    int skup1[26] = {0};
    int skup2[26] = {0};

    for(int i = 0; i < s1.size(); i++) {
        skup1[s1[i]-97] ++;
    }

    for(int i = 0; i < s2.size(); i++) {
        skup2[s2[i]-97] ++;
    }

    for(int i = 0; i < 26; i++) {
        if(skup1[i] != 0) {
            if (skup1[i] != skup2[i]) {
                cout << "Ne moze" << endl;
                return;
            }
        }
    }

    cout << "Moze" << endl;
}

// zad 35. ---  IP adresa je jedinstvena oznaka hosta u računarskoj mreži. IP adresa se sastoji od 
//              četiri prirodna broja od 0 do 255 (bez vodećih nula) odvojena tačkama. Napisati 
//              program koji sa standardnog ulaza učitava string i provjerava da li taj string 
//              predstavlja validnu IP adresu.

bool segmentJeValidan(string s) {
    for(int i = 0; i < s.size(); i++) {
        if (!(s[i] >= '0' && s[i] <= '9')) {
            return false;
        }
    }

    if(s[0] == '0' && s.size() > 1) return false;

    int opseg = stoi(s);
    if(!(opseg >= 0 && opseg <=255)) return false;

    return true;
}

void zad35() {
    string s;
    cin >> s;

    int brojTacaka = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '.') brojTacaka++;
    }

    if (brojTacaka != 3) {
        cout << "Nije validna" << endl;
        return;
    }

    int i = 0;
    while(i < s.size()) {
        int pocetak = i;
        int duzina = 0;
        while(s[i] != '.')  {
            duzina++;
            i++;
        }
        i++;
        string substr = s.substr(pocetak, duzina);
        if(!(segmentJeValidan(substr))) {
            cout << "Nije validan" << endl;
            return;
        }
    }

    cout << "Validan" << endl;

}
int main() {
    // ZADATAK 8. NIJE URADJEN
    // ZADATAK 27. NIJE RUADJEN 
    // ZADATAK 29. NIJE RADJEN
    // ZADATAK 32. NIJE RADJEN


    zad35();

    return 0;
}