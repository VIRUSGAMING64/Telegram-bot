#include <bits/stdc++.h>
#include "map.hpp"
#include "menu.hpp"
string MAPPATH="d:/Github/TELEGRAM-BOT/C++/myworld/MAP";
struct ACT_CHU{
    int x,y;  
};
PLAY_POS pos;
using namespace std;

void start(){
    auto chunck = LoadChunk(0,0,MAPPATH);
    system("cls");
    for(int i = 0 ; i < CHUNKSIZE; i++){
        for(int j = 0; j < CHUNKSIZE; j++){
            cout << chunck[i][j] << " ";
        }cout << endl;
    }
}

int main(){
    freopen("errs.txt","w",stderr);
    auto lpin = MAIN_MENU();
    if(!lpin)return 0;


    LoadPlayerPos(pos);
    cerr << "INI POS: "<< pos.x << " " << pos.y << endl;

    CreateMap("d:/Github/TELEGRAM-BOT/C++/myworld");   
    if(lpin == 1){
        start();
    }
}