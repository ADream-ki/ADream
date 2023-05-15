/*
 * @Description:
 * @Author: Xiao
 * @Date: 2023-05-08 18:33:40
 * @LastEditTime: 2023-05-15 21:08:51
 * @LastEditors: Xiao
 */
#include "BaseWindow.h"

BaseWindow::BaseWindow(QFrame *parent) : QFrame(parent)
{
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);

    // m_container = new ADBorderContainer(this);
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

    // m_container->
    setLayout(m_layout);
}

void BaseWindow::setWindowTitle(const QString &title)
{
    m_titleBar->setWindowTitle(title);
}

QWidget *BaseWindow::contentWidget()
{
    return m_contentWidget;
}
