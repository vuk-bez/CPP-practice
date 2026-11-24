#include <iostream>
#include <string.h>
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

    int duzina = max(s1.size(), s2.size());

    
}
int main() {

    zad9();
    return 0;
}