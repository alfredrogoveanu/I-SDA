#include <stdio.h>
#include <iostream>

using namespace std;

class Angajat
{
    public:

        string nume, prenume;
        int sal_bas, sal_tot, xp;

        Angajat () {

        }

        Angajat (string n, string p, int sb, int st, int x)
        {
            this->nume = n;
            this->prenume = p;
            this->sal_bas = sb;
            this->sal_tot = st;
            this->xp = x;
        }

        ~Angajat(){}

        void setName (string n)
        {
            this->nume = n;
        }

        void setPrenume (string p)
        {
            this->prenume = p;
        }

        void setBas (int sb)
        {
            this->sal_bas = sb;
        }

        void setTot (int st)
        {
            this->sal_tot = st;
        }

        void setXP (int x)
        {
            this->xp = x;
        }

        string getNume ()
        {
            return nume;
        }

        string getPrenume ()
        {
            return prenume;
        }

        int getBas ()
        {
            return sal_bas;
        }

        int getTot ()
        {
            return sal_tot;
        }

        int getXP ()
        {
            return xp;
        }
};

template<typename T> class BinarySearchTree {
    public:
        BinarySearchTree<T> *root, *left_son, *right_son, *parent;
        T *pinfo;

        BinarySearchTree() {
            left_son = right_son = NULL;
            root = this;
            pinfo = NULL;
        }

        void setInfo(T info) {
            pinfo = new T;
            *pinfo = info;
        }

        void insert(T x) {
            if (pinfo == NULL)
                setInfo(x);
            else
                insert_rec(x);
        }

        int calculate()
        {
            int s;
            if (left_son != NULL && right_son != NULL)
                {
                    s=10/100*(right_son->calculate())+(10/100*left_son->calculate());
                    (*pinfo).setTot(s);
                }
            if (left_son == NULL && right_son != NULL)
                {
                    s=10/100*(right_son->calculate());
                    (*pinfo).setTot(s);
                }
            if (left_son != NULL && right_son == NULL)
                {
                    s=10/100*(left_son->calculate());
                    (*pinfo).setTot(s);
                }
            if (left_son == NULL && right_son == NULL)
                {
                    s=(*pinfo).getBas();
                    (*pinfo).setTot(s);
                }
        }

        void insert_rec(T x) {
            int next_son;
			if (x.getXP() <= (*pinfo).getXP())
                next_son = 0;
            else
                next_son = 1;

            if (next_son == 0) {  // left son
                if (left_son == NULL) {
                    left_son = new BinarySearchTree<T>;
                    left_son->pinfo = new T;
                    *(left_son->pinfo) = x;
                    left_son->left_son = left_son->right_son = NULL;
                    left_son->parent = this;
                    left_son->root = root;
                } else
                    left_son->insert_rec(x);
            } else { // right son
                if (right_son == NULL) {
                    right_son = new BinarySearchTree<T>;
                    right_son->pinfo = new T;
                    *(right_son->pinfo) = x;
                    right_son->left_son = right_son->right_son = NULL;
                    right_son->parent = this;
                    right_son->root = root;
                } else
                    right_son->insert_rec(x);
            }
        }

		BinarySearchTree<Angajat>* find(int x) {
            BinarySearchTree<Angajat> *rez;

            if (pinfo == NULL)
                return NULL;

            if ((*pinfo).getXP() == x)
                return this;

            if (x <= (*pinfo).getXP()) {
                if (left_son != NULL)
                    return left_son->find(x);
                else
                    return NULL;
            } else {
                if (right_son != NULL)
                    return right_son->find(x);
                else
                    return NULL;
            }
        }

        void removeInfo(T x) {
            BinarySearchTree<T> *t = find(x);
            if (t != NULL)
                t->remove();
        }

		void remove() {
            BinarySearchTree<T> *p;
            T *paux;

            if (left_son == NULL && right_son == NULL) {
                if (parent == NULL) { // this == root
                    delete this->pinfo;
                    root->pinfo = NULL;
                } else {
                    if (parent->left_son == this)
                        parent->left_son = NULL;
                    else
                        parent->right_son = NULL;

                    delete this->pinfo;
                    delete this;
                }
            } else {
                if (left_son != NULL) {
                    p = left_son;
                    while (p->right_son != NULL)
                        p = p->right_son;
                } else { // right_son != NULL
                    p = right_son;
                    while (p->left_son != NULL)
                        p = p->left_son;
                }

                paux = p->pinfo;
                p->pinfo = this->pinfo;
                this->pinfo = paux;
                p->remove();
            }
        }

        void inOrderTraversal() {
            if (left_son != NULL)
                left_son->inOrderTraversal();
           cout<<(*pinfo).getNume()<<" "<<(*pinfo).getPrenume()<<", "<<(*pinfo).getBas()<<", "<<(*pinfo).getTot()<<", "<<(*pinfo).getXP()<<endl;
            if (right_son != NULL)
                right_son->inOrderTraversal();
        }

        void preOrderTraversal() {
         	printf("%d\t", *pinfo);
            if (left_son != NULL)
                left_son->preOrderTraversal();

            if (right_son != NULL)
                right_son->preOrderTraversal();
        }

         void postOrderTraversal() {
            if (left_son != NULL)
                left_son->postOrderTraversal();

            if (right_son != NULL)
                right_son->postOrderTraversal();
           	printf("%d\t", *pinfo);
        }

        void findLowestValue() {
        	BinarySearchTree<T> *currNode=this;

        	while (currNode->left_son != NULL)
        	{
	        	currNode=currNode->left_son;
	        }
	        cout<<*currNode->pinfo;
        }

    int maxHeight() {
        	if (this == NULL)
				return -1;
   			else
  				return max(left_son->maxHeight(), right_son->maxHeight())+1;

        	}

    int max (int x, int y) {
        if (x>y) return x;
            else return y;
    }

    void One (int x)
    {
        if (left_son != NULL)
            left_son->One(x);
        if ((*pinfo).getXP() == x)
            cout<<(*pinfo).getTot()<<" ";
        if (right_son != NULL)
            right_son->One(x);
    }

    int Two (BinarySearchTree<T> *currNode)
    {
        BinarySearchTree<T> *currNodeL=currNode->left_son;
        BinarySearchTree<T> *currNodeR=currNode->right_son;
        if (currNodeL!=0 && currNodeR==NULL)
            return 1+Two(currNodeL);
        if (currNodeL!=0 && currNodeR==NULL)
            return 1+Two(currNodeR);
        if (currNodeL!=0 && currNodeR!=0)
            return 0+Two(currNodeL);
        if (currNodeL==NULL && currNodeR==NULL)
            return 0;
    }

    void Three (int y, int z)
    {
      /*  BinarySearchTree<Angajat> *a1 = find(y);
        BinarySearchTree<Angajat> *a2 = find(z);
        cout<<a2->left_son.getXP();

        Ideea era ca incercam sa ii localizez pe y si z si apoi
        sa urc treptat pana ajungeam la un sef comun.

        O alta solutie era ca sa
    */}


};




