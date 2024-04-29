#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "userclasses.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    float getfun(float x);

private slots:
    void checkFun();
    void on_calcButton_clicked();

    void on_agreeButton_clicked();

private:
    float A,B,C;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
