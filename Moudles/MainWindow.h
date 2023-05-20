#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFrame>
#include <QWidget>
#include <QVBoxLayout>
#include "TitleBar.h"
#include "Config.h"
#include "../Controls/FrameLessHelper/ADBorderContainer.h"

class MainWindow : public QFrame
{
    Q_OBJECT
public:
    explicit MainWindow(QFrame *parent = NULL);
    ~MainWindow();
    void setWindowTitle(const QString &title);
    QWidget *contentWidget();
    void setContentWidget(QWidget *contentWidget);
    void setStyle();

private:
    void initWidget();
    void setAtr();

private:
    Config *config = Config::getInstance(); // 全局变量
    QWidget *m_contentWidget;               // 内容组件
    TitleBar *m_titleBar;                   // 标题栏
    QVBoxLayout *m_layout;                  // 布局管理器
    ADBorderContainer *border;              // 边框
};
#endif // MAINWINDOW_H