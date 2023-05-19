/*
 * @Description:基本动画特效类
 * @Author: Xiao
 * @Date: 2023-05-19 21:49:14
 * @LastEditTime: 2023-05-19 22:06:30
 * @LastEditors: Xiao
 */
#ifndef BASEEFFECT_H
#define BASEEFFECT_H

#include <QObject>
#include <QWidget>
#include <QPropertyAnimation>

class BaseEffect : public QObject
{
    Q_OBJECT
public:
    // 显示动画
    QPropertyAnimation *animation_in;
    // 消失动画
    QPropertyAnimation *animation_out;
    // 需要加载动画的控件
    QWidget *control_widget;

public:
    BaseEffect(QObject *parent, QWidget *control_widget) : QObject(parent)
    {
        control_widget = control_widget;
    };

public slots:
    /// 点击按钮 开始动画运动
    void DoStart(bool intoout)
    {
        // 动画开始
        if (intoout)
        {
            animation_in->start();
        }
        else
        {
            animation_out->start();
        }
    };
};

#endif // BASEEFFECT_H