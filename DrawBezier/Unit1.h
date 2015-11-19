//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TImage *Image1;
    TGroupBox *GroupBox2;
    TButton *Button1;
    TButton *Button2;
    TButton *Button3;
    TGroupBox *GroupBox3;
    TEdit *Edit1;
    TLabel *Label1;
    TGroupBox *GroupBox4;
    TButton *Button4;
    TButton *Button5;
    TButton *Button6;
    TButton *Button7;
    TButton *Button8;
    TButton *Button9;
    TEdit *Edit2;
    TUpDown *UpDown1;
    TGroupBox *GroupBox6;
    TButton *Button10;
    TButton *Button11;
    TButton *Button12;
    TButton *Button13;
    TGroupBox *GroupBox7;
    TButton *Button14;
    TButton *Button15;
    TButton *Button16;
    TButton *Button17;
    TGroupBox *GroupBox8;
    TButton *Button18;
    TButton *Button19;
    TButton *Button20;
    TButton *Button21;
    TGroupBox *GroupBox9;
    TCheckBox *CheckBox1;
    TGroupBox *GroupBox1;
    TTrackBar *T1;
    TTrackBar *T2;
    TImage *Image2;
    void __fastcall T1Change(TObject *Sender);
    void __fastcall T2Change(TObject *Sender);
    void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button5Click(TObject *Sender);
    void __fastcall Button6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
    void __fastcall DrawBezier(TRect rect, int curveX, int curveY);
    TPoint p[13] ;
    TRect SelectRect;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
