#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "fordbworkclass.h"//надо добавить файл класса в файл, в котором он используется

#include "QTextEdit"//общий класс для создания и работы с полем для текста TextEdit

#include "QSqlDatabase"//для работы с БД
#include "QSqlQuery"//для работы с SQL запросами
#include "QTableView"//для работы с графическим выводом информации в виде таблиц
#include "QListView"//для работы с графическим выводом информации в виде списка
#include "QTreeView"//для работы с графическим выводом информации в виде дерева
#include "QStandardItemModel"//общий класс для создания и работы с моделями типов таблица, дерево и список
#include "QStandardItem"//общий класс для создания и работы пунктов модели
#include "QDebug"
#include "QLabel"
#include "QMap"


#include "QRegExp"
#include "QStringList"

// подключение драйвера для БД SQLite, должно осуществляться один раз!
QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(createTable()));


examplefunction(3,126);//вызов функции
}

MainWindow::~MainWindow()
{
    delete ui;
}



//функция, которая вводит текст из поля в массивы
void MainWindow::createTable(){
    //создание объекта класса fordbworkclass
        //Fordbworkclass base;









    //при его создании автоматически сработает метод-функция конструктор, но только один раз!

   QString str = ui->textEdit->toPlainText();//поместить значения из текстового поля в строку
       QStringList list; //массив значений
       list = str.split(' ');//разделить строку знаком пробел и поместить значения в массив

  QString str2 = ui->textEdit_2->toPlainText();//поместить значения из текстового поля в строку
       QStringList list2; //массив значений
       list2 = str2.split(' ');//разделить строку знаком пробел и поместить значения в массив

  QString str3 = ui->textEdit_3->toPlainText();//поместить значения из текстового поля в строку
       QStringList list3; //массив значений
       list3 = str3.split(' ');//разделить строку знаком пробел и поместить значения в массив

  QString str4 = ui->textEdit_4->toPlainText();//поместить значения из текстового поля в строку
      QStringList list4; //массив значений
      list4 = str4.split(' ');//разделить строку знаком пробел и поместить значения в массив

  QString str5 = ui->textEdit_5->toPlainText();//поместить значения из текстового поля в строку
     QStringList list5; //массив значений
     list5 = str5.split(' ');//разделить строку знаком пробел и поместить значения в массив

  QString str6 = ui->textEdit_6->toPlainText();//поместить значения из текстового поля в строку
    QStringList list6; //массив значений
    list6 = str6.split(' ');//разделить строку знаком пробел и поместить значения в массив

   QString str7 = ui->textEdit_7->toPlainText();//поместить значения из текстового поля в строку
     QStringList list7; //массив значений
     list7 = str7.split(' ');//разделить строку знаком пробел и поместить значения в массив

    QString str8 = ui->textEdit_8->toPlainText();//поместить значения из текстового поля в строку
     QStringList list8; //массив значений
     list8 = str8.split(' ');//разделить строку знаком пробел и поместить значения в массив

     QString str9 = ui->textEdit_9->toPlainText();//поместить значения из текстового поля в строку
      QStringList list9; //массив значений
     list9 = str9.split(' ');//разделить строку знаком пробел и поместить значения в массив

     QString str10 = ui->textEdit_10->toPlainText();//поместить значения из текстового поля в строку
      QStringList list10; //массив значений
      list10 = str10.split(' ');//разделить строку знаком пробел и поместить значения в массив

       QStringList lists = { "list", "list2", "list3", "list4", "list5", "list6", "list7", "list8", "list9", "list10" };

QMap<int,QStringList> mapList;//создать массив с ключами int и объектами типа QStringList

mapList.insert(1,list);//присваиваю каждому элементу номер ключа, по которому можно будет обращаться к каждому массиву
mapList.insert(2,list2);
mapList.insert(3,list3);
mapList.insert(4,list4);
mapList.insert(5,list5);
mapList.insert(6,list6);
mapList.insert(7,list7);
mapList.insert(8,list8);
mapList.insert(9,list9);
mapList.insert(10,list10);


int coincidence;//кол-во совпадений для подсчета
int num=0;//номер примера
int i; // номер 1 массива начинается от 1 до 10
int k; // номер 2 массива начинается от i+1 до 10
int a,b; //номера элементов в массиве
//mapList.value(i) и mapList.value(k) обратиться к массиву с номером i или k
//mapList.value(i).size() и mapList.value(k).size() кол-во элементов в массиве mapList.value(k)или mapList.value(i)
//mapList.value(i)[a] и mapList.value(k)[b] значение элементов в массиве с номером a или b

//start
for (i=1;i<=10;i++) {//номер первого массива

for (k=i+1;k<=10;k++) {//номер второго массива
coincidence=0;
      //с элементами первого массива
      for (a = 0; a < mapList.value(i).size(); a++){
       //с элементами второго массива
          for (b = 0; b < mapList.value(k).size(); b++){
              if(mapList.value(i)[a]==mapList.value(k)[b]){//если значения совпадают
                  coincidence++;
                  //qDebug() << "номера совпали= "<< mapList.value(i)[a] << ",";
                 // ui->textEdit_11->append("совпали номера = "+mapList.value(i)[a]);// Добавляет значения в текстовое поле
              }          
          }

}
      ++num;//увеличить номер операции
   // coincidence1=coincidence;//присвоить кол-во совпадений
      ui->textEdit_11->append("№№ таблиц= "+QString::number(i)+" и "+QString::number(k));// Добавляет значения в текстовое поле
      //qDebug() << "№№ таблиц= " << i << " и " << k;
     ui->textEdit_11->append("кол-во совпадений = "+QString::number(coincidence));// Добавляет значения в текстовое поле
    //qDebug() << "кол-во совпадений= " << coincidence;
     //ui->textEdit_11->append("номер операции = "+QString::number(num));// Добавляет значения в текстовое поле
    //qDebug() << "номер операции= " << num;
}
//      qDebug() << "Номер  примера" << num << "с наименьшим кол-вом совпадений " << coincidence1;
}//end






QString stra = ui->textEdit_11->toPlainText();//поместить значения из текстового поля в строку
//поиск с помощью регулярных выражений
QRegExp rx("(\\d+)");//ищет числа и помещает их в массив

//QString stra = "Offsets: 12 14 99 231 7";
QStringList lista;
int pos = 0;

while ((pos = rx.indexIn(stra, pos)) != -1) {
    lista << rx.cap(1);
    pos += rx.matchedLength();
}

for (int i = 0; i < lista.size(); i++) {

        qDebug() << "Значение элемента № " <<i<< " в массиве: "<< lista[i];
}
qDebug() << "размер массива = "<<lista.size();

qDebug() << "все значения массива = "<<lista;

}




void MainWindow::examplefunction(int x, int y){
    int z;
    z=x*y;
    qDebug() << "Пример x+y= "<<z;
}



