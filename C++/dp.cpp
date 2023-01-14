#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    string s;
    cin >> s;
    bool ok = true;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a' || s[i] == 'A'){
            cout <<"Francis Puto\n";
        } else {
            cout << "Francis genio\n";
        }
    } 
    
    return 0;
} 