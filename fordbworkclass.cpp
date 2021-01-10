#include "fordbworkclass.h"

#include "QSqlQuery"//для работы с SQL запросами
#include "QTableView"//для работы с графическим выводом информации в виде таблиц
#include "QSqlTableModel" //класс для работы с редактируемой одиночной таблицей из БД
#include "QSqlRelationalTableModel" //класс для работы с редактируемой таблицей из БД с поддержкой внешних ключей
#include "QSqlQueryModel" //класс для работы с таблицей только для чтения из БД для вывода SQL запросов

#include "QDebug"

//Класс::Метод класса
Fordbworkclass::Fordbworkclass()
{
//описание действий конструктора, который сработает сразу при создании объекта этого класса,
    //но этот метод нельзя вызвать повторно!!!
    //может быть пустым, а может выполнять какие-либо действия
    qDebug()<< "Конструктор сработал!!!";
}



//прописать действияе метода, извне
int Fordbworkclass::exampleFunction(){
    //присвоить значение переменной напрямую извне нельзя!
    //это возможно только через метод класса
    exampleVariable=5;
    return exampleVariable;
}







