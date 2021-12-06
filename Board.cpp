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
        if( ((ball->Top + ball->Height) > paddleLeft->Top) &&
            (ball->Top < (paddleLeft->Top + paddleLeft->Height)) &&
            (ball->Left <= (paddleLeft->Left + paddleLeft->Width)) &&
            (ball->Left > paddleLeft->Left) )
        {
                x = -x;
                bounceCounter++;
        }
        if( ((ball->Top + ball->Height) > paddleRight->Top) &&
            (ball->Top < (paddleRight->Top + paddleRight->Height)) &&
            ((ball->Left+ball->Width) >= paddleRight->Left) &&
            (ball->Left + ball->Width < paddleRight->Left + paddleRight->Width) )
        {
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



