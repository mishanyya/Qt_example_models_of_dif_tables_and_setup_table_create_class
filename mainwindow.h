#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QMainWindow"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
void createTable();   // это созданный нами слот для

void examplefunction(int x, int y);   // это созданный нами слот для

};
#endif // MAINWINDOW_H
