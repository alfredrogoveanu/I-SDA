#include <iostream>
#include "queue1.h"
using namespace std;

int main()
{
    int N, X, A, i;
    cout<<"Insert the number of goblins: ";
    cin>>N;
    int aN=N;
    cout<<"Insert the number of goblins that are surrounding Legolas at one time: ";
    cin>>X;
    while (X>N)
        {
            cout<<"The number of goblins that are surrounding Legolas must be less than or equal to "<<N<<"!"<<endl;
            cin>>X;
        }
    Queue <int> goblins;
    Queue <int> index;
    for (i=0; i<N; i++)
        {
            cout<<"Insert the power of goblin no. "<<i<<": ";
            cin>>A;
            goblins.enqueue(A);
            index.enqueue(i);
        }
    Queue <int> auxg;
    Queue <int> auxi;
    while (goblins.isEmpty()!=1)
    {
        int max = -1, mix;
        if (aN<X)
            X=aN;
        for (i=0; i<X; i++)
        {
            int axg = goblins.dequeue();
            int axi = index.dequeue();
            if (max<axg)
                {
                    max=axg;
                    mix=axi;
                }
            auxg.enqueue(axg);
            auxi.enqueue(axi);
        }
        int ai=0;
        while (ai<i)
        {
            int axg = auxg.dequeue();
            int axi = auxi.dequeue();
            if (axi!=mix)
            {
                if (axg>0)
                    goblins.enqueue(axg-1);
                else
                    goblins.enqueue(axg);
                index.enqueue(axi);
            }
            ai++;
        }
        cout<<mix<<" ";
        aN--;
    }
    return 0;
}
