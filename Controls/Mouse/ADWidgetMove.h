/*
 * @Description: 控件移动
 * @Author: Xiao
 * @Date: 2023-05-11 19:44:58
 * @LastEditTime: 2023-05-15 00:22:18
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
    QPoint lastPoint; // 最后按下的坐标
    bool pressed;     // 鼠标是否按下
    bool leftButton;  // 限定鼠标左键
    bool inControl;   // 限定在容器内
    QWidget *widget;  // 移动的控件

public Q_SLOTS:
    // 设置是否限定鼠标左键
    void setLeftButton(bool leftButton);
    // 设置是否限定不能移出容器外面
    void setInControl(bool inControl);
    // 设置要移动的控件
    void setWidget(QWidget *widget);
};

#endif // ADWIDGETMOVE_H