#ifndef STABLO_H
#define STABLO_H

#include<ctime>
#include<iostream>
#include<utility>

using namespace std;

class Stablo{
private:
    struct Cvor{
        int element;
        int prioritet;
        Cvor *ld, *dd;

        Cvor(){}
        Cvor(int element){
            this->element = element;
            this->prioritet = rand() % 100;
            this->ld = this->dd = nullptr;
        }
        Cvor(int element, int prioritet){
            this->element = element;
            this->prioritet = prioritet;
            this->ld = this->dd = nullptr;
        }
    };

    Cvor *korijen;

    bool pretragaRek(int kljuc, Cvor* cvor);
    void rotirajD(Cvor* &cvor);
    void rotirajL(Cvor* &cvor);
    void umetanjeRek(int kljuc, Cvor* &cvor);
    void brisanjeRek(int kljuc, Cvor* &cvor);
    void umetanje2(int kljuc, int prioritet, Cvor* &cvor);

    void inorderRek(Cvor* cvor);

public:
    Stablo():korijen(nullptr){}

    bool pretraga(int kljuc) { pretragaRek(kljuc, korijen); }
    void umetanje(int kljuc) { umetanjeRek(kljuc, korijen); }
    void brisanje(int kljuc) { brisanjeRek(kljuc, korijen); }
    pair<Stablo, Stablo> razdvajanje(int kljuc);

    void inorder(){inorderRek(korijen);};
};
#endif // STABLO_H
