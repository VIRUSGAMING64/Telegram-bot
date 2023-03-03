#include <bits/stdc++.h>
using namespace std; 
#define S second
#define F first
#define N 100001
#define pii pair<int,int>
int n,m,p;
int main()
{
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    cin >> n >> m >> p;
    vector<vector<char>> lines;
    for(int i = 0 ; i < n ;i++)
    {
        vector<char> line;
        for(int j=0;j<m;j++)
        {
            char a;
            cin >> a;   
            for(int k = 0;k<p;k++)
            {
                line.push_back(a);
            }
        }
        for(int k=0;k<p;k++)
        lines.push_back(line);
    }
    for(auto L:lines)
    {
        for(auto c:L)
        {
            cout <<c;
        }cout << endl;
    }
}