//---------------------------------------------------------------------------

#ifndef GameOptionH
#define GameOptionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TGameOptionWindow : public TForm
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
        __fastcall TGameOptionWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGameOptionWindow *GameOptionWindow;
//---------------------------------------------------------------------------
#endif
