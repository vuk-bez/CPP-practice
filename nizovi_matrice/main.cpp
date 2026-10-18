#include <iostream>
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

int main() {

    zad35();

    return 0;
}