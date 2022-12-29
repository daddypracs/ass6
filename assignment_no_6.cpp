#include "assignment_no_6.h"
#include "ui_assignment_no_6.h"
QImage j(600,600,QImage::Format_RGB888);
Assignment_No_6::Assignment_No_6(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::Assignment_No_6)
{
  ui->setupUi(this);
}

Assignment_No_6::~Assignment_No_6()
{
  delete ui;
}


void Assignment_No_6::Bresenhams_Circle(int Xc,int Yc,int r)
{
  //Bresenham's Circle Drawing Algorithm
  int x,y,D;
  y = r;
  D = 3-(2*r);
  for (x = 0; x<=y;x++)
  {
      j.setPixel((y+Xc),(x+Yc),qRgb(0,255,255));
      j.setPixel((x+Xc),(y+Yc),qRgb(0,255,255));
      j.setPixel((-x+Xc),(y+Yc),qRgb(0,255,255));
      j.setPixel((-y+Xc),(x+Yc),qRgb(0,255,255));
      j.setPixel((-y+Xc),(-x+Yc),qRgb(0,255,255));
      j.setPixel((-x+Xc),(-y+Yc),qRgb(0,255,255));
      j.setPixel((x+Xc),(-y+Yc),qRgb(0,255,255));
      j.setPixel((y+Xc),(-x+Yc),qRgb(0,255,255));
      ui->label->setPixmap(QPixmap::fromImage(j));
      if (D<0)
      {
          D = D + 4 * x + 6;
      }
      else
      {
          D = D + 4 * ( x - y ) + 10 ;
          y = y - 1 ;
      }
    }
}
void Assignment_No_6::DDA_Line(float x1,float y1,float x2,float y2)
{
  //DDA Line Drawing Algorithm
  float step, dx, dy, i, x, y;
  dx = x2-x1;
  dy = y2-y1;
  if(abs(dx)>=abs(dy))
    {
      step = abs(dx);
    }
  else
    {
      step = abs(dy);
    }
  x = x1;
  y = y1;
  i = 0;
  dx = (dx/step);
  dy = (dy/step);
  while (i<=step)
    {
      j.setPixel((x),(y),qRgb(0,255,255));
      x = x + dx;
      y = y + dy;
      i++;
    }
}
//PATTERN 1:-->
void Assignment_No_6::on_pushButton_clicked()
{
  int Xc, Yc, r;
  Xc = ui->textEdit->toPlainText().toInt();
  Yc = ui->textEdit_2->toPlainText().toInt();
  r = ui->textEdit_3->toPlainText().toFloat();
  Bresenhams_Circle(Xc,Yc,r);//Outer Circle
  float x1 , y1 , x2 , y2 , x3 , y3 ;
  //Finding the coordinates of vertices of triangle
  x1 = Xc ;
  y1 = Yc - r ;
  x2 = Xc - (sqrt(3)/2)*r;
  y2 = Yc + 0.5*r;
  x3 = Xc + ((sqrt(3)/2)*r);
  y3 = Yc + 0.5*r;
  //Drawing The Triangle
  DDA_Line(x1,y1,x2,y2);
  DDA_Line(x2,y2,x3,y3);
  DDA_Line(x3,y3,x1,y1);
  float a = r/2;
  Bresenhams_Circle(Xc,Yc,a);//Inner Circle
  ui->label->setPixmap(QPixmap::fromImage(j));
}
//PATTERN 2 :--->
void Assignment_No_6::on_pushButton_2_clicked()
{
    float l , b , x1 , y1;
    l = ui->textEdit_4->toPlainText().toFloat();
    x1 = ui->textEdit_6->toPlainText().toFloat();
    b = ui->textEdit_5->toPlainText().toFloat();
    y1 = ui->textEdit_7->toPlainText().toFloat();
    //Rectangle Drawing
    DDA_Line(x1,y1,(x1+l),y1);
    DDA_Line((x1+l),(y1),(x1+l),(y1+b));
    DDA_Line((x1+l),(y1+b),x1,(y1+b));
    DDA_Line(x1,(y1+b),x1,y1);
    float a ,c;
    a = x1+(l/2);
    c = y1+(b/2);
    //Inner Diamond Drawing
    DDA_Line(a,(y1),(x1+l),c);
    DDA_Line((x1+l),c,a,(y1+b));
    DDA_Line(a,(y1+b),(x1),c);
    DDA_Line((x1),c,a,(y1));
    float rad,cal;
    cal = pow(l,2) + pow(b,2);
    cal = 2 * sqrt(cal);
    rad = ((l*b)/(cal));
    //Inner Circle
    Bresenhams_Circle(a,c,rad);
    ui->label->setPixmap(QPixmap::fromImage(j));
}

