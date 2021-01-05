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
fordbworkclass base;
//при его создании автоматически сработает метод-функция конструктор, но только один раз!

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createTable();//запуск функции, выводящий базу данных сразу после запуска программы   
}

MainWindow::~MainWindow()
{
    delete ui;
}


//функция, которая должна выводить базу данных в таблице при запуске программы
void MainWindow::createTable(){
//Общий код для QSqlTableModel, QSqlRelationalTableModel и QSqlQueryModel:

//может пригодиться!
//создает объект для запросов SQL
QSqlQuery query( db );
query.exec("SELECT * FROM basetable");
//Вывод значений из БД
query.next();

QString value_0 = query.value(0).toString();//value(0)-элемент 0 массива вывода
QString value_1 = query.value(1).toString();//value(1)-элемент 1 массива вывода
QString value_2 = query.value(2).toString();//value(2)-элемент 2 массива вывода
QString value_3 = query.value(3).toString();//value(3)-элемент 3 массива вывода

QStandardItemModel *model = new QStandardItemModel;//создает модель класса QStandardItemModel
QStandardItem *item;//создает разделы/ячейки в модели
//Ячейки могут содержать текст, иконки и радиокнопки
//По умолчанию разделы редактируемые, с возможностью выбора

//заполняется таблица значениями по типу матрицы
//начинаются координаты с левой верхней ячейки таблицы
//model->setItem настройка каждого элемента item в модели
//model->setItem(0, 0, item) означает 0 строка 0 ячейка, в ячейке содержится значение переменной item
//задает координаты ячейки и ее значение

item = new QStandardItem(QString(value_0));//помещение в модель значения value_0 - переменной со значением из БД
//item = new QStandardItem(QString("0 строка 0 ячейка"));
model->setItem(0, 0, item);
//повторением этого кода заполняется каждая ячейка модели таблицы

item = new QStandardItem(QString(value_1));//помещение в модель значения value_0 - переменной со значением из БД
model->setItem(0, 1, item);
item = new QStandardItem(QString(value_2));//помещение в модель значения value_0 - переменной со значением из БД
model->setItem(1, 0, item);
item = new QStandardItem(QString(value_3));//помещение в модель значения value_0 - переменной со значением из БД
model->setItem(1,1, item);

//model->setRowCount(11);//устанавливает 11 строк
//model->setColumnCount(9);//устанавливает 9 столбцов

//Создают заголовки столбцов таблицы с соответствующими названиями
QStringList horizontalHeader;
horizontalHeader.append("Первый");
horizontalHeader.append("Второй");
horizontalHeader.append("Третий");
horizontalHeader.append("Четвертый");

//Создают заголовки строк таблицы с соответствующими названиями
QStringList verticalHeader;
verticalHeader.append("Это Строка 0");
verticalHeader.append("Это Строка 1");

model->setHorizontalHeaderLabels(horizontalHeader);//добавляет в модель заголовки столбцов
model->setVerticalHeaderLabels(verticalHeader);//добавляет в модель заголовки строк
//без названий заголовки все равно будут, но с номерами 1,2,3 и т.д. вместо названий

//вывести модель в элементе ui->tableView
ui->tableView->setModel(model);//выводит в виде таблицы все элементы

//по умолчанию размеры ячеек фиксированны и содержимое обрезается
ui->tableView->resizeRowsToContents();//расширяет ячейки таблицы до содержимого
ui->tableView->resizeColumnsToContents();//расширяет ячейки таблицы до содержимого

//Код для QSqlTableModel и QSqlRelationalTableModel - таблиц с редактируемыми ячейками
//QSqlRelationalTableModel работает также как QSqlTableModel, но позволяет настройку внешних ключей с другими таблицами
//model->setEditStrategy(QSqlTableModel::OnRowChange);//данные сохранятся в БД сразу при переходе на другую строку


//заполняется таблица значениями по типу матрицы
//начинаются координаты с левой верхней ячейки таблицы
//model->setItem настройка каждого элемента item в модели
//model->setItem(0, 0, item) означает 0 строка 0 ячейка, в ячейке содержится значение переменной item
//задает координаты ячейки и ее значение


/*
ui->tableWidget->setColumnCount(5); // Указываем число колонок
    ui->tableWidget->setShowGrid(true); // Включаем сетку
    // Разрешаем выделение только одного элемента
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    // Разрешаем выделение построчно
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем заголовки колонок
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    // Растягиваем последнюю колонку на всё доступное пространство
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    // Скрываем колонку под номером 0
    ui->tableWidget->hideColumn(0);
*/


/*
//Код для QSqlQueryModel - таблиц только для чтения информации через запросы SQL
model1->setQuery("SELECT * FROM basetable");//в модель помещается результат SQL запроса к существующим в БД, таблице и полям
ui->tableView->setModel(model1);//выводит в виде таблицы все элементы в окне приложения, не работает в функции main()
*/

}
