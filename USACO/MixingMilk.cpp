#include <bits/stdc++.h>
using namespace std; 
#define S second
#define F first
#define N 100001
#define pii pair<int,int>
#define ll long long
int main()
{
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    ll a,ca,b,cb,c,cc;
    cin >> ca >>  a >> cb >> b >> cc >> c;
    for(int i = 0 ; i < 100; i++)
    {
        if(i%3==0)
        {
            if(b+a > cb)
            {
                a-=(cb-b);
                b = cb;
            }
            else
            {
                b+=a;a=0;
            }
        }
        else if(i%3 == 1)
        {
           if(c+b > cc)
            {
                b-=(cc-c);
                c = cc;
            }
            else
            {
                c+=b;b=0;
            }
        }
        else
        {
            if(a+c > ca)
            {
                c-=(ca-a);
                a = ca;
            }
            else
            {
                a+=c;c=0;
            }
        }
    }
    cout << a << endl << b << endl << c << endl;
}