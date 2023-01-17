#include <bits/stdc++.h>
using namespace std;

class neuron
{
    public:

    vector<double> IN,OUT;
    double n,m,rate;
    void assing(int n_t,int m_t,int rate_t)
    {
        n = n_t;
        m = m_t;
        rate = rate_t;
    }
    neuron()
    {
    }
    neuron(vector<double> train,vector<double> train_out)
    {
        if(train.size() == train_out.size())
        {
            IN = train;
            OUT = train_out;
        }
    }
    void linealReg(int t)
    {
        while(t--)
        for(int i = 0 ; i < IN.size(); i++)
        {
            double pred = (IN[i] * m) + n;
            double err = OUT[i] - pred;
            m = m - err*IN[i]+err;
            n = n - err;
        }
    }
};