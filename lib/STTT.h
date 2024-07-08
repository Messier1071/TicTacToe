#ifndef STTT_h
#define STTT_h
#include "TTT.h"
using namespace std;
class SuperTicTacToe : public TicTacToe
{
private:
    array <array<TicTacToe,3>,3> m_SuperBoard;
    TicTacToe m_ReferenceBoard;

    bool currentPlayer;
    char currentChar;
    pair<int,int> NextBoardCoordinate;
public:
    SuperTicTacToe(/* args */);
    ~SuperTicTacToe();
    char getChar();
    pair <pair<bool,char>,pair<int,int>> play(pair<int,int> BoardCoordinate,pair<int,int> Coordinate); // first pair is the win check, second pair is the next metaboard Coordinate
    stringstream getSuperBoardString(); 

    TicTacToe getSBoard(int i,int j);
};

#endif