#include <array>
#include <iostream>
#include "STTT.h"

using namespace std;

int main(int argc, char const *argv[])
{
   SuperTicTacToe board;

    int X=0,Y=0,x=0,y=0;
    cout <<board.getSuperBoardString().str()<<endl;
    pair<pair<bool,char>,pair<int,int>> WinCon(pair(false,' '),pair(-1,-1));
    while (true)
    {

    if (WinCon.second.first == -1)
    {
        cout<<"select a Board Coordinate \"Col Line\""<<endl;
        cin >>X>>Y;
    }else{
        cout << "playing in board:(" <<WinCon.second.first<<","<<WinCon.second.second<<")"<<endl;
        X = WinCon.second.first;
        Y = WinCon.second.second;
    }
    cout << "current player:("<<board.getChar()<<")"<<endl;
    cout<<"select a Coordinate \"Col Line\""<<endl;
    cin >>x>>y;
    WinCon = board.play(pair(X,Y),pair(x,y));
    cout <<board.getSuperBoardString().str()<<endl;

    if (WinCon.first.first)
    {
        cout<<WinCon.first.second<<"won"<<endl;
         break;
    }
    

    }
    
    


    return 0;
}

