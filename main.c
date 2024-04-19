#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct Punto{
    float x;
    float y;
};

void azzeraVettoreFloat(float vettore[], int lunghezza){
    for(int i = 0; i < lunghezza; i++){
        vettore[i] = 0;
    }
}

void azzeraVettoreInt(int vettore[], int lunghezza){
    for(int i = 0; i < lunghezza; i++){
        vettore[i] = 0;
    }
}

float calcolaDistanza(float x1, float x2, float y1, float y2){
    float xTot = (x1 - x2);
    float yTot = (y1 - y2);
    float d = sqrt(xTot*xTot + yTot*yTot);
    return d;
}

void stampaPunti(struct Punto p[], int lunghezza){
    for(int i = 0; i < lunghezza; i++){
        printf("Punto %d: x = %f; y = %f\n", i+1, p[i].x, p[i].y);
    }
}

int comparaCentroidi(struct Punto vecchiCentroidi[], struct Punto c[], int lunghezza){
    int status = 0;
    for(int i = 0; i < lunghezza; i++){
        if(vecchiCentroidi[i].x == c[i].x && vecchiCentroidi[i].y == c[i].y){
            status = 1;
        }
    }
    return status;
}

int main()
{
    int nPunti;
    int nCentroidi;
    srand(time(NULL));

    printf("Inserisci il numero di punti casuali da generare:\n");
    scanf("%d", &nPunti);
    struct Punto p[nPunti];

    for(int i = 0; i < nPunti; i++){
        p[i].x = (float)rand() / RAND_MAX * 10000;
        p[i].y = (float)rand() / RAND_MAX * 10000;
    }
    stampaPunti(p, nPunti);
    printf("\n\n");

    printf("Inserisci il numero di centroidi casuali da generare:\n");
    scanf("%d", &nCentroidi);
    struct Punto c[nCentroidi];

    for(int i = 0; i < nCentroidi; i++){
        int puntoRandom = rand()%nPunti;
        c[i].x = p[puntoRandom].x;
        c[i].y = p[puntoRandom].y;
    }
    stampaPunti(c, nCentroidi);
    printf("\n\n");

    struct Punto vecchioCentroide[nCentroidi];
    for(int i = 0; i < nCentroidi; i++){
        vecchioCentroide[i].x = c[i].x;
        vecchioCentroide[i].y = c[i].y;
    }
    int counter = 0;
    int equilibrio = 0;
    while(equilibrio == 0){
        int contatoreCentroidi[nCentroidi];
        float mediaX[nCentroidi];
        float mediaY[nCentroidi];
        azzeraVettoreFloat(mediaX, nCentroidi);
        azzeraVettoreFloat(mediaY, nCentroidi);
        azzeraVettoreInt(contatoreCentroidi, nCentroidi);
        for(int i = 0; i < nPunti; i++){
            int pos = 0;
            float min = calcolaDistanza(p[i].x, c[0].x, p[i].y, c[0].y);
            for(int j = 1; j < nCentroidi; j++){
                float d = calcolaDistanza(p[i].x, c[j].x, p[i].y, c[j].y);
                if(min > d){
                    min = d;
                    pos = j;
                }
            }
            mediaX[pos] += p[i].x;
            mediaY[pos] += p[i].y;
            contatoreCentroidi[pos]++;
        }
        for(int i = 0; i < nCentroidi; i++){
            c[i].x = mediaX[i]/contatoreCentroidi[i];
            c[i].y = mediaY[i]/contatoreCentroidi[i];
        }
        if(comparaCentroidi(vecchioCentroide, c, nCentroidi) == 0){
            for(int i = 0; i < nCentroidi; i++){
                vecchioCentroide[i].x = c[i].x;
                vecchioCentroide[i].y = c[i].y;
                counter++;
            }
        }
        else{
            equilibrio = 1;
            stampaPunti(c, nCentroidi);
            printf("\nSpostamenti: %d", counter);
        }
    }
}
