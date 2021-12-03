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
        Label1->Visible = false;
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
        paddleCollision();
        isOver();
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

void TBoardWindow::paddleCollision()
{
        if( ((ball->Top - ball->Height+2) > paddleLeft->Top) &&
            (ball->Top -2 < paddleLeft->Top + paddleLeft->Height) &&
            (ball->Left == (paddleLeft->Left + paddleLeft->Width)) )
        {
                x = -x;
        }
        if( ((ball->Top - ball->Height+2) > paddleRight->Top) &&
            (ball->Top -2 < (paddleRight->Top + paddleRight->Height)) &&
            ((ball->Left+ball->Width) == paddleRight->Left) )
        {
                x = -x;
        }
}

void  TBoardWindow::isOver()
{
        if (ball->Left < 0)
        {
                Label1->Visible = true;
                Label1->Caption = "Wygrywa gracz po prawej";
                ball->Enabled = false;
        }
        if((ball->Left + ball->Width) > BoardWindow->Width)
        {
                Label1->Visible = true;
                Label1->Caption = "Wygrywa gracz po lewej";
                ball->Enabled = false;
        }
}
//---------------------------------------------------------------------------



void __fastcall TBoardWindow::FormCreate(TObject *Sender)
{
//DoubleBuffered = true;
}
//---------------------------------------------------------------------------


void __fastcall TBoardWindow::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == 'W')
        {
                leftPaddleUpTimer->Enabled = true;
        }
        else if(Key == 'S')
        {
                leftPaddleDownTimer->Enabled = true;
        }
        if(Key == VK_UP)
        {
                rightPaddleUpTimer->Enabled = true;
        }
        else if(Key == VK_DOWN)
        {
                rightPaddleDownTimer->Enabled = true;
        }

}
//---------------------------------------------------------------------------

void __fastcall TBoardWindow::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == 0x57)
        {
                leftPaddleUpTimer->Enabled = false;
        }
        else if(Key == 0x53)
        {
                leftPaddleDownTimer->Enabled = false;
        }
        if(Key == VK_UP)
        {
                rightPaddleUpTimer->Enabled = false;
        }
        else if(Key == VK_DOWN)
        {
                rightPaddleDownTimer->Enabled = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TBoardWindow::leftPaddleUpTimerTimer(TObject *Sender)
{
        if(paddleLeft->Top > 0)
             paddleLeft->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TBoardWindow::leftPaddleDownTimerTimer(TObject *Sender)
{
        if(paddleLeft->Top + paddleLeft->Height < BoardWindow->Height -40  )
             paddleLeft->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TBoardWindow::rightPaddleUpTimerTimer(TObject *Sender)
{
        if(paddleRight->Top > 0)
             paddleRight->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TBoardWindow::rightPaddleDownTimerTimer(TObject *Sender)
{
        if(paddleRight->Top + paddleRight->Height < BoardWindow->Height -40  )
             paddleRight->Top += 10;
}
//---------------------------------------------------------------------------

