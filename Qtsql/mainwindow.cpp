#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QTableView>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  //使用sqlite数据库驱动
    db.setDatabaseName("/Users/kingjames/Desktop/oopproject/电影.db");
    QSqlQuery douban(db);
    model = new QSqlTableModel(this);
    model->setTable("douban");
    model->select();

    // 设置编辑策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();

    // 根据姓名进行筛选，一定要使用单引号
    model->setFilter(QString("电影 = '%1'").arg(name));
    model->select();
    ui->tableView->setModel(model);
}

void MainWindow::on_pushButton_2_clicked()
{
    model->setTable("Douban");
    model->select();

    // 设置编辑策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);

}
