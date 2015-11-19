#ifndef __RectTracker_H
#define __RectTracker_H
/***************************
 * VERSION:   2           *
 * REFERENCE: NONE        *
 **************************/

#include <Windows.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
/*#include <Forms.hpp>*/
//---------------------------------------------------------------
#define   rhitLeftTop          1
#define   rhitRightTop         2
#define   rhitLeftBottom       3
#define   rhitRightBottom      4
#define   rhitLeftCenter       5
#define   rhitRightCenter      6
#define   rhitTopCenter        7
#define   rhitBottomCenter     8
#define   rhitInside           10
#define   rhitNothing          -1
//---------------------------------------------------------------
enum ERectHandleType{ rhtLeftTop, rhtRightTop, rhtLeftBottom, rhtRightBottom,
                      rhtLeftCenter, rhtRightCenter, rhtTopCenter, rhtBottomCenter };
class YRectTracker
{
private:
     TCanvas*       OwnerCanvas;
     TRect          ValidRect;
     int            HandleWidth;
     int            HandleHeight;
     TColor         RectColor;
     TColor         HandleColor;
     TColor         ChoosedColor;
     TColor         DrawRectColor;

     int            ID;
     bool           HandleAble;
     bool           Sizeabled;
     bool           IsChoosed;
     AnsiString     Name;
     bool           UseBezier;     //使用貝茲
public:
     bool           Visible;       //畫框是否可被看見
public:
     YRectTracker(TCanvas *Canvas, int number);
     YRectTracker(TCanvas *Canvas, TRect &rect, int number);
     YRectTracker(TCanvas *Canvas, TPoint &LeftTop, TPoint &RightBottom, int number);
     YRectTracker(TCanvas *Canvas, TRect &rect, AnsiString name);
     ~YRectTracker(void);
     void      __fastcall SetDefaults(void);
     TRect     __fastcall GetRect(void);
     TRect     __fastcall GetHandleRect(ERectHandleType type);
     void      __fastcall SetRect(TRect &rect);
     void      __fastcall SetColor(TColor color);
     void      __fastcall SetHandleColor(TColor color);
     void      __fastcall SetHandleAble(bool able);
     void      __fastcall SetHandleAble(bool enableTrk, bool changeSize);
     bool      __fastcall GetHandleAble(void);
     void      __fastcall SetChoosed(bool choosed);
     void      __fastcall SetID(int number);
     int       __fastcall GetID(void);
     void      __fastcall SetName(AnsiString nm);
     bool      __fastcall IsInRect(int X, int Y);
     bool      __fastcall IsInRect(int X, int Y, TRect &rect);
     void      __fastcall NormalizeRect(TRect &rect);
     void      __fastcall Paint(void);
     int       __fastcall HitTest(int X, int Y);
     bool      __fastcall Track(int StartX, int StartY);
     bool      __fastcall TrackHandle(int StartX, int StartY, int HitTest);

     bool      __fastcall TrackInRect(int StartX, int StartY, int HitTest, TRect &Rect);
     bool      __fastcall SetBezier(int usebezier){UseBezier = usebezier;};
};
#endif
 