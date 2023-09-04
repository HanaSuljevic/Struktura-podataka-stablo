#include "stablo.h"
#include<utility>

bool Stablo::pretragaRek(int kljuc, Cvor* cvor){
    if(cvor == nullptr)
    return false;
    if(cvor->element == kljuc)
        return true;
    if(kljuc < cvor->element)
        return pretragaRek(kljuc, cvor->ld);
    return pretragaRek(kljuc, cvor->dd);
}

void Stablo::rotirajD(Cvor* &cvor){
    Cvor* L = cvor->ld;
    Cvor* Y = cvor->ld->dd;

    L->dd = cvor;
    cvor->ld = Y;

    cvor = L;
}

void Stablo::rotirajL(Cvor* &cvor){
    Cvor* D = cvor->dd;
    Cvor* X = cvor->dd->ld;

    D->ld = cvor;
    cvor->dd = X;

    cvor = D;
}

void Stablo::umetanjeRek(int kljuc, Cvor* &cvor){
    if(cvor == nullptr){
        cvor = new Cvor(kljuc);
        return;
    }
    if(kljuc > cvor->element){
        umetanjeRek(kljuc, cvor->dd);
        if (cvor->dd != nullptr && cvor->dd->prioritet > cvor->prioritet) {
            rotirajL(cvor);
        }
    }
    else {
        umetanjeRek(kljuc, cvor->ld);
        if(cvor->ld != nullptr && cvor->ld->prioritet > cvor->prioritet){
            rotirajD(cvor);
        }
    }
}

void Stablo::brisanjeRek(int kljuc, Cvor* &cvor){
    if(cvor == nullptr)
        return;

    if(kljuc > cvor->element)
        brisanjeRek(kljuc, cvor->dd);
    else if(kljuc < cvor->element)
        brisanjeRek(kljuc, cvor->ld);
    else{
        if(cvor->ld == nullptr && cvor->dd == nullptr){
            delete cvor;
            cvor = nullptr;
        }
        else if(cvor->ld && cvor->dd){
            if(cvor->ld->prioritet < cvor->dd->prioritet){
            rotirajL(cvor);
            brisanjeRek(kljuc, cvor->ld);
            }
            else {
                rotirajD(cvor);
                brisanjeRek(kljuc, cvor->dd);
            }
        }
        else {
            Cvor *dijete;
            Cvor *trenutno = cvor;

            if(cvor->ld != nullptr)
                dijete = cvor->ld;
            else
                dijete = cvor->dd;

            cvor = dijete;
            delete trenutno;
        }
    }
}

void Stablo::umetanje2(int kljuc, int prioritet, Cvor* &cvor){
    if(cvor == nullptr){
        cvor = new Cvor(kljuc, prioritet);
        return;
    }
    if(kljuc > cvor->element){
        umetanje2(kljuc, prioritet, cvor->dd);
        if (cvor->dd != nullptr && cvor->dd->prioritet > cvor->prioritet) {
            rotirajL(cvor);
        }
    }
    else {
        umetanje2(kljuc, prioritet, cvor->ld);
        if(cvor->ld != nullptr && cvor->ld->prioritet > cvor->prioritet){
            rotirajD(cvor);
        }
    }
}

pair<Stablo, Stablo> Stablo::razdvajanje(int kljuc){
    this->umetanje2(kljuc, INT_MAX, this->korijen);
    Stablo S1, S2;
    S1.korijen = this->korijen->ld;
    S2.korijen = this->korijen->dd;

    this->korijen->ld = nullptr;
    this->korijen->dd = nullptr;
    delete this->korijen;
    this->korijen = nullptr;

    return make_pair(S1, S2);
}

void Stablo::inorderRek(Cvor* cvor)
{
    if (cvor)
    {
        inorderRek(cvor->ld);
        cout << "element: "<< cvor->element << " | prioritet: "
            << cvor->prioritet;
        if (cvor->ld)
            cout << " | lijevo dijete: " << cvor->ld->element;
        if (cvor->dd)
            cout << " | desno dijete: " << cvor->dd->element;
        cout << endl;
        inorderRek(cvor->dd);
    }
}


