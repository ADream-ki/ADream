/*
 * @Description:
 * @Author: Xiao
 * @Date: 2023-05-17 11:21:10
 * @LastEditTime: 2023-05-17 20:45:39
 * @LastEditors: Xiao
 */
#include "QssHelper.h"
#include <QFile>

QssHelper::QssHelper(QWidget *QssWidget, QObject *parent) : QObject(parent), QssWidget(QssWidget)
{
}

QssHelper::~QssHelper() {}

 void QssHelper::setStyle(const QString &qssFile)
{
    QFile file(qssFile); // 样式信息存储在了TestWidget.qss文件中
    if (file.open(QFile::ReadOnly))
    {
        QString stylesheet = file.readAll(); // 读取qss样式文件中的所有数据
        file.close();
        // QssWidget->setStyleSheet(stylesheet); // 为当前界面类设置样式表
    }
}