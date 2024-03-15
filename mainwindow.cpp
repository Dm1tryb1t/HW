#include "mainwindow.h"
#include "ui_mainwindow.h"
// #include "solver.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(&form, &Form::firstWindow, this, &MainWindow::showMaximized);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // QString dir = textEdit->toPlainText();
    // QString dir("C:\\Users\\Dmitry\\Desktop\\github\\HW");
    // Solver solve(dir);
    form.showMaximized();
    this->close();
}

