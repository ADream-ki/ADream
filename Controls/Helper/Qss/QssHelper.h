/*
 * @Description: Qss帮助类
 * @Author: Xiao
 * @Date: 2023-05-17 11:14:43
 * @LastEditTime: 2023-05-17 12:41:35
 * @LastEditors: Xiao
 */
#ifndef QSSHELPER_H
#define QSSHELPER_H

#include <QFile>
#include <QObject>

class QssHelper : public QObject
{
    Q_OBJECT
public:
    explicit QssHelper(QObject *parent = nullptr);
    ~QssHelper();
    // 设置指定样式
    void setStyle(const QString &qssFile);
};

#endif // QSSHELPER_H