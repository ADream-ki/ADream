/*
 * @Description:
 * @Author: Xiao
 * @Date: 2023-05-17 14:43:03
 * @LastEditTime: 2023-05-23 13:23:47
 * @LastEditors: Xiao
 */
#include "Content2D.h"
#include "LeftFloatingBar.h"
#include "../../Controls/Helper/Qss/QssHelper.h"

Content2D::Content2D(QWidget *parent) : QWidget(parent)
{
    initPar();
    initWidget();
    setStyle();
}

Content2D::~Content2D()
{
}

void Content2D::setLeftbar(QWidget *leftbar)
{
    leftbar = leftbar;
}

void Content2D::initWidget()
{
    // 左侧悬浮侧边栏
    leftbar = new LeftFloatingBar(this);
    leftbar->setGeometry(0, 0, 200, 200);
    leftbar->show();

    // v_layout = new QVBoxLayout;
}
void Content2D::initPar()
{
    // 无边框
    setWindowFlag(Qt::FramelessWindowHint);
    // 启用qss
    setAttribute(Qt::WA_StyledBackground, true);
    setObjectName("leftbar");
}
void Content2D::setStyle()
{
    // QssHelper::setStyle(":Qss/LeftBar2D", this);
}