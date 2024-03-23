#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::setAns(QString str) {
    ui->textEdit->setText(str);
}

void Form::on_pushButton_clicked()
{
    ui->textEdit->setText("");
    if (this->isMaximized()) {
        emit firstWindowMaximized();
    } else {
        emit firstWindow();
    }
    this->close();

}


void Form::on_pushButton_2_clicked()
{
    this->close();
}

