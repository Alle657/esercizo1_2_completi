#include <stdio.h>
#include <string.h>

#define N 10


void stampaArray(int v[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void scambia(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


// Bubble Sort con Bandiera

void bubbleSort(int v[], int n) {
    int ordinato = 0;

    while(n > 1 && !ordinato) {
        ordinato = 1;

        for(int i = 0; i < n-1; i++) {
            if(v[i] > v[i+1]) {
                scambia(&v[i], &v[i+1]);
                ordinato = 0;
            }
        }

        n--;
    }
}


// Naive Sort

int trovaPosMax(int v[], int n) {
    int posMax = 0;

    for(int i = 1; i < n; i++)
        if(v[i] > v[posMax])
            posMax = i;

    return posMax;
}

void naiveSort(int v[], int n) {
    while(n > 1) {
        int p = trovaPosMax(v, n);

        if(p < n-1)
            scambia(&v[p], &v[n-1]);

        n--;
    }
}


// Insertion Sort

void insertionSort(int v[], int n) {
    for(int k = 1; k < n; k++) {
        int x = v[k];
        int i = k - 1;

        while(i >= 0 && v[i] > x) {
            v[i+1] = v[i];
            i--;
        }

        v[i+1] = x;
    }
}


// Quick Sort

void quickSort(int v[], int left, int right) {
    int i = left, j = right;
    int pivot = v[(left + right)/2];

    while(i <= j) {
        while(v[i] < pivot) i++;
        while(v[j] > pivot) j--;

        if(i <= j) {
            scambia(&v[i], &v[j]);
            i++;
            j--;
        }
    }

    if(left < j) quickSort(v, left, j);
    if(i < right) quickSort(v, i, right);
}


// Merge Sort

void merge(int v[], int left, int mid, int right) {
    int temp[N];
    int i = left, j = mid+1, k = left;

    while(i <= mid && j <= right) {
        if(v[i] < v[j])
            temp[k++] = v[i++];
        else
            temp[k++] = v[j++];
    }

    while(i <= mid) temp[k++] = v[i++];
    while(j <= right) temp[k++] = v[j++];

    for(i = left; i <= right; i++)
        v[i] = temp[i];
}

void mergeSort(int v[], int left, int right) {
    if(left < right) {
        int mid = (left + right)/2;

        mergeSort(v, left, mid);
        mergeSort(v, mid+1, right);
        merge(v, left, mid, right);
    }
}


// ESERCIZIO 1

void esercizio1() {
    int v[N];
    int scelta;

    printf("\nInserisci 10 numeri:\n");
    for(int i = 0; i < N; i++)
        scanf("%d", &v[i]);

    printf("\nScegli algoritmo:\n");
    printf("1. Bubble Sort\n");
    printf("2. Naive Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Quick Sort\n");
    printf("5. Merge Sort\n");
    scanf("%d", &scelta);

    switch(scelta) {
        case 1: bubbleSort(v, N); break;
        case 2: naiveSort(v, N); break;
        case 3: insertionSort(v, N); break;
        case 4: quickSort(v, 0, N-1); break;
        case 5: mergeSort(v, 0, N-1); break;
        default: printf("Scelta non valida\n"); return;
    }

    printf("\nArray ordinato:\n");
    stampaArray(v, N);
}


// ESERCIZIO 2

void esercizio2() {
    int v[N] = {5, 10, 15, 20, 25, 30, 35, 40, 45};
    int nuovo, scelta;

    printf("\nArray iniziale ordinato:\n");
    stampaArray(v, N-1);

    printf("Inserisci nuovo valore: ");
    scanf("%d", &nuovo);

    v[N-1] = nuovo;

    printf("\nScegli algoritmo per riordinare:\n");
    printf("1. Bubble Sort\n");
    printf("2. Naive Sort\n");
    printf("3. Insertion Sort (vero inserimento)\n");
    printf("4. Quick Sort\n");
    printf("5. Merge Sort\n");
    scanf("%d", &scelta);

    switch(scelta) {
        case 1:
            bubbleSort(v, N);
            break;

        case 2:
            naiveSort(v, N);
            break;

        case 3: {
            int x = v[N-1];
            int i = N-2;

            while(i >= 0 && v[i] > x) {
                v[i+1] = v[i];
                i--;
            }

            v[i+1] = x;
            break;
        }

        case 4:
            quickSort(v, 0, N-1);
            break;

        case 5:
            mergeSort(v, 0, N-1);
            break;

        default:
            printf("Scelta non valida\n");
            return;
    }

    printf("\nArray aggiornato:\n");
    stampaArray(v, N);
}


int main() {
    int scelta;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Esercizio 1 - Ordinamento 10 numeri\n");
        printf("2. Esercizio 2 - Inserimento in array ordinato\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch(scelta) {
            case 1: esercizio1(); break;
            case 2: esercizio2(); break;
            case 0: printf("Uscita...\n"); break;
            default: printf("Scelta non valida\n");
        }

    } while(scelta != 0);

    return 0;
}