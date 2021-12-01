//---------------------------------------------------------------------------

#ifndef BoardH
#define BoardH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TBoardWindow : public TForm
{
__published:	// IDE-managed Components
        TImage *paddleLeft;
        TImage *paddleRight;
        TImage *ball;
        TImage *controlPicture;
        TTimer *leftPalletTimer;
        TTimer *RightPalletTimer;
        TTimer *ballTimer;
private:	// User declarations
public:		// User declarations
        __fastcall TBoardWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBoardWindow *BoardWindow;
//---------------------------------------------------------------------------
#endif
