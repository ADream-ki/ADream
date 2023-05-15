/*
 * @Description: 
 * @Author: Xiao
 * @Date: 2023-05-08 18:33:40
 * @LastEditTime: 2023-05-10 18:35:39
 * @LastEditors: Xiao
 */
#include "ADButton.h"

#include <QPainter>
#include <QMouseEvent>
#include <QIcon>


ADButton::ADButton(QString ico_url,  int w, int h, QWidget *parent)
    : QWidget(parent), ico_url(ico_url), w(w), h(h)
{   
    // 将窗口设置为透明
    // setWindowFlag(Qt::FramelessWindowHint);
    // 大小策略,自适应,水平方向与垂直方向
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    // 设置大小
    setFixedSize(w, h);
    //设置默认追踪鼠标，否则在触发鼠标移动时，必须先点一下才有效
    this->setMouseTracking(true);
    //设置无边框
    this->setWindowFlags(Qt::FramelessWindowHint);
    

    //显示图片
    this->contain = new QLabel(this);
    this->contain->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QIcon icon = QIcon(ico_url);
    this->contain->setPixmap(icon.pixmap(w, h));

    this->contain->setStyleSheet("background-color: #ff5f5f5f");
    this->contain->setMouseTracking(true);
}

void ADButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked();
    }
}

//点击移动，不是悬浮
void ADButton::mouseMoveEvent(QMouseEvent *event)
{
    this->contain->setStyleSheet("background-color: #7fdcdcdc");
}

void ADButton:: leaveEvent(QEvent *event)
{
    this->contain->setStyleSheet("background-color: #ff5f5f5f");
}


void ADButton::setIco(QString url)
{
    this->contain->setPixmap(QIcon(url).pixmap(w, h));
}