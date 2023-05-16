#ifndef FRAMELESS_HELPER_H
#define FRAMELESS_HELPER_H

#include <QObject>

class QWidget;
class FramelessHelperPrivate;

class FramelessHelper : public QObject
{
    Q_OBJECT

public:
    explicit FramelessHelper(QObject *parent = 0);
    ~FramelessHelper();
    // 激活窗体
    void activateOn(QWidget *topLevelWidget);
    // 移除窗体
    void removeFrom(QWidget *topLevelWidget);
    // 设置窗体移动
    void setWidgetMovable(bool movable);
    // 设置窗体缩放
    void setWidgetResizable(bool resizable);
    // 设置橡皮筋移动
    void setRubberBandOnMove(bool movable);
    // 设置橡皮筋缩放
    void setRubberBandOnResize(bool resizable);
    // 设置边框的宽度
    void setBorderWidth(uint width);
    // 设置标题栏高度
    void setTitleHeight(uint height);
    bool widgetResizable();
    bool widgetMovable();
    bool rubberBandOnMove();
    bool rubberBandOnResisze();
    uint borderWidth();
    uint titleHeight();

    // FramelessHelper *pHelper = new FramelessHelper(this);  this指需要处理的窗体
    // pHelper->activateOn(this);  //激活当前窗体
    // pHelper->setTitleHeight(m_pTitleBar->height());  //设置窗体的标题栏高度
    // pHelper->setWidgetMovable(true);  //设置窗体可移动
    // pHelper->setWidgetResizable(true);  //设置窗体可缩放
    // pHelper->setRubberBandOnMove(true);  //设置橡皮筋效果-可移动
    // pHelper->setRubberBandOnResize(true);  //设置橡皮筋效果-可缩放

protected:
    // 事件过滤，进行移动、缩放等
    virtual bool eventFilter(QObject *obj, QEvent *event);

private:
    FramelessHelperPrivate *d;
};

#endif // FRAMELESS_HELPER_H