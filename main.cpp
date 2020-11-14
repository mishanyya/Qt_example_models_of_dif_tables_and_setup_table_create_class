#include "mainwindow.h"



#include <QApplication>
#include "QSqlQuery"//для работы с SQL запросами
#include "QTableView"//для работы с графическим выводом информации в виде таблиц
#include "QSqlTableModel" //класс для работы с редактируемой одиночной таблицей из БД
#include "QSqlRelationalTableModel" //класс для работы с редактируемой таблицей из БД с поддержкой внешних ключей
#include "QSqlQueryModel" //класс для работы с таблицей только для чтения из БД для вывода SQL запросов


#include "fordbworkclass.h"//надо добавить файл класса в файл, в котором он используется

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

       w.show();
    return a.exec();
}
