/*
 * @Description:
 * @Author: Xiao
 * @Date: 2023-05-05 14:27:52
 * @LastEditTime: 2023-05-17 00:36:54
 * @LastEditors: Xiao
 */
#include "TitleBar.h"

void TitleBar::initMove(QWidget *parent)
{
    // 设置移动控制
    moveWidget = new ADWidgetMove(this);
    moveWidget->setWidget(parent, this);

    connect(this, SIGNAL(setisMove(bool)), moveWidget, SLOT(setisMove(bool)));
}

void TitleBar::initWidget()
{
    // 初始化布局
    auto *layout = new QHBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);

    // 设置图标
    QIcon icon = QIcon(":LOGO");
    m_iconLabel = new QLabel(this);
    m_iconLabel->setPixmap(icon.pixmap(20, 20));
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
    // //设置最小化按钮
    m_minimizeButton = new ADButton(":None", 20, 20, this);
    layout->addWidget(m_minimizeButton);

    if (config->isMaxScreen)
    {
        m_maximizeButton = new ADButton(":Main-min", 20, 20, this);
    }
    else
    {
        m_maximizeButton = new ADButton(":Main-max", 20, 20, this);
    }
    layout->addWidget(m_maximizeButton);

    m_closeButton = new ADButton(":Close", 20, 20, this);
    layout->addWidget(m_closeButton);

    this->setLayout(layout);

    connect(m_minimizeButton, SIGNAL(clicked()), this, SLOT(onClicked()));
    connect(m_maximizeButton, SIGNAL(clicked()), this, SLOT(onClicked()));
    connect(m_closeButton, SIGNAL(clicked()), this, SLOT(onClicked()));
}

void TitleBar::initPar(QWidget *parent)
{
    // 设置标题栏大小
    //  this->setFixedWidth(parent->width());
    this->setFixedHeight(20);
    // 设置名字
    this->setObjectName("titleBar");
    setProperty("titleBar", true);

    QPalette palette;
    palette.setColor(QPalette::Window, "#ff5f5f5f"); // Qt::yellow);
    this->setAutoFillBackground(true);
    this->setPalette(palette);
}

TitleBar::TitleBar(QString ico_url, QString name, int h,
                   QWidget *parent) : QWidget(parent)
{
    initPar(parent);
    initWidget();
    initMove(parent);
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
