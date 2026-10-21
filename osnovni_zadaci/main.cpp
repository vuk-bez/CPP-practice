#include <iostream>
#include <cmath>
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

void zad11() {
    int n;
    cin >> n;
    int otpornost = 0;

    while (n/10 != 0) {
        int suma = 0;
        while(n != 0) {
            int cifra = n % 10;
            n /= 10;
            suma += cifra;
        }
        n = suma;
        otpornost++;
    }

    cout << otpornost << endl;
}

void zad12() {

    int max = 0;
    int n = 0;
    int m = 0;

    for (int i = 1; i < 100; i++) {
        for(int j = 1; j < 100; j++) {
            int suma = i*i + j*j;
            if (abs(i*i + i*j + j*j) == 100 && suma > max) {
                max = suma;
                n = i; m = j;
            }
        }
    }

    cout << n << " i " << m << endl;
}

void zad13() {
    int n;
    cin >> n;

    double suma = 0;
    for (int i = 1; i <= n; i++) {
        suma += pow(-1, i) / (double)i;
    }

    cout << suma << endl;
}

void zad14() {
    double e;
    cin >> e;

    double suma = 0;
    int imenilac = 1;
    int i = 1;
    while (true) {
        double sabirak = imenilac / pow(i, 2);
        if (sabirak < e) {
            cout << suma << endl;
            return;
        }

        suma += sabirak; 
        i++;
        imenilac += 2;
    }
}

void zad15() {
    double x;
    int n;
    cin >> x >> n;

    double suma = 0;
    double faktorijel = 1;
    for (int i = 1; i <= n; i++) {
        faktorijel *= i;
        suma += (pow(-1, i-1)*sin(x-2)*sin(x-2))/(faktorijel);
    }

    cout << suma << endl;
}

void zad16() {
    double x;
    int n;
    cin >> x >> n;

    double suma = 0;
    double faktorijel = 1;
    for(int i = 1; i <= n; i++) {
        faktorijel *= i;
        suma += (pow(-1,i)*pow(x+1,2*i+1))/faktorijel;
    }

    cout << suma << endl;
}

void zad17() {
    int h, w;
    cin >> h >> w;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(i == 0 || j == 0 || i == h-1 || j == w-1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// funkcija uz zadatak 18
double rastojanje (double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}
void zad18() {
    double x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double a, b, c;
    a = rastojanje(x1, y1, x2, y2);
    b = rastojanje(x2, y2, x3, y3);
    c = rastojanje(x1, y1, x3, y3);

    if (a + b > c && a + c > b && b + c > a) {
        cout << "Obrazuju trougao" << endl;
    } else {
        cout << "Ne obrazuju trougao" << endl;
    }

}

// ista funkcija rastojanje koristi se i za ovaj zadatak
void zad19() {
    double x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double a, b, c;
    a = rastojanje(x1, y1, x2, y2);
    b = rastojanje(x2, y2, x3, y3);
    c = rastojanje(x1, y1, x3, y3);

    double s = (a + b + c)/2;
    cout << sqrt(s*(s - a)*(s - b)*(s - c)) << endl;

}

// ista funkcija rastojanje koristi se i za ovaj zadatak
void zad20() {
    double x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double duzine[3];
    duzine[0] = rastojanje(0, 0, x1, y1);
    duzine[1] = rastojanje(0, 0, x2, y2);
    duzine[2] = rastojanje(0, 0, x3, y3);

    int min = duzine[0];
    int minI = 0;
    for(int i = 1; i < 3; i++) {
        if(duzine[i] < min) { min = duzine[i]; minI=i; }
    }

    switch(minI) {
        case 0: {
            cout << "(" << x1 << "," << y1 << ")" << " ";
            double ugao2 = atan2(y2, x2);
            double ugao3 = atan2(y3, x3);
            if (ugao2 > ugao3) {
                cout << "(" << x2 << "," << y2 << ")" << " ";
                cout << "(" << x3 << "," << y3 << ")" << endl;
            } else {
                cout << "(" << x3 << "," << y3 << ")" << " ";
                cout << "(" << x2 << "," << y2 << ")" << endl;
            }
            break;
        }
        case 1: {
            cout << "(" << x2 << "," << y2 << ")" << " ";
            double ugao1 = atan2(y1, x1);
            double ugao3 = atan2(y3, x3);
            if (ugao1 > ugao3) {
                cout << "(" << x1 << "," << y1 << ")" << " ";
                cout << "(" << x3 << "," << y3 << ")" << endl;
            } else {
                cout << "(" << x3 << "," << y3 << ")" << " ";
                cout << "(" << x1 << "," << y1 << ")" << endl;
            }
            break;
        }
        case 2: {
            cout << "(" << x3 << "," << y3 << ")" << " ";
            double ugao1 = atan2(y1, x1);
            double ugao2 = atan2(y2, x2);
            if (ugao1 > ugao2) {
                cout << "(" << x1 << "," << y1 << ")" << " ";
                cout << "(" << x2 << "," << y2 << ")" << endl;
            } else {
                cout << "(" << x2 << "," << y2 << ")" << " ";
                cout << "(" << x1 << "," << y1 << ")" << endl;
            }
            break;
        }
    }


}

// u nastavku su iterativne verzije zadataka oznacene sa I, a rekurzivne sa R
void zad21I() {
    int n;
    cin >> n;

    int okrenut = 0;
    while(n != 0) {
        int cifra = n % 10;
        n /= 10;

        okrenut *= 10;
        okrenut += cifra;
    }

    cout << okrenut << endl;
}

int zad21R(int n, int i) {
    if (n == 0) {
        return 0;
    }

    int cifra = n % 10;
    
    return cifra*pow(10, i-1) + zad21R(n/10, i-1);
}

void zad22I(){
    int n;
    cin >> n;

    int m = 0;
    while(n != 0) {
        int cifra = n % 10;
        n /= 10;

        if(cifra % 2 != 0) {
            m *= 10;
            m += cifra;
        }
    }

    int obrnut = 0;
    while(m != 0) {
        int cifra = m % 10;
        m /= 10;

        obrnut *= 10;
        obrnut += cifra;
    }

    cout << obrnut << endl;
}

int zad22R(int n) {
    if (n == 0) {
        return 0;
    }

    int cifra = n % 10;
    if (cifra % 2 != 0) {
        return zad22R(n/10)*10 + cifra;
    } else {
        return zad22R(n/10);
    }
}

void zad23I() {
    double x, s, p;
    cin >> x >> s >> p;

    double godine = 0;
    while (s > x) {
        s = s - s*p/100;
        godine ++;
    }

    cout << godine << endl;
}

double zad23R(double x, double s, double p) {
    if (x > s) {
        return 0;
    }

    return zad23R(x, s - s*p/100, p) + 1;
}

void zad24() {
    int n;
    cin >> n;

    int kopija = n;
    while (n != 0) {
        int cifra = n % 10;
        n /= 10;

        if (kopija % cifra != 0) {
            cout << "Ne vazi" << endl;
            return;
        }
    }

    cout << "Vazi" << endl;
}

void zad25() {
    int n;
    cin >> n;

    while (n % 2 == 0) {
        n /= 2;
    }

    while (n % 3 == 0) {
        n /= 3;
    }

    while (n % 5 == 0) {
        n /= 5;
    }

    if (n == 1) {
        cout << "Jeste" << endl;
    } else {
        cout << "Nije" << endl;
    }
}

int main() {

    zad20();
    return 0;
}