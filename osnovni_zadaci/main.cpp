#include <iostream>
using namespace std;

// Zadaci su iz fajla Prva grupa zadatak za vjezbu.pdf i to prva kategorija

void zad01() {
    float f;
    cin >> f;

    float c = (f-32)*5/9;
    cout << c << endl;
}

void zad02() {
    int velicinaFajla;
    cin >> velicinaFajla; //u gigabajtima

    cout << ((float)(velicinaFajla*8)/0.1) << endl;
}

void zad03() {
    int i = 1;
    while (i <= 5) {
        int j = 0;
        while(j < i) {
            j++;
            cout << "*";
        }
        i++;
        cout << endl;
    }
    
    i--;

    while (i > 0) {
        i--;
        int j = 0;
        while (j < i) {
            j++;
            cout << "*";
        }
        cout << endl;
    }
}

void zad04() {
    int n;
    cin >> n;

    int niz[10] = {0};
    while (n != 0) {
        int cifra = n % 10;
        niz[cifra] = 1;
        n /= 10;
    }

    int suma = 0;
    for (int i = 0; i < 10; i++) {
        suma += niz[i];
    }

    cout << suma << endl;
}

void zad05() {
    int n;
    cin >> n;

    int niz[10] = {0};
    while (n != 0) {
        int cifra = n % 10;
        niz[cifra]++;
        n /= 10;
    }

    int najPo = 0;
    int najIndex = 0;
    for (int i = 0; i < 10; i++) {
        if (niz[i] > najPo) {
            najPo = niz[i];
            najIndex = i;
        }
    }

    cout << niz[najIndex] << endl;
}

void zad06() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "Ne" << endl;
        return;
    }

    int suma = 0;
    for (int i = 1; i <= n/2 + 1; i++) {
        if (n % i == 0) suma += i;
    }

    cout << (suma == n ? "Da" : "Ne") << endl;
}

// funkcija uz zad 07

bool jeDvojak(int n) {
    int niz[10] = {0};

    while (n != 0) {
        int cifra = n % 10;
        n /= 10;
        niz[cifra] = 1;
    }

    int suma = 0;
    for (int i = 0; i < 10; i++) {
        suma += niz[i];
    }

    return (suma > 2 ? false : true);
}
void zad07() {
    int n;
    cin >> n;
    
    int i = n;
    int j = n-1;
    while(true) {
        if (jeDvojak(i)) {
            cout << i << endl;
            return;
        } else {
            i++;
        }

        if(jeDvojak(j)) {
            cout << j << endl;
            return;
        } else {
            j--;
        }

    }
}

void zad08() {
    for (int c = 10; c <= 99; c++) {
        bool pitagorin = false;
        for (int a = 1; a < c && !pitagorin; a++) {
            for (int b = a; b < c; b++) {
                if (a * a + b * b == c * c) {
                    pitagorin = true;
                    break;
                }
            }
        }
        if (pitagorin)
            cout << c << " ";
    }
    cout << endl;
}

// pomocna funkcija uz zadatak 09
bool jeArmstrongov(int n) {
    
    int suma = 0;
    int kopija = n;

    while (n != 0) {
        int cifra = n % 10;
        n /= 10;
        suma += cifra*cifra*cifra;
    }

    return (suma == kopija ? true : false);
}

void zad09() {
    for (int i = 100; i < 1000; i++) {
        if(jeArmstrongov(i)) {
            cout << i << " ";
        }
    }

    cout << endl;
}

// funkcija uz zadatak 10

bool jeProst(int n) {
    for(int i = 2; i < n/2 + 1; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

void zad10() {
    int n;
    cin >> n;

    int i = 2;
    while (n != 1) {
        if (n % i == 0) {
            if (jeProst(i)) cout << i << " ";
            while(n % i == 0) {
                n /= i;
            }
        }
        i++;
    }

    cout << endl;
}

int main() {
    zad10();
    return 0;
}