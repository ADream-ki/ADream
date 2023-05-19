#include "Fly.h"
#include <QRect>
Fly::Fly(QObject *parent, QWidget *control_widget) : QObject(parent), control_widget(control_widget)
{
    // 设置仿真对象，并设置仿真属性为几何属性
    animation_in = new QPropertyAnimation(control_widget, "geometry", parent);
    animation_in->setEasingCurve(QEasingCurve::InOutSine);
    animation_in->setDuration(1000);                      // 动画持续的时间(毫秒)
    animation_in->setStartValue(QRect(0, 0, 300, 100));   // 动画属性开始时的值
    animation_in->setEndValue(QRect(300, 300, 300, 100)); // 动画属性结束时的值

    animation_out = new QPropertyAnimation(control_widget, "geometry", parent);
    animation_out->setEasingCurve(QEasingCurve::InOutSine);
    animation_out->setDuration(1000);                        // 动画持续的时间(毫秒)
    animation_out->setStartValue(QRect(300, 300, 300, 300)); // 动画属性开始时的值
    animation_out->setEndValue(QRect(0, 0, 300, 100));       // 动画属性结束时的值
}

Fly::~Fly()
{
}

void Fly::DoStart(bool intoout)
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
}