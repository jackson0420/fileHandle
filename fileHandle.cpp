#include "fileHandle.h"


filehandle::filehandle()
{
    path = NULL;
    lineNow = 0;
    getRowInfo1 = "SPN";
    getRowInfo2 = "FMI";
    getRowInfo3 = "P-Code";
    getRowInfo4 = "DTCB";
    getRowInfo5 = "故障";
    outFilePath = "D:/CreatedFile.txt";
    //file = std::make_unique<QFile>(path);
}

bool filehandle::fileImport(QTextEdit* edit)
{
    path = QFileDialog::getOpenFileName(nullptr, "选择 Excel 文件","","Excel 文件 (*.xls *.xlsx)");
    edit->setText(path);
    return true;
}

bool filehandle::fileTreatment()
{
    if(path.isEmpty())
    {
        qDebug()<<"path is empty";
        return false;
    }
    file = std::make_unique<Document>(path);

    if(!file->load())
    {
        qDebug()<<"open false";
        return false;
    }

    Worksheet *sheet = dynamic_cast<Worksheet*>(file->currentWorksheet());
    if (!sheet) {
        qDebug() << "当前工作表为空！";
        return false;
    }

    CellRange range = sheet->dimension();

    //解析第一行中的所有列名,将与需提取行的列名比较,保存符合的列数
    int findNow = 0;
    for (int col = range.firstColumn(); col <= range.lastColumn(); ++col) {
        QVariant value = file->read(1, col);
        qDebug()<<getRowInfo1<<value.toString()<<col;
        if(getDataRow(value.toString(),col,findNow))
        {
            col = 0;
        }
    }

    // 读取保存列的每行数据,按固定规则拼接,放入指定文件路径的.txt文件中
    for (int row = range.firstRow() + 1; row <= range.lastRow(); ++row) {
        QString rowData = "{\"";
        int col = 0;
        for (; col < 5; ++col) {
            QVariant value = file->read(row, getRow[col]);
            if(value.toString() == "")
            {
                col = 10;
                break;
            }
            if(col == 0)
            {
                rowData += value.toString() + "\",";
            }
            else if(col != 4)
            {
                rowData += value.toString() + ",";
            }
            else
            {
                rowData += value.toString() + "},\n";
            }
        }
        if(col != 10)
            fileTxt(rowData);
        lineNow++;
        qDebug() << "第" << row << "行:" << rowData;
    }

    return true;
}

void filehandle::fileTxt(QString line)
{
    QFile outFile(outFilePath);

    if(!outFile.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        qDebug() << "无法创建文件:" << outFile.errorString();
        return;
    }

    QTextStream out(&outFile);
    out << line;

    outFile.close();
}

bool filehandle::getDataRow(QString value,int row,int& findNow)
{
    if(value.compare(getRowInfo1) == 0 && findNow == 0)
    {
        getRow.push_back(row);
        findNow++;
        return true;
    }
    if(value.compare(getRowInfo2) == 0 && findNow == 1)
    {
        getRow.push_back(row);
        findNow++;
        return true;
    }
    if(value.compare(getRowInfo3) == 0 && findNow == 2)
    {
        getRow.push_back(row);
        findNow++;
        return true;
    }
    if(value.compare(getRowInfo4) == 0 && findNow == 3)
    {
        getRow.push_back(row);
        findNow++;
        return true;
    }
    if(value.compare(getRowInfo5) == 0 && findNow == 4)
    {
        getRow.push_back(row);
        findNow++;
        return true;
    }
    return false;
}
