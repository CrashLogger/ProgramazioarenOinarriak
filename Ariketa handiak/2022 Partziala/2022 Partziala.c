/*
 * Erlantz Alonso Santamarina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMAINAMAX 128
#define FITXA2 "FITXATEGIA.DAT"
#define FITXAIZENA "DEKODIFIKATU.DAT"

//Prototipoak
struct fitxa* arraySortu(int _tamaina);
void menua(struct fitxa *_zerrenda, int *_elemKop);
void elementuaSartu(struct fitxa *_zerrenda, int *_elemKop);
void nanEskatu(struct fitxa *_tmp);
int posizioaBilatu(struct fitxa *_zerrenda, int *_elemKop, struct fitxa _tmp);
int bilaketaBitarra(struct fitxa *_zerrenda, int _a, int _b, int _aurrekoErdia, struct fitxa _target);
void kodeaEskatu(struct fitxa *_tmp);
int zenbakiaEskatu(void);
void posizioanSartu(struct fitxa *_zerrenda, int *_elemKop, struct fitxa _tmp, int _pos);
void fitxategiaIrakurri(struct fitxa *_zerrenda, int *_elemKop, char *_fitxaIzena, int _modua);
void fitxategiraIdatzi(struct fitxa *_zerrenda, int *_elemKop, char *_fitxaIzena);
unsigned char* byteArraySortu(int _tamaina);
void byteIrakurri(unsigned char *_zerrenda, int *_elemKop, char *_fitxaIzena);
void byteMugitu(unsigned char *_zerrenda, int *_elemKop);
void byteIdatzi(unsigned char *_zerrenda, int *_elemKop, char *_fitxaIzena);

struct fitxa{
    //Azken karaktere extra behar dugu '\0' gordetzeko.
    //Struct bakoitza 16 byte okupatzen ditu beraz (9 + 3 + 4).
    char nan[9];
    char kodea[3];
    int zenbakia;
};

int main(int argc, char** argv) {

    struct fitxa* zerrenda;
    int elemKop = 0;
    zerrenda = arraySortu(TAMAINAMAX);
    
    kodifikatu(FITXA2, FITXAIZENA);
    
    fitxategiaIrakurri(zerrenda, &elemKop, FITXAIZENA, 0);
    
    menua(zerrenda, &elemKop);
    free(zerrenda);
    
    kodifikatu(FITXAIZENA, FITXA2);
    
    return (EXIT_SUCCESS);
}

struct fitxa* arraySortu(int _tamaina){
    
    struct fitxa *tmp;
    tmp = (struct fitxa*)malloc(_tamaina * sizeof(struct fitxa));
    return tmp;
    
}

void menua(struct fitxa *_zerrenda, int *_elemKop){
    
    int aukera = 0;
    
    do{
        
        printf("\n\nAukerak:\n\t0. Programatik irten\n\t1. Elementu berria sartu\n\t2.Elementua aldatu\n\t3. Fitxategia bistaratu\n\n");
        fflush(stdout);
        
        __fpurge(stdin);
        scanf("%d", &aukera);
        
        switch(aukera){
            case 0:
                return;
            case 1:
                elementuaSartu(_zerrenda, _elemKop);
                break;
            case 2:
                elementuaAldatu(_zerrenda, _elemKop);
                break;
            case 3:
                fitxategiaIrakurri(_zerrenda, _elemKop, FITXAIZENA, 1);
                break;
            case 4:
                //Debugeatzeko, arraya ikusi nahi badut.
                for(int i = 0; i<*_elemKop; i++){
                    printf("%s\t%s\t%d\n", (_zerrenda + i)->nan, (_zerrenda + i)->kodea, (_zerrenda + i)->zenbakia);
                    fflush(stdout);
                }
                break;
            default:
                printf("Mesedez, 0 eta 3 arteko zenbakia eman!\n"); 
                break;
        }
        
    }while(aukera >= 0);   
}

void elementuaSartu(struct fitxa *_zerrenda, int *_elemKop){
 
    /*
     NAN Lortu                              VV
     Posizioa bilatu                        VV
     Existitzen bada konprobatu             VV
        Ez badago, beste datuak eskatu      VV
        Sartu posizioan                     VV
        Fitxategia eguneratu                VV       
     */
    
    struct fitxa tmp;
    int pos = 0;
    
    
    nanEskatu(&tmp);
    //printf("NAN: %s\n", tmp.nan);
    //fflush(stdout);
    
    pos = posizioaBilatu(_zerrenda, _elemKop, tmp);
    //printf("POS: %d\n", pos);
    //fflush(stdout);
    
    if(strcmp((_zerrenda + pos)->nan, tmp.nan)!=0){
        kodeaEskatu(&tmp);
        //printf("KODEA: %s\n", tmp.kodea);
        //fflush(stdout);
        
        tmp.zenbakia = zenbakiaEskatu();
        //printf("ZBKIA: %d\n", tmp.zenbakia);
        //fflush(stdout);
        
        posizioanSartu(_zerrenda, _elemKop, tmp, pos);
        fitxategiraIdatzi(_zerrenda, _elemKop, FITXAIZENA);
    }
    else{
        printf("NAN horretarako badugu elementu bat gordeta dago jada!\n");
        fflush(stdout);
    }
}

void nanEskatu(struct fitxa *_tmp){
    
    printf("Eman zure NAN zenbakia (letrarik ez!):\n");
    fflush(stdout);
    
    __fpurge(stdin);
    fgets((_tmp)->nan, sizeof((_tmp)->nan), stdin);
}

int posizioaBilatu(struct fitxa *_zerrenda, int *_elemKop, struct fitxa _tmp){
    
    int a = 0;
    int b = *_elemKop;
    int pos = 0;

    pos = bilaketaBitarra(_zerrenda, a, b, -1, _tmp);
    
    return pos;
}

int bilaketaBitarra(struct fitxa *_zerrenda, int _a, int _b, int _aurrekoErdia, struct fitxa _target){
    
    int erdia = ((_a + _b)/2);
    
    //printf("ERDIA:%d\n", erdia);
    //fflush(stdout);
    
    if(erdia == _aurrekoErdia){
        return(erdia);
    }

    if(_b < 2 && strcmp(_target.nan, (_zerrenda + _b)->nan)>0){
        return(_b);
    }
    
    if(strcmp(_target.nan, (_zerrenda + _a)->nan)<0){
        return(_a);
    }
    
    //printf("%s eta %s konparatzen.\n", (_zerrenda + erdia)->nan, _target.nan);
    //fflush(stdout);
    if(strcmp((_zerrenda + erdia)->nan, _target.nan)>=0){
        if(strcmp((_zerrenda + erdia -1)->nan, _target.nan)<0){
            return(erdia);
        }
        else{
            return(bilaketaBitarra(_zerrenda, _a, erdia, erdia, _target));
        }
    }
    
    if(strcmp((_zerrenda + erdia)->nan, _target.nan)<0){
        return(bilaketaBitarra(_zerrenda, erdia, _b, erdia, _target));
    }
}

void kodeaEskatu(struct fitxa *_tmp){
    
    printf("Eman zure 2 letrako kodea:\n");
    fflush(stdout);
    
    __fpurge(stdin);
    fgets((_tmp)->kodea, sizeof((_tmp)->kodea), stdin);
}

int zenbakiaEskatu(void){
    
    int zenbakia = 0;
    printf("Eman zure zenbakia:\n");
    fflush(stdout);
    
    __fpurge(stdin);
    scanf("%d", &zenbakia);
    
    return zenbakia;
}

void posizioanSartu(struct fitxa *_zerrenda, int *_elemKop, struct fitxa _tmp, int _pos){
    
    for(int i = *_elemKop; i>_pos; i--){
        *(_zerrenda + i) = *(_zerrenda + i - 1);
    }
    *(_zerrenda + _pos) = _tmp;
    *_elemKop = *_elemKop + 1; 
}

void fitxategiraIdatzi(struct fitxa *_zerrenda, int *_elemKop, char *_fitxaIzena){
    
    FILE* filePtr = (FILE*)NULL;
    filePtr = fopen(_fitxaIzena, "wb");
    
    if(filePtr != (FILE*)NULL){
        for(int i = 0; i<*_elemKop; i++){
            fwrite((_zerrenda + i), sizeof(struct fitxa), 1, filePtr);
        }
        fclose(filePtr);
    }   
    else{
        printf("Fitxategia ezin da aldatu momentu honetan.\n");
        fflush(stdout);
    }
}

void fitxategiaIrakurri(struct fitxa *_zerrenda, int *_elemKop, char *_fitxaIzena, int _modua){
    
    FILE* filePtr = (FILE*)NULL;
    filePtr = fopen(_fitxaIzena, "rb");
    
    struct fitxa buffer;
    
    if(_modua){
        printf("***********************************************************************************************************\n");
        fflush(stdout);
    }
    
    if(filePtr != (FILE*)NULL){
        while(fread(&buffer, sizeof(struct fitxa), 1, filePtr)){
            if(!_modua){
                *(_zerrenda + *_elemKop) = buffer;
                *_elemKop = *_elemKop + 1;
                
                printf("%d elementu irakurrita.",*_elemKop);
                fflush(stdout);
            }
            else{
                printf("%8s\t\t%2s\t\t%d\n",buffer.nan, buffer.kodea, buffer.zenbakia);
                fflush(stdout);
            }
        }
    }
    else{
        printf("Fitxategia ezin da aldatu momentu honetan, edo ez da existitzen.\n");
        fflush(stdout);
    }
    
    if(_modua){
        printf("***********************************************************************************************************\n");
        fflush(stdout);
    }
}

void elementuaAldatu(struct fitxa *_zerrenda, int *_elemKop){

    struct fitxa tmp;
    int pos = 0;
    
    
    nanEskatu(&tmp);
    //printf("NAN: %s\n", tmp.nan);
    //fflush(stdout);
    
    pos = posizioaBilatu(_zerrenda, _elemKop, tmp);
    //printf("POS: %d\n", pos);
    //fflush(stdout);
    
    if(strcmp((_zerrenda + pos)->nan, tmp.nan)==0){
        kodeaEskatu(&tmp);
        //printf("KODEA: %s\n", tmp.kodea);
        //fflush(stdout);
        
        tmp.zenbakia = zenbakiaEskatu();
        //printf("ZBKIA: %d\n", tmp.zenbakia);
        //fflush(stdout);
        
        *(_zerrenda + pos) = tmp;
        fitxategiraIdatzi(_zerrenda, _elemKop, FITXAIZENA);
    }
    else{
        printf("NAN horretarako ez dugu informaziorik!\n");
        fflush(stdout);
    }
}

void kodifikatu(char *_sourceIzena, char *_targetIzena){
    
    unsigned char* charZerrenda;
    int elemKop = 0;
    
    charZerrenda = byteArraySortu(TAMAINAMAX * 16);
    
    byteIrakurri(charZerrenda, &elemKop, _sourceIzena);
    //byteIrakurri(charZerrenda, )
    
    byteMugitu(charZerrenda, &elemKop);
    
    byteIdatzi(charZerrenda, &elemKop, _targetIzena);
    
    free(charZerrenda);
    
}

unsigned char* byteArraySortu(int _tamaina){
    unsigned char* tmp;
    tmp = (unsigned char*)malloc(_tamaina * sizeof(unsigned char));
    return tmp;
}

void byteIrakurri(unsigned char *_zerrenda, int *_elemKop, char *_fitxaIzena){
    
    FILE* filePtr = (FILE*)NULL;
    filePtr = fopen(_fitxaIzena, "rb");

    unsigned char buffer;
    
    if(filePtr != (FILE*)NULL){
        while(fread(&buffer, sizeof(unsigned char), 1, filePtr)){
            *(_zerrenda + *_elemKop) = buffer;
            *_elemKop = *_elemKop + 1;
            
            printf("%d elementu irakurrita: %c\n", *_elemKop, buffer);
            fflush(stdout);
        }
        fclose(filePtr);
    }
    else{
        printf("Fitxategia ezin da aldatu momentu honetan, edo ez da existitzen.\n");
        fflush(stdout);
    }
}

void byteMugitu(unsigned char *_zerrenda, int *_elemKop){
    
    unsigned char tmp = 0;
    for(int i = 0; i<*_elemKop; i = i+4){
        printf("SARRERA: %c %c %c %c\n", *(_zerrenda + i),*(_zerrenda + i + 1), *(_zerrenda + i +2), *(_zerrenda + i + 3));
        fflush(stdout);
        
        tmp = *(_zerrenda + i);
        *(_zerrenda + i) = *(_zerrenda + i + 2);
        *(_zerrenda + i + 2) = tmp;
        
        tmp = *(_zerrenda + i + 1);
        *(_zerrenda + i + 1) = *(_zerrenda + i + 3);
        *(_zerrenda + i + 3) = tmp;
        
        printf("EMAITZA: %c %c %c %c\n", *(_zerrenda + i),*(_zerrenda + i + 1), *(_zerrenda + i +2), *(_zerrenda + i + 3));
        fflush(stdout);
    }
}

void byteIdatzi(unsigned char *_zerrenda, int *_elemKop, char *_fitxaIzena){
    
    FILE* filePtr = (FILE*)NULL;
    filePtr = fopen(_fitxaIzena, "wb");
    
    if(filePtr != (FILE*)NULL){
        for(int i = 0; i<*_elemKop; i++){
            fwrite((_zerrenda + i), sizeof(unsigned char), 1, filePtr);
        }
        fclose(filePtr);
    }   
    else{
        printf("Fitxategia ezin da aldatu momentu honetan.\n");
        fflush(stdout);
    }
}