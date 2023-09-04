#include <iostream>
#include "stablo.h"

using namespace std;

int main()
{
    Stablo S;
    S.umetanje(23);
    S.umetanje(12);
    S.umetanje(35);
    S.umetanje(4);
    S.umetanje(7);
    S.umetanje(52);
    S.umetanje(45);
    S.umetanje(54);
    S.inorder();
    S.brisanje(7);
    S.inorder();
    cout<<endl<<"Nema "<<S.pretraga(7);
    cout<<endl<<"Ima "<<S.pretraga(4);
    cout<<endl<<"Ima "<<S.pretraga(52);
    cout<<endl;
    pair<Stablo, Stablo> p = S.razdvajanje(40);
    Stablo S1 = p.first;
    Stablo S2 = p.second;
    cout<<"S1:"<<endl;
    S1.inorder();
    cout<<"S2:"<<endl;
    S2.inorder();

    return 0;
}

