/*
 * @Description: 控件展开收起
 * @Author: Xiao
 * @Date: 2023-05-18 08:16:12
 * @LastEditTime: 2023-05-19 21:57:36
 * @LastEditors: Xiao
 */

#ifndef EXPANDTOCOLLAPSE_H
#define EXPANDTOCOLLAPSE_H

#include <QObject>
#include <QWidget>
#include <QPropertyAnimation>
#include "BaseEffect.h"

class ExpandtoCollapse : public BaseEffect
{
    Q_OBJECT

public:
    ExpandtoCollapse(QObject *parent, QWidget *control_widget);
    ~ExpandtoCollapse();
};

#endif // EXPANDTOCOLLAPSE_H