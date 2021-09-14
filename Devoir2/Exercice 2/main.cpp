#include <iostream>

using namespace std;
template<typename TnodeInfo, typename TedgeInfo>
class Graph {
    public:
        int N;
        int **A;
        int *D,*S,*T;

        Graph(int numNodes) {
            int i, j;

            N = numNodes;

            A = new int*[N];
            D = new int[N];
            S = new int[N];
            T = new int[N];

            for (i = 1; i <= N; i++)
                {
                    A[i] = new int[N];
                }

            for (i = 1; i <= N; i++)
                {
                    D[i] = S[i] = T[i] = 0;
                    for (j = 1; j <= N; j++)
                        A[i][j] = -1;
                }
        }

        void addEdge(int i, int j, int profit) {
            A[i][j] = profit;
        }

        ~Graph() {
            int i;
            for (i = 1; i <= N; i++) {
                delete A[i];
            }
            delete A;
        }

        void way (int i)
        {
            if (T[i]) way(T[i]);
            if (i == N)
                cout << i;
            else
                cout << i << ", ";
        }

        void profit ()
        {
            int max, i, j, poz = 0;
            S[1] = 1;
            for (i = 1; i <= N; i++)
            {
                D[i] = A[1][i];
                if (i != 1)
                    if (D[i] > 0)
                        T[i] = 1;
            }
            for (i = 1; i <= N - 1; i++)
            {
                max = 0;
                for (j = 1; j <= N; j++)
                    if (S[j] == 0)
                        if (D[j] > max)
                            {
                                max = D[j];
                                poz = j;
                            }
                S[poz] = 1;
                for (j = 1; j <= N; j++)
                    if (S[j] == 0)
                        if (D[j] < D[poz] + A[poz][j])
                            {
                                D[j] = D[poz] + A[poz][j];
                                T[j] = poz;
                            }
            }
            for (i = 1; i <= N; i++)
                if (i == N)
                    if(T[i])
                        {
                            cout << "The maximum profit from port 1 to " << i << " is " << D[i] << "." << endl << "Jack travelled through these ports: ";
                            way(i);
                            cout << "." << endl;
                        }
        }
};

int main()
{
    int P, N, i, a, b, p;
    cout << "How many ports there are? ";
    cin >> P;
    cout << "How many links between ports there are? ";
    cin >> N;
    Graph<int, int> ports(P);
    cout << endl << "Read the profits per distance..." << endl;
    for (i = 1; i <= N; i++)
    {
        cout << "Insert the coordinate <<a>> for the link no. " << i << ": ";
        cin >> a;
        cout << "Insert the coordinate <<b>> for the link no. " << i << ": ";
        cin >> b;
        cout << "Enter the profit for way " << a << "-" << b << ": ";
        cin >> p;
        ports.addEdge(a, b, p);
    }
    cout << endl;
    ports.profit();
    return 0;
}
