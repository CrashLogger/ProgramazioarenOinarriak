
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FITXAIZENA "hitzorduak.dat"
#define TAMAINA 128

// Prototipoak
struct fitxa* arraySortu(int _tamaina);
void fitxategiaIrakurri(struct fitxa *_zerrenda, int *_elemKop, char *_fitxategiIzena, int _bistaratuIrakurketa);
void menua(struct fitxa* _zerrenda, int *_elemKop);
void hitzorduBerria(struct fitxa* _zerrenda, int *_elemKop);
struct fitxa datuakLortu(void);
void nKendu(char *_string);
int posizioaBilatu(struct fitxa *_zerrenda, int *_elemKop, struct fitxa _tmp);
void posizioanSartu(struct fitxa *_zerrenda, int *_elemKop, struct fitxa _tmp, int _pos);

void arrayAskatu(struct fitxa* _zerrenda);

struct fitxa{
    
    char izena[39];
    char nanZbkia[10];
    char data[9];
    char ordua[6];
    
};

int main(int argc, char** argv) {
    
    struct fitxa *zerrenda;
    int elemKop = 0;
    zerrenda = arraySortu(TAMAINA);
    
    fitxategiaIrakurri(zerrenda, &elemKop, FITXAIZENA, 0);
    
    menua(zerrenda, &elemKop);
    
    arrayAskatu(zerrenda);
    return (EXIT_SUCCESS);
}

void fitxategiaIrakurri(struct fitxa *_zerrenda, int *_elemKop, char *_fitxategiIzena, int _bistaratuIrakurketa){
    
    FILE* filePtr;
    
    filePtr = fopen(_fitxategiIzena, "rb");
    
    //Asumitzen dugu fitxategia programa honek egin duela, eta beraz, zuzen egingo dela.
    
    struct fitxa tmp;
    
    if(_bistaratuIrakurketa == 0){
        *_elemKop = 0;
    }
    
    
    printf("*****************************************************************************************************************\n");
    fflush(stdout);
    
    if(filePtr != NULL){
        
        while(fread(&tmp, sizeof(struct fitxa), 1, filePtr)){
            
            if(_bistaratuIrakurketa == 0){
                _zerrenda[*_elemKop] = tmp;
                *_elemKop = *_elemKop + 1;
            }
            else{
                printf("%9s\t%38s\t%6s\t%5s\n", tmp.nanZbkia, tmp.izena, tmp.data, tmp.ordua);
                fflush(stdout);
            }
        }
        
        if(_bistaratuIrakurketa == 0){
            printf("%d elementu irakurri dira fitxategitik.\n", *_elemKop);
            fflush(stdout);
        }

        fclose(filePtr);
        
    }else{

        printf("Fitxategia ez da existitzen!\n");
        fflush(stdout);

    }
    
    printf("*****************************************************************************************************************\n\n");
}

struct fitxa* arraySortu(int _tamaina){
    struct fitxa *tmp;
    tmp = (struct fitxa*)malloc(_tamaina * sizeof(struct fitxa));
    
    printf("\n%d Elementuko array-a sortuta!\n", TAMAINA);
    fflush(stdout);
    
    return tmp;
}

void menua(struct fitxa* _zerrenda, int *_elemKop){
    
    int aukera = 0;
    
    do{
        
        printf("\nHurrengo aukeretatik aukeratu\n\t0\tIrten\n\n\t1\tHitzordua gehitu\n\t2\tHitzordua kendu\n\t3\tFitxategia bistaratu\n\t4\tEgutegiak sortu\n\n");
        fflush(stdout);
        
        __fpurge(stdin);
        scanf("%d", &aukera);
        
        switch(aukera){
            case 1:
                hitzorduBerria(_zerrenda, _elemKop);
                break;
            case 2:
                break;
            case 3:
                fitxategiaIrakurri(_zerrenda, _elemKop, FITXAIZENA, 1);
                break;
            case 4:
                break;
                //DEBUGEATZEKO AUKERA
            case 5:
                for(int i = 0; i<=*_elemKop; i++){
                    printf("%s\n", (_zerrenda + i)->nanZbkia);
                    fflush(stdout);
                }
                break;
            default:
                printf("\nHori ez da aukera egokia, mesedez, saiatu berriro!\n");
                fflush(stdout);
                break;
        };
        
    }while(aukera != 0);
    return;
}

void hitzorduBerria(struct fitxa* _zerrenda, int *_elemKop){
    
    int pos = 0;
    struct fitxa tmp;
    
    tmp = datuakLortu();
    
    pos = posizioaBilatu(_zerrenda, _elemKop, tmp);
    
    printf("NAN = %s\n", tmp.nanZbkia);
    
    if(pos >= 0){
        printf("%d Posizioan sartu elementua.\n", pos);
        fflush(stdout);
        posizioanSartu(_zerrenda, _elemKop, tmp, pos);
        
        fitxategianSartu(_zerrenda, _elemKop, FITXAIZENA);
    }
    else{
        printf("NAN horrekin badago hitzordu bat, mesedez, ezabatu hori berria sartu baino lehen!\n");
    }
    
}

struct fitxa datuakLortu(void){
    
    struct fitxa tmp;
    
    printf("\nEman zure NAN zenbakia:\n");
    fflush(stdout);
    __fpurge(stdin);
    fgets(tmp.nanZbkia, sizeof(tmp.nanZbkia), stdin);
    
    printf("\nEman zure Izena:\n");
    fflush(stdout);
    __fpurge(stdin);
    fgets(tmp.izena, sizeof(tmp.izena), stdin);
    nKendu(tmp.izena);
    
    printf("\nHitzorduaren data eman UUUUHHEE formatuan:\n");
    fflush(stdout);
    __fpurge(stdin);
    fgets(tmp.data, sizeof(tmp.data), stdin);
    
    printf("\nHitzorduaren ordua eman HH:MM formatuan:\n");
    fflush(stdout);
    __fpurge(stdin);
    fgets(tmp.ordua, sizeof(tmp.ordua), stdin);
    
    
    return tmp;
}

void nKendu(char *_string){
    
    int luzera = 0;
    luzera = strlen(_string);
    
    *(_string + luzera - 1)='\0';
}

int posizioaBilatu(struct fitxa *_zerrenda, int *_elemKop, struct fitxa _tmp){
    
    int a = 0;
    int b = *_elemKop;
    int erdia = 0;
    int aurkituta = 0;
    
    while(aurkituta != 1){
        
        erdia = (a + b)/2;
        
        if(!aurkituta && strcmp(_tmp.nanZbkia, (_zerrenda + *_elemKop)->nanZbkia) > 0){
            aurkituta = 1;
            erdia = *_elemKop;
            break;
        }
        else if(!aurkituta && strcmp(_tmp.nanZbkia, (_zerrenda + 0)->nanZbkia) < 0){
            aurkituta = 1;
            erdia = 0;
            break;
        }
        
        if(strcmp((_zerrenda + erdia)->nanZbkia, _tmp.nanZbkia) == 0){
            printf("woah");
            aurkituta = 1;
            erdia = -1;
        }
        else{
            if(strcmp((_zerrenda + erdia)->nanZbkia, _tmp.nanZbkia) > 0){
                if(strcmp((_zerrenda + erdia - 1)->nanZbkia, _tmp.nanZbkia) < 0){
                    aurkituta = 1;
                }
                else{
                    b = erdia;
                }
            }
            else{
                a = erdia;
            }
        }
    }
    
    return erdia;
}

void posizioanSartu(struct fitxa *_zerrenda, int *_elemKop, struct fitxa _tmp, int _pos){
    
    for(int i = *_elemKop; i>_pos; i--){
        _zerrenda[i] = _zerrenda[i-1];
    }
    _zerrenda[_pos] = _tmp;
    *_elemKop = *_elemKop + 1;
}

void fitxategianSartu(struct fitxa *_zerrenda, int *_elemKop, char *_fitxategiIzena){
     FILE* filePtr;
    
    filePtr = fopen(_fitxategiIzena, "wb");

    if(filePtr != NULL){
        
        for(int i = 0; i<*_elemKop; i++){
            fwrite((_zerrenda + i), sizeof(struct fitxa), 1, filePtr);
        }
    }
    fclose(filePtr);
}

void arrayAskatu(struct fitxa* _zerrenda){
       
    free(_zerrenda);
    
    printf("\nAskatuta!\n");
    fflush(stdout);
}

