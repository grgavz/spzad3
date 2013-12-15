struct podaci{
    pacijenti pacijent;
    podaci *sljedeci;
};

struct red{
    podaci *naprijed,*nazad;
};

void EnQueueQ(pacijenti p, red *r){
    podaci *novi = new podaci;
    novi->pacijent = p;
    novi->sljedeci = NULL;
    r->nazad->sljedeci = novi;
    r->nazad = novi;
    }

void DeQueueQ(red *r){
    podaci *brisi = r->naprijed;
    r->naprijed = r->naprijed->sljedeci;
    delete brisi;
    }

red *InitQ(red *r){
    r = new red;
    podaci *novi = new podaci;
    novi->sljedeci = NULL;
    r->naprijed = novi;
    r->nazad = novi;
    return r;
    }

bool IsEmptyQ(red *r){
    return r->nazad==r->naprijed;
    }

pacijenti FrontQ(red *r){
    if(IsEmptyQ(r)) cout << "Red je prazan..." << endl;
    else return r->naprijed->sljedeci->pacijent;
    }
