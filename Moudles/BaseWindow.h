/*
 * @Description:
 * @Author: Xiao
 * @Date: 2023-05-08 18:33:40
 * @LastEditTime: 2023-05-15 21:08:40
 * @LastEditors: Xiao
 */
#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QFrame>
#include <QWidget>
#include <QVBoxLayout>
#include "TitleBar.h"
#include "../Controls/ADBorderContainer.h"

class BaseWindow : public QFrame
{
    Q_OBJECT
public:
    BaseWindow(QFrame *parent = NULL);
    void setWindowTitle(const QString &title);
    QWidget *contentWidget();

private:
    QWidget *m_contentWidget;       // 内容组件
    TitleBar *m_titleBar;           // 标题栏
    QVBoxLayout *m_layout;          // 布局管理器
    ADBorderContainer *m_container; // 最外层容器
};
#endif // BASEWINDOW_H