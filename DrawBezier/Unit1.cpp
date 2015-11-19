//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    SelectRect.left = 100;
    SelectRect.top = 100;
    SelectRect.right = 200;
    SelectRect.Bottom = 200;

    T1->Max = SelectRect.Width() / 3 * 2;
    T1->Min = -(SelectRect.Width() / 3 * 2);
    T1->Position = 0;

    T2->Max = SelectRect.Height() / 3 * 2;
    T2->Min = -(SelectRect.Height() / 3 * 2);
    T2->Position = 0;

    Image2->Picture->LoadFromFile("C:\\sample.bmp");


    //Graphics::TBitmap *Bitmap = new Graphics::TBitmap();
    //Bitmap->LoadFromFile("C:\\Sample.bmp");
   // Image1->Width = Bitmap->Width;
   // Image1->Height = Bitmap->Height;
   // Image1->AutoSize = false;
    //Image1->Canvas->Draw(0,0,Bitmap);
    //delete Bitmap;

    //設定影像透明顏色
    Graphics::TBitmap *tempBmp = new Graphics::TBitmap();
    tempBmp->Width = Image1->Width;
    tempBmp->Height = Image1->Height;
    tempBmp->Canvas->Brush->Color=clWhite;
    tempBmp->Canvas->Pen->Color=clWhite;
    tempBmp->Canvas->Brush->Style=bsSolid;
    tempBmp->Canvas->Rectangle(0,0,tempBmp->Width,tempBmp->Height);
    Image1->Picture->Bitmap->Assign(tempBmp);
    Image1->Picture->Bitmap->TransparentMode = tmFixed;
    Image1->Picture->Bitmap->TransparentColor = clWhite;
    delete tempBmp;

    //設定畫筆、填充樣式
    //Image1->Canvas->Brush->Color = clWhite;
    Image1->Canvas->Pen->Style =psSolid;
    Image1->Canvas->Pen->Color =clRed;
    
    Form1->DoubleBuffered = true;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::DrawBezier(TRect rect, int curveX, int curveY)
{

Image1->Canvas->Brush->Color = clWhite;
Image1->Canvas->Rectangle(0,0,1000,1000);

Image1->Canvas->Pen->Color = clRed;
    //Image1->Canvas->Pen->Mode = pmNotXor;
    //Image1->Canvas->PolyBezier(p, 12) ;

    int x = T1->Position;
    int y = T2->Position;
    //x = 30;
    //y = 30;

    TPoint p0(rect.left, rect.top);
    TPoint p1(rect.right, rect.top);
    TPoint p2(rect.right, rect.bottom);
    TPoint p3(rect.left, rect.bottom);

    p[0] = p0;
    p[1] = Point(p0.x, p0.y - y) ;
    p[2] = Point(p1.x, p1.y - y) ;
    p[3] = p1;
    p[4] = Point(p1.x + x, p1.y) ;
    p[5] = Point(p2.x + x, p2.y) ;
    p[6] = p2;
    p[7] = Point(p2.x, p2.y + y);
    p[8] = Point(p3.x, p3.y + y);
    p[9] = p3;
    p[10] = Point(p3.x - x, p3.y);
    p[11] = Point(p0.x - x, p0.y);
    p[12] = p0;


   // Image1->Canvas->Brush->Color = clBlue;
   // Image1->Canvas->Brush->Style = bsSolid;
    Image1->Canvas->PolyBezier(p, 12) ;

    //Image1->Picture->Bitmap->Canvas->FloodFill(150,150,clRed,fsBorder);
    //Image1->Canvas->FloodFill(150, 150, clRed, fsSurface/*fsBorder*/) ;

    //Image1->Canvas->Pen->Style =psSolid;
    //Image1->Canvas->Rectangle(50,50,150,150);


}
void __fastcall TForm1::T1Change(TObject *Sender)
{
    DrawBezier(SelectRect, T1->Position, T2->Position);    
}
//---------------------------------------------------------------------------
void __fastcall TForm1::T2Change(TObject *Sender)
{
    DrawBezier(SelectRect, T1->Position, T2->Position);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{

    Image1->Picture->Bitmap->Canvas->Brush->Color = clBlue;
    //Image1->Picture->Bitmap->Canvas->FloodFill(X,Y,clBlack,fsBorder);
    //Image1->Picture->Bitmap->Canvas->FloodFill(150,150,clWhite,fsSurface);
    Image1->Picture->Bitmap->Canvas->FloodFill(X,Y,clRed,fsBorder);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
Image1->Picture->Bitmap->Canvas->Brush->Color = clBlue;
    //Image1->Picture->Bitmap->Canvas->Brush->Style = bsClear;
    //Image1->Picture->Bitmap->Canvas->FloodFill(X,Y,clBlack,fsBorder);
    //Image1->Picture->Bitmap->Canvas->FloodFill(150,150,clWhite,fsSurface);
    Image1->Picture->Bitmap->Canvas->FloodFill(150,150,clRed,fsBorder);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
Graphics::TBitmap *tempBmp=new Graphics::TBitmap();
    tempBmp->Width = Image1->Width;
    tempBmp->Height = Image1->Height;
    tempBmp->Canvas->Brush->Color=clWhite;
    tempBmp->Canvas->Pen->Color=clWhite;
    tempBmp->Canvas->Brush->Style=bsSolid;
    tempBmp->Canvas->Rectangle(0,0,tempBmp->Width,tempBmp->Height);
    Image1->Picture->Bitmap->Assign(tempBmp);
    Image1->Picture->Bitmap->TransparentMode = tmFixed;
    Image1->Picture->Bitmap->TransparentColor = clWhite;

    delete tempBmp;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
  Image1->Picture->Bitmap->Canvas->Brush->Color=clWhite;
    Image1->Picture->Bitmap->Canvas->FloodFill(150,150,clBlue,fsSurface);
}
//---------------------------------------------------------------------------

