#include "ADCanva.h"
#include "ADContainer.h"
#include <QPainter>
#include <QMouseEvent>
#include <QResizeEvent>

ADCanva::ADCanva(QWidget *parent) : QWidget(parent), scale_(1.0), optimizePerformance_(false)
{
    // 设置 ADCanva 的背景色为白色
    setStyleSheet("background-color: white;");
}

ADCanva::~ADCanva() {}

void ADCanva::paintEvent(QPaintEvent *event)
{
    // 在 ADCanva 上绘制你的图形
    QPainter painter(this);
    painter.scale(scale_, scale_);
    painter.setPen(Qt::black);
    painter.drawText(rect(), Qt::AlignCenter, "Hello, ADCanva!");
}

void ADCanva::mousePressEvent(QMouseEvent *event)
{
    // 鼠标按下时将焦点设置为当前 ADCanva 控件
    setFocus();
    QWidget::mousePressEvent(event);
}

void ADCanva::mouseMoveEvent(QMouseEvent *event)
{
    // 在移动过程中发出尺寸变化信号
    emit sizeChanged();
    QWidget::mouseMoveEvent(event);
}

void ADCanva::mouseReleaseEvent(QMouseEvent *event)
{
    // 在释放鼠标时发出尺寸变化信号
    emit sizeChanged();
    QWidget::mouseReleaseEvent(event);
}

void ADCanva::resizeEvent(QResizeEvent *event)
{
    // 在 ADCanva 尺寸变化时发出尺寸变化信号
    emit sizeChanged();
    QWidget::resizeEvent(event);
}

qreal ADCanva::scale() const
{
    return scale_;
}

void ADCanva::setScale(const qreal &scale)
{
    scale_ = scale;
    update();
}

void ADCanva::setOptimizePerformance(bool optimize)
{
    optimizePerformance_ = optimize;
}
