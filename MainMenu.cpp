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

void __fastcall TMainMenuWindow::optionButtonClick(TObject *Sender)
{
        GameOptionWindow->Visible = true;        
}
//---------------------------------------------------------------------------

AnsiString TMainMenuWindow::controlText()
{
AnsiString welcome = "Witaj w grze Ping Pong!\n";
AnsiString leftPaddleControl = "\nGracz niebieski steruje klawiszami 'W' i 'S'\n";
AnsiString rightPaddleControl = "Gracz czerwony steruje strzalka w gore i w dol\n";
AnsiString acceleration = "\nGdy pilka uderzy w srodek paletki, to przyspieszy.\n";
AnsiString slowingDown = "Natomiast gdy uderzy w jej obrzeza, to zwolni.\n";
AnsiString sizeable = "\nRomiar planszy moze byc dowolnie modyfikowany.\n";
AnsiString wishes = "\nPowodzenia!";
AnsiString text = welcome + leftPaddleControl + rightPaddleControl + acceleration + slowingDown + sizeable + wishes;
return text;
}
//---------------------------------------------------------------------------

void __fastcall TMainMenuWindow::FormCreate(TObject *Sender)
{
        ShowMessage(controlText());
}
//---------------------------------------------------------------------------

