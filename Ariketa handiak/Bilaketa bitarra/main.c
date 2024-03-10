
#include <stdio.h>
#include <stdlib.h>

/*
void lortuEdukiera(int* edukiera);
*/
int* arraySortu(int _edukiera);
void arrayBistaratu(int* _array, int _edukiera);

int main(int argc, char** argv) {
    int edukiera;
    int target = 3;    
    int pos = 0;
    
    int* array;
    
    edukiera = 200;
    
    array = arraySortu(edukiera);
    arrayBete(array, edukiera);
    //arrayBistaratu(array, edukiera);
    
    posizioaBilatu(array, edukiera, 69);
       
    return (EXIT_SUCCESS);
}

int posizioaBilatu(int* _array, int _edukiera, int _target){
    
    int pos = 0;
    int aurkituta = 0;

    int a, b, c, tartea;
    a = 0;
    b = _edukiera-1;
    pos = (a+b)/2;

    printf("(%d, %d) tartean dago %d        Tartea: %d \n", *(_array + a), *(_array + b), _target, tartea);
    
    while(!aurkituta){
        tartea = b-a;
        if(_target < *(_array + pos)){
            
            b=pos;
            pos = (a+b)/2;
            tartea = b-a;
            /*
            b = b/2;
            printf("A\n");
            fflush(stdout);
            */
        }
        else if(_target > *(_array + pos)){
            a = pos;
            pos = (a+b)/2;
            tartea = b-a;
            /*
            a = a+(b/2);
            printf("B\n");
            fflush(stdout);
            */
        }
        
        if(tartea <= 1){
            aurkituta = 1;
        }
        printf("(%d, %d) tartean dago %d\t\tTartea: %d\t\tPosizioa:%d\n", *(_array + a), *(_array + b), _target, tartea, pos);
    } 
    
    return pos;
}

/*
void lortuEdukiera(int* _edukiera){
    printf("Eman arrayaren edukiera:\n");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d", _edukiera);
}
*/

int* arraySortu(int _edukiera){
    int* array;
    array = (int*)malloc(_edukiera * sizeof(int));
    return array;
    
}

void arrayBete(int* _array, int _edukiera){
    for(int i = 0; i<_edukiera; i++){
        *(_array + i) = i*2;
    }
}

void arrayBistaratu(int* _array, int _edukiera){
    for(int i = 0; i<_edukiera; i++){
        printf("%d\n", *(_array + i));
        fflush(stdout);
    }
}

