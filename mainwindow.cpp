#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "solver.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(&form, &Form::firstWindowMaximized, this, &MainWindow::showMaximized);
    connect(&form, &Form::firstWindow, this, &MainWindow::show);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString dir = ui->lineEdit->text();
    // QString dir("C:\\Users\\Dmitry\\Desktop\\github\\HW");
    try {
        Solver solve;
        solve.solve(dir);
        if (this->isMaximized()) {
            form.showMaximized();
        } else {
            form.show();
        }
        form.setAns(solve.getAns());
        ui->lineEdit->setText("");
        this->close();
    } catch(const std::exception&) {
        error.show();
    }


}


void MainWindow::on_toolButton_clicked()
{
    QString DirName = QFileDialog::getExistingDirectory(this, "Choose directory", "/", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->lineEdit->setText(DirName);
}

