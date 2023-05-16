/*
 * @Description:内容管理，同时可拉伸
 * @Author: Xiao
 * @Date: 2023-05-08 18:33:40
 * @LastEditTime: 2023-05-16 09:24:11
 * @LastEditors: Xiao
 */
#include "BaseWindow.h"
#include <QEvent>

BaseWindow::BaseWindow(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);

    // 关闭QT边框
    setMouseTracking(true);

    // 设置最小尺寸
    setMinimumSize(config->Min_width, config->Min_height);

    m_titleBar = new TitleBar(":LOGO",
                              "ADream", 20, this);

    m_contentWidget = new QWidget(this);
    m_contentWidget->setObjectName("Contents");
    m_layout = new QVBoxLayout;
    m_layout->addWidget(m_titleBar);
    m_layout->addWidget(m_contentWidget);
    m_layout->setSpacing(0);
    m_layout->setContentsMargins(0, 0, 0, 0);

    // border->
    setLayout(m_layout);
    // 创建边框类容器
    border = new MyBorderContainer(this);
}

BaseWindow::~BaseWindow()
{
}

void BaseWindow::setWindowTitle(const QString &title)
{
    m_titleBar->setWindowTitle(title);
}

QWidget *BaseWindow::contentWidget()
{
    return m_contentWidget;
}
