#ifndef SOLVER_H
#define SOLVER_H

#include <QString>

#include <QWidget>
#include <QDir>


class Solver
{
    QString answer;
public:
    Solver();
    QString getAns();
    void solve(QString);
};

#endif // SOLVER_H
