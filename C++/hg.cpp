#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#define N 1000005
#define MOD 1000000007
#define ll long long double
using namespace std;
#define F first
#define S second


auto ta(vector<int> &a)
{
    int n = a.size();
    vector<int> ta(n);
    ta[0]=a[0];
    for(int i = 1; i < n; i++){
        ta[i] = ta[i-1] + a[i];
    }
    return ta;
}

class solv{
public:
    solv(){

        int n;
        cin >> n;
        vector<int> a(n),h(n);
        for(int i = 0 ; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0 ; i < n; i++){
            cin >> h[i];
        }
        auto Ta = ta(a);
        auto Th = ta(h);        
        
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)solv s;

}