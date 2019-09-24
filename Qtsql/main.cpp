#include <QApplication>
#include <QTextEdit>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QDateTime>
#include <QDebug>
#include <QSqlQueryModel>
#include <QTableView>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    /*QTextEdit display;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  //使用sqlite数据库驱动
    db.setDatabaseName("/Users/kingjames/Desktop/sql/test.db");  //我们之前建立的数据库
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery douban(db);
    douban.exec("select *from Douban");
    model->setQuery(douban);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("bianhao"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("bianhao"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("bianhao"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("bianhao"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("bianhao"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("bianhao"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("bianhao"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("bianhao"));
    QTableView *view = new QTableView();
    view->setModel(model);

    view->show();

    /*bool ok = db.open();  //尝试连接数据库
    if (ok)
    {  //这里用text已经成功连上数据库
        QSqlQuery query;  //新建一个查询的实例
    if (query.exec("select * from Douban"))   //尝试列出 student 表的所有记录
    {  //本次查询成功
int numRows = 0;  //询问数据库驱动，是否驱动含有某种特性
if (db.driver()->hasFeature(QSqlDriver::QuerySize))
            {
                numRows = query.size();  //如果支持结果影响的行数，那么直接记录下来
            }
else
            {
                query.last(); //否则定位到结果最后，qt 文档说，这个方法非常慢
                numRows = query.at() + 1;
                query.seek(-1);
            }
            QString name, age;
            display.append("===========================================");
while(query.next())
            {  //定位结果到下一条记录
                name = query.value(0).toString();
                age = query.value(1).toString();
                QString result = name + " " + age;
                display.append(result);
            }
            display.append("===========================================");
            display.append(QString("totally %1 rows").arg(numRows) );
        }
else
        {  //如果查询失败，用下面的方法得到具体数据库返回的原因
            QSqlError error = query.lastError();
            display.append("From mysql database: " + error.databaseText());
        }
    }
else
    {  //打开数据库失败，显示数据库返回的失败描述
        display.append("cannot open database.");
        display.append("Reason: " + db.lastError().databaseText());
    }
    //QApplication::connect(&app, SIGNAL(lastWindowClose()), &app, SLOT(quit()));*/
    MainWindow w;
    w.show();
return app.exec();
}
