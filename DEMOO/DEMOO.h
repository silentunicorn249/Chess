#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_DEMOO.h"
class DEMOO : public QMainWindow
{
    Q_OBJECT

public:
    DEMOO(QWidget *parent = nullptr);
    ~DEMOO();
        
private:
    Ui::DEMOOClass ui;
    QGridLayout* layout;
    QPushButton* pushButton61;
    QPushButton* pushButton00;
    QPushButton* pushButton64;
    QPushButton* pushButton02;
    QPushButton* pushButton17;
    QPushButton* pushButton25;
    QPushButton* pushButton07;
    QPushButton* pushButton55;
    QPushButton* pushButton43;
    QPushButton* pushButton27;
    QPushButton* pushButton14;
    QPushButton* pushButton51;
    QPushButton* pushButton32;
    QPushButton* pushButton57;
    QPushButton* pushButton22;
    QPushButton* pushButton52;
    QPushButton* pushButton47;
    QPushButton* pushButton54;
    QPushButton* pushButton30;
    QPushButton* pushButton56;
    QPushButton* pushButton26;
    QPushButton* pushButton65;
    QPushButton* pushButton42;
    QPushButton* pushButton35;
    QPushButton* pushButton31;
    QPushButton* pushButton15;
    QPushButton* pushButton23;
    QPushButton* pushButton16;
    QPushButton* pushButton13;
    QPushButton* pushButton12;
    QPushButton* pushButton20;
    QPushButton* pushButton40;
    QPushButton* pushButton62;
    QPushButton* pushButton45;
    QPushButton* pushButton41;
    QPushButton* pushButton04;
    QPushButton* pushButton67;
    QPushButton* pushButton24;
    QPushButton* pushButton21;
    QPushButton* pushButton06;
    QPushButton* pushButton34;
    QPushButton* pushButton46;
    QPushButton* pushButton33;
    QPushButton* pushButton53;
    QPushButton* pushButton10;
    QPushButton* pushButton50;
    QPushButton* pushButton05;
    QPushButton* pushButton37;
    QPushButton* pushButton63;
    QPushButton* pushButton01;
    QPushButton* pushButton11;
    QPushButton* pushButton36;
    QPushButton* pushButton60;
    QPushButton* pushButton66;
    QPushButton* pushButton44;
    QPushButton* pushButton03;
    QPushButton* pushButton72;
    QPushButton* pushButton74;
    QPushButton* pushButton75;
    QPushButton* pushButton76;
    QPushButton* pushButton77;
    QPushButton* pushButton73;
    QPushButton* pushButton71;
    QPushButton* pushButton70;
    QWidget* centralWidget;
    QWidget* gridLayoutWidget;
    QGridLayout* gridLayout_2;
    QPushButton* numButtons[8][8];
    void Image(int row, int col);
//    void Disablebuttons(Piece* p);
//    void Enablebuttons(Piece* p);


private slots:

    void Click();
 
};
