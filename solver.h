#ifndef SOLVER_H
#define SOLVER_H

#include <QString>

#include <QWidget>
#include <QDir>


class Solver
{
    QString answer;
public:
    Solver(QString dirPATH);
    QString getAns();
};

#endif // SOLVER_H
