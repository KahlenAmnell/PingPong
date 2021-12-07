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
        bluePlayerResult = 0;
        redPlayerResult = 0;
}
//---------------------------------------------------------------------------

void __fastcall TBoardWindow::startButtonClick(TObject *Sender)
{
    ball->Left = 500;
    ball->Top = 288;
    controlPicture->Visible = false;
    startButton->Visible = false;
    ballTimer->Enabled = true;
    finishCondition(false);
    bounceCounter = 0;
    y = 5;
    x = 5;
    randomStart();
}
//---------------------------------------------------------------------------

void __fastcall TBoardWindow::ballTimerTimer(TObject *Sender)
{
        ballMove();
        wallCollision();
        paddleCollision();
        if(isOver() == true)
        {
                ball->Enabled = false;
                ballTimer->Enabled = false;
                finishCondition(true);
                intResult->Caption = IntToStr(bluePlayerResult) + " : " + IntToStr(redPlayerResult);
                numberOfBounce->Caption = "Liczba odbic: " + IntToStr(bounceCounter);
        }
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
        int ballMiddleHeight =  ball->Top + (ball->Height/2);
        int ballDown = ball->Top + ball->Height;
        int ballRight = ball->Left + ball->Width;
        int ballMiddleWidth = ball->Left + (ball->Width/2);

        int paddleLeftDown =  paddleLeft->Top + paddleLeft->Height;
        int paddleLeftRight = paddleLeft->Left + paddleLeft->Width;
        int paddleLeftHeightMiddle = paddleLeft->Top + (paddleLeft->Height/2);

        int paddleRightDown = paddleRight->Top + paddleRight->Height;
        int paddleRightRight = paddleRight->Left + paddleRight->Width;
        int paddleRightHeightMiddle = paddleRight->Top + (paddleRight->Height/2);

        if( (ballDown >= paddleLeft->Top) && (ball->Top <= (paddleLeft->Top - ball->Height)) &&
             (ballMiddleWidth >= paddleLeft->Left) && (ballMiddleWidth <= paddleLeftRight))
           {
                y = -y;
                bounceCounter++;
           }
        if ((ball->Top <= paddleLeftDown) && (ball->Top <= (paddleLeft->Top + ball->Height)) &&
             (ballMiddleWidth >= paddleLeft->Left) && (ballMiddleWidth <= paddleLeftRight))
             {
                y = -y;
                bounceCounter++;
           }

        if( (ballDown >= paddleRight->Top) && (ball->Top <= (paddleRight->Top - ball->Height)) &&
             (ballMiddleWidth >= paddleRight->Left) && (ballMiddleWidth <= paddleRightRight))
           {
                y = -y;
                bounceCounter++;
           }

        if ((ball->Top <= paddleRightDown) && (ball->Top <= (paddleRight->Top + ball->Height)) &&
             (ballMiddleWidth >= paddleRight->Left) && (ballMiddleWidth <= paddleRightRight))
             {
                y = -y;
                bounceCounter++;
           }

        if( (ballDown > paddleLeft->Top) && (ball->Top < paddleLeftDown) &&
            (ball->Left <= paddleLeftRight) && (ball->Left > paddleLeft->Left) )
        {
                if((ballMiddleHeight < (paddleLeftHeightMiddle + 20)) &&
                  ( ballMiddleHeight > (paddleLeftHeightMiddle - 20)))
                {
                        x -= 1;
                }
                else if( (ballMiddleHeight < paddleLeft->Top +10) &&
                         (ballMiddleHeight > (paddleLeftDown - 10)) )
                {
                        if(x<-5)
                        {
                                x += 1;
                        }
                }
                x = -x;
                bounceCounter++;
        }
        if( (ballDown > paddleRight->Top) && (ball->Top < paddleRightDown) &&
            (ballRight >= paddleRight->Left) && (ballRight < paddleRightRight) )
        {
                if((ballMiddleHeight < (paddleRightHeightMiddle + 20)) &&
                  ( ballMiddleHeight > (paddleRightHeightMiddle - 20)))
                {
                        x += 1;
                }
                else if( (ballMiddleHeight < paddleRight->Top +10) &&
                         (ballMiddleHeight > (paddleRightDown - 10)) )
                {
                        if(x>5)
                        {
                                x -= 1;
                        }
                }
                x = -x;
                bounceCounter++;
        }
}

bool  TBoardWindow::isOver()
{
        if (ball->Left < 0)
        {
                whoWin->Caption = "Czerwony";
                redPlayerResult++;
                return true;
        }
        else if((ball->Left + ball->Width) > BoardWindow->Width)
        {
                whoWin->Caption = "Niebieski";
                bluePlayerResult++;
                return true;
        }
        else
                return false;
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
void TBoardWindow::finishCondition(bool con)
{
        win->Visible = con;
        whoWin->Visible = con;
        result->Visible =con;
        intResult->Visible = con;
        numberOfBounce->Visible = con;
        returnToMenuButton->Visible = con;
        startButton->Visible = con;
        startButton->Caption = "Nastepna runda";
}

void __fastcall TBoardWindow::returnToMenuButtonClick(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------



void __fastcall TBoardWindow::FormCreate(TObject *Sender)
{
        BoardWindow->DoubleBuffered = true;
}
//---------------------------------------------------------------------------

