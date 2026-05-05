#include <iostream>

using namespace std;

#define N 10

void stampaArray(int v[], int n) {
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}

void scambia(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Bubble Sort con bandiera
void bubbleSort(int v[], int n) {
    bool ordinato = false;

    while (n > 1 && !ordinato) {
        ordinato = true;

        for (int i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1]) {
                scambia(v[i], v[i + 1]);
                ordinato = false;
            }
        }
        n--;
    }
}

// Naive Sort
int trovaPosMax(int v[], int n) {
    int posMax = 0;

    for (int i = 1; i < n; i++)
        if (v[i] > v[posMax])
            posMax = i;

    return posMax;
}

void naiveSort(int v[], int n) {
    while (n > 1) {
        int p = trovaPosMax(v, n);

        if (p < n - 1)
            scambia(v[p], v[n - 1]);

        n--;
    }
}

// Quick Sort
void quickSort(int v[], int left, int right) {
    int i = left, j = right;
    int pivot = v[(left + right) / 2];

    while (i <= j) {
        while (v[i] < pivot) i++;
        while (v[j] > pivot) j--;

        if (i <= j) {
            scambia(v[i], v[j]);
            i++;
            j--;
        }
    }

    if (left < j) quickSort(v, left, j);
    if (i < right) quickSort(v, i, right);
}

// Merge Sort
void merge(int v[], int left, int mid, int right) {
    int temp[N];
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (v[i] < v[j])
            temp[k++] = v[i++];
        else
            temp[k++] = v[j++];
    }

    while (i <= mid) temp[k++] = v[i++];
    while (j <= right) temp[k++] = v[j++];

    for (i = left; i <= right; i++)
        v[i] = temp[i];
}

void mergeSort(int v[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(v, left, mid);
        mergeSort(v, mid + 1, right);
        merge(v, left, mid, right);
    }
}

// ESERCIZIO 1
void esercizio1() {
    int v[N];
    int scelta;

    cout << "\nInserisci 10 numeri:\n";
    for (int i = 0; i < N; i++)
        cin >> v[i];

    cout << "\nScegli algoritmo:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Naive Sort\n";
    cout << "3. Quick Sort\n";
    cout << "4. Merge Sort\n";
    cin >> scelta;

    switch (scelta) {
        case 1: bubbleSort(v, N); break;
        case 2: naiveSort(v, N); break;
        case 3: quickSort(v, 0, N - 1); break;
        case 4: mergeSort(v, 0, N - 1); break;
        default:
            cout << "Scelta non valida\n";
            return;
    }

    cout << "\nArray ordinato:\n";
    stampaArray(v, N);
}

// ESERCIZIO 2
void esercizio2() {
    int v[N] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 0};
    int nuovo, scelta;

    cout << "\nArray iniziale ordinato:\n";
    stampaArray(v, N - 1);

    cout << "Inserisci nuovo valore: ";
    cin >> nuovo;

    v[N - 1] = nuovo;

    cout << "\nScegli algoritmo per riordinare:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Naive Sort\n";
    cout << "3. Quick Sort\n";
    cout << "4. Merge Sort\n";
    cin >> scelta;

    switch (scelta) {
        case 1: bubbleSort(v, N); break;
        case 2: naiveSort(v, N); break;
        case 3: quickSort(v, 0, N - 1); break;
        case 4: mergeSort(v, 0, N - 1); break;
        default:
            cout << "Scelta non valida\n";
            return;
    }

    cout << "\nArray aggiornato:\n";
    stampaArray(v, N);
}

int main() {
    int scelta;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Esercizio 1 - Ordinamento 10 numeri\n";
        cout << "2. Esercizio 2 - Inserimento in array ordinato\n";
        cout << "0. Esci\n";
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1: esercizio1(); break;
            case 2: esercizio2(); break;
            case 0: cout << "Uscita...\n"; break;
            default: cout << "Scelta non valida\n";
        }

    } while (scelta != 0);

    return 0;
}