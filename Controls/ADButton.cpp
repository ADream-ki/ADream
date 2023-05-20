/*
 * @Description:
 * @Author: Xiao
 * @Date: 2023-05-08 18:33:40
 * @LastEditTime: 2023-05-20 15:25:40
 * @LastEditors: Xiao
 */
#include "ADButton.h"

#include <QPainter>
#include <QMouseEvent>
#include <QIcon>

void ADButton::initAtr()
{
    // 大小策略,自适应,水平方向与垂直方向
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    // 设置大小
    setFixedSize(w, h);
    // 设置默认追踪鼠标，否则在触发鼠标移动时，必须先点一下才有效
    setMouseTracking(true);
    // 设置无边框
    setWindowFlags(Qt::FramelessWindowHint);
    // 启用QSS
    setAttribute(Qt::WA_StyledBackground, true);
}

void ADButton::initWidget()
{
    // 显示图片
    contain = new QLabel(this);
    contain->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QIcon icon = QIcon(ico_url);
    contain->setPixmap(icon.pixmap(w, h));
    contain->setObjectName("icon");
    contain->setMouseTracking(true);
    contain->setWindowFlags(Qt::FramelessWindowHint);
}

ADButton::ADButton(QString ico_url, int w, int h, QWidget *parent)
    : QWidget(parent), ico_url(ico_url), w(w), h(h)
{
    initAtr();
    initWidget();
}

void ADButton::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit clicked();
    }
}

void ADButton::setIco(QString url)
{
    this->contain->setPixmap(QIcon(url).pixmap(w, h));
}