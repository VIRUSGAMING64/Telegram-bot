#include<bits/stdc++.h>
#define ld long double
using namespace std;
using namespace chrono;
ld a,b,c,d;

void tester(int x,int y)
{
    cout << -a*x + y - b << endl;
}

vector<vector<ld>> test
{
  {1},
  {2}
};
ld rate = 0.000001;

ld f(ld x)
{
    return a * x + b;//Func
}

void learn(int times = 1)
{
    while(times--)
        for(int i = 0; i < test[0].size(); i++)
        {
            ld pred = f(test[0][i]);
            ld err = pred - test[1][i];
            a = a - err * rate * test[0][i];
            b = b - err * rate;
        }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 300000;i++)
    {
        learn();
    }
    cout << a << "x + " << b << "\n";
}