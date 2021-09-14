#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

template <typename T> struct Noeud {
    T info;
    Noeud <T> *next;
};

template <typename T> class LinkedList {
    public:
        Noeud <T> *pfirst;
        Noeud <T> *plast;

    void add(T x)
    {

        Noeud <T> *paux;

        paux = new Noeud<T>;
        paux->info = x;

        if (pfirst == NULL)
            {
                paux->next = paux;
                pfirst = paux;
            }

        if (plast != NULL)
            plast->next = paux;

        if (pfirst != NULL)
            paux->next = pfirst;

        plast = paux;
    }


    T getInfo (Noeud<T>* p)
    {
        return p->info;
    }

    LinkedList()
    {
        pfirst = plast = NULL;
    }

    void musicalChairs (int n, int r)
    {
        int life, lify = -1;
        n--;
        Noeud <T> *chair = pfirst;
        while (n)
        {
            life = chair->info.getLife();
            if (life>0)
                {
                    n--;
                }
            chair = chair->next;
            life = chair->info.getLife();
            if (life==2)
                life--;
            lify = chair->info.getLife();
            while (lify == 0)
            {
                chair = chair->next;
                lify = chair->info.getLife();
                life = lify;
            }
        }
        string ch = chair->info.getName();
        if (life != 2)
            {
                cout << ch << " was eliminated.";
                if (ch == "Bogdan")
                    cout << " He was eliminated in round no. " << r << "." << endl;
                else
                    cout << endl;
            }

        chair->info.setLife(life-1);
    }

    void winner ()
    {
        Noeud <T> *winner = pfirst;
        int lifes;
        string win;
        while(winner->next != pfirst)
        {
            lifes = winner->info.getLife();
            if (lifes == 1)
                win = winner->info.getName();
            winner = winner->next;
        }
        cout << win << " has won the game! Congratulations!";
    }
};
