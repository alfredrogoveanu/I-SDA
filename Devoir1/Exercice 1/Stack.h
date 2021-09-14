#include <iostream>
using namespace std;
#define NMAX 100

template<typename T>
class Stack {
    private:
        T stackArray[NMAX];
        int topLevel;

    public:
        void push(T x)
		 {
            if (topLevel >= NMAX - 1)
            {
                return;
            }
            stackArray[++topLevel] = x;
        }

      int isEmpty()
        {
            return (topLevel < 0);
        }

     T pop()
     {
       if (isEmpty())
        {
            T x;
            return x;
        }
        return stackArray[topLevel--];
    }

    T peek()
    {
	    if (isEmpty())
        {
            cout<<"The stack is empty! \n";
            T x;
            return x;
        }
        return stackArray[topLevel];
}

    Stack()
    {
        topLevel = -1;
    }

    ~Stack() {}
};




