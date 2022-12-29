#ifndef ASSIGNMENT_NO_6_H
#define ASSIGNMENT_NO_6_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Assignment_No_6; }
QT_END_NAMESPACE

class Assignment_No_6 : public QMainWindow
{
  Q_OBJECT

public:
  Assignment_No_6(QWidget *parent = nullptr);
  ~Assignment_No_6();
  void Bresenhams_Circle(int,int,int);
  void DDA_Line(float,float,float,float);
private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

private:
  Ui::Assignment_No_6 *ui;
};
#endif // ASSIGNMENT_NO_6_H
