#include <bits/stdc++.h>
#define ll long long
#define S second
#define F first 
#define pb push_back

using namespace std;
ll INF = 1000000;
ll cnt  = 0;
vector <pair <string,char> > v;
void f (int n, int sol, char x) {
    if (sol == n) {
        cnt++;
        return;
    }
    for (auto c :v ) {
        if (c.S == x) {
            f (n, sol+1,c.F[0]);
        }    
    }

}

int main () {

    ios_base::sync_with_stdio(0); cin.tie(0);
    cerr << 
    int n, q; cin >> n >> q;
    v.resize(q);
    for (int i = 0; i < q; i++) {
        string a; char b;
        cin >> a >> b;  
        v[i].F = a;
        v[i].S = b;      
    }
    f(n, 1, 'a');
    cout << cnt;

    return 0;
}