/*
 * @Description: 左侧悬浮栏，不可移动，具备飞入飞出效果，以及淡入淡出效果
 * @Author: Xiao
 * @Date: 2023-05-17 12:55:41
 * @LastEditTime: 2023-05-18 00:22:37
 * @LastEditors: Xiao
 */
#include "LeftFloatingBar.h"

LeftFloatingBar::LeftFloatingBar(QWidget *parent) : QWidget(parent)
{
    initWidget(parent);
}

LeftFloatingBar::~LeftFloatingBar() {}

void LeftFloatingBar::initWidget(QWidget *parent)
{
    glay = new QGridLayout();
    Two_pen = new ADButton(":Close", 20, 20, this);
    Two_none = new ADButton(":Close", 20, 20, this);

    glay->addWidget(Two_pen, 0, 0, 1, 1); // 把按钮pb添加到第0行0列，该按钮占据1行和1列单元格。
    glay->addWidget(Two_none, 0, 1, 1, 1);

    setLayout(glay);
}

void LeftFloatingBar::initAtr()
{
    // 无边框
    setWindowFlag(Qt::FramelessWindowHint);
}