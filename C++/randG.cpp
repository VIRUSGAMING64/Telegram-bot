#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main()
{
    srand(time(0));
    cout << "tipo de grafo?"
         << endl
         << "1 - sin peso normal"
         << endl
         << "2 - con peso normal"
         << endl
         << "3 - de tipo matriz sin peso (g[i][j] i -> j )"
         << endl
         << "4 - de tipo matriz con peso"
         << endl
         << "5 - lista de arista sin peso"
         << endl
         << "6 - lista de arista con peso" << endl;
    int type, n, m;
    cout << "type: ";
    cin >> type;
    if(type <= 0 || type >= 7)
        type = 1;
    cout << "Nodos: ";
    cin >> n;
    cout << "Aristas: ";
    cin >> m;
    if (n > 500)
    {
        freopen("test.in", "w", stdout);
    }

    if(type == 1 || type == 2){
        cout << n << " " << m << endl;
        for(int i = 0 ; i < m; i++){
            ERR:
            int a = 1 + rand() % n, b = 1 + rand() % n;
            if(a == b)
                goto ERR;
            cout
                << a << " " << b;
            if(type == 2){
                cout << " " << 1 + rand() % MOD;
            }
            cout << endl;
        }
        return 0;
    }else if(type == 3 || type == 4)
    {
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
            {
                if(i == j ){
                    cout << 1 << " ";
                    continue;
                }
                if(m > 0)
                cout <<(rand() % ((type==3)?(2):(MOD))) << " ";
                else
                cout << "0 ";
                m--;
            }
            cout << endl;
        }
    }else if(type == 5 || type == 6){
        for (int i = 0; i <= m; i++){

        }
            
    }
        cout << endl;
}