#include "solver.h"
#include "mainwindow.h"

QString Solver::getAns() {
    return answer;
}

void get_fileslst_Helper(QFileInfoList& fileslist, const QString& PATH) {
    QDir dir(PATH);
    QDir dir1 = dir;
    dir.setFilter(QDir::Dirs);
    dir1.setFilter(QDir::Files);
    QFileInfoList newfileslist = dir1.entryInfoList();
    for (int i = 0; i < newfileslist.length(); ++i) {
        fileslist.append(newfileslist[i]);
    }
    QFileInfoList dirslist = dir.entryInfoList();
    for (int i = 2; i < dirslist.length(); ++i) {
        get_fileslst_Helper(fileslist, dirslist[i].absoluteFilePath());
    }

}

QFileInfoList get_fileslst(const QString& PATH) {
    if (!QDir(PATH).exists()) {
        return QFileInfoList();
    }
    QDir dir(PATH);
    QDir dir1 = dir;
    dir.setFilter(QDir::Dirs);
    dir1.setFilter(QDir::Files);
    QFileInfoList fileslist = dir1.entryInfoList();
    QFileInfoList dirslist = dir.entryInfoList();
    for (int i = 2; i < dirslist.length(); ++i) {
        get_fileslst_Helper(fileslist, dirslist[i].absoluteFilePath());
    }
    return fileslist;
}

Solver::Solver(QString dirPATH) {
    answer = "";
    QFileInfoList fileslst = get_fileslst(dirPATH);
    if (fileslst.length() > 0) {
        std::sort(fileslst.begin(), fileslst.end(), [](QFileInfo file1, QFileInfo file2) {
            return file1.size() > file2.size();
        });
        for (int i = 0; i < 5; ++i) {
            answer += "Path to file: " + fileslst[i].absoluteFilePath() + "    It's weight: " + QString::number(fileslst[i].size()) + " bytes\n";
        }
    } else {
        answer += "no such directory or zero files in it";
    }
}
