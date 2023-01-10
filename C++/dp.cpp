#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0;i<n;i++)
        {
            cin >> v[i];
        }
        bool a[102000],b[102000];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        vector<int>resp1,resp2;
        for(int i = 0;i<n;i++)
        {
            if(a[v[i]] == false)
            {
                resp1[i] = v[i];
                a[v[i]] = true;
            }    
            else
            {
                resp2[i] = v[i];
            }
        }
        for(int i = 0; i < n;i++)
        {
            if(resp1[i] == 1)
            {   
                resp2[i]=1;
                continue;
            }
        

        }
    }
}

