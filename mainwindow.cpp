#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Решатель квадратных уравнений");
    A = 0;
    B = 0;
    C = 0;
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabEnabled(1, false);
    ui->tabWidget->setTabEnabled(2, false);

    ui->graphWidget->setInteraction(QCP::iRangeZoom,true);
    ui->graphWidget->setInteraction(QCP::iRangeDrag,true);
}

// --------------------------------------------------

MainWindow::~MainWindow()
{
    delete ui;
}

// --------------------------------------------------

float MainWindow::getfun(float x)
{
    return A*(x*x) + B*x + C;
}

// --------------------------------------------------

void MainWindow::checkFun()
{
    if (A == 0 and B == 0 and C == 0) {
      Type1 q(A, B, C);
      ui->infoLabel->setText(q.vsegVerno());
    }
    else if(A != 0 and B == 0 and C == 0) {
      Type2 q(A, B, C);
      ui->infoLabel->setText("x = " + QString::number(q.ret0()));
    }
    else if (A == 0 and B == 0 and C != 0) {
      Type3 q(A, B, C);
      ui->infoLabel->setText(q.retErr());
    }
    else if (A != 0 and B == 0 and C != 0) {
      Type4 q(A, B, C);
      if (q.Check())
      {
          QString text = "x1 = " + QString::number(q.getX1()) + "; ";
          text += "x2 = " + QString::number(q.getX2());
          ui->infoLabel->setText(text);
      }
      else {
       ui->infoLabel->setText("Не существуют");
      }
    }
    else if (A == 0 and B != 0 and C != 0)
    {
      Type5 q(A, B, C);
      ui->infoLabel->setText("x = " + QString::number(q.GetX()));
    }
    else if (A != 0 and B != 0 and C != 0)
    {
      Type6 q(A, B, C);
      if(q.calcDisc() < 0 ){
          ui->infoLabel->setText("Дискриминант меньше нуля");
      }
      else{
      QString text = "x1 = " + q.getX1() + "; ";
      text += "x2 = " + q.getX2();
      ui->infoLabel->setText(text);
      }
    }
    else if (A == 0 and B != 0 and C == 0)
    {
      Type7 q(A, B, C);
      ui->infoLabel->setText("x = " + QString::number(q.ret0()));
    }
    else if (A != 0 and B != 0 and C == 0) {
      Type8 q(A, B, C);
      QString text = "x1 = " + QString::number(q.getX1()) + "; ";
      text += "x2 = " + QString::number(q.getX2());
      ui->infoLabel->setText(text);
    }
}

// --------------------------------------------------

void MainWindow::on_calcButton_clicked()
{
    A = ui->A_SpinBox->value();
    B = ui->B_SpinBox->value();
    C = ui->C_SpinBox->value();
    checkFun();

    // Интервал построения
    float start_X = ui->startIntSpin->value();
    float end_X   = ui->endIntSpin->value();
    float step    = ui->stepSpin->value();

    QVector<double> xVec, yVec;

    float stepper = start_X;

    while(stepper < end_X)
    {
       xVec.append(stepper);
       yVec.append(getfun(stepper));
       stepper += step;
    }

    ui->graphWidget->addGraph();
    ui->graphWidget->graph(0)->setData(xVec, yVec);

    // задаем имена осей координат
    ui->graphWidget->xAxis->setLabel("x");
    ui->graphWidget->yAxis->setLabel("y");

    // задаем размеры осей
    ui->graphWidget->xAxis->setRange(start_X, end_X);
    ui->graphWidget->yAxis->setRange(-500, 500);
    ui->graphWidget->replot();
}


void MainWindow::on_agreeButton_clicked()
{
    ui->tabWidget->setTabEnabled(1, true);
    ui->tabWidget->setTabEnabled(2, true);
}

