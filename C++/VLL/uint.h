#ifndef _uint
#include <bits/stdc++.h>
using namespace std;
#define _uint
class uint
{
public:
    string num;
    uint(int res)
    {
        this->num = to_string(res);
    }
    size_t max_size()
    {
        return num.max_size();
    }
    size_t size()
    {
        return num.size();
    }
    void operator++() // O(log10( this->size()) )
    {
        long long i = this->num.size() - 1;
        while (this->num[i] == '9')
        {
            this->num[i] = '0';
            i--;
            if (i < 0)
            {
                this->num = '1' + this->num;
                return;
            }
        }
        this->num[i]++;
    }
    char &operator[](int pos)
    {
        return this->num[pos];
    }
};
uint operator+(uint a, uint b)
{
    long long n_size = max(b.size(), a.size()) + 1;
    reverse(a.num.begin(), a.num.end());
    reverse(b.num.begin(), b.num.end());
    b.num.resize(n_size);
    a.num.resize(n_size);
    for (int i = 0; i < n_size; i++)
    {
        if (!(a[i] >= '0' && a[i] <= '9'))
        {
            a[i] = '0';
        }
        if (!(b[i] >= '0' && b[i] <= '9'))
        {
            b[i] = '0';
        }
    }
    reverse(a.num.begin(), a.num.end());
    reverse(b.num.begin(), b.num.end());

    int carry = 0;
    for (int i = n_size - 1; i >= 0; i--)
    {
        if (carry)
        {
            int news = a[i] + b[i] - '0' - '0' + carry;
            carry = 0;
            if (news > 9)
            {
                carry = (news / 10) % 10;
                a[i] = char(news % 10) + '0';
            }
            else
            {
                a[i] = char(news) + '0';
            }
        }
        else
        {
            int news = a[i] + b[i] - '0' - '0';
            if (news > 9)
            {
                carry = 1;
                a[i] = char(news % 10) + '0';
            }
            else
            {
                a[i] = char(news) + '0';
            }
        }
    }
    int i = 0;
    
}
#endif // !uint

