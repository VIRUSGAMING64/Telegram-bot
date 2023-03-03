#include <bits/stdc++.h>
using namespace std; 
#define S second
#define F first
#define N 100001
#define pii pair<int,int>

int main()
{
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int n,m;
    cin >> n >> m;
    int C[N];
    int act = 0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin >> a >> b;
        for(int i=0;i<a;i++)
        {
            C[act] = b;
            act++;
        }
    }   
    int res = 0;
    act = 0;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        for(int i =0;i<a;i++)
        {
            res = max((C[act] - b)*-1,res);
            act++;
        }
    }
    cout << res << endl;
}