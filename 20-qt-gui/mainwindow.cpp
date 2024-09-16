#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int firstNum, secondNum;
float resultNum;
void MainWindow::on_btnSum_clicked()
{
    firstNum = ui->lineFirstNumber->text().toInt();
    secondNum = ui->lineSecondNumber->text().toInt();
    resultNum  = firstNum + secondNum;
    ui->lineResult->setText(QString::number(resultNum));
}


void MainWindow::on_btnSub_clicked()
{
    firstNum = ui->lineFirstNumber->text().toInt();
    secondNum = ui->lineSecondNumber->text().toInt();
    resultNum  = firstNum - secondNum;
    ui->lineResult->setText(QString::number(resultNum));
}


void MainWindow::on_btnDiv_clicked()
{
    firstNum = ui->lineFirstNumber->text().toInt();
    secondNum = ui->lineSecondNumber->text().toInt();
    resultNum  = firstNum / (float)secondNum;
    ui->lineResult->setText(QString::number(resultNum));
}


void MainWindow::on_btnMult_clicked()
{
    firstNum = ui->lineFirstNumber->text().toInt();
    secondNum = ui->lineSecondNumber->text().toInt();
    resultNum  = firstNum * secondNum;
    ui->lineResult->setText(QString::number(resultNum));
}

