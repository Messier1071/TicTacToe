#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "lib/STTT.h"
#include <iostream>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    SuperTicTacToe board;
    bool BoardSelected;
    std::pair<std::pair<bool,char>,std::pair<int,int>> WinCon;
    bool GameEnded;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void UpdateAll();

    void Updatebackground(std::pair<int,int> currentBoard);

    void Update_0_0();

    void Update_0_1();

    void Update_0_2();

    void Update_1_0();

    void Update_1_1();

    void Update_1_2();

    void Update_2_0();

    void Update_2_1();

    void Update_2_2();




    void on_B_0_0_clicked();
    void on_B_0_1_clicked();
    void on_B_0_2_clicked();
    void on_B_1_0_clicked();
    void on_B_1_1_clicked();
    void on_B_1_2_clicked();
    void on_B_2_0_clicked();
    void on_B_2_1_clicked();
    void on_B_2_2_clicked();





    void on_B_0_6_clicked();
    void on_B_0_8_clicked();
    void on_B_0_7_clicked();
    void on_B_1_6_clicked();
    void on_B_1_8_clicked();
    void on_B_1_7_clicked();
    void on_B_2_6_clicked();
    void on_B_2_7_clicked();
    void on_B_2_8_clicked();
    void on_B_0_9_clicked();
    void on_B_0_11_clicked();
    void on_B_0_10_clicked();
    void on_B_1_9_clicked();
    void on_B_1_11_clicked();
    void on_B_1_10_clicked();
    void on_B_2_9_clicked();
    void on_B_2_10_clicked();
    void on_B_2_11_clicked();
    void on_B_0_12_clicked();
    void on_B_0_14_clicked();
    void on_B_0_13_clicked();
    void on_B_1_12_clicked();
    void on_B_1_14_clicked();
    void on_B_1_13_clicked();
    void on_B_2_12_clicked();
    void on_B_2_13_clicked();
    void on_B_2_14_clicked();
    void on_B_0_15_clicked();
    void on_B_0_17_clicked();
    void on_B_0_16_clicked();
    void on_B_1_15_clicked();
    void on_B_1_17_clicked();
    void on_B_1_16_clicked();
    void on_B_2_15_clicked();
    void on_B_2_16_clicked();
    void on_B_2_17_clicked();
    void on_B_0_18_clicked();
    void on_B_0_20_clicked();
    void on_B_0_19_clicked();
    void on_B_1_18_clicked();
    void on_B_1_20_clicked();
    void on_B_1_19_clicked();
    void on_B_2_18_clicked();
    void on_B_2_19_clicked();
    void on_B_2_20_clicked();
    void on_B_0_21_clicked();
    void on_B_0_23_clicked();
    void on_B_0_22_clicked();
    void on_B_1_21_clicked();
    void on_B_1_23_clicked();
    void on_B_1_22_clicked();
    void on_B_2_21_clicked();
    void on_B_2_22_clicked();
    void on_B_2_23_clicked();
    void on_B_0_24_clicked();
    void on_B_0_26_clicked();
    void on_B_0_25_clicked();
    void on_B_1_24_clicked();
    void on_B_1_26_clicked();
    void on_B_1_25_clicked();
    void on_B_2_24_clicked();
    void on_B_2_25_clicked();
    void on_B_2_26_clicked();
    void on_B_0_27_clicked();
    void on_B_0_29_clicked();
    void on_B_0_28_clicked();
    void on_B_1_27_clicked();
    void on_B_1_29_clicked();
    void on_B_1_28_clicked();
    void on_B_2_27_clicked();
    void on_B_2_28_clicked();
    void on_B_2_29_clicked();

private:
    Ui::MainWindow *ui;
    void play(std::pair<int,int> BoardCoordinate,std::pair<int,int>Coordinate);
};
#endif // MAINWINDOW_H
