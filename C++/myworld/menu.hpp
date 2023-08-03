#include <bits/stdc++.h>
using namespace std;

int MAIN_MENU(){
    while(1){
        cout << "1 - START\n" 
             << "0 - EXIT\n";
        int op;
        cout << "Option: ";cin >> op;
        if(op > 1)continue;
        return op;
    }
}