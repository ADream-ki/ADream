/*
 * @Description:
 * @Author: Xiao
 * @Date: 2023-05-08 18:33:40
 * @LastEditTime: 2023-05-17 14:46:52
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
    w.showMaximized();

    return a.exec();
}
