/***************************
 * VERSION:   2           *
 * REFERENCE: NONE        *
 **************************/
#include "YRectTracker.h"

//---------------------------------------------------------------
//這種產生方式是在 RunTime 時的 ROI ,所以不用顯示出來
YRectTracker::YRectTracker(TCanvas *Canvas, int number)
{
     OwnerCanvas=Canvas;
     SetDefaults();
     ValidRect.Left=0;
     ValidRect.Top=0;
     ValidRect.Right=50;
     ValidRect.Bottom=50;

     HandleAble=false;
     Sizeabled =false;
     ID=number;
     Visible=false;
     Name = "";

     UseBezier = false;
}

//以下兩種產生方式為 Design Time 時的ROI, 所以要指定畫框的大小及設定可以 Handle
YRectTracker::YRectTracker(TCanvas *Canvas, TRect &rect, int number)
{
     OwnerCanvas=Canvas;
     SetDefaults();
     ValidRect.Left=rect.Left;
     ValidRect.Top=rect.Top;
     ValidRect.Right=rect.Right;
     ValidRect.Bottom=rect.Bottom;

     HandleAble=true;
     Sizeabled =true;
     ID=number;
     Visible=true;
     Name = "";
}

YRectTracker::YRectTracker(TCanvas *Canvas, TPoint &LeftTop, TPoint &RightBottom, int number)
{
     OwnerCanvas=Canvas;
     SetDefaults();
     ValidRect.Left=LeftTop.x;
     ValidRect.Top=LeftTop.y;
     ValidRect.Right=RightBottom.x;
     ValidRect.Bottom=RightBottom.y;

     HandleAble=true;
     Sizeabled =true;
     ID=number;
     Visible=true;
     Name = "";
}

YRectTracker::YRectTracker(TCanvas *Canvas, TRect &rect, AnsiString name)
{
     OwnerCanvas=Canvas;
     SetDefaults();
     ValidRect.Left=rect.Left;
     ValidRect.Top=rect.Top;
     ValidRect.Right=rect.Right;
     ValidRect.Bottom=rect.Bottom;

     HandleAble=true;
     Sizeabled =true;
     ID=0;
     Visible=true;
     Name = name;
}


YRectTracker::~YRectTracker(void)
{
}
//---------------------------------------------------------------
void __fastcall YRectTracker::SetDefaults(void)
{
     RectColor=clRed;
     DrawRectColor=RectColor;
     HandleColor=clWhite;
     ChoosedColor=clLime;
     HandleWidth=8;
     HandleHeight=8;
}
//---------------------------------------------------------------
TRect __fastcall YRectTracker::GetRect(void)
{
     return (ValidRect);
}
//---------------------------------------------------------------
TRect __fastcall YRectTracker::GetHandleRect(ERectHandleType type)
{
     TRect rtn;
     switch(type)
     {
        case rhtLeftTop:      rtn.Left=ValidRect.Left-HandleWidth/2;
                              rtn.Top=ValidRect.Top-HandleHeight/2;
                              rtn.Right=ValidRect.Left+HandleWidth/2;
                              rtn.Bottom=ValidRect.Top+HandleHeight/2;
                              break;
        case rhtRightTop:     rtn.Left=ValidRect.Right-HandleWidth/2;
                              rtn.Top=ValidRect.Top-HandleHeight/2;
                              rtn.Right=ValidRect.Right+HandleWidth/2;
                              rtn.Bottom=ValidRect.Top+HandleHeight/2;
                              break;
        case rhtLeftBottom:   rtn.Left=ValidRect.Left-HandleWidth/2;
                              rtn.Top=ValidRect.Bottom-HandleHeight/2;
                              rtn.Right=ValidRect.Left+HandleWidth/2;
                              rtn.Bottom=ValidRect.Bottom+HandleHeight/2;
                              break;
        case rhtRightBottom:  rtn.Left=ValidRect.Right-HandleWidth/2;
                              rtn.Top=ValidRect.Bottom-HandleHeight/2;
                              rtn.Right=ValidRect.Right+HandleWidth/2;
                              rtn.Bottom=ValidRect.Bottom+HandleHeight/2;
                              break;
        case rhtLeftCenter:   rtn.Left=ValidRect.Left-HandleWidth/2;
                              rtn.Top=ValidRect.Top + (ValidRect.Height()/2) - HandleHeight/2;
                              rtn.Right=ValidRect.Left+HandleWidth/2;
                              rtn.Bottom=ValidRect.Top + (ValidRect.Height()/2) + HandleHeight/2;
                              break;
        case rhtRightCenter:   rtn.Left=ValidRect.Right-HandleWidth/2;
                              rtn.Top=ValidRect.Top + (ValidRect.Height()/2) - HandleHeight/2;
                              rtn.Right=ValidRect.Right+HandleWidth/2;
                              rtn.Bottom=ValidRect.Top + (ValidRect.Height()/2) + HandleHeight/2;
                              break;
        case rhtTopCenter:    rtn.Left=ValidRect.left + (ValidRect.Width()/2) - HandleWidth/2;
                              rtn.Top=ValidRect.Top-HandleHeight/2;;
                              rtn.Right=ValidRect.left + (ValidRect.Width()/2) + HandleWidth/2;;
                              rtn.Bottom=ValidRect.Top+HandleHeight/2;
                              break;
        case rhtBottomCenter: rtn.Left=ValidRect.left + (ValidRect.Width()/2) - HandleWidth/2;
                              rtn.Top=ValidRect.bottom-HandleHeight/2;;
                              rtn.Right=ValidRect.left + (ValidRect.Width()/2) + HandleWidth/2;;
                              rtn.Bottom=ValidRect.bottom+HandleHeight/2;
                              break;

        default: break;
     }

     return(rtn);
}
//---------------------------------------------------------------
void __fastcall YRectTracker::SetRect(TRect &rect)
{
     ValidRect.Left=rect.Left;
     ValidRect.Top=rect.Top;
     ValidRect.Right=rect.Right;
     ValidRect.Bottom=rect.Bottom;
     NormalizeRect(ValidRect);
}
//---------------------------------------------------------------
void __fastcall YRectTracker::SetColor(TColor color)
{
     RectColor=color;
}
//---------------------------------------------------------------
void __fastcall YRectTracker::SetHandleColor(TColor color)
{
     HandleColor=color;
}
//---------------------------------------------------------------
void __fastcall YRectTracker::SetHandleAble(bool able)
{
     HandleAble=able;
     Sizeabled =able;
}
//---------------------------------------------------------------
void __fastcall YRectTracker::SetHandleAble(bool enableTrk, bool changeSize)
{
     HandleAble = enableTrk;
     Sizeabled  = changeSize;
}
//---------------------------------------------------------------
bool __fastcall YRectTracker::GetHandleAble(void)
{
     return (HandleAble);
}
//---------------------------------------------------------------
void __fastcall YRectTracker::SetChoosed(bool choosed)
{
     IsChoosed=choosed;
     if(choosed) DrawRectColor=ChoosedColor;
     else DrawRectColor=RectColor;
     Paint();
}
//---------------------------------------------------------------
void __fastcall YRectTracker::SetID(int number)
{
     ID=number;
}
//---------------------------------------------------------------
int __fastcall YRectTracker::GetID(void)
{
     return ID;
}
//---------------------------------------------------------------
void __fastcall YRectTracker::SetName(AnsiString nm)
{
    Name = nm;
}

//---------------------------------------------------------------
bool __fastcall YRectTracker::IsInRect(int X, int Y)
{
     if( (X>=ValidRect.Left) && (X<=ValidRect.Right) && (Y>=ValidRect.Top) && (Y<=ValidRect.Bottom) )
       return true;
     return false;
}
//---------------------------------------------------------------
bool __fastcall YRectTracker::IsInRect(int X, int Y, TRect &rect)
{
     if( (X>=rect.Left) && (X<=rect.Right) && (Y>=rect.Top) && (Y<=rect.Bottom) )
       return true;
     return false;
}
//---------------------------------------------------------------
void __fastcall YRectTracker::NormalizeRect(TRect &rect)
{
     TRect rtn;

     if(rect.left<rect.right) { rtn.left=rect.left; rtn.right=rect.right; }
     else { rtn.left=rect.right; rtn.right=rect.left; }

     if(rect.top<rect.bottom) { rtn.top=rect.top; rtn.bottom=rect.bottom; }
     else { rtn.top=rect.bottom; rtn.bottom=rect.top; }

     rect=rtn;
     return;
}
//---------------------------------------------------------------
void __fastcall YRectTracker::Paint(void)
{
     TPen      *OldPen;
     TBrush    *OldBrush;



     if(!Visible) return;

     OldPen=OwnerCanvas->Pen;
     OldBrush=OwnerCanvas->Brush;

     OwnerCanvas->Pen->Color=DrawRectColor;
     OwnerCanvas->Brush->Style=bsClear;

     OwnerCanvas->Rectangle(ValidRect);

     OwnerCanvas->Brush->Style=bsSolid;
     OwnerCanvas->Brush->Color=HandleColor;
     if(Name != "")
         OwnerCanvas->TextOutA(ValidRect.left+5,ValidRect.top+5, Name);
     else
         OwnerCanvas->TextOutA(ValidRect.left+5,ValidRect.top+5,AnsiString(ID));
     if(HandleAble)
     {
        if(Sizeabled)
        {
           OwnerCanvas->FillRect(GetHandleRect(rhtLeftTop));
           OwnerCanvas->FillRect(GetHandleRect(rhtRightTop));
           OwnerCanvas->FillRect(GetHandleRect(rhtLeftBottom));
           OwnerCanvas->FillRect(GetHandleRect(rhtRightBottom));

           if(UseBezier)
           {
               OwnerCanvas->FillRect(GetHandleRect(rhtLeftCenter));
               OwnerCanvas->FillRect(GetHandleRect(rhtRightCenter));
               OwnerCanvas->FillRect(GetHandleRect(rhtTopCenter));
               OwnerCanvas->FillRect(GetHandleRect(rhtBottomCenter));
           }
        }
     }
     OwnerCanvas->Pen=OldPen;
     OwnerCanvas->Brush=OldBrush;
     return;
}
//---------------------------------------------------------------
int __fastcall YRectTracker::HitTest(int X, int Y)
{
     TRect HandleRect;

     NormalizeRect(ValidRect);

     if(!HandleAble) return rhitNothing;        //這是執行階段(RunTime),使用者不可調整邊框尺寸

     HandleRect=GetHandleRect(rhtLeftTop);
     if( IsInRect(X,Y,HandleRect) ) return (Sizeabled ? rhitLeftTop : rhitNothing);
     HandleRect=GetHandleRect(rhtRightTop);
     if( IsInRect(X,Y,HandleRect) ) return (Sizeabled ? rhitRightTop: rhitNothing);
     HandleRect=GetHandleRect(rhtLeftBottom);
     if( IsInRect(X,Y,HandleRect) ) return (Sizeabled ? rhitLeftBottom: rhitNothing);
     HandleRect=GetHandleRect(rhtRightBottom);
     if( IsInRect(X,Y,HandleRect) ) return (Sizeabled ? rhitRightBottom: rhitNothing);

     if( IsInRect(X,Y) ) return rhitInside;


     return rhitNothing;
}
//---------------------------------------------------------------
bool __fastcall YRectTracker::Track(int StartX, int StartY)
{
     bool rtn;
     if(!HandleAble) return false;
     rtn=TrackHandle(StartX, StartY, HitTest(StartX,StartY));
     return rtn;
}
//---------------------------------------------------------------
bool __fastcall YRectTracker::TrackHandle(int StartX, int StartY, int HitTest)
{
     if( (HitTest!=rhitLeftTop) && (HitTest!=rhitRightTop) && (HitTest!=rhitLeftBottom) &&
         (HitTest!=rhitRightBottom) && (HitTest!=rhitInside) ) return false;

     TRect OriginalRect,NewRect;
     bool  bExit=false;

     MSG       msg;
     TPen      *OldPen;
     TBrush    *OldBrush;
     int       X,Y;
     bool  bCanceled=false;
/*
     TColor      PenColor, BrushColor;
     TBrushStyle BrushStyle;
     TPenMode    PenMode;

     PenColor = OwnerCanvas->Pen->Color;
     PenMode  = OwnerCanvas->Pen->Mode;
     BrushColor = OwnerCanvas->Brush->Color;
     BrushStyle = OwnerCanvas->Brush->Style;
*/
     OldPen=OwnerCanvas->Pen;
     OldBrush=OwnerCanvas->Brush;

     //這是因為在有影像的畫布上,畫框在被調整時出現會混淆的現象,權宜之計
     //Start.
     OwnerCanvas->Pen->Color=clBlue;
     OwnerCanvas->Brush->Style=bsClear;
     OwnerCanvas->Rectangle(ValidRect);
     //End.

     OwnerCanvas->Pen->Color=DrawRectColor;
     OwnerCanvas->Brush->Color=HandleColor;
     OwnerCanvas->Brush->Style=bsClear;
     OwnerCanvas->Pen->Mode=pmXor;
     OriginalRect=ValidRect;
     //draw the rect first
     //OwnerCanvas->Rectangle(ValidRect);

     while(!bExit)
     {
          ::GetMessage(&msg, NULL, 0, 0);

          switch (msg.message)
          {
              // handle movement/accept messages
              case WM_LBUTTONUP:
                    bExit = TRUE;
                    //加入這行   讓滑鼠自動點擊(放開左鍵)
                    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
                    break;

              case WM_MOUSEMOVE:
                    NewRect=ValidRect;
                    X=(int)(short)LOWORD(msg.lParam);
                    Y=(int)(short)HIWORD(msg.lParam);

                    switch(HitTest)
                    {
                       case rhitLeftTop:          NewRect.Left=X;     NewRect.Top=Y;      break;
                       case rhitRightTop:         NewRect.Right=X;    NewRect.Top=Y;      break;
                       case rhitLeftBottom:       NewRect.Left=X;     NewRect.Bottom=Y;   break;
                       case rhitRightBottom:      NewRect.Right=X;    NewRect.Bottom=Y;   break;
                       case rhitInside:           NewRect.Left=OriginalRect.Left+(X-StartX);
                                                  NewRect.Top=OriginalRect.Top+(Y-StartY);
                                                  NewRect.Right=OriginalRect.Right+(X-StartX);
                                                  NewRect.Bottom=OriginalRect.Bottom+(Y-StartY);
                                                  break;
                       default: break;
                    }

                    //draw new rect.
                    OwnerCanvas->Rectangle(NewRect);

                    //erase old rect.
                    OwnerCanvas->Rectangle(ValidRect);

                    ValidRect=NewRect;

                    if (msg.message == WM_LBUTTONUP || msg.message == WM_RBUTTONDOWN)
                        bExit = TRUE;
                    break;

              // handle cancel messages
              case WM_KEYDOWN:
                    if (msg.message == VK_ESCAPE)
                    {
                         bCanceled = true;
                         bExit = true;
                    };
                    break;

              case WM_RBUTTONDOWN:
                    bCanceled = true;
                    bExit = true;
                    break;

              // just dispatch rest of the messages
              default:
                    ::DispatchMessage(&msg);
                    break;
	  }//switch
     }; //while

     if (bCanceled)  ValidRect = OriginalRect;

     OwnerCanvas->Pen->Mode=pmCopy;
     //OwnerCanvas->Rectangle(ValidRect);

     OwnerCanvas->Pen=OldPen;
     OwnerCanvas->Brush=OldBrush;
/*
     OwnerCanvas->Pen->Color = PenColor;
     OwnerCanvas->Pen->Mode  = PenMode;
     OwnerCanvas->Brush->Color = BrushColor;
     OwnerCanvas->Brush->Style = BrushStyle;
*/

     return !bCanceled ;
}
//---------------------------------------------------------------
bool __fastcall YRectTracker::TrackInRect(int StartX, int StartY, int HitTest, TRect &Rect)
{
    if( (HitTest!=rhitLeftTop) && (HitTest!=rhitRightTop) && (HitTest!=rhitLeftBottom) &&
        (HitTest!=rhitRightBottom) && (HitTest!=rhitInside) ) return false;

    TRect OriginalRect,NewRect;
    bool  bExit=false;

    MSG       msg;
    TPen      *OldPen;
    TBrush    *OldBrush;
    int       X,Y;
    bool  bCanceled = false;

    OldPen=OwnerCanvas->Pen;
    OldBrush=OwnerCanvas->Brush;

    //這是因為在有影像的畫布上,畫框在被調整時出現會混淆的現象,權宜之計
    //Start.
    OwnerCanvas->Pen->Color=clBlue;
    OwnerCanvas->Brush->Style=bsClear;
    OwnerCanvas->Rectangle(ValidRect);
    //End.

    OwnerCanvas->Pen->Color=DrawRectColor;
    OwnerCanvas->Brush->Color=HandleColor;
    OwnerCanvas->Brush->Style=bsClear;
    OwnerCanvas->Pen->Mode=pmXor;
    OriginalRect=ValidRect;
    //draw the rect first
    //OwnerCanvas->Rectangle(ValidRect);

     while(!bExit)
     {
          ::GetMessage(&msg, NULL, 0, 0);

          switch (msg.message)
          {
              // handle movement/accept messages
              case WM_LBUTTONUP:   bExit = TRUE; break;

              case WM_MOUSEMOVE:
                    NewRect=ValidRect;
                    X=(int)(short)LOWORD(msg.lParam);
                    Y=(int)(short)HIWORD(msg.lParam);

                    switch(HitTest)
                    {
                       case rhitLeftTop:
                           if( X >= Rect.left && X <= Rect.right)  NewRect.Left= X;
                           if( Y >= Rect.top  && Y <= Rect.bottom) NewRect.Top = Y;
                           break;

                       case rhitRightTop:
                           if( X >= Rect.left && X <= Rect.right) NewRect.Right=X;
                           if( Y >= Rect.top  && Y <= Rect.bottom) NewRect.Top= Y;
                           break;

                       case rhitLeftBottom:
                           if( X >= Rect.left && X <= Rect.right)NewRect.Left=X;
                           if( Y >= Rect.top  && Y <= Rect.bottom)NewRect.Bottom=Y;
                           break;

                       case rhitRightBottom:
                           if( X >= Rect.left && X <= Rect.right)NewRect.Right=X;
                           if( Y >= Rect.top  && Y <= Rect.bottom)NewRect.Bottom=Y;
                           break;
                       case rhitInside:

                           // 往右邊走
                           if((X-StartX) >= 0 )
                           {
                               // 判斷是否超出右極限
                               if(OriginalRect.Right+(X-StartX) <= Rect.right)
                               {
                                    NewRect.Right =  OriginalRect.Right+(X-StartX);
                                    NewRect.Left =   OriginalRect.Left+(X-StartX);
                               }

                               // 往下走
                               if((Y-StartY) >= 0)
                               {
                                   if(OriginalRect.Bottom+(Y-StartY) <=  Rect.Bottom)
                                   {
                                        NewRect.Top=OriginalRect.Top+(Y-StartY);
                                        NewRect.Bottom=OriginalRect.Bottom+(Y-StartY);
                                   }
                               }
                               else
                               {
                                  if(OriginalRect.Top+(Y-StartY) >=  Rect.Top)
                                  {
                                      NewRect.Top=OriginalRect.Top+(Y-StartY);
                                      NewRect.Bottom=OriginalRect.Bottom+(Y-StartY);
                                  }
                               }
                           }
                           else // 往左邊走
                           {
                               // 判斷是否超出左極限
                               if(OriginalRect.Left+(X-StartX) >= Rect.Left)
                               {
                                    NewRect.Right =  OriginalRect.Right+(X-StartX);
                                    NewRect.Left =   OriginalRect.Left+(X-StartX);
                               }

                               // 往下走
                               if((Y-StartY) >= 0)
                               {
                                   if(OriginalRect.Bottom+(Y-StartY) <=  Rect.Bottom)
                                   {
                                        NewRect.Top=OriginalRect.Top+(Y-StartY);
                                        NewRect.Bottom=OriginalRect.Bottom+(Y-StartY);
                                   }
                               }
                               else
                               {
                                  if(OriginalRect.Top+(Y-StartY) >=  Rect.Top)
                                  {
                                      NewRect.Top=OriginalRect.Top+(Y-StartY);
                                      NewRect.Bottom=OriginalRect.Bottom+(Y-StartY);
                                  }
                               }

                           }

                           break;
                           default: break;
                    };

                    //draw new rect.
                    OwnerCanvas->Rectangle(NewRect);

                    //erase old rect.
                    OwnerCanvas->Rectangle(ValidRect);

                    ValidRect=NewRect;

                    if (msg.message == WM_LBUTTONUP || msg.message == WM_RBUTTONDOWN)
                    bExit = TRUE;
                    break;

              // handle cancel messages
              case WM_KEYDOWN:
                    if (msg.message == VK_ESCAPE)
                    {
                         bCanceled = true;
                         bExit = true;
                    };
                    break;

              case WM_RBUTTONDOWN:
                    bCanceled = true;
                    bExit = true;
                    break;

              // just dispatch rest of the messages
              default:
                    ::DispatchMessage(&msg);
                    break;
	  }//switch
     }; //while

     if (bCanceled)  ValidRect = OriginalRect;

     OwnerCanvas->Pen->Mode=pmCopy;
     OwnerCanvas->Pen=OldPen;
     OwnerCanvas->Brush=OldBrush;


     return !bCanceled ;


}
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
