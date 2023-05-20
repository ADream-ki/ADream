/*
 * @Description:内容管理，同时可拉伸
 * @Author: Xiao
 * @Date: 2023-05-08 18:33:40
 * @LastEditTime: 2023-05-20 14:33:57
 * @LastEditors: Xiao
 */
#include "BaseWindow.h"
#include <QEvent>
#include "Paint2D/Content2D.h"
#include "../Controls/Helper/Qss/QssHelper.h"

BaseWindow::BaseWindow(QWidget *parent) : QWidget(parent)
{
    setAtr();     // 设置属性
    initWidget(); // 设置子控件
    setStyle();   // 设置样式
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

void BaseWindow::setContentWidget(QWidget *contentWidget)
{
    m_layout->removeWidget(m_contentWidget);
    delete m_contentWidget;
    m_contentWidget = contentWidget;
    m_layout->addWidget(m_contentWidget);
}

void BaseWindow::setStyle()
{
    // QSS样式应该从主界面到最小的控件
    QssHelper::setStyle(":Qss/Main", this); // 底层主界面
    // QssHelper::setStyle(":Qss/TitleBar", m_titleBar);      // 标题栏
    // QssHelper::setStyle(":Qss/TitleBar", m_contentWidget); // 内容组件
}

void BaseWindow::initWidget()
{
    m_titleBar = new TitleBar(":LOGO",
                              "ADream", 30, this);
    m_titleBar->setObjectName("TitleBar");
    m_titleBar->setProperty("TitleBar", true);

    m_contentWidget = new QWidget(this);
    m_contentWidget->setFixedHeight(this->width() - 50);
    m_contentWidget->setObjectName("Contents");
    m_contentWidget->setProperty("Contents", true);

    m_layout = new QVBoxLayout; // 垂直布局
    m_layout->addWidget(m_titleBar);
    m_layout->addWidget(m_contentWidget);
    m_layout->setSpacing(0);
    m_layout->setContentsMargins(0, 0, 0, 0);

    setLayout(m_layout);
    // 创建边框类容器
    border = new ADBorderContainer(this, 800, 800, 5);
}

void BaseWindow::setAtr()
{
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    // 关闭QT边框
    setMouseTracking(true);
    // 设置最小尺寸
    setMinimumSize(config->Min_width, config->Min_height);
    setObjectName("mainwindow");
}