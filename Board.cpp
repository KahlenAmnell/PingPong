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
}
//---------------------------------------------------------------------------

void __fastcall TBoardWindow::ballTimerTimer(TObject *Sender)
{
        ball->Left += 5;
        ball->Top += 5;
}
//---------------------------------------------------------------------------

void __fastcall TBoardWindow::startButtonClick(TObject *Sender)
{
    controlPicture->Visible = false;
    this->Visible = false;
    ballTimer->Enabled = true;
}
//---------------------------------------------------------------------------

