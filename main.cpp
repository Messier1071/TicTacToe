#include <array>
#include <iostream>

using namespace std;

void printBoard(array <array<char,3>,3>leque);
pair<bool,char> checkwin(array <array<char,3>,3>Board);
char checkarr(array<char,3>Arr);

int main(int argc, char const *argv[])
{
    
    array <array<char,3>,3> test{' ',' ',' ',' ',' ',' ',' ',' ',' '};
    pair<bool,char>winner(false,'P');
    
    printBoard(test);
    bool currentPlayer=false,loop=false;
    char currentChar=' ';
    int col,lin;
    while (true)
    {
    
    for (size_t k = 0; k < 9; k++)
    {
    if (currentPlayer){currentPlayer=false;}else{currentPlayer=true;}
    if (currentPlayer){currentChar='O';}else{currentChar='X';}
    
    do{
        
        cout <<"curentPlayer: "<< currentChar <<endl;
        loop=false;

        cin>>col;
        cin>>lin;

        if (test.at(col).at(lin)==' '){test.at(col).at(lin) = currentChar;}
        else{loop=true;printBoard(test);}

        winner = checkwin(test);


    } while (loop);

    
    
    if (winner.first)
    {
        cout <<"Winner:"<<winner.second;
        break;
    }
    
    printBoard(test);
    }}
    




    return 0;
}

void printBoard(array <array<char,3>,3>leque){
    cout<<"\n\n\n\n\n\n\n\n\n\n\n";
cout <<"  | 0 | 1 | 2 |"<<endl;
int i=0,j=0;
for ( i = 0; i < leque.size(); i++)
{
    cout << i<<" | ";
    for (j = 0; j < leque.at(0).size();j++)
    {
        cout << leque.at(i).at(j)<<" | ";
    }    cout <<endl;

}
cout<<"line / column"<<endl;
}


pair<bool,char> checkwin(array <array<char,3>,3>Board){
    int i=0,j=0;
    pair<bool,char>win(false,' ');
    char ch = ' ';
    
    for (i = 0; i < 3; i++)
    {
        ch = checkarr(Board.at(i)); // check LineS
        if (ch != ' ')
        {
            win.first = true;
            win.second =  ch;
            return win;
        }
    }
    
    
    // ch = checkarr(Board.at(0)); // check Line 1
    // if (ch != ' ')
    // {
    //     win.first = true;
    //     win.second =  ch;
    //     return win;
    // }

    // checkarr(Board.at(1)); // check Line 2
    // if (ch != ' ')
    // {
    //     win.first = true;
    //     win.second =  ch;
    //     return win;
    // }
    // checkarr(Board.at(2)); // check Line 3
    // if (ch != ' ')
    // {
    //     win.first = true;
    //     win.second =  ch;
    //     return win;
    // }

    //this is Jank, i know
 

 
    for (i = 0; i < 3; i++)
    {
        if (Board.at(0).at(i)==Board.at(1).at(i)) //check Col1
        {
         if (Board.at(1).at(i)==Board.at(2).at(i))
         {
            if (Board.at(0).at(i) == ' '){continue;}
            win.first = true;
            win.second =  Board.at(0).at(i);
            return win;
         }
        }
    }

    if (Board.at(0).at(0)==Board.at(1).at(1)) //diag1
    {
         if (Board.at(1).at(1)==Board.at(2).at(2))
         {
            if (Board.at(0).at(0) == ' '){return win;}
            win.first = true;
            win.second =  Board.at(0).at(0);
            return win;
         }
    }

    if (Board.at(0).at(2)==Board.at(1).at(1)) //diag2
    {
         if (Board.at(1).at(1)==Board.at(2).at(0))
         {
            if (Board.at(1).at(1) == ' '){return win;}
            win.first = true;
            win.second =  Board.at(1).at(1);
            return win;
         }
    }


    
    
    



    return win;
}

char checkarr(array<char,3>Arr){
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
