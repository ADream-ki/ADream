/*
 * @Description:
 * @Author: Xiao
 * @Date: 2023-05-18 08:16:31
 * @LastEditTime: 2023-05-19 22:03:44
 * @LastEditors: Xiao
 */
#include "ExpandtoCollapse.h"

ExpandtoCollapse::ExpandtoCollapse(QObject *parent, QWidget *control_widget) : BaseEffect(parent, control_widget)
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

ExpandtoCollapse::~ExpandtoCollapse() {}