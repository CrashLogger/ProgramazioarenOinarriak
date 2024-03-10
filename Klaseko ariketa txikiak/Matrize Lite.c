/*
 * 
 */

#include <stdio.h>
#include <stdlib.h>

//Prototipoak
void matrizeTamaina(int *_lerroKop, int *_zutabeKop);
int** matrizeaSortu(int *_lerroKop, int *_zutabeKop);
void matrizeaBete(int** _matrizea, int _lerroKop, int _zutabeKop);
void matrizeaBistaratu(int** _matrizea, int _lerroKop, int _zutabeKop);
void matrizeaAskatu(int** _matrizea, int _lerroKop, int _zutabeKop);
void lerroMaxBilatu(int** _matrizea, int _lerroKop, int _zutabeKop);
void zutabeMinBilatu(int** _matrizea, int _lerroKop, int _zutabeKop);
void irauliaBete(int** _matrizea, int** _iraulia, int _lerroKop, int _zutabeKop);
//------------------------------

int main(int argc, char** argv) {

    int** matrizea;
    int** iraulia;
    int lerroKop;
    int zutabeKop;
    
    //Oraindik balioak ez daudenez ezarrita punteroekin hartu
    
    matrizea = matrizeaSortu(&lerroKop, &zutabeKop);
       
    //Balioak ditugunez, balioen kopiak bidali ditzakegu
    matrizeaBete(matrizea, lerroKop, zutabeKop);
    printf("#=====  MATRIZEA =====#\n");
    fflush(stdout);
    matrizeaBistaratu(matrizea, lerroKop, zutabeKop);
    
    //Iraulia sortuko dugu orain beteta dagoela, eta bistaratuko dugu
    iraulia = matrizeaSortu(&zutabeKop, &lerroKop);
    irauliaBete(matrizea, iraulia, lerroKop, zutabeKop);
    printf("#=====  IRAULIA  =====#\n");
    fflush(stdout);
    matrizeaBistaratu(iraulia, zutabeKop, lerroKop);
    printf("#=====================#\n\n");
    fflush(stdout);
    
    lerroMaxBilatu(matrizea, lerroKop, zutabeKop);
    zutabeMinBilatu(matrizea, lerroKop, zutabeKop);

    //Amaieran matrizea askatzen dugu
    matrizeaAskatu(matrizea, lerroKop, zutabeKop);
    matrizeaAskatu(iraulia, zutabeKop, lerroKop);
    
    return (EXIT_SUCCESS);
}

int** matrizeaSortu(int *_lerroKop, int *_zutabeKop){
    int** matrizea;
    matrizeTamaina(_lerroKop, _zutabeKop);
    matrizea = (int**)malloc(*_lerroKop * sizeof(int*));
    
    for(int i = 0; i<*_lerroKop; i++){
        *(matrizea + i) = (int*)malloc(*_zutabeKop * sizeof(int));
    }
    return matrizea;
}

void matrizeTamaina(int *_lerroKop, int *_zutabeKop){
    if(*_lerroKop == 0 || *_zutabeKop == 0){
        do{
            printf("Eman matrizearen lerro kopurua:\n");
            fflush(stdout);
            __fpurge(stdin);
            scanf("%d", _lerroKop);
        }while(*_lerroKop < 1);

        do{
            printf("Eman matrizearen zutabe kopurua:\n");
            fflush(stdout);
            __fpurge(stdin);
            scanf("%d", _zutabeKop);
        }while(*_zutabeKop < 1);    
    }
}

void matrizeaBete(int** _matrizea, int _lerroKop, int _zutabeKop){
    printf("Matrizearen posizioak matematika eran emanda, ez informatika eran (1 etik hasiko dira!):");
    fflush(stdout);
    for(int i = 0; i<_lerroKop; i++){
        for(int j = 0; j<_zutabeKop; j++){
            printf("\nM(%3d, %3d) = ",i+1,j+1);
            fflush(stdout);
            __fpurge(stdout);
            scanf("%d", (*(_matrizea + i)+j));
        }
    }
    printf("\n\n");
    fflush(stdout);
}

void matrizeaBistaratu(int** _matrizea, int _lerroKop, int _zutabeKop){
    for(int i = 0; i<_lerroKop; i++){
        for(int j = 0; j<_zutabeKop; j++){
            printf("%4d\t", *(*(_matrizea + i)+j));
            fflush(stdout);
        }
        printf("\n");
        fflush(stdout);
    }
}

void matrizeaAskatu(int** _matrizea, int _lerroKop, int _zutabeKop){
    //Array-barruko pointer bakoitzaren arraya askatzen da lehen.
    for(int i = 0; i<_lerroKop; i++){
        free(*(_matrizea + i));
    }
    free(_matrizea);
}

void lerroMaxBilatu(int** _matrizea, int _lerroKop, int _zutabeKop){
    //Lerro bakoitzeko balioak haien artean konparatu, eta maximoa aurkitu.
    int max;
    int aux = 0;
    for(int i = 0; i<_lerroKop; i++){
        max = 0;
        for(int j = 0; j<_zutabeKop; j++){
            aux = *(*(_matrizea + i)+j);
            if(aux > max){
                max = aux;
            }
        }
        printf("%3d. Lerroko maximoa %3d da.\n",i+1,max);
        fflush(stdout);
    }
    printf("\n");
    fflush(stdout);
}

void zutabeMinBilatu(int** _matrizea, int _lerroKop, int _zutabeKop){
    //Zutabe bakoitzeko balioak haien artean konparatu, eta minimoa aurkitu.
    int min;
    int aux = 0;
    for(int i = 0; i<_zutabeKop; i++){
        min = 99999999;
        for(int j = 0; j<_lerroKop; j++){
            aux = *(*(_matrizea + j)+i);
            if(aux < min){
                min = aux;
            }
        }
        printf("%3d. Zutabeko minimoa %3d da.\n",i+1,min);
        fflush(stdout);
    }
}

void irauliaBete(int** _matrizea, int** _iraulia, int _lerroKop, int _zutabeKop){
    for(int i = 0; i<_lerroKop; i++){
        for(int j = 0; j<_zutabeKop; j++){
            *(*(_iraulia + j)+i) = *(*(_matrizea +i)+j);
        }
    }
}