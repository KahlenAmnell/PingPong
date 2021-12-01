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
        TButton *startButton;
        void __fastcall ballTimerTimer(TObject *Sender);
        void __fastcall startButtonClick(TObject *Sender);
private:	// User declarations
        void randomStart();
        void ballMove();
        void wallCollision();
public:		// User declarations
        __fastcall TBoardWindow(TComponent* Owner);
        int y;
        int x;

};
//---------------------------------------------------------------------------
extern PACKAGE TBoardWindow *BoardWindow;
//---------------------------------------------------------------------------
#endif
