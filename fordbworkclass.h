#include <QMainWindow>

#ifndef FORDBWORKCLASS_H
#define FORDBWORKCLASS_H


class fordbworkclass
{
    //private означает, что элементы НЕ доступны из других функций. их можно получить только с помощью public методов этого класса
    //установлено по умолчанию
private:


    //все рабочие функции описываются после public
public://public означает, что элементы доступны из других функций?
    fordbworkclass();//конструктор, установлен по умолчанию


//создание метода opendb()
    void opendb();//создаваемый метод класса для открытия и подключения к БД



};
#endif // FORDBWORKCLASS_H
