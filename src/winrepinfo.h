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

public:
    explicit WinRepInfo(QWidget *parent = nullptr);
    ~WinRepInfo();

    void setTabHeader();
    void setTab(QStringList list, int row);

private:
    Ui::WinRepInfo *ui;
};

#endif // WINREPINFO_H
