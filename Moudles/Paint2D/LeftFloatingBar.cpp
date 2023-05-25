/*
 * @Description: 左侧悬浮栏，不可移动，具备展开收起效果，以及淡入淡出效果
 * @Author: Xiao
 * @Date: 2023-05-17 12:55:41
 * @LastEditTime: 2023-05-21 14:29:36
 * @LastEditors: Xiao
 */
#include "LeftFloatingBar.h"
#include "../../Controls/Helper/Qss/QssHelper.h"

LeftFloatingBar::LeftFloatingBar(QWidget *parent) : QWidget(parent)
{
    initWidget(parent);
    initAtr();
    QssHelper::setStyle(":Qss/LeftBar2D", this);
    setLayout(glay);
}

LeftFloatingBar::~LeftFloatingBar() {}

void LeftFloatingBar::initWidget(QWidget *parent)
{
    glay = new QGridLayout(this);
    glay->setContentsMargins(0, 0, 0, 0); // 外边框为0
    glay->setSpacing(0);

    Two_pen = new ADButton(":Close", 20, 20, this);
    Two_none = new ADButton(":Close", 20, 20, this);

    glay->addWidget(Two_pen, 0, 0, 1, 1); // 把按钮pb添加到第0行0列，该按钮占据1行和1列单元格。
    glay->addWidget(Two_none, 0, 1, 1, 1);

    glay->setObjectName("ceshi");
    Two_none->setObjectName("Two_none");
    Two_pen->setObjectName("Two_pen");
}

void LeftFloatingBar::initAtr()
{
    // 无边框
    setWindowFlag(Qt::FramelessWindowHint);
    // 启用qss
    setAttribute(Qt::WA_StyledBackground, true);
    setObjectName("leftbar");
}