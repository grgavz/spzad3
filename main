#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

struct pacijenti{
    string ime,prezime;
    int Godina;
    char spol;
    int ai,bi,ci,di,ei;
};

#include "polje.h"
//#include "pokazivac.h"

pacijenti *polje;
int generator(){
    srand(time(0));
    int n,i;
    cout << "Broj zapisa (x3): "; cin >> n;
    polje = new pacijenti [n];
    for(i=0;i<n;i++){
        polje[i].ai = rand()%250+50;
        polje[i].bi = rand()%250+50;
        polje[i].ci = rand()%5+1;
        polje[i].di = rand()%4+1;
      ponovi:
		polje[i].ei = rand()%5+1;
		switch(polje[i].ei){
			case 1:
				if(polje[i].ci==3 || polje[i].ci==1)
					goto ponovi;
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				if(polje[i].ci==4)
					goto ponovi;
				break;
			case 5:
				if(polje[i].ci==3 || polje[i].ci==4)
					goto ponovi;
				break;
			}
        }
    cout << endl;
    return n;
    }
void sortiraj(red *r){
    int i;
    pacijenti p;
    red *pom=InitQ(pom),*pom2=InitQ(pom2);
    for(i=1;i<=5;i++){
        while(!IsEmptyQ(r)){
            p = FrontQ(r);
            DeQueueQ(r);
            if(p.ci==i) EnQueueQ(p,pom);
            else EnQueueQ(p,pom2);
            }
        while(!IsEmptyQ(pom2)){
            p = FrontQ(pom2);
            DeQueueQ(pom2);
            EnQueueQ(p,r);
            }
        }
    while(!IsEmptyQ(pom)){
        p = FrontQ(pom);
        DeQueueQ(pom);
        EnQueueQ(p,r);
        }
    }

void dodaj(red *r, int n){
    int i,j,d=0;
    pacijenti p;
    for(i=0;i<n;i++)
        for(j=0;j<3;j++) {
            p.ai = polje[i].ai;
            p.bi = polje[i].bi;
            if((p.spol=='m' && polje[i].ci==3) || (d>6 && polje[i].ci==4)) polje[i].ci = 5;
            p.ci = polje[i].ci;
            p.di = polje[i].di;
            polje[i].ei = rand()%5+1;
            if(polje[i].ei==4 && p.spol=='m') polje[i].ei = 5;
            p.ei = polje[i].ei;
            cout << "Ime paijenta: ";
            cin >> p.ime;
            cout << "Prezime pacijenta: ";
            cin >> p.prezime;
            cout << "Godina rodenja: ";
            cin >> p.Godina;
            cout << "Spol (m/z): ";
            cin >> p.spol;
            EnQueueQ(p,r);
            }
    sortiraj(r);
    red *pomocni = InitQ(pomocni);
    bool zene = false;
    cout << "Zene starije od 25 g koje trebaju na oftalmologiju: " << endl;
    while(!IsEmptyQ(r)){
        p = FrontQ(r);
        DeQueueQ(r);
        EnQueueQ(p,pomocni);
        }
    while(!IsEmptyQ(pomocni)){
        p = FrontQ(pomocni);
        DeQueueQ(pomocni);
        d = 2013 - p.Godina;
        if(d>25 && p.ei==2 && p.spol=='z'){
            cout << p.ime << " " << p.prezime << endl << endl;
            zene = true;
            }
        EnQueueQ(p,r);
        }
    if(!zene) cout << "---PRAZNO---." << endl << endl;
    }

void ispis(red *r){
    pacijenti p;
    red *pomocni = InitQ(pomocni);
    while(!IsEmptyQ(r)){
        p = FrontQ(r);
        cout << p.ime << " " << p.prezime << " --> ";
        switch(p.ci){
            case 1: cout << "hitni slucaj ";
            break;
            case 2: cout << "invalid ";
            break;
            case 3: cout << "trudnica ";
            break;
            case 4: cout << "dijete ";
            break;
            case 5: cout << "pacijent ";
            break;
            }
        cout << " --> ";
        switch(p.di){
            case 1: cout << "pregled ";
            break;
            case 2: cout << "previjanje ";
            break;
            case 3: cout << "recept ";
            break;
            case 4: cout << "uputnica ";
            break;
            }
        cout << "saljemo ga na ";
        switch(p.ei){
            case 1: cout << "odjel obiteljske medicine.";
            break;
            case 2: cout << "oftalmologiju.";
            break;
            case 3: cout << "dermatovenerologiju.";
            break;
            case 4: cout << "ginekologiju.";
            break;
            case 5: cout << "urologiju.";
            break;
            }
        DeQueueQ(r);
        EnQueueQ(p,pomocni);
        cout << endl << endl;
        }
    while(!IsEmptyQ(pomocni)){
        p = FrontQ(pomocni);
        DeQueueQ(pomocni);
        EnQueueQ(p,r);
        }
    }

void brisanje(red *r){
    pacijenti p;
    red *pomocni = InitQ(pomocni);
    bool ima = false;
    int d=0;
    cout << "Invalidi stariji od 50 godina koji su bili na obiteljskoj medicini: " << endl;
    while(!IsEmptyQ(r)){
        p = FrontQ(r);
        DeQueueQ(r);
        EnQueueQ(p,pomocni);
        }
    while(!IsEmptyQ(pomocni)){
        p = FrontQ(pomocni);
        DeQueueQ(pomocni);
        d = 2013 - p.Godina;
        if(d>50 && p.ei==1 && p.ci==2){
            cout << p.ime << " " << p.prezime << endl << endl;
            ima = true;
            }
        else EnQueueQ(p,r);
        }
    if(!ima) cout << "Nema takvih pacijenata." << endl << endl;
    cout << "----------\nCekaonica:\n----------" << endl;
    ispis(r);
    }

red *novi = InitQ(novi);
void brzi_red(red *r,int i){
    pacijenti p;
    if(IsEmptyQ(r)) return;
    else{
        p=FrontQ(r);
        DeQueueQ(r);
        brzi_red(r,++i);
        }
    static int m=int(0.7*i);
    if(i>m) EnQueueQ(p,novi);
    else EnQueueQ(p,r);
    }

void vrati(red *r){
    pacijenti p;
    if(IsEmptyQ(r)) return;
    else{
        p=FrontQ(r);
        DeQueueQ(r);
        vrati(r);
        }
    EnQueueQ(p,r);
    }

int main(){
    srand(time(0));
    rand();
    int odabir,broj;
    red *r = InitQ(r);
    bool alociran = false;
    broj = generator();
    if(broj) alociran = true;

    do{
        cout << "-----IZBORNIK-----" <<endl
             << "1 - Dodaj zapis o pacijentima" << endl
             << "2 - Brisi invalide starije od 50 godina koji trebaju na previjanje" << endl
             << "3 - Generator brojeva (ako treba ponovno)" << endl
             << "4 - Otvori red brzih usluga" << endl
             << "5 - Ispis reda" << endl
             << "0 - Izlaz iz programa" << endl << endl;
        cin >> odabir;
        switch(odabir){
            case 0:
               break;
            case 1:
                dodaj(r,broj);
                break;
            case 2:
                brisanje(r);
                break;
            case 3:
                broj = generator();
                if(broj) alociran = true;
                break;
            case 4:
                brzi_red(r,0);
                vrati(r);
                cout << "------------------\nStanje u brzom redu:\n------------------ " << endl << endl;
                ispis(novi);
                cout << "------------------\nStanje u starom redu:\n------------------ " << endl << endl;
                ispis(r);
                break;
            case 5:
                 ispis(r);
                 break;
            default:
                    cout << "Pogresan unos!!" << endl;
                    break;
            }
    }while(odabir!=0);

    return 0;
    }
