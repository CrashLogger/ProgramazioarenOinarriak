#include <stdio.h>
#include <stdlib.h>

void matrizeAskatu(int** _array, int _lerroKop, int _zutabeKop);
int** matrizeSortu(int _lerroKop, int _zutabeKop);
void tamainaEskatu(int *_lerroKop, int *_zutabeKop);
void matrizeBistaratu(int** _array, int _lerroKop, int _zutabeKop);
void matrizeBete(int **_array, int _lerroKop, int _zutabeKop);
void maximoaBilatu(int** _array, int _lerroKop, int _zutabeKop);
void minimoaBilatu(int** _array, int _lerroKop, int _zutabeKop);
void lehenZutabea(int** _array, int _lerroKop, int _zutabeKop);
void azkenLerroa(int** _array, int _lerroKop, int _zutabeKop);
void diagonalaBistaratu(int** _array, int _lerroKop, int _zutabeKop);

int main(int argc, char **argv)
{
	int zutabeKop = 0;
	int lerroKop = 0;
	int aukera = 0;
	
	int** matrizea;
	
	do{
		printf("\n#==================== MENUA ====================#\n");
		printf("\nAukeratu ezazu ekintza bat:\n");
		printf("1\tMxN array bat eratu eta bete\n");
		printf("2\tArraya bistaratu\n");
		printf("3\tElementurik handiena aurkitu\n");
		printf("4\tElementurik txikiena aurkitu\n");
		printf("5\tLehen zutabea bistaratu\n");
		printf("6\tAzken lerroa bistaratu\n");
		printf("7\tDiagonala bistaratu\n");
		printf("8\tIrten\n");
		printf("\n#===============================================#\n");
		fflush(stdout);
		scanf("%d", &aukera);
		switch(aukera){
			case 1:
				//Arraya eratu eta bete
				tamainaEskatu(&lerroKop, &zutabeKop);
				matrizea = matrizeSortu(lerroKop, zutabeKop);
				matrizeBete(matrizea, lerroKop, zutabeKop);
			break;
			case 2:
				//Arraya bistaratu
				matrizeBistaratu(matrizea, lerroKop, zutabeKop);
		
			break;
			case 3:
				maximoaBilatu(matrizea, lerroKop, zutabeKop);
		
			break;
			case 4:
				minimoaBilatu(matrizea, lerroKop, zutabeKop);
			break;
			case 5:
				lehenZutabea(matrizea, lerroKop, zutabeKop);
			break;
			case 6:
				azkenLerroa(matrizea, lerroKop, zutabeKop);
			break;
			case 7:
				diagonalaBistaratu(matrizea, lerroKop, zutabeKop);
			break;
		}
	}while(aukera != 8 && aukera >= 0);	
	matrizeAskatu(matrizea, lerroKop, zutabeKop);
	return 0;
}

void matrizeBete(int **_array, int _lerroKop, int _zutabeKop){
	for(int i = 0; i<_lerroKop; i++){
		for(int j = 0; j<_zutabeKop; j++){
			printf("M(%d,%d) posizioko balioa eman:\n", i+1, j+1);
			fflush(stdout);
			scanf("%d", (*(_array + i)+j));
		}
	}
	
}

void tamainaEskatu(int *_lerroKop, int *_zutabeKop){
	printf("Matrizearen lerro kopurua eman:\n");
	fflush(stdout);
	//__fpurge(stdin);
	scanf("%d", _lerroKop);
	
	printf("Matrizearen zutabe kopurua eman:\n");
	fflush(stdout);
	//__fpurge(stdin);
	scanf("%d", _zutabeKop);
	
	printf("%d x %d-ko Matrizea eratuko da.\n", *_lerroKop, *_zutabeKop);
	fflush(stdout);
}

void matrizeBistaratu(int** _array, int _lerroKop, int _zutabeKop){
	printf("\n");
	fflush(stdout);
	for(int i = 0; i<_lerroKop; i++){
		for(int j = 0; j<_zutabeKop; j++){
			printf("%4d\t", *(*(_array + i)+j));
			fflush(stdout);
		}		
		printf("\n");
		fflush(stdout);
	}
}

int** matrizeSortu(int _lerroKop, int _zutabeKop){
	int **array;
	array = (int**)malloc(_lerroKop * sizeof(int*));
	
	for(int i = 0; i < _lerroKop; i++){
		*(array + i) = (int*)malloc(_zutabeKop * sizeof(int));
		
	}
	return array;
}

void matrizeAskatu(int** _array, int _lerroKop, int _zutabeKop){
	for(int i = 0; i<_lerroKop; i++){
		free(*(_array + i));
	}
	free(_array);
}

void maximoaBilatu(int** _array, int _lerroKop, int _zutabeKop){
	int max = 0;
	int maxLerro = 0;
	int maxZutabe = 0;
	
	for(int i = 0; i<_lerroKop; i++){
		for(int j = 0; j<_zutabeKop; j++){
			if(*(*(_array + i)+j) >= max){
				maxLerro = i+1;
				maxZutabe = j+1;
				max = *(*(_array + i)+j);
			}
		}
	}
	
	printf("\nMaximoa:\nM(%d,%d) posizioan dago eta bere balioa %d da.", maxLerro, maxZutabe, max);
	fflush(stdout);
}

void minimoaBilatu(int** _array, int _lerroKop, int _zutabeKop){
	int min = 999999999;
	int minLerro = 0;
	int minZutabe = 0;
	
	for(int i = 0; i<_lerroKop; i++){
		for(int j = 0; j<_zutabeKop; j++){
			if(*(*(_array + i)+j) <= min){
				minLerro = i+1;
				minZutabe = j+1;
				min = *(*(_array + i)+j);
			}
		}
	}
	printf("\nMinimoa:\nM(%d,%d) posizioan dago eta bere balioa %d da.", minLerro, minZutabe, min);
	fflush(stdout);
}

void lehenZutabea(int** _array, int _lerroKop, int _zutabeKop){
	printf("Lehen zutabea:\n\n");
	fflush(stdout);
	for(int i = 0; i<_zutabeKop; i++){
		printf("%d\n", **(_array + i));
	}
	printf("\n\n");
	fflush(stdout);
}

void azkenLerroa(int** _array, int _lerroKop, int _zutabeKop){
	printf("Azken Lerroa:\n\n");
	fflush(stdout);
	for(int j = 0; j<_zutabeKop; j++){
		printf("%d\t", *(*(_array + _lerroKop-1)+j));
	}
	printf("\n\n");
	fflush(stdout);
}

void diagonalaBistaratu(int** _array, int _lerroKop, int _zutabeKop){
	int tamaina = 0;
	if(_lerroKop < _zutabeKop){
		tamaina = _lerroKop;
	}
	else{
		tamaina = _zutabeKop;
	}

	for(int i = 0; i<tamaina; i++){
		printf("%d\t", *(*(_array + i)+i));
	}
	printf("\n\n");
	fflush(stdout);
}
