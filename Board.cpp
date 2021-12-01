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

