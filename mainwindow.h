#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "form.h"

#include <QMainWindow>
#include <QDir>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

private:
    Ui::MainWindow *ui;
    Form form;
};
#endif // MAINWINDOW_H
