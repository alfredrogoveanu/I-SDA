#include <iostream>
#include <string.h>
#include "liste.h"
using namespace std;

class Person {
    private:
        string name;
        int age, life;

    public:
        Person ()
        {

        }

        Person (string n, int a, int l)
        {
            this->name = n;
            this->age = a;
            this->life = l;
        }

        ~Person() {}

        void setName (string n)
        {
            this->name = n;
        }

        void setAge (int a)
        {
            this->age = a;
        }

        void setLife (int l)
        {
            this->life = l;
        }

        string getName ()
        {
            return name;
        }

        int getSymbole ()
        {
            return age;
        }

        int getLife ()
        {
            return life;
        }

        void toString()
        {
            cout << name;
        }

};

int main()
{
    int P, cn, a, N, v[100], i, bok=0, lf;
    string na;
    cout << "How many persons are playing this game? ";
    cin >> P;
    while (P <= 1)
    {
        cout << "Bogdan can't play this game alone. He has friends. Please enter a number greater than 1. ";
        cin >> P;
    }
    cn = P;
    LinkedList <Person> guests;
    while (cn)
    {
        cout << "Insert the name of person no. " << (cn - P) * (-1) + 1 << ": ";
        if (bok == 0 && (cn - P) * (-1) + 1 == P)
            {
                na = "Bogdan";
                cout << na << endl;
                lf = 2;
            }
        else
            cin >> na;
        lf = 1;
        if(na == "Bogdan")
            {
                lf = 2;
                bok = 1;
            }
        cout << "Insert the age of person no. " << (cn - P) * (-1) + 1 << ": ";
        cin >> a;
        Person someone(na, a, lf);
        if ((cn - P) * (-1) + 1 == 1)
            guests.add(someone);
        else
            guests.add(someone);
        cn--;
    }
    cn = P;
    cout << endl << "How long should this song be? ";
    cin >> N;
    cout << endl << "Read the times..." << endl;
    while (cn)
    {
        cout << "Insert time no. " << (cn - P) * (-1) + 1 << ": ";
        cin >> v[(cn - P) * (-1) + 1];
        while (v[(cn - P) * (-1) + 1] == 0 || v[(cn - P) * (-1) + 1] > N)
            {
                cout << "Error. Please retry: ";
                cin >> v[(cn - P) * (-1) + 1];
            }
        cn--;
    }
    cout<<endl;
    for (i=1; i<=P; i++)
    {
        guests.musicalChairs(v[i], i);
    }
    cout<<endl;
    guests.winner();
    cout<<endl;
    return 0;
}
