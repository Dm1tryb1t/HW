#include "solver.h"
#include "mainwindow.h"

QString Solver::getAns() {
    return answer;
}

void get_fileslst_Helper(QFileInfoList& fileslst, const QString& PATH) {


}

QFileInfoList get_fileslst(const QString& PATH) {

    QDir dir(PATH);
    QDir dir1 = dir;

    return QFileInfoList(dir.entryInfoList());
}

Solver::Solver(QString dirPATH) {
    answer = "";
    QFileInfoList fileslst = get_fileslst(dirPATH);
    for (int i = 0; i < fileslst.length(); ++i) {
        answer += fileslst[i].absoluteFilePath() + '\n';
    }
}
