/*
 * @Description:内容管理，同时可拉伸
 * @Author: Xiao
 * @Date: 2023-05-08 18:33:40
 * @LastEditTime: 2023-05-17 13:12:25
 * @LastEditors: Xiao
 */
#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QFrame>
#include <QWidget>
#include <QVBoxLayout>
#include "TitleBar.h"
#include "Config.h"
#include "../Controls/FrameLessHelper/ADBorderContainer.h"

class BaseWindow : public QWidget
{
    Q_OBJECT
public:
    explicit BaseWindow(QWidget *parent = NULL);
    ~BaseWindow();
    void setWindowTitle(const QString &title);
    QWidget *contentWidget();

private:
    Config *config = Config::getInstance(); // 全局变量
    QWidget *m_contentWidget;               // 内容组件
    TitleBar *m_titleBar;                   // 标题栏
    QVBoxLayout *m_layout;                  // 布局管理器
    ADBorderContainer *border;              // 边框
};
#endif // BASEWINDOW_H