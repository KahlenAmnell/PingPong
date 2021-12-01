//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Board.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBoardWindow *BoardWindow;
//---------------------------------------------------------------------------
__fastcall TBoardWindow::TBoardWindow(TComponent* Owner)
        : TForm(Owner)
{
        y = 5;
        x = 5;
}
//---------------------------------------------------------------------------

void __fastcall TBoardWindow::startButtonClick(TObject *Sender)
{
    controlPicture->Visible = false;
    startButton->Visible = false;
    ballTimer->Enabled = true;
    randomStart();
}
//---------------------------------------------------------------------------

void __fastcall TBoardWindow::ballTimerTimer(TObject *Sender)
{
        ballMove();
        wallCollision();

}
//---------------------------------------------------------------------------

void TBoardWindow::randomStart()
{
        randomize();
        int startOption = random(4);
        switch(startOption)
        {
                case 1:
                        break;
                case 2:
                        y = -y;
                        break;
                case 3:
                        x = -x;
                        break;
                case 4:
                        x = -x;
                        y = -y;
                        break;
        }
}
//---------------------------------------------------------------------------

void TBoardWindow::ballMove()
{
        ball->Left += x;
        ball->Top += y;
}

//---------------------------------------------------------------------------

void TBoardWindow::wallCollision()
{
        if(ball->Top <= 0)
        {
                y = -y;
         }
        if(ball->Top + (ball->Height)*2 >= BoardWindow->Height)
        {
                y = -y;
         }
}

//---------------------------------------------------------------------------


