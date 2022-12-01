#include<bits/stdc++.h>
using namespace std;
#define ll long long
class bin_str
{
public:
	string str = "";
	bin_str(string str2)
	{
		str = str2;

		del0();
	}
	bin_str()
	{
		str = "0";
	}
	bin_str(long long r)
	{
		str = bin(r);
		del0();
	}
	void concat(string sr)
	{
		str = str + sr;
		del0();
	}
	long long count(bool b = 1)
	{
		long long cnt001 = 0;
		if(b)
		{
			for(long long i = 0;i<int(str.size());i++)
			{
				if(str[i] == '1')
				{
					cnt001++;
				}
			}
		}
		else
		{
			for(long long i = 0;i<int(str.size());i++)
			{
				if(str[i] == '0')
				{
					cnt001++;
				}
			}
		}
		return cnt001;
	}
	string bin(long long a)
	{
		string bi = "";
		for(long long i = 0;i < 64LL;i++)
		{
			if(a & (1LL << i))
			{
				bi = "1" + bi;
			}
			else{
				bi = "0" + bi;
			}
		}
		return bi;
	}

	long long size(){
		return str.size();
	}
	void del0()
	{
		string aux = "";
		bool ok = false;
		for(int i = 0;i<int(str.size());i++)
		{
			if(!ok)
			{
				if(str[i] != '0')
				{
					ok = 1;
				}
			}
			if(ok)
			{
				if(str[i] == '0' || str[i] == '1')aux += str[i];
				else aux += '1';
			}
		}
		str = aux;
		if(str.size() == 0){
			str = "0";
		}
	}

	ll _int()
	{
		if(str.size() > 63)return -1;
		ll res = 0;
		for(ll i = 0;i < str.size();i++)
		{
			if(str[i] == '1')
			{
				res += (1LL << str.size()-i-1);
			}
		}
		return res;
	}
};

ostream& operator<<(ostream& out,bin_str str)
{

	str.del0();
	out << str.str;
	return out;
}
istream& operator>>(istream& in,bin_str& str)
{
	in >> str.str;
	str.del0();
	return in;
}

void operator++(bin_str& str)
{
	if(str.str[str.size() - 1] == '0')
	{
		str.str[str.size() - 1] = '1';
	}
	else
	{
		int aux = 1;
		while(str.str[str.size() - aux] == '1')
		{
			str.str[str.size() - aux] = '0';
			aux++;

			if(str.size() - aux < 0)
			{
				str.str = "0" + str.str;
			}
		}
		str.str[str.str.size() - aux] = '1';
	}
}

bin_str operator^(bin_str a,bin_str b)
{
	while(a.size() < b.size())
	{
		a.str = "0" + a.str;
	}
	while(b.size() < a.size())
	{
		b.str = "0" + b.str;
	}
	for(int i = 0;i < a.size();i++)
	{
		if(a.str[i] == b.str[i])
		{
			a.str[i] = '0';
		}
		else
		{
			a.str[i] = '1';
		}
	}
	return a;
}

bin_str operator+(bin_str a,string y)
{
	bin_str b(y);
	while(a.size() < b.size())
	{

		a.str = "0" + a.str;
	}
	while(b.size() < a.size())
	{
		b.str = "0" + b.str;
	}
	a.str = "0" + a.str;
	b.str = "0" + b.str;
	string s1(a.size(),'0');
	int ac = 0;
	for(int i = b.size() - 1;i >= 0;i--)
	{

		if(a.str[i] == b.str[i] && ac >= 1 && a.str[i] == '1')
		{
			s1[i] = '1';
		}
		else if(a.str[i] == b.str[i] && ac == 0 && a.str[i] == '1')
		{
			ac++;
			s1[i] = '0';
		}
		else if(a.str[i] == b.str[i] && ac == 0 && a.str[i] == '0')
		{
			s1[i] = '0';
		}
		else if(a.str[i] == b.str[i] && ac >= 1 && a.str[i] == '0')
		{
			s1[i] = '1';
			ac--;
		}
		else
			if(a.str[i] != b.str[i] && ac >= 1)
			{
				s1[i] = '0';
			}
			else if(a.str[i] != b.str[i] && ac == 0)
			{
				s1[i] = '1';
			}
	}
	bin_str c;
	c.str = s1;
	return c;
}


bin_str operator+(string y,bin_str a)
{
	bin_str b(y);
	while(a.size() < b.size())
	{

		a.str = "0" + a.str;
	}
	while(b.size() < a.size())
	{
		b.str = "0" + b.str;
	}
	a.str = "0" + a.str;
	b.str = "0" + b.str;
	string s1(a.size(),'0');
	int ac = 0;
	for(int i = b.size() - 1;i >= 0;i--){

		if(a.str[i] == b.str[i] && ac >= 1 && a.str[i] == '1')
		{
			s1[i] = '1';
		}
		else if(a.str[i] == b.str[i] && ac == 0 && a.str[i] == '1')
		{
			ac++;
			s1[i] = '0';
		}
		else if(a.str[i] == b.str[i] && ac == 0 && a.str[i] == '0')
		{
			s1[i] = '0';
		}
		else if(a.str[i] == b.str[i] && ac >= 1 && a.str[i] == '0')
		{
			s1[i] = '1';
			ac--;
		}
		else if(a.str[i] != b.str[i] && ac >= 1)
		{
			s1[i] = '0';
		}
		else if(a.str[i] != b.str[i] && ac == 0)
		{
			s1[i] = '1';
		}
	}
	bin_str c;
	c.str = s1;
	return c;
}

bin_str operator+(bin_str a,bin_str b)
{
	while(a.size() < b.size())
	{

		a.str = "0" + a.str;
	}
	while(b.size() < a.size())
	{
		b.str = "0" + b.str;
	}
	a.str = "0" + a.str;
	b.str = "0" + b.str;
	string s1(a.size(),'0');
	int ac = 0;
	for(int i = b.size() - 1;i >= 0;i--)
	{

		if(a.str[i] == b.str[i] && ac >= 1 && a.str[i] == '1')
		{
			s1[i] = '1';
		}
		else if(a.str[i] == b.str[i] && ac == 0 && a.str[i] == '1')
		{
			ac++;
			s1[i] = '0';
		}
		else if(a.str[i] == b.str[i] && ac == 0 && a.str[i] == '0')
		{
			s1[i] = '0';
		}
		else if(a.str[i] == b.str[i] && ac >= 1 && a.str[i] == '0')
		{
			s1[i] = '1';
			ac--;
		}
		else
			if(a.str[i] != b.str[i] && ac >= 1)
			{
				s1[i] = '0';
			}
			else if(a.str[i] != b.str[i] && ac == 0)
			{
				s1[i] = '1';
			}
	}
	bin_str c;
	c.str = s1;
	return c;
}
bin_str operator+(bin_str str,long long n)
{
	bin_str a(n);
	return str + a;
}

bin_str operator+(long long n,bin_str str)
{
	bin_str a(n);
	return str + a;
}

bin_str operator&(bin_str a,bin_str b)
{
	while(a.size() < b.size())
	{
		a.str = "0" + a.str;
	}
	while(b.size() < a.size())
	{
		b.str = "0" + b.str;
	}
	for(int i = 0;i < b.size();i++)
	{
		if(b.str[i] == a.str[i] && a.str[i] == '1')
		{
			a.str[i] = '1';
		}
		else{
			a.str[i] = '0';
		}
	}
	return a;
}

bin_str operator|(bin_str a,bin_str b)
{
	while(a.size() < b.size())
	{
		a.str = "0" + a.str;
	}
	while(b.size() < a.size())
	{
		b.str = "0" + b.str;
	}
	for(int i = 0; i < a.size(); i++)
	{
		if(a.str[i] == '1' || b.str[i] == '1')
		{
			a.str[i] = '1';
		}
		else{
			a.str[i] = '0';
		}
	}
	return a;
}

bin_str operator!(bin_str a)
{
	while(a.size() < 64)
	{
		a.str = "0" + a.str;
	}
	for(int i = 0;i < a.size();i++)
	{
		if(a.str[i] == '1'){
			a.str[i] = '0';
		}
		else{
			a.str[i] = '1';
		}
	}
	return a;
}


bin_str __multbinstraux__(bin_str a,long long num)
{
	if(num == 0)return 0;
	if(num % 2 == 0){
		bin_str t = __multbinstraux__(a,num / 2);
		return t + t;
	}
	else{
		bin_str t = __multbinstraux__(a,num / 2);
		return t + t + a;
	}
}

bool operator==(bin_str stdS,string st)
{
	if(stdS.str == st)return true;
	return false;
}
bool operator==(string st,bin_str stdS)
{
	if(stdS.str == st)return true;
	return false;
}

bool operator==(bin_str st,bin_str stdS)
{
	if(stdS.str == st.str)return true;
	return false;
}


bin_str operator<<(bin_str a,long long b)
{
	string us(b,'0');
	a.str = a.str + us;
	return a;
}

bin_str operator>>(bin_str a,long long b)
{
	if(a.size() - b <= 0){
		a.str = "0";
		return a;
	}
	a.str.resize(a.size() - b);
	return a;
}

bin_str __multbinstraux__(bin_str a,bin_str num)
{
	string __cero = "0";
	if(num == __cero)return __cero;

	if(num.str[num.str.size() - 1] == '0')
	{
		num = num >> 1;
		bin_str t = __multbinstraux__(a,num);
		return t + t;
	}
	else{
		num = num >> 1;
		bin_str t = __multbinstraux__(a,num);
		return t + t + a;
	}
}

bin_str operator*(bin_str a,long long num)
{
	if(num == 0)
	{
		a.str = "0";
		return a;
	}
	return __multbinstraux__(a,num);
}

bin_str operator*(long long num,bin_str a)
{
	if(num == 0)
	{
		a.str = "0";
		return a;
	}
	return __multbinstraux__(a,num);
}

bin_str operator*(bin_str num,bin_str a)
{
	if(num == "0" || a == "0")
	{
		a.str = "0";
		return a;
	}
	return __multbinstraux__(a,num);
}

bool operator>(bin_str a,bin_str b)
{
	if(a.size() > b.size())return true;
	if(a.size() < b.size())return false;
	for(int i = 0;i < a.size(); i++)
	{
		if(a.str[i] == '1' && b.str[i] == '0')
		{
			return true;
		}
		else if(b.str[i] == '1' && a.str[i] == '0')
		{
			return false;
		}
	}
	return false;
}

bool operator<(bin_str a,bin_str b)
{
	if(a == b)return false;
	if(a > b)return false;
	return true;
}

bool operator<=(bin_str a,bin_str b)
{
	bool f1 = a < b;
	bool f2 = a == b;
	f1 = f2 | f1;
	return f1;
}
bool operator>=(bin_str a,bin_str b)
{
	bool f1 = a > b;
	bool f2 = a == b;
	f1 = f2 | f1;
	return f1;
}

bin_str __div(bin_str a,bin_str b)
{
	if(b == "0")exit(0);
	bin_str l(0),r(a);
	bin_str res(0);
	while(l <= r)
	{
		bin_str m = (l + r) >> 1;
		res = m;
		if(res * b == a)break;
		if(res * b > a)
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}
	return res;

}


int main()
{
	
}
