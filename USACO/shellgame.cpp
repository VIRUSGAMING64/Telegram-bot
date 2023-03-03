#include <bits/stdc++.h>
using namespace std; 
#define S second
#define F first
#define N 100001
#define pii pair<int,int>
vector<pair<pii,int>> v;
int sim(int in,vector<pair<pii,int>> a)
{
    int n = a.size();
    int res = 0;
    int OK[N];
    memset(OK, 0, sizeof(OK));
    OK[in] = 1;
    for(int i=0;i<n;i++)
    {
        swap(OK[a[i].F.F],OK[a[i].F.S]);
        if(OK[a[i].S])res++;
    }
    return res;
}
int main()
{
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int n;
    cin >> n;
    while(n--)
    {
        int a,b,q;
        cin >> a >> b >> q;
        v.push_back({{a,b},q});
    }
    int res = max(0,sim(1,v));
    res = max(res,sim(2,v));
    res = max(res,sim(3,v));
    cout << res << endl;
}