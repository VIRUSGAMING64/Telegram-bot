#include <bits/stdc++.h>
using namespace std; 
#define S second
#define F first
#define N 100001
#define pii pair<int,int>

int main()
{
    //freopen("shuffle.in", "r", stdin);
    //freopen("shuffle.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        a[i]--;
        b[a[i]] = i;
    }
    vector<string> s(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> s[i];
    }
    for(int i=0;i<3;i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            swap(s[b[n-1-j]],s[n-1-j]);
        }
    }
    for(auto C:s)
    {
        cout << C << endl;
    }
}