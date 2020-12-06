#include "fordbworkclass.h"

#include "QSqlQuery"//для работы с SQL запросами
#include "QTableView"//для работы с графическим выводом информации в виде таблиц
#include "QSqlTableModel" //класс для работы с редактируемой одиночной таблицей из БД
#include "QSqlRelationalTableModel" //класс для работы с редактируемой таблицей из БД с поддержкой внешних ключей
#include "QSqlQueryModel" //класс для работы с таблицей только для чтения из БД для вывода SQL запросов

#include "QDebug"

fordbworkclass::fordbworkclass()
{



}

//описание метода opendb() - создаваемого метода класса для открытия и подключения к БД
//fordbworkclass:: - означает, что метод создается для класса fordbworkclass
void fordbworkclass::opendb()
{
    //здесь идет подробное описание, что делает метод

    extern QSqlDatabase db;// подключение переменной из другого файла, которая должна существовать в одном экземпляре и вызываться один раз - драйвера для БД SQLite

    //подключить БД по ее адресу на компьютере
    db.setDatabaseName("/home/mishanyya/fordbwork/examplebdfordbwork");
    //открывает базу данных, указанную в db.setDatabaseName("/home/mishanyya/fordbwork/examplebdfordbwork");
    db.open();

    //показывает параметры просто для проверки работы
     qDebug()<< "isOpen=" <<db.isOpen();

}


