#include <iostream>
#include <cmath>
using namespace std;

// Zadaci su iz fajla Prva grupa zadatak za vjezbu.pdf i to druga kategorija

//funkcije unosNiza i ispisNiza bice nam potrebne za naredne zadatke
void unosNiza(int* niz, int n) {
    for (int i = 0; i < n; i++) {
        cin >> niz[i];
    }
}

void ispisNiza(int* niz, int n) {
    for (int i = 0; i < n; i++) {
        cout << niz[i] << " ";
    }
}

void zad26() {
    int n, k;
    cin >> n >> k;

    int* niz = new int[n];
    unosNiza(niz, n);

    int suma = 0;
    for (int i = 0; i < n; i++) {
        if (niz[i] % 2 == 0 && niz[i] > k) {
            suma++;
        }
    }

    delete[] niz;
    cout << suma << endl;
}

void zad27() {
    int n;
    cin >> n;

    int* niz = new int[n];
    unosNiza(niz, n);

    int parni = 0;
    int neparni = 0;
    for (int i = 0; i < n; i++) {
        if (niz[i] % 2 == 0) parni++;
        else neparni++;
    }

    int* parniNiz = new int[parni];
    int* neparniNiz = new int[neparni];
    int j = 0, k = 0;
    for (int i = 0; i < n; i++) {
        if (niz[i] % 2 == 0) parniNiz[j++] = niz[i];
        else neparniNiz[k++] = niz[i];
    }

    ispisNiza(neparniNiz,neparni);
    cout << endl;
    ispisNiza(parniNiz, parni);

    delete[] niz;
    delete[] neparniNiz;
    delete[] parniNiz;
}

void zad28() {
    int n;
    cin >> n;

    int* niz = new int[n];
    unosNiza(niz, n);

    int* noviNiz = new int[2*n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        noviNiz[j++] = niz[i];
        noviNiz[j++] = niz[i];
    }

    ispisNiza(noviNiz, 2*n);
    delete[] noviNiz;
    delete[] niz;
}

void zad29() {
    int n;
    cin >> n;

    int* niz = new int[n];
    unosNiza(niz, n);

    int i = 0, j = n-1;
    while (i < j) {
        if (niz[i] % 2 == 0) i++;
        if (niz[j] % 2 != 0) j--;

        if (i >= j) break;
        int temp = niz[i];
        niz[i] = niz[j];
        niz[j] = temp;
    }

    ispisNiza(niz, n);
    delete[] niz;
}

void zad30() {
    int n;
    cin >> n;

    int* ects = new int[n];
    unosNiza(ects, n);
    int* ocjene = new int[n];
    unosNiza(ocjene, n);

    double suma = 0;
    double prosjek = 0;
    for (int i = 0; i < n; i++) {
        suma += ects[i];
        prosjek += ects[i]*ocjene[i];
    }

    cout << prosjek/suma << endl;
    delete[] ects;
    delete[] ocjene;
}

void zad31() {
    int n;
    cin >> n;

    int* niz = new int[n];
    unosNiza(niz, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && niz[i] == niz[j]) {
                cout << "Ima duplikata" << endl;
                delete[] niz;
                return;
            }
        }
    }

    cout << "Nema duplikata" << endl;
    delete[] niz;
}

void zad32() {
    int n;
    cin >> n;

    int* niz = new int[n];
    unosNiza(niz, n);

    int* mapa = new int[n];
    for (int i = 0; i < n; i++) {
        mapa[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        mapa[niz[i]-1] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (mapa[i] == 0) {
            cout << i+1 << " ";
        }
    }

    cout << endl;
    delete[] mapa;
    delete[] niz;
}

void zad33() {
    int n;
    cin >> n;

    int* niz = new int[n];
    unosNiza(niz, n);

    int* mapa = new int[n];
    for (int i = 0; i < n; i++) {
        mapa[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        mapa[niz[i]-1] ++;
    }

    int max = 0;
    int maxI = 0;
    for (int i = 0; i < n; i++) {
        if (mapa[i] > max) {
            max = mapa[i];
            maxI = i;
        }
    }

    cout << maxI + 1 << endl;
    delete[] mapa;
    delete[] niz;
}

void zad34() {
    int n, m;
    cin >> n >> m;

    int* niz = new int[n];
    unosNiza(niz, n);
    int* niz2 = new int[m];
    unosNiza(niz2, m);

    //zbir polinoma
    int* zbir = new int[n > m ? n : m];
    if (n > m) {
        for (int i = 0; i < m; i++) {
            zbir[i] = niz2[i] + niz[i];
        }
        for (int i = m; i < n; i++) {
            zbir[i] = niz[i];
        }
    } else {
        for (int i = 0; i < n; i++) {
            zbir[i] = niz2[i] + niz[i];
        }
        for (int i = n; i < m; i++) {
            zbir[i] = niz2[i];
        }
    }
    ispisNiza(zbir, (n > m ? n : m));
    delete[] zbir;

    //proizvod polinoma
    int* proizvod = new int[m+n-1];
    for (int i = 0; i < m+n-1; i++) {
        proizvod[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            proizvod[i+j] += niz[i]*niz2[j];
        }
    }

    ispisNiza(proizvod, m+n-1);
    delete[] proizvod;
    delete[] niz;
    delete[] niz2;

}

void zad35() {
    int n;
    cin >> n;
    int* niz = new int[n];
    unosNiza(niz, n);

    int prefix = 0;
    int postfix = 0;
    for (int i = 0; i < n; i++) {
        postfix += niz[i];
    }

    int indicator = 0;
    for (int i = 0; i < n; i++) {
        if (i-1 > 0) {
            prefix += niz[i-1];
        }
        postfix -= niz[i];
        if (prefix == postfix) {
            cout << i << " ";
            indicator++;
        }
    }

    if (indicator == 0) cout << "-1" << endl;
    delete[] niz;
}

void zad36() {
    int n, m;
    cin >> n >> m;

    int* prvi = new int[n]; // prvi veci ili jednak drugom
    unosNiza(prvi, n);
    int* drugi = new int[m];
    unosNiza(drugi, m);

    int*  zbir = new int[n+1];
    int prenos = 0;
    for(int i = m-1; i >= 0; i--) {
        zbir[i + (n-m)+1] = (prvi[i+(n-m)]+drugi[i]+prenos) % 10;
        prenos = (prvi[i+(n-m)]+drugi[i]+prenos) / 10;
    }

    for(int i = n-m-1; i >= 0; i--) {
        zbir[i+1] = (prenos + prvi[i]) % 10;
        prenos = (prvi[i] + prenos) / 10;
    }
    zbir[0] = prenos;

    if(zbir[0] == 0) {
        int* temp = new int[n];
        for(int i = 0; i < n; i++) {
            temp[i] = zbir[i+1];
        }
        ispisNiza(temp, n);
    } else {
        ispisNiza(zbir, n+1);
    }

    delete[] zbir;
    cout << endl;

    int* razlika = new int[n];
    int pozajmica = 0;

    for(int i = n - 1, j = m - 1; i >= 0; i--, j--) { // proba sa dva brojaca
        int d = prvi[i] - pozajmica - (j >= 0 ? drugi[j] : 0); //ternari operator
        if(d < 0) {
            d += 10;
            pozajmica = 1;
        } else {
            pozajmica = 0;
        }
        razlika[i] = d;
    }

    // preskoči vodeće nule, ali ostavi bar jednu cifru
    int pocetak = 0;
    while(pocetak < n - 1 && razlika[pocetak] == 0) pocetak++;

    ispisNiza(razlika + pocetak, n - pocetak);

    delete[] prvi;
    delete[] drugi;
    delete[] razlika;

}

void zad37() {
    int n;
    cin >> n ;

    int* realniDio = new int[n];
    unosNiza(realniDio, n);
    int* imaginarniDio = new int[n];
    unosNiza(imaginarniDio, n);

    int realniDioP = realniDio[0];
    int imaginarniDioP = imaginarniDio[0];

    for(int i = 0; i < n - 1; i++) {
        int temp = realniDioP; // da bih za racunanje imaginarnog koristio stari realni a ne novo izracunati
        realniDioP = realniDioP*realniDio[i+1] - imaginarniDioP*imaginarniDio[i+1];
        imaginarniDioP = realniDio[i+1]*imaginarniDioP + temp*imaginarniDio[i+1];
    }

    cout << realniDioP << " + " << imaginarniDioP << "i" << endl;
    delete[] imaginarniDio;
    delete[] realniDio;
}

// pomocna funkcija za zadatke

int rastojanje (int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

void zad38() {
    int n;
    cin >> n;

    int* X = new int[n];
    int* Y = new int[n];
    unosNiza(X, n);
    unosNiza(Y, n);

    double max = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                double a = rastojanje(X[i], Y[i], X[j], Y[j]);
                double b = rastojanje(X[j], Y[j], X[k], Y[k]);
                double c = rastojanje(X[k], Y[k], X[i], Y[i]);

                double s = (a+b+c)/2.0;

                double povrsina = sqrt(s*(s-a)*(s-b)*(s-c));
                if (povrsina > max) {
                    max = povrsina;
                }
            }
        }
    }

    cout << max << endl;
    delete[] X;
    delete[] Y;

}

void zad39() {
    int n;
    cin >> n;

    int* X = new int[n];
    int* Y = new int[n];
    unosNiza(X, n);
    unosNiza(Y, n);

    
}

int main() {

    zad38();

    return 0;
}