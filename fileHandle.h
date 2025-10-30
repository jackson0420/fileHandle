#ifndef FILEHANDLE_H
#define FILEHANDLE_H
#include <QFileDialog>
#include <QFile>
#include "QTextEdit.h"
#include "xlsxdocument.h"
#include <vector>
using namespace QXlsx;


class filehandle
{
private:
    std::unique_ptr<Document> file;
    QString path;
    QVariant  lineArr;
    QFile outFile;
    int lineNow;
    std::vector<int> getRow;

public:
    filehandle();
    ~filehandle(){};

    bool fileImport(QTextEdit* edit);
    bool fileTreatment();
    void fileTxt(QString line);
    void outFilePathInit(QString path);
    bool getDataRow(QString value,int row,int& findNow);

    QString getRowInfo1;
    QString getRowInfo2;
    QString getRowInfo3;
    QString getRowInfo4;
    QString getRowInfo5;

    QString outFilePath;
};





#endif // FILEHANDLE_H
