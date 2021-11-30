//---------------------------------------------------------------------------

#ifndef MainMenuH
#define MainMenuH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TMainMenuWindow : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *newGameButton;
        TBitBtn *optionButton;
        TBitBtn *closeButton;
        TLabel *mainMenu;
private:	// User declarations
public:		// User declarations
        __fastcall TMainMenuWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainMenuWindow *MainMenuWindow;
//---------------------------------------------------------------------------
#endif
