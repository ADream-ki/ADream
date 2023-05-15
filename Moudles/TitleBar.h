/*
 * @Description:
 * @Author: Xiao
 * @Date: 2023-05-05 14:27:42
 * @LastEditTime: 2023-05-14 21:52:30
 * @LastEditors: Xiao
 */
#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QLabel>
#include <QPalette>
#include <QApplication>
#include "../Controls/ADButton.h"

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    // 图标，标题，三个按钮，宽高，父窗口
    explicit TitleBar(QString ico_url, QString name, int h,
                      QWidget *parent = nullptr);
    ~TitleBar();

protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *event);

private:
    // 初始化控件
    void initWidget(QWidget *parent);
    // 初始化对应参数
    void initPar(QWidget *parent);

protected slots:
    // 最小化、最大化/还原、关闭按钮点击时响应的槽函数
    void onClicked();

private:
    QLabel *m_iconLabel;
    QLabel *m_titleLabel;
    ADButton *m_minimizeButton;
    ADButton *m_maximizeButton;
    ADButton *m_closeButton;
    QPoint m_start;           // 起始点
    QPoint m_end;             // 结束点
    bool m_leftButtonPressed; // 鼠标左键按下标记
};

#endif // TITLEBAR_H
