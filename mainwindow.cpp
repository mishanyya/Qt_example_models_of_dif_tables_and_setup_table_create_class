#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "fordbworkclass.h"//надо добавить файл класса в файл, в котором он используется


#include "QSqlDatabase"//для работы с БД
#include "QSqlQuery"//для работы с SQL запросами
#include "QTableView"//для работы с графическим выводом информации в виде таблиц
#include "QListView"//для работы с графическим выводом информации в виде списка
#include "QTreeView"//для работы с графическим выводом информации в виде дерева
#include "QStandardItemModel"//общий класс для создания и работы с моделями типов таблица, дерево и список
#include "QStandardItem"//общий класс для создания и работы пунктов модели
#include "QDebug"
#include "QLabel"



// подключение драйвера для БД SQLite, должно осуществляться один раз!
QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");


//создание объекта класса fordbworkclass
Fordbworkclass base;
//при его создании автоматически сработает метод-функция конструктор, но только один раз!


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "значение переменной класса ="<<base.exampleFunction();

    createTable();//запуск функции, выводящий базу данных сразу после запуска программы   
}

MainWindow::~MainWindow()
{
    delete ui;
}


//функция, которая должна выводить базу данных в таблице при запуске программы
void MainWindow::createTable(){


}
