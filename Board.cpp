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
    customizeLabelsToBoardWindowSize();
    ball->Left = BoardWindow->Width/2;
    ball->Top = BoardWindow->Height/2;
    paddleRight->Left = BoardWindow->Width - 44;
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

        int paddleLeftDown =  paddleLeft->Top + paddleLeft->Height;
        int paddleLeftRight = paddleLeft->Left + paddleLeft->Width;
        int paddleLeftHeightMiddle = paddleLeft->Top + (paddleLeft->Height/2);

        int paddleRightDown = paddleRight->Top + paddleRight->Height;
        int paddleRightRight = paddleRight->Left + paddleRight->Width;
        int paddleRightHeightMiddle = paddleRight->Top + (paddleRight->Height/2);

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
        if ((ball->Left+20) < (paddleLeft->Left+paddleLeft->Width))
        {
                whoWin->Caption = "Czerwony";
                redPlayerResult++;
                return true;
        }
        else if((ball->Left + ball->Width-20) > paddleRight->Left)
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
void TBoardWindow::finishCondition(bool condition)
{
        win->Visible = condition;
        whoWin->Visible = condition;
        result->Visible =condition;
        intResult->Visible = condition;
        numberOfBounce->Visible = condition;
        returnToMenuButton->Visible = condition;
        startButton->Visible = condition;
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

void TBoardWindow::customizeLabelsToBoardWindowSize()
{
        int leftCoordinate = BoardWindow->Width/2 - (intResult->Width/2);
        int buttonsLeft = BoardWindow->Width/2 - (startButton->Width/2);

        intResult->Left =  leftCoordinate;
        numberOfBounce->Left = leftCoordinate;
        result->Left = leftCoordinate;
        returnToMenuButton->Left = buttonsLeft;
        startButton->Left = buttonsLeft;
        whoWin->Left = leftCoordinate;
        win->Left = leftCoordinate;
}
