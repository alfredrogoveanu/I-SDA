#include <stdio.h>
#include <iostream>
#define NMAX 100

using namespace std;

class order {

    private:
        int time;
        int duration;

    public:
        order (){};

        order(int t, int d)
        {
            this->time=t;
            this->duration=d;
        }

        int getTime ()
        {
            return time;
        }

        int getDuration ()
        {
            return duration;
        }

        void setTime (int t)
        {
            this->time=t;
        }

        void setDuration (int d)
        {
            this->duration=d;
        }
};

template<typename T> class Queue {
    private:
        T queueArray[NMAX];
        int head, tail;
    public:

        void enqueue(T x) {
            if (tail == NMAX) {
                cout<<"Error 101 - The queue is full!\n";
                return;
            }
            queueArray[tail] = x;
            tail++;
        }

        T dequeue() {
            if (isEmpty()) {
                cout<<"Error 102 - The queue is empty!\n";
                T x;
                return x;
            }
            T x = queueArray[head];
            head++;
            return x;   }

        T peek() {
            if (isEmpty()) {
                cout<<"Error 103 - The queue is empty!\n";
                T x;
                return x;
            }
            return queueArray[head];
        }

        int isEmpty() {
            return (head == tail);
        }

    Queue() {
        head = tail = 0;
    }

        void sort() {
            int i, j, aux1, aux2;
            for (i=head; i<tail-1; i++)
                for (j=i+1; j<tail; j++)
                    if (queueArray[i].getTime()>queueArray[j].getTime())
                        {
                            aux1=queueArray[i].getTime();
                            aux2=queueArray[i].getDuration();
                            queueArray[i].setTime(queueArray[j].getTime());
                            queueArray[i].setDuration(queueArray[j].getDuration());
                            queueArray[j].setTime(aux1);
                            queueArray[j].setDuration(aux2);
                        }

        }
};
