#include "winrepinfo.h"
#include "ui_winrepinfo.h"

WinRepInfo::WinRepInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WinRepInfo)
{
    ui->setupUi(this);
//    ui->tabRepInfo->clear();
    ui->tabRepInfo->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);

    this->resize(1600, 1100);


    QTableWidgetItem * item = new QTableWidgetItem("test");
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tabRepInfo->setItem(2, 2, item);

    setTabHeader();

    ui->tabRepInfo->resizeColumnsToContents(); //自动适应内容宽度
    ui->tabRepInfo->resizeRowsToContents();   //自动适应内容高度

//    ui->tabRepInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //内容均分适应
//    ui->tabRepInfo->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    qDebug()<<"---00000000000000000000000--------------------";
}


WinRepInfo::~WinRepInfo()
{
    delete ui;
}

/*!
 * \brief WinRepInfo::setTabHeader 设置表头
 */
void WinRepInfo::setTabHeader()
{
    QStringList list;
    list<<"序号(num)"<<"仓库名(name)_____________"<<"默认分支(default_branch)"
       <<"链接(html_url)_________________________________________"<<"存档(archived)"<<"uos分支(bool)"<<"其他(other)";
    ui->tabRepInfo->setColumnCount(list.count());

    for (int i = 0; i < list.count(); i++) {
        QTableWidgetItem *item = new QTableWidgetItem(list.at(i));
        ui->tabRepInfo->setHorizontalHeaderItem(i, item);
    }

    ui->tabRepInfo->setRowCount(300);  // 先暂定为 300 行
    for (int i = 0; i < 300; i++) {
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(i));
        ui->tabRepInfo->setVerticalHeaderItem(i, item);
    }
}

/*!
 * \brief WinRepInfo::setTab 实例化表格
 * \param list
 */
void WinRepInfo::setTab(QStringList list, int row)
{
    qDebug()<<"--->"<<list<<"   -->"<<row;
    for (int col = 0; col < list.count(); col++) {
        QTableWidgetItem * item = new QTableWidgetItem(list.at(col));
        ui->tabRepInfo->setItem(row - 1, col, item);
    }
}
