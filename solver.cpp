#include "solver.h"

void get_fileslst_Helper(QList<QFileInfo>& fileslst, const QString& PATH) {
    QDir dir(PATH);
    QDir dir1 = dir;
    dir1.setFilter(QDir::Files);
    QList<QFileInfo> newfileslst = dir1.entryInfoList();
    for (int i = 0; i < newfileslst.size(); ++i) {
        fileslst.push_back(newfileslst.at(i));
    }
    dir.setFilter(QDir::Dirs);
    QFileInfoList dirlist = dir.entryInfoList();
    for (int i = 0; i < dirlist.size(); ++i) {
        get_fileslst_Helper(dirlist, PATH + dirlist.at(i).fileName());
    }
}

QList<QFileInfo> get_fileslst(const QString& PATH) {
    QDir dir(PATH);
    QDir dir1 = dir;
    dir1.setFilter(QDir::Files);
    QList<QFileInfo> fileslst = dir1.entryInfoList();
    dir.setFilter(QDir::Dirs);
    QList dirlist = dir.entryInfoList();
    for (int i = 0; i < dirlist.size(); ++i) {
        get_fileslst_Helper(dirlist, PATH + dirlist.at(i).fileName());
    }
    return fileslst;
}

Solver::Solver(QString dirPATH) {
    QList<QFileInfo> fileslst = get_fileslst(dirPATH);

}
