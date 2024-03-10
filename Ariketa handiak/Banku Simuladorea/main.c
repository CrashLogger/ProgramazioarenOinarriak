/*
 * Created on October 24, 2022, 7:52 PM
 */ 

#include <stdio.h>
#include <stdlib.h>

#define KONTUZENBAKILUZERA 9

//LEHEN ALDIZ HONEN GARRANTZIA IKUSI DUT: OK
int* arrayBihurtu(int _kontuZenbakia);
int batuketa(int *_array);
int kenketa(int *_array);
int biderketa(int *_array);

int main(int argc, char** argv) {

    int operazioMota = 0;
    unsigned int kontuZenbakia = 0;
    int *kontuZenbakiArraya;
    
    //Operazio mota lortzen
    do{
        printf("#======= Eman operazio motaren zenbakia: ========#\n");
        fflush(stdout);
        __fpurge(stdin);
        scanf("%d",&operazioMota);
    }while(operazioMota < 0 || operazioMota > 3);
        
    //Kontu zenbakia lortzen
    do{
        printf("#========Orain eman zure kontu zenbakia: ========#\n");
        fflush(stdout);
        __fpurge(stdin);
        scanf("\n%d", &kontuZenbakia);
    }while(kontuZenbakia == 0);
    
    //Kontu zenbaki zatitua lortzen, batuketa, kenketa eta biderketak errazteko Array-en bidez
    kontuZenbakiArraya = arrayBihurtu(kontuZenbakia);
    
    int emaitza = 0;
    
    switch(operazioMota){
        case 1:
            emaitza = batuketa(kontuZenbakiArraya);
            printf("\n#==============Operazioaren egoera: =============#\n\n", emaitza, *(kontuZenbakiArraya + KONTUZENBAKILUZERA -1));
            fflush(stdout);
            
            if (emaitza == *(kontuZenbakiArraya + KONTUZENBAKILUZERA -1)){
                printf("\tOperazioa era egokian amaitu da!\n#================================================#");
                fflush(stdout);
            }
            else{
                printf("\t\tOperazioa ezin da aurrera eraman!\nZure banku kontua ez dago operazio mota hau egiteko baimenduta.\nMesedez begiratu sartutako zenbakiak zuzenak diren\n\n");
                fflush(stdout);
            }
        break;
        case 2:
            emaitza = kenketa(kontuZenbakiArraya);
            printf("\n#==============Operazioaren egoera: =============#\n\n", emaitza, *(kontuZenbakiArraya + KONTUZENBAKILUZERA -1));
            fflush(stdout);
            
            if (emaitza == *(kontuZenbakiArraya + KONTUZENBAKILUZERA -1)){
                printf("\tOperazioa era egokian amaitu da!\n#================================================#");
                fflush(stdout);
            }
            else{
                printf("\t\tOperazioa ezin da aurrera eraman!\nZure banku kontua ez dago operazio mota hau egiteko baimenduta.\nMesedez begiratu sartutako zenbakiak zuzenak diren\n\n");
                fflush(stdout);
            }
        break;
        case 3:
            emaitza = biderketa(kontuZenbakiArraya);
            printf("\n#==============Operazioaren egoera: =============#\n\n", emaitza, *(kontuZenbakiArraya + KONTUZENBAKILUZERA -1));
            fflush(stdout);
            
            if (emaitza == *(kontuZenbakiArraya + KONTUZENBAKILUZERA -1)){
                printf("\tOperazioa era egokian amaitu da!\n#================================================#");
                fflush(stdout);
            }
            else{
                printf("\tOperazioa ezin da aurrera eraman!\nZure banku kontua ez dago operazio mota hau egiteko baimenduta.\nMesedez begiratu sartutako zenbakiak zuzenak diren\n\n");
                fflush(stdout);
            }
        break;
        //Ez da inoiz default-era joango aurretiaz bornatu dugulako operazioMota-ren balio tartea.
    }
    free(kontuZenbakiArraya);
    
    return (EXIT_SUCCESS);
}

int* arrayBihurtu(int _kontuZenbakia){
    
    //Arraya dinamikoki sortzen
    int *_array;
    _array = (int*)malloc(KONTUZENBAKILUZERA*sizeof(int));
    //Arrayean zifrak sartzen
    int zenbakia = _kontuZenbakia;
    
    for(int i=KONTUZENBAKILUZERA-1; i>=0; i--){
        int tmp = zenbakia/10;
        int digitoa = zenbakia-(10*tmp);
        zenbakia = tmp;
        
        *(_array + i) = digitoa;
    }
    return(_array);
}

int batuketa(int *_array){
    int emaitza = 0;
    int azkenzifra = 0;
    //Array batean gaudenez eta array-aren tamaina KONTUZENBAKILUZERA denez, 0 tik KONTUZENBAKILUZERA-1 eraino egin behar dugu begizta
    for(int i = 0; i<KONTUZENBAKILUZERA-1; i++){
        emaitza = (*(_array + i)) + emaitza;
    }
    fflush(stdout);
    
    //Azken zifra lortzeko matrizera bihurtzeko funtzio berdina erabili dezakegu!
    int *zifratanBanatuta;
    zifratanBanatuta = arrayBihurtu(emaitza); 
    azkenzifra = *(zifratanBanatuta + KONTUZENBAKILUZERA-1);
    
    //array hau ezin da main-en bidez askatu eta beraz hemen egingo da.
    free(zifratanBanatuta);
    
    return azkenzifra;
}

int kenketa(int *_array){
    int emaitza = (*(_array));
    int azkenzifra = 0;
    //Array batean gaudenez eta array-aren tamaina KONTUZENBAKILUZERA denez, 0 tik KONTUZENBAKILUZERA-1 eraino egin behar dugu begizta
    for(int i = 1; i<KONTUZENBAKILUZERA-1; i++){
        emaitza = (*(_array + i)) - emaitza;
    }
    
    int *zifratanBanatuta;
    zifratanBanatuta = arrayBihurtu(emaitza);
    azkenzifra = *(zifratanBanatuta + KONTUZENBAKILUZERA-1);
    
    //array hau ezin da main-en bidez askatu eta beraz hemen egingo da.
    free(zifratanBanatuta);
    
    return azkenzifra;
}

int biderketa(int *_array){
    int emaitza = 1;
    int azkenzifra = 0;
    //Array batean gaudenez eta array-aren tamaina KONTUZENBAKILUZERA denez, 0 tik KONTUZENBAKILUZERA-1 eraino egin behar dugu begizta
    for(int i = 0; i<KONTUZENBAKILUZERA-1; i++){
        emaitza = (*(_array + i)) * emaitza;
    }
    
    int *zifratanBanatuta;
    zifratanBanatuta = arrayBihurtu(emaitza);
    azkenzifra = *(zifratanBanatuta + KONTUZENBAKILUZERA-1);
    
    //array hau ezin da main-en bidez askatu eta beraz hemen egingo da.
    free(zifratanBanatuta);
    
    return azkenzifra;
}

void arrayAskatu(int *_array){
    free(_array);
}