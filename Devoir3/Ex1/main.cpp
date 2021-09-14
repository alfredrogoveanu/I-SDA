#include <iostream>
#include "bst.h"
using namespace std;

int main()
{
    BinarySearchTree<Angajat> *r = new BinarySearchTree<Angajat>;
    Angajat a1 ("Nume1", "Prenume1", 4000, 4000, 7);
    Angajat a2 ("Nume2", "Prenume2", 3000, 3000, 4);
    Angajat a3 ("Nume3", "Prenume3", 3000, 3000, 12);
    Angajat a4 ("Nume4", "Prenume4", 2000, 2000, 2);
    Angajat a5 ("Nume5", "Prenume5", 2000, 2000, 6);
    Angajat a6 ("Nume6", "Prenume6", 2000, 2000, 9);
    Angajat a7 ("Nume7", "Prenume7", 2000, 2000, 19);
    Angajat a8 ("Nume8", "Prenume8", 1000, 1000, 3);
    Angajat a9 ("Nume9", "Prenume9", 1000, 1000, 5);
    Angajat a10 ("Nume10", "Prenume10", 1000, 1000, 8);
    Angajat a11 ("Nume11", "Prenume11", 1000, 1000, 11);
    Angajat a12 ("Nume12", "Prenume12", 1000, 1000, 15);
    Angajat a13 ("Nume13", "Prenume13", 1000, 1000, 20);


    r->insert(a1);
    r->insert(a2);
    r->insert(a3);
    r->insert(a4);
    r->insert(a5);
    r->insert(a6);
    r->insert(a7);
    r->insert(a8);
    r->insert(a9);
    r->insert(a10);
    r->insert(a11);
    r->insert(a12);
    r->insert(a13);
    r->calculate();
    r->inOrderTraversal();

    int x, y, z;
    cout<<endl<<"Introduceti o instructiune: ";
    cin>>x;

    if (x==1){
        cin>>y;
        r->One(y);
    }


    if (x==2){
        y=r->Two(r);
        if (y==0)
            cout<<"Arbore complet.";
        else
            cout<<"Arbore incomplet.";
    }

    if (x==3) {
        cin>>y>>z;
        r->Three(y, z);
    }
    return 0;
}
