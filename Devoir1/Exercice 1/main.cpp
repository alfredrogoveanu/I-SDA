#include <iostream>
#include <string.h>
#include "stack.h"
using namespace std;

class Variable
{
    private:
        int valeur;
        char symbole [1];

    public:

        Variable ()
        {

        }

        Variable (int v, char s[1])
        {
            this->valeur=v;
            this->symbole[0]=s[0];
        }

        void setValeur (int v)
        {
            this->valeur=v;
        }

        void setSymbole (char s[1])
        {
            this->symbole[0]=s[0];
        }

        int getValeur ()
        {
            return valeur;
        }

        char getSymbole ()
        {
            return symbole[0];
        }
};


int main()
{
    int i, c=0, n=0, aux, j;
    char equation [100];
    cout<<"Read the expression: ";
    cin.get(equation, 100);
    Stack <char> stack;
    Stack <char> op;
    Stack <char> var;
    char opx [1];
    for (i=strlen(equation)-1; i>=0; i--)
    {
        if (strchr("+-*/", equation[i]))
        {
            op.push(equation[i]);
            c++;
        }
        else
            {
                var.push(equation[i]);
                n++;
            }
    }
    Stack <char> op2=op;
    Variable matrix [100];
    for (i=0; i<c; i++)
    {
        opx[0]=op2.pop();
        matrix[i].setSymbole(opx);
    }
    while (op.isEmpty()!=1 || var.isEmpty()!=1)
    {
        if (op.isEmpty()!=1)
            opx[0] = op.pop();
        if (strchr("*/", opx[0]))
        {
            op2.push(opx[0]);
            while (op.isEmpty()!=1)
            {
                op2.push(op.pop());
            }
            while (op2.isEmpty()!=1)
            {
                stack.push(op2.pop());
                c--;
            }
            opx[0]=' ';
        }
        if (c>0)
            {
                stack.push(opx[0]);
                c--;
            }
        stack.push(var.pop());
    }
    while (stack.isEmpty()!=1)
    {
        op.push(stack.pop());
    }
    Stack <char> copy = op;
    cout<<"Postfix form: ";
    while (op.isEmpty()!=1)
    {
        cout<<op.pop();
    }
    cout<<endl;
    for (i=0; i<n; i++)
        {
            cout<<"Read the coefficient no. "<<i+1<<": ";
            cin>>aux;
            matrix[i].setValeur(aux);
        }
    while (n>1)
    {
        for (i=0; i<n-1; i++)
        {
            if (matrix[i].getSymbole()=='*')
            {
                matrix[i].setValeur(matrix[i].getValeur()*matrix[i+1].getValeur());
                opx[0]=matrix[i+1].getSymbole();
                matrix[i].setSymbole(opx);
                for (j=i+1; j<n-1; j++)
                {
                    matrix[j].setValeur(matrix[j+1].getValeur());
                    opx[0]=matrix[j+1].getSymbole();
                    matrix[j].setSymbole(opx);
                }
                n--;
            }
            if (matrix[i].getSymbole()=='/')
            {
                matrix[i].setValeur(matrix[i].getValeur()/matrix[i+1].getValeur());
                opx[0]=matrix[i+1].getSymbole();
                matrix[i].setSymbole(opx);
                for (j=i+1; j<n-1; j++)
                {
                    matrix[j].setValeur(matrix[j+1].getValeur());
                    opx[0]=matrix[j+1].getSymbole();
                    matrix[j].setSymbole(opx);
                }
                n--;
            }
        }
        for (i=0; i<n-1; i++)
        {
            if (matrix[i].getSymbole()=='+')
            {
                matrix[i].setValeur(matrix[i].getValeur()+matrix[i+1].getValeur());
                opx[0]=matrix[i+1].getSymbole();
                matrix[i].setSymbole(opx);
                for (j=i+1; j<n-1; j++)
                {
                    matrix[j].setValeur(matrix[j+1].getValeur());
                    opx[0]=matrix[j+1].getSymbole();
                    matrix[j].setSymbole(opx);
                }
                n--;
            }
            if (matrix[i].getSymbole()=='-')
            {
                matrix[i].setValeur(matrix[i].getValeur()-matrix[i+1].getValeur());
                opx[0]=matrix[i+1].getSymbole();
                matrix[i].setSymbole(opx);
                for (j=i+1; j<n-1; j++)
                {
                    matrix[j].setValeur(matrix[j+1].getValeur());
                    opx[0]=matrix[j+1].getSymbole();
                    matrix[j].setSymbole(opx);
                }
                n--;
            }
        }
    }
    cout<<"The result of the expression is: "<<matrix[0].getValeur();
    return 0;
}
