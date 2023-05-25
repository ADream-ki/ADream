/*
 * @Description:
 * @Author: Xiao
 * @Date: 2023-05-08 18:33:40
 * @LastEditTime: 2023-05-21 01:00:30
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
#include "Moudles/MainWindow.h"
#include "Moudles/Paint2D/Content2D.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Content2D *content = new Content2D(&w);
    w.setContentWidget(content);
    w.showMaximized();

    return a.exec();
}
