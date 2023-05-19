/*
 * @Description:控制控件飞入飞出，具备信号槽
 * @Author: Xiao
 * @Date: 2023-05-18 00:28:22
 * @LastEditTime: 2023-05-19 20:11:42
 * @LastEditors: Xiao
 */
#ifndef FLY_H
#define FLY_H

#include <QObject>
#include <QWidget>
#include <QPropertyAnimation>

class Fly : public QObject
{
    Q_OBJECT
private:
    // 飞入动画
    QPropertyAnimation *animation_in;
    // 飞出动画
    QPropertyAnimation *animation_out;
    // 需要加载动画的控件
    QWidget *control_widget;

public:
    Fly(QObject *parent, QWidget *control_widget);
    ~Fly();

public slots:
    /// 点击按钮 开始动画运动
    void DoStart(bool intoout);
};

#endif // FLY_H