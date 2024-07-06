#include <array>
#include <iostream>
#include "TTT.h"

using namespace std;

int main(int argc, char const *argv[])
{
    array<array<TicTacToe,3>,3> Games;
    int col=0,lin=0;
    TicTacToe Game;
    pair<bool,char> winner;
    while (1)
    {
        cout << Game.getBoardString().str()<<endl;

        cin>>col;
        cin>>lin;
        winner = Game.play(pair(col,lin));
        if (winner.first)
        {
            cout << "winner:" << winner.second<<endl;
            break;
        }
        
    }
        
  
    
    


    return 0;
}


/*

*/