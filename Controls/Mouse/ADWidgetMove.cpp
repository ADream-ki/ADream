/*
 * @Description:
 * @Author: Xiao
 * @Date: 2023-05-11 21:15:51
 * @LastEditTime: 2023-05-16 12:07:59
 * @LastEditors: Xiao
 */
#include "ADWidgetMove.h"

ADWidgetMove::ADWidgetMove(QObject *parent) : QObject(parent)
{
    lastPoint = QPoint(0, 0);
    pressed = false;
    leftButton = true;
    inControl = true;
    control_widget = 0;
    event_widget = 0;

}

ADWidgetMove::~ADWidgetMove()
{
}

bool ADWidgetMove::eventFilter(QObject *watched, QEvent *event)
{
    if (control_widget && watched == event_widget) // watch 过滤对象
    {
        QMouseEvent *mouseEvent = (QMouseEvent *)event;
        if (mouseEvent->type() == QEvent::MouseButtonPress)
        {
            // 如果限定了只能鼠标左键拖动则判断当前是否是鼠标左键
            if (leftButton && mouseEvent->button() != Qt::LeftButton)
            {
                return false;
            }

            // 判断控件的区域是否包含了当前鼠标的坐标
            if (event_widget->rect().contains(mouseEvent->pos()))
            {
                lastPoint = mouseEvent->pos();
                pressed = true;
            }
        }
        else if (mouseEvent->type() == QEvent::MouseMove && pressed)
        {
            // 计算坐标偏移值,调用move函数移动过去
            int offsetX = mouseEvent->pos().x() - lastPoint.x();
            int offsetY = mouseEvent->pos().y() - lastPoint.y();
            int x = control_widget->x() + offsetX;
            int y = control_widget->y() + offsetY;
            if (inControl)
            {
                // 可以自行调整限定在容器中的范围,这里默认保留20个像素在里面
                int offset = 20;
                bool xyOut = (x + control_widget->width() < offset || y + control_widget->height() < offset);
                bool whOut = false;
                QWidget *w = (QWidget *)control_widget->parent();
                if (w)
                {
                    whOut = (w->width() - x < offset || w->height() - y < offset);
                }
                if (xyOut || whOut)
                {
                    return false;
                }
            }

            control_widget->move(x, y);
        }
        else if (mouseEvent->type() == QEvent::MouseButtonRelease && pressed)
        {
            pressed = false;
        }
    }

    return QObject::eventFilter(watched, event);
}

void ADWidgetMove::setLeftButton(bool leftButton)
{
    this->leftButton = leftButton;
}

void ADWidgetMove::setInControl(bool inControl)
{
    this->inControl = inControl;
}

void ADWidgetMove::setWidget(QWidget *control_widget, QWidget *event_widget)
{
    if (this->control_widget == 0)
    {
        this->control_widget = control_widget;
        this->event_widget = event_widget;
        this->event_widget->installEventFilter(this);
    }
}