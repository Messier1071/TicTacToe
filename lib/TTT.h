#ifndef TTT_H
#define TTT_H
#include <array>
#include <sstream>
using namespace std;
class TicTacToe
{

private:
    int count;
    array <array<char,3>,3> m_Board;
    pair<bool,char>m_winner;
    

    pair<bool,char> checkWin();     //* done
    char checkArr(array<char,3>Arr);//* done

    

public:
    TicTacToe(/* args */);
    ~TicTacToe();
    
    void resetBoard(char);              //* done

    stringstream getBoardString();        //* done
    array <array<char,3>,3> getBoard();

    pair<bool,char> play(pair<int,int> coordinate,char currentchar);
    bool checkpos(pair<int,int>coordinate);
};

#endif