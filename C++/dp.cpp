#pragma GCC optimize("Ofast")
#pragma GCC target("avx2") 
#define N 100005
#define MOD 1000000007
#define INF 1000000000000000LL
#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
vector<int> a;

int main() 
{
    int t;
    cin >> t;
    vector<vector<int>> GCD(N+1);
    for(int i=1;i<N;i++)
    {
        for(int j = 1;j*j<=i;j++)
        {
            if(i%j == 0)
            {
                GCD[i].push_back(j);
                if(i/j!=j)
                {
                    GCD[i].push_back(i/j);
                }
            }
        }
        sort(GCD[i].begin(), GCD[i].end());
    }   
    while(t--)
    {
        cin >> n;
        a.resize(n);
        vector<int> b(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool D = 1;
        for(int i=0;i<n;i++)
        {
            bool F = 0;
            for(auto c:GCD[i+1])
            {
                if(a[i] == c)
                {
                    F = 1;
                }
            }
            D = (D&F);
        }
        if(D)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}