/*
 * @Description:
 * @Author: Xiao
 * @Date: 2023-05-08 18:33:40
 * @LastEditTime: 2023-05-15 00:02:20
 * @LastEditors: Xiao
 */
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTreeView>
#include <QPushButton>
#include "Moudles/TitleBar.h"
#include "Controls/ADButton.h"
#include "Moudles/BaseWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BaseWindow w;
    w.setWindowTitle("WidgetBase");
    QPushButton* button1 = new QPushButton("OK");
    QHBoxLayout* hLayout1 = new QHBoxLayout;
    hLayout1->addStretch(1);
    hLayout1->addWidget(button1);

    QVBoxLayout* layout = new QVBoxLayout;
    QTreeView* treeView = new QTreeView;
    layout->addWidget(treeView);
    layout->addLayout(hLayout1);
    layout->addStretch(1);
    w.contentWidget()->setLayout(layout);
    // w.setWindowTitleHeight(40);
    w.show();

    return a.exec();
}
