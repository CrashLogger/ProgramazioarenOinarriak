#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define pabilioiKop 5
#define standKop 128
#define pabilioiTamaina 250

//Prototipoen hasiera
struct stand* standZerrendaSortu(int _standKopMax);
struct pabilioi* pabilioiZerrendaSortu(int _pabKopMax);

struct stand standInformazioaEskatu(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda);

int bilatuPos(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda, struct stand _tmp);
int kentzekoElementuaBilatu(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda, struct stand _tmp);

void pabilioiInformazioaBete(struct pabilioi* _pabilioiZerrenda, int _pabilioiKop);
void sartuZerrendan(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda, struct stand _tmp, int _pos);
void standGehitu(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda);
void informazioaBistaratu(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda);
void standKendu(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda);
void tarifaBerriaSartu(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda, int _tarifaBerria, int _pabilioiMod);
void elementuaKendu(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda, int _pos);
void pabilioiTarifa(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda);
//Prototipoen amaiera

struct pabilioi{

    int tarifa;
    int tamaina;

};

struct stand{

    char izena[20];
    int zbki;
    int epea;
    int tamaina;
    int prezioa;

};

//Stand arraya sortu
struct stand* standZerrendaSortu(int _standKopMax){
    struct stand* zerrenda;

    zerrenda = (struct stand*)malloc(_standKopMax * sizeof(struct stand));

    return zerrenda;
}

//Pabilioi arraya sortu
struct pabilioi* pabilioiZerrendaSortu(int _pabKopMax){
    struct pabilioi* zerrenda;

    zerrenda = (struct pabilioi*)malloc(_pabKopMax * sizeof(struct pabilioi));

    return zerrenda;
}

void menua(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda){
    int aukera = 0;
    do{
        printf("\n\nHurrengo aukeretako bat aukeratu:\n");
        printf("\t1 - Stand bat gehitu\n");
        printf("\t2 - Stand bat kendu\n");
        printf("\t3 - Pabilioi baten tarifa aldatu\n");
        printf("\t4 - Stand eta pabilioien informazioa bistaratu\n");

        //Hau errealitatean edozein baliorekin egingo da, 1, 2, 3 eta 4 ez den bitartean.
        printf("\t5 - Programatik irten\n");
        fflush(stdout);
        scanf("%d", &aukera);

        switch(aukera){
        case 1:
            standGehitu(_standKopurua, _pabilioiZerrenda, _standZerrenda);
            break;
        case 2:
            //Stand-aren izena sartu eta bilatuko dugu. Behin aurkituta, horren atzeko stand guztiak pausu bat mugitu aurrera.
            standKendu(_standKopurua, _pabilioiZerrenda, _standZerrenda);
            break;
        case 3:
            pabilioiTarifa(_standKopurua, _pabilioiZerrenda, _standZerrenda);
            break;
        case 4:
            informazioaBistaratu(_standKopurua, _pabilioiZerrenda, _standZerrenda);
            break;
        default:
            break;
        }

    }while(aukera < 5);
}

void standGehitu(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda){

    struct stand tmp;
    int pos;

    //tmp izeneko elementu bat sortuko dugu, hori ondoren arrayean sartuko dugu
    tmp = standInformazioaEskatu(_standKopurua, _pabilioiZerrenda, _standZerrenda);
    pos = bilatuPos(_standKopurua, _pabilioiZerrenda, _standZerrenda, tmp);

    //Posizioa lortuta, bertan sartuko dugu
    sartuZerrendan(_standKopurua, _pabilioiZerrenda, _standZerrenda, tmp, pos);
}

void sartuZerrendan(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda, struct stand _tmp, int _pos){

    //Atzetik aurrera, stand bakoitza pausu bat aurrera mugitu.
    for(int i = *_standKopurua; i>_pos; i--){
        //i-1 ekin egin behar da, atzetik aurrera gaudelako mugitzen!
        _standZerrenda[i] = _standZerrenda[i-1];
    }
    //Posizioan beraz tmp elementua sartu, eta kopuruari +1 egiteaz ez ahaztu!
    _standZerrenda[_pos] = _tmp;
    *_standKopurua = *_standKopurua + 1;
    //printf("Stand Kopurua:%d", *_standKopurua);
    //fflush(stdout);
}

int bilatuPos(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda, struct stand _tmp){

    int hasiera = 0;
    int amaiera = *_standKopurua;
    int pos = 0;
    int aurkituta = 0;

    while(aurkituta != 1){
        //Posizioa bisekzio eran egin daiteke, a+b/2
        pos = (hasiera + amaiera)/2;
        //2. String-a atzerago dago, beraz, tmp atzerago dagoenez, eskumako erdian dago gure posizioa.
        if(strcmp((_standZerrenda + pos)-> izena, _tmp.izena)> 0){
            amaiera = pos;
        }
        //2. String-a aurrerago dago, beraz, tmp aurrerago dagoenez, ezkerreko erdian dago gure posizioa.
        else if(strcmp((_standZerrenda + pos)-> izena, _tmp.izena)< 0){
            hasiera = pos;
        }

        //Hasiera amaieraren balio berdina edo handiagoa bada, gure puntura heldu gara.
        if(hasiera >= (amaiera - 1)){
            aurkituta = 1;
        }
    }

    //tmp-ren izena txikiagoa bada, amaierako balioa itzuliko dugu. tmp-ren izena handiena bada, hasierako balioa itzuliko dugu.
    //aurkituta 1 izan dadin, bi balio horiek berdinak izan behar direnez, edo orden arraroan (hasiera > amaiera) egon behar direnez;
    //honela emaitza zuzena lortzen dugu.

    if(strcmp((_standZerrenda + pos)-> izena, _tmp.izena)< 0){
        return(amaiera);
    }
    else{
        return(hasiera);
    }
}

struct stand standInformazioaEskatu(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda){

    struct stand tmp;
    int pabilioiTarifa = 0;

    do{
        printf("\nZein pabilioitan alokatu nahi duzu?\n");
        fflush(stdout);
        scanf("%d", &tmp.zbki);
    }while(tmp.zbki >= pabilioiKop ||tmp.zbki < 0);


    do{
        printf("\nPabilioi horretan %d m^2 alokatu daitezke.\n", (_pabilioiZerrenda + tmp.zbki)->tamaina); //(_pabilioiZerrenda + tmp.zbki)->tamaina);
        printf("\nZenbat espazio alokatu nahi duzu?\n");
        fflush(stdout);
        scanf("%d", &tmp.tamaina);
    }while(tmp.tamaina > (_pabilioiZerrenda + tmp.zbki)->tamaina);

    do{
        printf("Pabilioietako espazioa gutxienez egun batez alokatu behar da.");
        printf("\nZenbat egunetarako alokatu nahi duzu?\n");
        fflush(stdout);
        scanf("%d", &tmp.epea);
    }while(tmp.epea < 1);

    printf("\nStand-aren izena:\n");
    fflush(stdout);
    //Lehen fgets bufferreko \n-a jateko eginkizuna betetzen du soilik.
    fgets(tmp.izena, sizeof(tmp.izena),stdin);
    fgets(tmp.izena, sizeof(tmp.izena),stdin);
    //String-aren azken karakterea \n bat denez, hori \0 terminator batekin ordezkatuz lerro gehiegi gehitzea ekiditu dezakegu.
    //strlen \0 naturalaren posizioa ematen du!. Bestela, for loop batekin \n-ak bilatu eta ordezkatu.
    tmp.izena[strlen(tmp.izena)-1]='\0';

    //Pabilioiaren tarifa, tamaina eta denborarekin biderkatuko dugu prezio osoa lortzeko.
    pabilioiTarifa = (_pabilioiZerrenda + tmp.zbki)->tarifa;
    tmp.prezioa = pabilioiTarifa*tmp.epea*tmp.tamaina;

    (_pabilioiZerrenda + tmp.zbki)->tamaina = (_pabilioiZerrenda + tmp.zbki)->tamaina - tmp.tamaina;
    printf("Stand-aren prezio osoa %d €-koa izango da.\n\n", tmp.prezioa);
    fflush(stdout);

    return tmp;
};


void standKendu(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda){

    //pos kasu honetak, kendu nahi dugun stand-aren posizioa izango da.
    int pos = 0;
    //ez da oso eraginkorra, baina struct bat erabili dezakegu izena kentzeko.
    struct stand tmp;

    printf("Kendu nahi duzun stand-aren izena eman:\n");
    fflush(stdout);
    fgets(tmp.izena, sizeof(tmp.izena), stdin);
    fgets(tmp.izena, sizeof(tmp.izena), stdin);

    //String-aren azken karakterea \n bat denez, hori \0 terminator batekin ordezkatuz lerro gehiegi gehitzea ekiditu dezakegu.
    //strlen \0 naturalaren posizioa ematen du!. Bestela, for loop batekin \n-ak bilatu eta ordezkatu.
    tmp.izena[strlen(tmp.izena)-1]='\0';

    pos = kentzekoElementuaBilatu(_standKopurua, _pabilioiZerrenda, _standZerrenda, tmp);
    //kenduElementua(_standKopurua, _pabilioiZerrenda, _standZerrenda, pos);
    elementuaKendu(_standKopurua, _pabilioiZerrenda, _standZerrenda, pos);
}

void elementuaKendu(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda, int _pos){

    int espazioHutsa = 0;
    //Stand bat kentzen dugunean, hutsik geratzen den espazioa pabilioiari itzuliko diogu.
    espazioHutsa = (_standZerrenda + _pos)->tamaina;
    (_pabilioiZerrenda + ((_standZerrenda + _pos)->zbki))->tamaina = (_pabilioiZerrenda + ((_standZerrenda + _pos)->zbki))->tamaina + espazioHutsa;

    if(_pos != standKop){

        for(int i = _pos; i<*_standKopurua; i++){
            *(_standZerrenda + i) = *(_standZerrenda + i + 1);
        }
        *_standKopurua = *_standKopurua - 1;
    }
    else{
        //Emandako izena ez badu aurkitzen zerrendan, standKop emango du.
        //Hori ematekotan, hau saltatu.
        return;
    }
}

int kentzekoElementuaBilatu(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda, struct stand _tmp){

    int pos = 0;
    int aurkituta = 0;

    for(int i = 0; i<=*_standKopurua-1; i++){
        printf("\n%s Izeneko elementua Konparatzen\n",(_standZerrenda + i)->izena);
        if(strcmp((_standZerrenda + i)->izena, _tmp.izena)==0){
            pos = i;
            aurkituta = 1;

            printf("%d Posizioko elementua kenduko da!\n",i);
            fflush(stdout);
            return pos;
        }
    }
    if(aurkituta == 0){
        printf("Ez da '%20s' izeneko stand-ik existitzen!\n\n", _tmp.izena);
        fflush(stdout);
        return standKop;
    }
}

void pabilioiTarifa(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda){

    int pabilioiMod = 0;
    int tarifaBerria = 0;

    do{
        printf("\nTarifa modifikatzeko pabilioiaren zenbakia eman:\n");
        fflush(stdout);
        scanf("%d", &pabilioiMod);
    }while(pabilioiMod > pabilioiKop || pabilioiMod < 0);

    do{
        printf("%d Pabilioiaren tarifa berria eman:\n", pabilioiMod);
        fflush(stdout);
        scanf("%d", &tarifaBerria);
    }while(tarifaBerria < 0);

    tarifaBerriaSartu(_standKopurua, _pabilioiZerrenda, _standZerrenda, tarifaBerria, pabilioiMod);
}

void tarifaBerriaSartu(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda, int _tarifaBerria, int _pabilioiMod){

    (_pabilioiZerrenda + _pabilioiMod)->tarifa = _tarifaBerria;

    for(int i = 0; i<=*_standKopurua; i++){
    //printf("%d \t-\t %d", i, (_standZerrenda + i)->zbki == _pabilioiMod);
    //fflush(stdout);

        if((_standZerrenda + i)->zbki == _pabilioiMod){

            (_standZerrenda + i)->prezioa = (_tarifaBerria * (_standZerrenda + i)->tamaina * (_standZerrenda + i)->epea);
        }
    }
}

void informazioaBistaratu(int* _standKopurua, struct pabilioi* _pabilioiZerrenda, struct stand* _standZerrenda){
    printf("\n - - - - - - - - - - - - PABILIOI ZERRENDA: - - - - - - - - - - - - \n");
    fflush(stdout);

    //Taula tituluak politago bihurtzen du.
    printf("\t%12s\t %16s\t %32s\n", "Pab. Zbkia", "Tamaina", "Tarifa (E/(m^2 * egun))");
    fflush(stdout);

    //Pabilioi bakoitzaren informazioa eman.
    for(int i = 0; i<pabilioiKop; i++){
        printf("\t%12d Pabilioia\t %6d m^2 libre\t %24d\n", i, (_pabilioiZerrenda + i)->tamaina, (_pabilioiZerrenda + i)-> tarifa);
        fflush(stdout);
    }

    printf("\n - - - - - - - - - - - - STAND ZERRENDA: - - - - - - - - - - - - \n");
    fflush(stdout);

    //Taula tituluak politago bihurtzen du.
    printf("%20s\t%4s\t%10s\t%10s\t%12s\n", "Izena", "Pab.", "Epea", "Tamaina", "Prezioa");
    fflush(stdout);
    //Stand bakoitzaren informazioa eman.
    for(int i = 0; i<*_standKopurua; i++){
        printf("%20s\t%4d\t%5d egun\t%6d m^2\t%6d euro \n", (_standZerrenda + i)->izena, (_standZerrenda + i)->zbki, (_standZerrenda + i)->epea,(_standZerrenda + i)->tamaina, (_standZerrenda + i)->prezioa);
        fflush(stdout);
    }
}


int main(){
    struct stand* standZerrenda;
    struct pabilioi* pabilioiZerrenda;

    //Stand kopuru maximoa 128-ra ezarriko dugu, baina zenbat stand hartuko ditugun eskuz kontrolatuko dugu.
    int standKopurua = 0;
    standZerrenda = standZerrendaSortu(standKop);
    pabilioiZerrenda = pabilioiZerrendaSortu(pabilioiKop);

    pabilioiInformazioaBete(pabilioiZerrenda, pabilioiKop);


    menua(&standKopurua, pabilioiZerrenda, standZerrenda);

    free(standZerrenda);
    free(pabilioiZerrenda);
    return 0;
}

void pabilioiInformazioaBete(struct pabilioi* _pabilioiZerrenda, int _pabilioiKop){

    for(int i = 0; i<_pabilioiKop; i++){
        int tmpTarifa = 0;
        do{
            printf("%d Pabilioiaren tarifa sartu:\n", i);
            fflush(stdout);
            scanf("%d", &tmpTarifa);
            (_pabilioiZerrenda + i)->tarifa = tmpTarifa;
            (_pabilioiZerrenda + i)->tamaina = pabilioiTamaina;
            //printf("%d\n",(_pabilioiZerrenda + i)->tarifa);
        }while(tmpTarifa < 0);
    }
}
