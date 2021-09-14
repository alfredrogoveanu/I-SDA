#include <iostream>
#include "queue1.h"

using namespace std;



int main()
{
    int N, T, i, d, t, C=0, max=0;
    cout<<"Insert the number of orders: ";
    cin>>N;
    cout<<"Insert the closing time: ";
    cin>>T;
    Queue <order> list;
    Queue <int> index;
    for (i=0; i<N; i++)
    {
        cout<<"Insert the time when the client "<<i<<" has arrived: ";
        cin>>t;
        cout<<"Insert the duration for preparing the dish no. "<<i<<": ";
        cin>>d;
        order ord(t, d);
        list.enqueue(ord);
        index.enqueue(i+1);
    }
    list.sort();
    int S=0;
    while (list.isEmpty()!=1)
    {
        if (list.peek().getDuration()>max)
            max=list.peek().getDuration();
        if (list.peek().getTime()-S>0)
            {
                cout<<"The chef takes a break between "<<S<<" and "<<list.peek().getTime()<<"."<<endl;
                S=list.peek().getTime();
            }
        cout<<"Order "<<index.peek()<<": Expected completion time = "<<list.peek().getTime()+list.peek().getDuration()<<", actual completion time = "<<S+list.peek().getDuration()<<endl;
        S+=list.peek().getDuration();
        C+=list.peek().getDuration();
        list.dequeue();
        index.dequeue();
    }
    if (S>T)
        cout<<"There are orders that remained unfinished. Come back tomorrow!"<<endl;
    else
        cout<<"All the orders were finished in time."<<endl;
    cout<<"The longest order took "<<max<<" units of time to prepare."<<endl;
    cout<<"The total time the chef has worked is "<<C<<".";
    return 0;
}
