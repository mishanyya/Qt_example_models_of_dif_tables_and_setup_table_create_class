#include "fordbworkclass.h"

#include "QSqlQuery"//для работы с SQL запросами
#include "QTableView"//для работы с графическим выводом информации в виде таблиц
#include "QSqlTableModel" //класс для работы с редактируемой одиночной таблицей из БД
#include "QSqlRelationalTableModel" //класс для работы с редактируемой таблицей из БД с поддержкой внешних ключей
#include "QSqlQueryModel" //класс для работы с таблицей только для чтения из БД для вывода SQL запросов

#include "QDebug"

fordbworkclass::fordbworkclass()
{
//описание действий конструктора, который сработает сразу при создании объекта этого класса,
    //но этот метод нельзя вызвать повторно!!!
    //может быть пустым, а может выполнять какие-либо действия

// использовать переменную из другого файла, которая вызывает драйвера для БД SQLite
   extern QSqlDatabase db;

    //подключить БД по ее адресу на компьютере
    db.setDatabaseName("/home/mishanyya/databaseexample/examplebdfordbwork");
    //открыть базу данных, указанную в db.setDatabaseName("/home/mishanyya/databaseexample/examplebdfordbwork");
   db.open();
   //показывает параметры просто для проверки работы
    qDebug()<< "isOpen=" <<db.isOpen();
    qDebug()<< "Конструктор сработал!!!";
}
