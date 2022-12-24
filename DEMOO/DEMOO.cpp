
#include "DEMOO.h" 
#include<iostream>
#include"gBoard.h"
#include <QtWidgets/QApplication>
#include<QString>
#include<QDebug>
#include <QGraphicsDropShadowEffect>
#include"AllPossibleMoves.h"
#include"Check.h"
using namespace std;
QPushButton* caller;

 int nclick = 0;
 int orow;
int ocol;
int r;
int c;
int turn = 0;
QString e;
 
DEMOO::DEMOO(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
 
    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 8; j++) {
            QString butname = "pushButton" + QString::number(i) + QString::number(j);
            numButtons[i][j] = findChild<QPushButton*>(butname);
            Image(i,j);
           connect(numButtons[i][j], SIGNAL(released()), this, SLOT(Click()));
        }
    }  
}
void DEMOO::Click()
{
     b.display();
      if (nclick==1)/*return original color*/
    {
        caller->setStyleSheet(e);
        ocol = c;
        orow = r;
    }
       caller = qobject_cast<QPushButton*>(sender());
        e = caller->styleSheet();
        QString buttonv = caller->objectName();//get row and column
        qDebug() << "caller:" << caller->objectName();
        QString row = buttonv[10];
        QString col = buttonv[11];
         r = row.toInt();
         c = col.toInt();
         //we reset the nclick to enable the one in turn to move (not to pass the 
         //turn to the other player)for moving agaiin (not to pass the turn t
         if ((orow == r) && (ocol == c))
         {
             nclick = 0;
         }
         //saving the right coordinates of the initial place of the piece we want to move
         if (nclick == 0)
         {
             orow = r;
             ocol = c;
         }
          if ((turn % 2 == 0))//white turn
          {
              //check if the first click has a piece and is the desired color 
             if(b.board[orow][ocol]->getPiece() &&(b.board[orow][ocol]->getPiece()->isWhite()))
             {                 
                 //check if it's the first click to change it to grey
                     if (((b.board[r][c]->getPiece()) && (nclick == 0)))
                     {
                         numButtons[r][c]->setStyleSheet("background-color: grey");
                         nclick = 1;
                     }                 
             }
             //avoiding moving between two null squares
               if (((b.board[orow][ocol]->getPiece()) && (nclick == 1) && (b.board[orow][ocol]->getPiece()->isWhite())))
             {                      
                     bool validmove = b.board[orow][ocol]->getPiece()->move(orow, ocol, r, c);
                     if (validmove == true)
                     {
                         Board b2 = Board(b);
                      b.board[orow][ocol]->move(r, c);
                      if (checkWhite())
                      {
                          b = b2;
                          qDebug() << "killing myself white";
                          return;
                      }
                      checkBlack();
                      numButtons[orow][ocol]->setIcon(QIcon());
                      Image(r, c);
                      if (CheckMateBlack())
                      {
                          qDebug() << "WHITE WINS!";
                      }
                      nclick = 0;
                      turn++;
                     }                     
             }
          }

         else
         {
              if (b.board[orow][ocol]->getPiece() && !(b.board[orow][ocol]->getPiece()->isWhite()))
              {
                  if (((b.board[r][c]->getPiece()) && (nclick == 0)))
                  {
                      numButtons[r][c]->setStyleSheet("background-color: grey");
                      nclick = 1;
                  }
              }
              if (((b.board[orow][ocol]->getPiece()) && (nclick == 1)) && !(b.board[orow][ocol]->getPiece()->isWhite()))
              {                      
                  bool validmove = b.board[orow][ocol]->getPiece()->move(orow, ocol, r, c);
                  if (validmove == true)
                  {
                      Board b2 = Board(b);
                    b.board[orow][ocol]->move(r, c);
                    if (checkBlack())
                    {
                        b = b2;
                        qDebug() << "killing myself black";
                        return;
                    }
                    checkWhite();
                    numButtons[orow][ocol]->setIcon(QIcon());
                    Image(r, c);
                    if (CheckMateWhite())
                    {
                        qDebug() << "BLACK WINS!";
                    }
                    nclick = 0;
                    turn++;
                  }
                     
              }
         }         
}


DEMOO::~DEMOO()
{}

void DEMOO::Image(int row,int col)
{

    QIcon icon;

    QPixmap qpm;
    QString s;
    if (b.board[row][col]->getPiece() != nullptr)
    {
        if (b.board[row][col]->getPiece()->getName() == 'R' && b.board[row][col]->getPiece()->isWhite())
        {
            s = "C:/Users/nourn/Downloads/Saved Pictures/White/WRook.png";
        }
        else if (b.board[row][col]->getPiece()->getName() == 'B' && b.board[row][col]->getPiece()->isWhite())
        {
            s = "C:/Users/nourn/Downloads/Saved Pictures/White/Wbishop.png";

        }
        else if (b.board[row][col]->getPiece()->getName() == 'K' && b.board[row][col]->getPiece()->isWhite())
        {
            s = "C:/Users/nourn/Downloads/Saved Pictures/White/Wking.png";

        }
        else if (b.board[row][col]->getPiece()->getName() == 'N' && b.board[row][col]->getPiece()->isWhite())
        {
            s = "C:/Users/nourn/Downloads/Saved Pictures/White/Wknight.png";

        }
        else if (b.board[row][col]->getPiece()->getName() == 'P' && b.board[row][col]->getPiece()->isWhite())
        {
            s = "C:/Users/nourn/Downloads/Saved Pictures/White/Wpawn.png";

        }
        else if (b.board[row][col]->getPiece()->getName() == 'Q' && b.board[row][col]->getPiece()->isWhite())
        {
            s = "C:/Users/nourn/Downloads/Saved Pictures/White/Wqueen.png";

        }
        else if (b.board[row][col]->getPiece()->getName() == 'R' && !(b.board[row][col]->getPiece()->isWhite()))
        {
            s = "C:/Users/nourn/Downloads/Saved Pictures/Black/BRook.png";
        }
        else if (b.board[row][col]->getPiece()->getName() == 'B' && !(b.board[row][col]->getPiece()->isWhite()))
        {
            s = "C:/Users/nourn/Downloads/Saved Pictures/Black/Bbishop.png";

        }
        else if (b.board[row][col]->getPiece()->getName() == 'K' && !(b.board[row][col]->getPiece()->isWhite()))
        {
            s = "C:/Users/nourn/Downloads/Saved Pictures/Black/Bking.png";

        }
        else if (b.board[row][col]->getPiece()->getName() == 'N' && !(b.board[row][col]->getPiece()->isWhite()))
        {
            s = "C:/Users/nourn/Downloads/Saved Pictures/Black/Bknight.png";

        }
        else if (b.board[row][col]->getPiece()->getName() == 'P' && !(b.board[row][col]->getPiece()->isWhite()))
        {
            s = "C:/Users/nourn/Downloads/Saved Pictures/Black/Bpawn.png";

        }
        else if (b.board[row][col]->getPiece()->getName() == 'Q' && !(b.board[row][col]->getPiece()->isWhite()))
        {
            s = "C:/Users/nourn/Downloads/Saved Pictures/Black/Bqueen.png";

        }

        if (qpm.load(s))
        {
            icon.addPixmap(qpm);


            numButtons[row][col]->setIconSize(QSize(99, 70));

            numButtons[row][col]->setIcon(icon);
        }
    }
}

