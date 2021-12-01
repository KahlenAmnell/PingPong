//---------------------------------------------------------------------------

#ifndef MainMenuH
#define MainMenuH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include "Board.h"
//---------------------------------------------------------------------------
class TMainMenuWindow : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *newGameButton;
        TBitBtn *optionButton;
        TBitBtn *closeButton;
        TLabel *mainMenu;
        void __fastcall newGameButtonClick(TObject *Sender);
        void __fastcall closeButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainMenuWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainMenuWindow *MainMenuWindow;
//---------------------------------------------------------------------------
#endif
