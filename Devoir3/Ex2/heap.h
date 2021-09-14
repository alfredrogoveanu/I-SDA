#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;


class Vrajitor {

    public:
        string nume, prenume, casa;
        int scor;

        Vrajitor ()
        {

        }

        Vrajitor (string n, string p, int s, string c)
        {
            this->nume = n;
            this->prenume = p;
            this->scor = s;
            this->casa = c;
        }

        ~Vrajitor(){}

        void setName (string n)
        {
            this->nume = n;
        }

        void setPrenume (string p)
        {
            this->prenume = p;
        }

        void setScor (int s)
        {
            this->scor = s;
        }

        void setCasa (string c)
        {
            this->casa = c;
        }

        string getName ()
        {
            return nume;
        }

        string getPrenume ()
        {
            return prenume;
        }

        int getScor ()
        {
            return scor;
        }

        string getCasa ()
        {
            return casa;
        }
};

///implementation du MIN HEAP a l'aide du vecteur
template<typename T> class Heap {
    public:
        T *H;
        int currentDim, maxDim;

		///Attention! On commence a l'indice 1.
        Heap(int maxDim) {
            this->maxDim = maxDim;
            H = new T[this->maxDim + 1];
            currentDim = 0;
        }

		///fonction pour inserer un element dans le tas
        void insertElement(Vrajitor x) {
            if (currentDim == maxDim) {
                fprintf(stderr, "Error!\n");
                return;
            }
            currentDim++;
            if (x.getScor()>=0 && x.getScor()<=5000)
                x.setCasa("Hufflepuff");
            if (x.getScor()>5000 && x.getScor()<=20000)
                x.setCasa("Gryffindor");
            if (x.getScor()>20000 && x.getScor()<=50000)
                x.setCasa("Ravenclaw");
            if (x.getScor()>50000)
                x.setCasa("Slytherin");
            H[currentDim] = x;
            filterUp(currentDim);
	}

		///fonction qui retourne la racine, mais ne la supprime pas
		T peek() {
            if (currentDim == 0) {
                fprintf(stderr, "Error!\n");
                T x;
                return x;
            }

            return H[1];
        }


		///fonction appelle par la fonction d'insertion pour maintenir les proprietes du heap
        void filterUp(int i) {
            int parent;
            Vrajitor vaux;

            parent = i / 2;
            while (i > 1 && H[parent].getScor() < H[i].getScor()) {
                vaux = H[parent];
                H[parent] = H[i];
                H[i] = vaux;

                i = parent;
                parent = i / 2;
            }
        }

        int Parent( int CI)
        {
        	int par;
        	par=CI/2;
        	return par;
        }

        int RightChild(int CI)
        {
        	int rc;
        	rc=2*CI+1;
        	return rc;
        }

        int LeftChild(int CI)
        {
        	int lc;
        	lc=2*CI;
        	return lc;
        }

        void printArray()
        {
        	for(int i=1;i<=currentDim;i++)
        		cout<<" "<<H[i].getScor();

        }

        void display()
        {
            int niv = 1;
            cout<<"Niveau 1: ";
            for (int i = 1; i <= currentDim; i++)
            {
                if (i<pow(2,niv))
                    cout<<H[i].getScor()<<" ";
                else
                {
                    niv++;
                    cout<<endl;
                    cout << "Niveau " << niv << ": ";
                    cout << H[i].getScor() << " ";
                }
            }
        }

        void homes()
        {
            int i;
            cout<<"Casa Hufflepuff: ";
            for (i = 1; i <= currentDim; i++)
                if (H[i].getCasa()=="Hufflepuff")
                    cout<<H[i].getPrenume()<<" "<<H[i].getName()<<", "<<H[i].getScor()<<"; ";
            cout<<endl<<"Casa Gryffindor: ";
            for (i = 1; i <= currentDim; i++)
                if (H[i].getCasa()=="Gryffindor")
                    cout<<H[i].getPrenume()<<" "<<H[i].getName()<<", "<<H[i].getScor()<<"; ";
            cout<<endl<<"Casa Ravenclaw: ";
            for (i = 1; i <= currentDim; i++)
                if (H[i].getCasa()=="Ravenclaw")
                    cout<<H[i].getPrenume()<<" "<<H[i].getName()<<", "<<H[i].getScor()<<"; ";
            cout<<endl<<"Casa Slytherin: ";
            for (i = 1; i <= currentDim; i++)
                if (H[i].getCasa()=="Slytherin")
                    cout<<H[i].getPrenume()<<" "<<H[i].getName()<<", "<<H[i].getScor()<<"; ";
        }
};


/*int main() {



}*/










