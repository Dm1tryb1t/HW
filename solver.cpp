#include "solver.h"
#include "mainwindow.h"

Solver::Solver() {
    answer = "";
}

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
    if (dirslist.length() > 500) {
        throw std::exception();
    }
    for (int i = 2; i < dirslist.length(); ++i) {
        if (fileslist.length() > 0) {
            std::sort(fileslist.begin(), fileslist.end(), [](QFileInfo file1, QFileInfo file2) {
                return file1.size() > file2.size();
            });
            fileslist.resize(((5 < fileslist.length())? 5 : fileslist.length()));
        }
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
    if (dirslist.length() > 500) {
        throw std::exception();
    }
    for (int i = 2; i < dirslist.length(); ++i) {
        get_fileslst_Helper(fileslist, dirslist[i].absoluteFilePath());
        if (fileslist.length() > 0) {
            std::sort(fileslist.begin(), fileslist.end(), [](QFileInfo file1, QFileInfo file2) {
                return file1.size() > file2.size();
            });
            fileslist.resize(((5 < fileslist.length())? 5 : fileslist.length()));
        }
    }
    return fileslist;
}

void Solver::solve (QString dirPATH) {
    answer = "";
    QFileInfoList fileslst = get_fileslst(dirPATH);
    if (fileslst.length() > 0) {
        std::sort(fileslst.begin(), fileslst.end(), [](QFileInfo file1, QFileInfo file2) {
            return file1.size() > file2.size();
        });
        for (int i = 0; i < 5; ++i) {
            long double sz = fileslst[i].size();
            QString szType = "bytes";
            if (sz > static_cast<long double>(1 << 20)) {
                sz /= (1 << 20);
                szType = "Megabytes";
            } else if (sz > static_cast<long double>(1 << 10)) {
                sz /= (1 << 10);
                szType = "Kilobytes";
            }
            answer += "Path to file: " + fileslst[i].absoluteFilePath() + "    It's weight: " + QString::number(sz, 'f', 3) + ' ' + szType + '\n';
        }
    } /* else {
    answer += "no such directory or zero files in it";
    } */
}
