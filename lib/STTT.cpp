#include "STTT.h"

SuperTicTacToe::SuperTicTacToe(/* args */)
{
}

SuperTicTacToe::~SuperTicTacToe()
{
    currentPlayer = false;
}

 char SuperTicTacToe::getChar()
{
    if (currentPlayer){return 'X';}else{return 'O';}

    return ' ';
}
TicTacToe SuperTicTacToe::getSBoard(int i,int j){
    return m_SuperBoard.at(i).at(j);
}

stringstream SuperTicTacToe::getSuperBoardString(){
    stringstream ssboard;

    for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                for (size_t k = 0; k < 3; k++)
                {
                    for (size_t l = 0; l < 3; l++)
                    {
                        ssboard << "| "<<m_SuperBoard.at(i).at(k).getBoard().at(j).at(l)<<" ";
                    }
                    ssboard << "| ";
                }
                ssboard << endl;
            }
            ssboard <<"------------  -------------  ------------"<<endl;
            
        }
        ssboard<<m_ReferenceBoard.getBoardString().str();
    return ssboard;
}

pair <pair<bool,char>,pair<int,int>>  SuperTicTacToe::play(pair<int,int> BoardCoordinate,pair<int,int>Coordinate){// first pair is the win check, second pair is the next metaboard Coordinate
    pair<bool,char> response(pair(false,' '));
    pair<pair<bool,char>,pair<int,int>> WinCon(pair(false,' '), pair(Coordinate));
    if (m_ReferenceBoard.checkpos(BoardCoordinate)) //if you try to play on a closed position, return
    {
        return WinCon;
        WinCon.second.first =-1;
        WinCon.second.second =-1;
    }
    

    if (currentPlayer){currentPlayer=false;}else{currentPlayer=true;std::cout<<"changing players"<<std::endl;} //* cycle players
    if (currentPlayer){currentChar='O';}else{currentChar='X';}        //* set char
    response = m_SuperBoard.at(BoardCoordinate.first).at(BoardCoordinate.second).play(Coordinate,currentChar);
    // m_SuperBoard.at(0).at(0).resetBoard('a');
    // m_SuperBoard.at(0).at(1).resetBoard('b');
    // m_SuperBoard.at(0).at(2).resetBoard('c');
    // m_SuperBoard.at(1).at(0).resetBoard('d');
    // m_SuperBoard.at(1).at(1).resetBoard('e');
    // m_SuperBoard.at(1).at(2).resetBoard('f');
    // m_SuperBoard.at(2).at(0).resetBoard('g');
    // m_SuperBoard.at(2).at(1).resetBoard('h');
    // m_SuperBoard.at(2).at(2).resetBoard('i'); dont ask...
    if (response.first)
    {
        WinCon.first = m_ReferenceBoard.play(BoardCoordinate,currentChar);
    }

    if (m_ReferenceBoard.checkpos(Coordinate))
    {
        WinCon.second.first =-1;
        WinCon.second.second =-1;
    }
    
    

    

    return WinCon;
}


