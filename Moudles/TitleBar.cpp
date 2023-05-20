/*
 * @Description:
 * @Author: Xiao
 * @Date: 2023-05-05 14:27:52
 * @LastEditTime: 2023-05-20 08:44:20
 * @LastEditors: Xiao
 */
#include "TitleBar.h"
#include <QFile>
#include "../Controls/Helper/Qss/QssHelper.h"

void TitleBar::initMove(QWidget *parent)
{
    // 设置移动控制
    moveWidget = new ADWidgetMove(this);
    moveWidget->setWidget(parent, this);

    connect(this, SIGNAL(setisMove(bool)), moveWidget, SLOT(setisMove(bool)));
}

void TitleBar::initWidget(int h)
{
    // 初始化布局
    auto *layout = new QHBoxLayout;

    // 设置图标
    QIcon icon = QIcon(":LOGO");
    m_iconLabel = new QLabel(this);
    m_iconLabel->setPixmap(icon.pixmap(h, h));
    m_iconLabel->setScaledContents(true);
    m_iconLabel->setObjectName("Icon");
    layout->addWidget(m_iconLabel);

    // 添加伸缩量
    layout->addStretch(1);

    // 设置标题
    m_titleLabel = new QLabel(this);
    m_titleLabel->setObjectName("TitleName");
    m_titleLabel->setText("ADream");
    m_titleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    layout->addWidget(m_titleLabel);

    // 添加伸缩量
    layout->addStretch(1);

    // 设置最小化按钮
    m_minimizeButton = new ADButton(":None", h, h, this);
    m_minimizeButton->setObjectName("None");
    layout->addWidget(m_minimizeButton);

    // 设置最大化按钮
    if (config->isMaxScreen)
    {
        m_maximizeButton = new ADButton(":Main-min", h, h, this);
    }
    else
    {
        m_maximizeButton = new ADButton(":Main-max", h, h, this);
    }
    m_maximizeButton->setObjectName("Main-max");
    layout->addWidget(m_maximizeButton);

    // 设置关闭按钮
    m_closeButton = new ADButton(":Close", h, h, this);
    m_closeButton->setObjectName("Close");
    layout->addWidget(m_closeButton);

    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);

    // 连接信号槽
    connect(m_minimizeButton, SIGNAL(clicked()), this, SLOT(onClicked()));
    connect(m_maximizeButton, SIGNAL(clicked()), this, SLOT(onClicked()));
    connect(m_closeButton, SIGNAL(clicked()), this, SLOT(onClicked()));
}

void TitleBar::initPar(QWidget *parent, int h)
{
    this->setFixedHeight(h);
    // 设置名字
    this->setObjectName("titleBar");
    setProperty("titleBar", true);

    setAttribute(Qt::WA_StyledBackground, true); // 控件启用 QSS
}

TitleBar::TitleBar(QString ico_url, QString name, int h,
                   QWidget *parent) : QWidget(parent)
{
    initPar(parent,h);
    initWidget(h);
    initMove(parent);

    QssHelper::setStyle(":Qss/TitleBar", this);
}

TitleBar::~TitleBar()
{
}

void TitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    // 双击放大
    m_maximizeButton->clicked();
}

void TitleBar::onClicked()
{
    ADButton *button = qobject_cast<ADButton *>(sender());
    QWidget *Window = this->window();
    if (Window->isWindow())
    {
        if (button == m_minimizeButton)
        {
            Window->showMinimized();
        }
        else if (button == m_maximizeButton)
        { // resize(config->Min_width, config->Min_height)
            if (Window->isMaximized())
            {
                Window->showNormal();
                m_maximizeButton->setIco(":Main-min");
                emit setisMove(true); // 发送信号，不能移动
            }
            else
            {
                Window->showMaximized();
                m_maximizeButton->setIco(":Main-max");
                emit setisMove(false); // 发送信号
            }
        }
        else if (button == m_closeButton)
        {
            Window->close();
        }
    }
}
