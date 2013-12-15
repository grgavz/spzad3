struct red{
    pacijenti pacijent[100];
    int naprijed,nazad;
};

void EnQueueQ(pacijenti p, red *r){
    int n;
    if(r->nazad==99) n=0;
    else n=r->nazad+1;
    r->pacijent[n] = p;
    r->nazad = n;
    }

int AddOne(int n){
    return (n+1)%100;
    }

bool IsEmptyQ(red *r){
    if(AddOne(r->nazad)==r->naprijed) return true;
    else return false;
    }

void DeQueueQ(red *r){
    if(IsEmptyQ(r)) cout << "Red je prazan..." << endl;
    else{
        if(r->naprijed==99) r->naprijed=0;
        else r->naprijed++;
        }
    }

red *InitQ(red *r){
    r = new red;
    r->naprijed = 0;
    r->nazad = 99;
    return r;
    }

pacijenti FrontQ(red *r){
    return r->pacijent[r->naprijed];
    }

