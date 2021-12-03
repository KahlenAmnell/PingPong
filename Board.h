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
        TTimer *leftPaddleUpTimer;
        TTimer *rightPaddleUpTimer;
        TTimer *ballTimer;
        TButton *startButton;
        TTimer *leftPaddleDownTimer;
        TTimer *rightPaddleDownTimer;
        void __fastcall ballTimerTimer(TObject *Sender);
        void __fastcall startButtonClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall leftPaddleUpTimerTimer(TObject *Sender);
        void __fastcall leftPaddleDownTimerTimer(TObject *Sender);
        void __fastcall rightPaddleUpTimerTimer(TObject *Sender);
        void __fastcall rightPaddleDownTimerTimer(TObject *Sender);
private:	// User declarations
        void randomStart();
        void ballMove();
        void wallCollision();
        void paddleCollision();
        bool isOver();

public:		// User declarations
        __fastcall TBoardWindow(TComponent* Owner);
        int y;
        int x;

};
//---------------------------------------------------------------------------
extern PACKAGE TBoardWindow *BoardWindow;
//---------------------------------------------------------------------------
#endif
