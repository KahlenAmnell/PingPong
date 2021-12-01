//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainMenu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainMenuWindow *MainMenuWindow;
//---------------------------------------------------------------------------
__fastcall TMainMenuWindow::TMainMenuWindow(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TMainMenuWindow::newGameButtonClick(TObject *Sender)
{
        Application->CreateForm(__classid(TBoardWindow), &BoardWindow);
}
//---------------------------------------------------------------------------

void __fastcall TMainMenuWindow::closeButtonClick(TObject *Sender)
{
        Application->Terminate();
}
//---------------------------------------------------------------------------

