#ifndef TicTacToe_H
#define TicTacToe_H
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



TicTacToe::TicTacToe(/* args */) : m_winner(true,' '),count(0)
{
    resetBoard(' ');
}

TicTacToe::~TicTacToe()
{
}

void TicTacToe::resetBoard(char C){
    m_Board.fill({C,C,C});
}

char TicTacToe::checkArr(array<char,3>Arr){
    if (Arr.at(0) == ' '){return ' ';}
    
    if (Arr.at(0)==Arr.at(1))
    {
        if (Arr.at(1)==Arr.at(2))
        {
            return Arr.at(0);
        }
    }
    return' ';
}

pair<bool,char> TicTacToe::checkWin(){
    int i=0,j=0;
    pair<bool,char>win(false,' ');
    char ch = ' ';
    
    for (i = 0; i < 3; i++)
    {
        ch = checkArr(m_Board.at(i)); // check LineS
        if (ch != ' ')
        {
            win.first = true;
            win.second =  ch;
            return win;
        }
    }
    
    for (i = 0; i < 3; i++)
    {
        if (m_Board.at(0).at(i)==m_Board.at(1).at(i)) //check Col1
        {
         if (m_Board.at(1).at(i)==m_Board.at(2).at(i))
         {
            if (m_Board.at(0).at(i) == ' '){continue;}
            win.first = true;
            win.second =  m_Board.at(0).at(i);
            return win;
         }
        }
    }

    if (m_Board.at(0).at(0)==m_Board.at(1).at(1)) //diag1
    {
         if (m_Board.at(1).at(1)==m_Board.at(2).at(2))
         {
            if (m_Board.at(0).at(0) == ' '){return win;}
            win.first = true;
            win.second =  m_Board.at(0).at(0);
            return win;
         }
    }
    if (m_Board.at(0).at(2)==m_Board.at(1).at(1)) //diag2
    {
         if (m_Board.at(1).at(1)==m_Board.at(2).at(0))
         {
            if (m_Board.at(1).at(1) == ' '){return win;}
            win.first = true;
            win.second =  m_Board.at(1).at(1);
            return win;
         }
    }
    return win;
};

stringstream TicTacToe::getBoardString(){
    stringstream ssboard;
    ssboard <<"  | 0 | 1 | 2 |"<<endl;
    int i=0,j=0;
    for ( i = 0; i < m_Board.size(); i++)
    {
        ssboard << i<<" | ";
        for (j = 0; j < m_Board.at(0).size();j++)
        {
            ssboard << m_Board.at(i).at(j)<<" | ";
        }          
        ssboard <<endl;
    }
    ssboard<<"line / column"<<endl;
    return ssboard;
}

array <array<char,3>,3> TicTacToe::getBoard(){
    return m_Board;
}

pair<bool,char> TicTacToe::play(pair<int,int> coordinate,char currentChar){ //* returns [true,X] or [true,O] depending on who won, otherwise returns [false, ]
    count++;
    pair<bool,char> check(false,' ');

    if(count == 9){
        if (m_Board.at(coordinate.first).at(coordinate.second)==' '){
            
            m_Board.at(coordinate.first).at(coordinate.second) = currentChar;//* update board
            check = checkWin();

            if (!check.first)
            {   
                resetBoard(' ');
            }}
            else{return pair(false,' ');}
            
            }

    if (count < 9)
    {
        if (m_Board.at(coordinate.first).at(coordinate.second)==' '){

            m_Board.at(coordinate.first).at(coordinate.second) = currentChar;;//* update board
            check = checkWin();
            }
        else{return pair(false,' ');}
    }


    return check;
}

bool TicTacToe::checkpos(pair<int,int>coordinate){ //returns True or false depending if the position is occupied or not
    if (m_Board.at(coordinate.first).at(coordinate.second)==' '){
        return false;
    }else{
        return true;
    }

}
#endif