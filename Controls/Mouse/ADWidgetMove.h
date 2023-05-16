/*
 * @Description: 控件移动
 * @Author: Xiao
 * @Date: 2023-05-11 19:44:58
 * @LastEditTime: 2023-05-16 09:57:02
 * @LastEditors: Xiao
 */

#ifndef ADWIDGETMOVE_H
#define ADWIDGETMOVE_H

#include <QWidget>
#include <QObject>
#include <QMouseEvent>

class ADWidgetMove : public QObject
{
    Q_OBJECT
public:
    explicit ADWidgetMove(QObject *parent = 0);
    ~ADWidgetMove();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    QPoint lastPoint;        // 最后按下的坐标
    bool pressed;            // 鼠标是否按下
    bool leftButton;         // 限定鼠标左键
    bool inControl;          // 限定在容器内
    bool isMove;             // 是否可以移动
    QWidget *control_widget; // 控制移动的控件
    QWidget *event_widget;   // 作用的对象

public Q_SLOTS:
    // 设置是否限定鼠标左键
    void setLeftButton(bool leftButton);
    // 设置是否限定不能移出容器外面
    void setInControl(bool inControl);
    // 设置要移动以及x的控件
    void setWidget(QWidget *control_widget, QWidget *event_widget);
    // 是否可以移动
    void setisMove(bool ismove);
};

#endif // ADWIDGETMOVE_H