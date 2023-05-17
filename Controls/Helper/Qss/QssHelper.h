/*
 * @Description: Qss帮助类
 * @Author: Xiao
 * @Date: 2023-05-17 11:14:43
 * @LastEditTime: 2023-05-17 20:46:46
 * @LastEditors: Xiao
 */
#ifndef QSSHELPER_H
#define QSSHELPER_H

#include <QObject>
#include <QWidget>

class QssHelper : public QObject
{
    Q_OBJECT
public:
    explicit QssHelper(QWidget *QssWidget, QObject *parent = nullptr);
    ~QssHelper();
    // 设置指定样式
    void setStyle(const QString &qssFile);

private:
    QWidget *QssWidget; // 需要设置qss样式的qwidget
};

#endif // QSSHELPER_H