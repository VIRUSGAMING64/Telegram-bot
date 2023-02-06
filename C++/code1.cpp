#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int a,b,c;
int memo[10000000];

int main()
{
    memset(memo,0,sizeof(memo));
    cin >> a >> b >> c;
    int res = 0;
    int cnt = 0;
    while(memo[res] == 0)
    {
        cnt = max(res,cnt);
        memo[res] = 1;
        if(res+b <= a)
        {
            memo[res] = 1;
            res+=b;
        }
        else if (res > c)
        {
            res-=c;
        }
    }
    cout << cnt << endl;
}