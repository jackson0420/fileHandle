#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filehandle fileHandle;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    fileHandle.fileImport(ui->textEdit);
}


void MainWindow::on_pushButton_2_clicked()
{
    if(ui->textEdit_2->toPlainText() != "")
        fileHandle.getRowInfo1 = ui->textEdit_2->toPlainText();
    if(ui->textEdit_3->toPlainText() != "")
        fileHandle.getRowInfo2 = ui->textEdit_3->toPlainText();
    if(ui->textEdit_4->toPlainText() != "")
        fileHandle.getRowInfo3 = ui->textEdit_4->toPlainText();
    if(ui->textEdit_5->toPlainText() != "")
        fileHandle.getRowInfo4 = ui->textEdit_5->toPlainText();
    if(ui->textEdit_6->toPlainText() != "")
        fileHandle.getRowInfo5 = ui->textEdit_6->toPlainText();
    if(ui->textEdit_7->toPlainText() != "")
        fileHandle.outFilePath = ui->textEdit_7->toPlainText();
}


void MainWindow::on_pushButton_3_clicked()
{
    fileHandle.fileTreatment();
}

