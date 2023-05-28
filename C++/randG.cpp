#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin >> n >> m;
    if (m > 500){
        ofstream out;
        out << n << " " << m << endl;
        for (int i = 0; i < m; i++){
            out << 1 + (rand() ^ rand()) % n << " " << 1 + (rand() ^ rand()) % n << endl;   
        }
    }else{
        cout << n << " " << m << endl;
        for (int i = 0; i < m; i++)
        {
            cout << 1 + (rand() ^ rand()) % n << " " << 1 + (rand() ^ rand()) % n << endl;
        }
    }

}