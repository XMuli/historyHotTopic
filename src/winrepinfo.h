#ifndef WINREPINFO_H
#define WINREPINFO_H

#include <QWidget>
#include <QDebug>
#include <QTableWidgetItem>

namespace Ui {
class WinRepInfo;
}

class WinRepInfo : public QWidget
{
    Q_OBJECT

private:
    enum ColNum {  //自定义各个表段在表格中的列号
        colNum,               //序号(num)
        colName,              //仓库名(name)
        colDefBrach,          //默认分支(default_branch)
        colDefBrachProtect,   //默认分支是否为保护分支
        colSpeBrach,          //指定分支(eg: uos 目标分支)
        colSpeBrachProtect,   //指定分支是否为保护分支
        colHtmlUrl,           //仓库链接
        colArchived           //是否处于存档
    };

public:
    explicit WinRepInfo(QWidget *parent = nullptr);
    ~WinRepInfo();

    void setTabHeader();
    void setTab(QStringList list, int row);


private:
    Ui::WinRepInfo *ui;
};

#endif // WINREPINFO_H
