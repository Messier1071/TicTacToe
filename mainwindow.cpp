#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,WinCon(std::pair(false,' '),std::pair(-1,-1))
    ,BoardSelected(false)
    ,board()
    ,GameEnded(false)


{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::play(std::pair<int, int> UIBoardCoordinate, std::pair<int, int> UICoordinate){
    if(GameEnded){
        QApplication::quit();
    }


    if (WinCon.second.first == -1)
    {
        BoardSelected = false;
    }else{
        std::cout << "playing in board:(" <<WinCon.second.first<<","<<WinCon.second.second<<")"<<std::endl;
        BoardSelected = true;
    }

    //WinCon = board.play(pair(UIBoardCoordinate.first,UIBoardCoordinate.second),pair(UICoordinate.first,UICoordinate.second));

    if(BoardSelected){
        WinCon = board.play(pair(WinCon.second.first,WinCon.second.second),pair(UICoordinate.first,UICoordinate.second));
    }else{
        WinCon = board.play(pair(UIBoardCoordinate.first,UIBoardCoordinate.second),pair(UICoordinate.first,UICoordinate.second));
    }

    //for debugging
    cout <<board.getSuperBoardString().str()<<endl;
    //

    if (WinCon.first.first)
    {
        std::string placeholder2 = "Winner: ";
            placeholder2+= WinCon.first.second;
        placeholder2 += "     reopen the program to reset";

        ui->menuplaceholder->setTitle(QString::fromStdString(placeholder2));
        cout<<WinCon.first.second<<"won"<<endl;
        GameEnded = true;
        //QApplication::quit();
    }

    std::string placeholder= "Current Player: ";
    placeholder += board.getChar();
    placeholder += "Current Board: (";
    placeholder += WinCon.second.first;
    placeholder += std::to_string(WinCon.second.first)+","+std::to_string(WinCon.second.second)+")";

    ui->menuplaceholder->setTitle(QString::fromStdString(placeholder));

    UpdateAll();
    Updatebackground(WinCon.second);

}

void MainWindow::Updatebackground(std::pair<int,int> CurrentBoard){
    QString style;
    if (CurrentBoard.first == -1)
    {
        if (CurrentBoard.second == -1)
        {
            style = "background-image: url(:/bg/bgs/bg.png);background-repeat: no-repeat;";
        }
    }
    if (CurrentBoard.first == 0)
    {
        if (CurrentBoard.second == 0)
        {
            style = "background-image: url(:/bg/bgs/bg00.png);background-repeat: no-repeat;";
        }
        if (CurrentBoard.second == 1)
        {
            style = "background-image: url(:/bg/bgs/bg01.png);background-repeat: no-repeat;";
        }
        if (CurrentBoard.second == 2)
        {
            style = "background-image: url(:/bg/bgs/bg02.png);background-repeat: no-repeat;";
        }
    }
    if (CurrentBoard.first == 1)
    {
        if (CurrentBoard.second == 0)
        {
            style = "background-image: url(:/bg/bgs/bg10.png);background-repeat: no-repeat;";
        }
        if (CurrentBoard.second == 1)
        {
            style = "background-image: url(:/bg/bgs/bg11.png);background-repeat: no-repeat;";
        }
        if (CurrentBoard.second == 2)
        {
            style = "background-image: url(:/bg/bgs/bg12.png);background-repeat: no-repeat;";
        }
    }
    if (CurrentBoard.first == 2)
    {
        if (CurrentBoard.second == 0)
        {
            style = "background-image: url(:/bg/bgs/bg20.png);background-repeat: no-repeat;";
        }
        if (CurrentBoard.second == 1)
        {
            style = "background-image: url(:/bg/bgs/bg21.png);background-repeat: no-repeat;";
        }
        if (CurrentBoard.second == 2)
        {
            style = "background-image: url(:/bg/bgs/bg22.png);background-repeat: no-repeat;";
        }
    }


    
    this->setStyleSheet(style);
}

void MainWindow::UpdateAll(){
    Update_0_0();
    Update_0_1();
    Update_0_2();
    Update_1_0();
    Update_1_1();
    Update_1_2();
    Update_2_0();
    Update_2_1();
    Update_2_2();

}

void MainWindow::Update_0_0(){
    std::array <std::array<char,3>,3> T_board = board.getSBoard(0,0).getBoard();
    int k = 0;
    std::array<QToolButton*,9> Buttons={
        ui->B_0_0,
        ui->B_0_1,
        ui->B_0_2,
        ui->B_1_0,
        ui->B_1_1,
        ui->B_1_2,
        ui->B_2_0,
        ui->B_2_1,
        ui->B_2_2};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::string placeholder= "";
            placeholder += T_board.at(i).at(j);
            Buttons.at(k)->setText(QString::fromStdString(placeholder));
            if(T_board.at(i).at(j)!=' '){
                Buttons.at(k)->setEnabled(false);
            }else{
                Buttons.at(k)->setEnabled(true);
            }
            k++;
        }
    }

}
void MainWindow::Update_0_1(){
    std::array <std::array<char,3>,3> T_board = board.getSBoard(0,1).getBoard();
    int k = 0;
    std::array<QToolButton*,9> Buttons={
                                            ui->B_0_6,
                                            ui->B_0_8,
                                            ui->B_0_7,
                                            ui->B_1_6,
                                            ui->B_1_8,
                                            ui->B_1_7,
                                            ui->B_2_6,
                                            ui->B_2_7,
                                            ui->B_2_8};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::string placeholder= "";
            placeholder += T_board.at(i).at(j);
            Buttons.at(k)->setText(QString::fromStdString(placeholder));
            if(T_board.at(i).at(j)!=' '){
                Buttons.at(k)->setEnabled(false);
            }else{
                Buttons.at(k)->setEnabled(true);
            }
            k++;
        }
    }

}
void MainWindow::Update_0_2(){
    std::array <std::array<char,3>,3> T_board = board.getSBoard(0,2).getBoard();
    int k = 0;
    std::array<QToolButton*,9> Buttons={
                                            ui->B_0_9,
                                            ui->B_0_11,
                                            ui->B_0_10,
                                            ui->B_1_9,
                                            ui->B_1_11,
                                            ui->B_1_10,
                                            ui->B_2_9,
                                            ui->B_2_10,
                                            ui->B_2_11};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::string placeholder= "";
            placeholder += T_board.at(i).at(j);
            Buttons.at(k)->setText(QString::fromStdString(placeholder));
            if(T_board.at(i).at(j)!=' '){
                Buttons.at(k)->setEnabled(false);
            }else{
                Buttons.at(k)->setEnabled(true);
            }
            k++;
        }
    }

}
void MainWindow::Update_1_0(){
    std::array <std::array<char,3>,3> T_board = board.getSBoard(1,0).getBoard();
    int k = 0;
    std::array<QToolButton*,9> Buttons={
                                            ui->B_0_12,
                                            ui->B_0_14,
                                            ui->B_0_13,
                                            ui->B_1_12,
                                            ui->B_1_14,
                                            ui->B_1_13,
                                            ui->B_2_12,
                                            ui->B_2_13,
                                            ui->B_2_14};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::string placeholder= "";
            placeholder += T_board.at(i).at(j);
            Buttons.at(k)->setText(QString::fromStdString(placeholder));
            if(T_board.at(i).at(j)!=' '){
                Buttons.at(k)->setEnabled(false);
            }else{
                Buttons.at(k)->setEnabled(true);
            }
            k++;
        }
    }

}
void MainWindow::Update_1_1(){
    std::array <std::array<char,3>,3> T_board = board.getSBoard(1,1).getBoard();
    int k = 0;
    std::array<QToolButton*,9> Buttons={
                                            ui->B_0_15,
                                            ui->B_0_17,
                                            ui->B_0_16,
                                            ui->B_1_15,
                                            ui->B_1_17,
                                            ui->B_1_16,
                                            ui->B_2_15,
                                            ui->B_2_16,
                                            ui->B_2_17};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::string placeholder= "";
            placeholder += T_board.at(i).at(j);
            Buttons.at(k)->setText(QString::fromStdString(placeholder));
            if(T_board.at(i).at(j)!=' '){
                Buttons.at(k)->setEnabled(false);
            }else{
                Buttons.at(k)->setEnabled(true);
            }
            k++;
        }
    }

}
void MainWindow::Update_1_2(){
    std::array <std::array<char,3>,3> T_board = board.getSBoard(1,2).getBoard();
    int k = 0;
    std::array<QToolButton*,9> Buttons={
                                            ui->B_0_18,
                                            ui->B_0_20,
                                            ui->B_0_19,
                                            ui->B_1_18,
                                            ui->B_1_20,
                                            ui->B_1_19,
                                            ui->B_2_18,
                                            ui->B_2_19,
                                            ui->B_2_20};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::string placeholder= "";
            placeholder += T_board.at(i).at(j);
            Buttons.at(k)->setText(QString::fromStdString(placeholder));
            if(T_board.at(i).at(j)!=' '){
                Buttons.at(k)->setEnabled(false);
            }else{
                Buttons.at(k)->setEnabled(true);
            }
            k++;
        }
    }

}
void MainWindow::Update_2_0(){    std::array <std::array<char,3>,3> T_board = board.getSBoard(2,0).getBoard();
    int k = 0;
    std::array<QToolButton*,9> Buttons={
                                            ui->B_0_21,
                                            ui->B_0_23,
                                            ui->B_0_22,
                                            ui->B_1_21,
                                            ui->B_1_23,
                                            ui->B_1_22,
                                            ui->B_2_21,
                                            ui->B_2_22,
                                            ui->B_2_23};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::string placeholder= "";
            placeholder += T_board.at(i).at(j);
            Buttons.at(k)->setText(QString::fromStdString(placeholder));
            if(T_board.at(i).at(j)!=' '){
                Buttons.at(k)->setEnabled(false);
            }else{
                Buttons.at(k)->setEnabled(true);
            }
            k++;
        }
    }

}
void MainWindow::Update_2_1(){
    std::array <std::array<char,3>,3> T_board = board.getSBoard(2,1).getBoard();
    int k = 0;
    std::array<QToolButton*,9> Buttons={
                                            ui->B_0_24,
                                            ui->B_0_26,
                                            ui->B_0_25,
                                            ui->B_1_24,
                                            ui->B_1_26,
                                            ui->B_1_25,
                                            ui->B_2_24,
                                            ui->B_2_25,
                                            ui->B_2_26};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::string placeholder= "";
            placeholder += T_board.at(i).at(j);
            Buttons.at(k)->setText(QString::fromStdString(placeholder));
            if(T_board.at(i).at(j)!=' '){
                Buttons.at(k)->setEnabled(false);
            }else{
                Buttons.at(k)->setEnabled(true);
            }
            k++;
        }
    }

}
void MainWindow::Update_2_2(){
    std::array <std::array<char,3>,3> T_board = board.getSBoard(2,2).getBoard();
    int k = 0;
    std::array<QToolButton*,9> Buttons={
                                            ui->B_0_27,
                                            ui->B_0_29,
                                            ui->B_0_28,
                                            ui->B_1_27,
                                            ui->B_1_29,
                                            ui->B_1_28,
                                            ui->B_2_27,
                                            ui->B_2_28,
                                            ui->B_2_29};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::string placeholder= "";
            placeholder += T_board.at(i).at(j);
            Buttons.at(k)->setText(QString::fromStdString(placeholder));
            if(T_board.at(i).at(j)!=' '){
                Buttons.at(k)->setEnabled(false);
            }else{
                Buttons.at(k)->setEnabled(true);
            }
            k++;
        }
    }

}










//board 0 0
void MainWindow::on_B_0_0_clicked()
{
    play(std::pair(0,0),std::pair(0,0));
}

void MainWindow::on_B_0_1_clicked()
{
    play(std::pair(0,0),std::pair(0,1));
}
void MainWindow::on_B_0_2_clicked()
{
    play(std::pair(0,0),std::pair(0,2));
}
void MainWindow::on_B_1_0_clicked()
{
    play(std::pair(0,0),std::pair(1,0));
}

void MainWindow::on_B_1_1_clicked()
{
    play(std::pair(0,0),std::pair(1,1));
}
void MainWindow::on_B_1_2_clicked()
{
    play(std::pair(0,0),std::pair(1,2));
}
void MainWindow::on_B_2_0_clicked()
{
    play(std::pair(0,0),std::pair(2,0));
}
void MainWindow::on_B_2_1_clicked()
{
    play(std::pair(0,0),std::pair(2,1));
}
void MainWindow::on_B_2_2_clicked()
{
    play(std::pair(0,0),std::pair(2,2));
}
//board 0 0

//board 0 1

void MainWindow::on_B_0_6_clicked()
{
    play(std::pair(0,1),std::pair(0,0));
}
void MainWindow::on_B_0_8_clicked()
{
    play(std::pair(0,1),std::pair(0,1));
}
void MainWindow::on_B_0_7_clicked()
{
    play(std::pair(0,1),std::pair(0,2));
}
void MainWindow::on_B_1_6_clicked()
{
    play(std::pair(0,1),std::pair(1,0));
}
void MainWindow::on_B_1_8_clicked()
{
     play(std::pair(0,1),std::pair(1,1));
}
void MainWindow::on_B_1_7_clicked()
{
     play(std::pair(0,1),std::pair(1,2));
}
void MainWindow::on_B_2_6_clicked()
{
     play(std::pair(0,1),std::pair(2,0));
}
void MainWindow::on_B_2_7_clicked()
{
    play(std::pair(0,1),std::pair(2,1));
}
void MainWindow::on_B_2_8_clicked()
{
    play(std::pair(0,1),std::pair(2,2));
}
//board 0 1

//board 0 2

void MainWindow::on_B_0_9_clicked()
{
    play(std::pair(0,2),std::pair(0,0));
}
void MainWindow::on_B_0_11_clicked()
{
    play(std::pair(0,2),std::pair(0,1));
}
void MainWindow::on_B_0_10_clicked()
{
    play(std::pair(0,2),std::pair(0,2));
}
void MainWindow::on_B_1_9_clicked()
{
    play(std::pair(0,2),std::pair(1,0));
}
void MainWindow::on_B_1_11_clicked()
{
    play(std::pair(0,2),std::pair(1,1));
}
void MainWindow::on_B_1_10_clicked()
{
    play(std::pair(0,2),std::pair(1,2));
}
void MainWindow::on_B_2_9_clicked()
{
    play(std::pair(0,2),std::pair(2,0));
}
void MainWindow::on_B_2_10_clicked()
{
    play(std::pair(0,2),std::pair(2,1));
}
void MainWindow::on_B_2_11_clicked()
{
    play(std::pair(0,2),std::pair(2,2));
}
// 0 2

// 1 0
void MainWindow::on_B_0_12_clicked()
{
    play(std::pair(1,0),std::pair(0,0));
}
void MainWindow::on_B_0_14_clicked()
{
    play(std::pair(1,0),std::pair(0,1));
}
void MainWindow::on_B_0_13_clicked()
{
    play(std::pair(1,0),std::pair(0,2));
}
void MainWindow::on_B_1_12_clicked()
{
    play(std::pair(1,0),std::pair(1,0));
}
void MainWindow::on_B_1_14_clicked()
{
    play(std::pair(1,0),std::pair(1,1));
}
void MainWindow::on_B_1_13_clicked()
{
    play(std::pair(1,0),std::pair(1,2));
}
void MainWindow::on_B_2_12_clicked()
{
    play(std::pair(1,0),std::pair(2,0));
}
void MainWindow::on_B_2_13_clicked()
{
    play(std::pair(1,0),std::pair(2,1));
}
void MainWindow::on_B_2_14_clicked()
{
    play(std::pair(1,0),std::pair(2,2));
}
// 1 0

// 1 1 start
void MainWindow::on_B_0_15_clicked()
{
    play(std::pair(1,1),std::pair(0,0));
}


void MainWindow::on_B_0_17_clicked()
{
    play(std::pair(1,1),std::pair(0,1));
}


void MainWindow::on_B_0_16_clicked()
{
    play(std::pair(1,1),std::pair(0,2));
}


void MainWindow::on_B_1_15_clicked()
{
    play(std::pair(1,1),std::pair(1,0));
}


void MainWindow::on_B_1_17_clicked()
{
    play(std::pair(1,1),std::pair(1,1));
}


void MainWindow::on_B_1_16_clicked()
{
    play(std::pair(1,1),std::pair(1,2));
}


void MainWindow::on_B_2_15_clicked()
{
    play(std::pair(1,1),std::pair(2,0));
}


void MainWindow::on_B_2_16_clicked()
{
    play(std::pair(1,1),std::pair(2,1));
}


void MainWindow::on_B_2_17_clicked()
{
    play(std::pair(1,1),std::pair(2,2));
}
//1 1 end

// 1 2 start
void MainWindow::on_B_0_18_clicked()
{
     play(std::pair(1,2),std::pair(0,0));
}


void MainWindow::on_B_0_20_clicked()
{
    play(std::pair(1,2),std::pair(0,1));
}


void MainWindow::on_B_0_19_clicked()
{
    play(std::pair(1,2),std::pair(0,2));
}


void MainWindow::on_B_1_18_clicked()
{
    play(std::pair(1,2),std::pair(1,0));
}


void MainWindow::on_B_1_20_clicked()
{
    play(std::pair(1,2),std::pair(1,1));
}


void MainWindow::on_B_1_19_clicked()
{
    play(std::pair(1,2),std::pair(1,2));
}


void MainWindow::on_B_2_18_clicked()
{
    play(std::pair(1,2),std::pair(2,0));
}


void MainWindow::on_B_2_19_clicked()
{
    play(std::pair(1,2),std::pair(2,1));
}


void MainWindow::on_B_2_20_clicked()
{
    play(std::pair(1,2),std::pair(2,2));
}

//1 2 end

//2 0
void MainWindow::on_B_0_21_clicked()
{
    play(std::pair(2,0),std::pair(0,0));
}


void MainWindow::on_B_0_23_clicked()
{
    play(std::pair(2,0),std::pair(0,1));
}


void MainWindow::on_B_0_22_clicked()
{
    play(std::pair(2,0),std::pair(0,2));
}


void MainWindow::on_B_1_21_clicked()
{
    play(std::pair(2,0),std::pair(1,0));
}


void MainWindow::on_B_1_23_clicked()
{
    play(std::pair(2,0),std::pair(1,1));
}


void MainWindow::on_B_1_22_clicked()
{
    play(std::pair(2,0),std::pair(1,2));
}


void MainWindow::on_B_2_21_clicked()
{
    play(std::pair(2,0),std::pair(2,0));
}


void MainWindow::on_B_2_22_clicked()
{
    play(std::pair(2,0),std::pair(2,1));
}


void MainWindow::on_B_2_23_clicked()
{
    play(std::pair(2,0),std::pair(2,2));
}
//2 0 end

//2 1 start
void MainWindow::on_B_0_24_clicked()
{
    play(std::pair(2,1),std::pair(0,0));
}


void MainWindow::on_B_0_26_clicked()
{
    play(std::pair(2,1),std::pair(0,1));
}


void MainWindow::on_B_0_25_clicked()
{
    play(std::pair(2,1),std::pair(0,2));
}


void MainWindow::on_B_1_24_clicked()
{
    play(std::pair(2,1),std::pair(1,0));
}


void MainWindow::on_B_1_26_clicked()
{
    play(std::pair(2,1),std::pair(1,1));
}


void MainWindow::on_B_1_25_clicked()
{
    play(std::pair(2,1),std::pair(1,2));
}


void MainWindow::on_B_2_24_clicked()
{
    play(std::pair(2,1),std::pair(2,0));
}


void MainWindow::on_B_2_25_clicked()
{
    play(std::pair(2,1),std::pair(2,1));
}

void MainWindow::on_B_2_26_clicked()
{
    play(std::pair(2,1),std::pair(2,2));
}
//2 1 end

//2 2 start



void MainWindow::on_B_0_27_clicked()
{
    play(std::pair(2,2),std::pair(0,0));
}


void MainWindow::on_B_0_29_clicked()
{
    play(std::pair(2,2),std::pair(0,1));
}


void MainWindow::on_B_0_28_clicked()
{
    play(std::pair(2,2),std::pair(0,2));
}


void MainWindow::on_B_1_27_clicked()
{
    play(std::pair(2,2),std::pair(1,0));
}


void MainWindow::on_B_1_29_clicked()
{
    play(std::pair(2,2),std::pair(1,1));
}


void MainWindow::on_B_1_28_clicked()
{
    play(std::pair(2,2),std::pair(1,2));
}


void MainWindow::on_B_2_27_clicked()
{
    play(std::pair(2,2),std::pair(2,0));
}


void MainWindow::on_B_2_28_clicked()
{
    play(std::pair(2,2),std::pair(2,1));
}


void MainWindow::on_B_2_29_clicked()
{
    play(std::pair(2,2),std::pair(2,2));
}

