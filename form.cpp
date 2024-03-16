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
    ui->label_2->setText(str);
}

void Form::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}

