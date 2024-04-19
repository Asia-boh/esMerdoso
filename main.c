#include <stdio.h>
#include <stdlib.h>

struct Punto{
    int x;
    int y;
};
struct Centroide{
    int x;
    int y;
    int posizione;
};

int main()
{
    int nPunti;
    int nCentroidi;
    srand(time(NULL));

    printf("Inserisci il numero di punti casuali da generare:\n");
    scanf("%d", &nPunti);
    struct Punto p[nPunti];

    for(int i = 0; i < nPunti; i++){
        p[i].x = rand();
        p[i].y = rand();
    }

    printf("Inserisci il numero di centroidi casuali da generare:\n");
    scanf("%d", &nCentroidi);
    struct Centroide c[nCentroidi];

    for(int i = 0; i < nCentroidi; i++){
        int puntoRandom = rand()% nPunti;
        c[i].x = p[puntoRandom].x;
        c[i].y = p[puntoRandom].x;
        c[i].posizione = puntoRandom;
    }
    int min = ;
    for(int i = 0; i < nPunti; i++){
        for(int j = 0; j < nCentroidi; j++){

        }
    }
}
