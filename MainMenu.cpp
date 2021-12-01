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
        BoardWindow->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TMainMenuWindow::newGameButtonClick(TObject *Sender)
{
        Application->CreateForm(__classid(TMainMenuWindow), &MainMenuWindow);
}
//---------------------------------------------------------------------------

