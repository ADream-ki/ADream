#include "ADContainer.h"
#include <QVBoxLayout>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QPainter>

ADContainer::ADContainer(QWidget *parent) : QWidget(parent), isMoving_(false), optimizePerformance_(false)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout(layout);

    // 添加初始的 Canvas 控件
    addCanvas();

    // 设置容器的背景色为白色
    setStyleSheet("background-color: white;");
}

ADContainer::~ADContainer() {}

void ADContainer::wheelEvent(QWheelEvent *event)
{
    // 使用滚轮实现放大缩小功能
    qreal scaleFactor = event->angleDelta().y() > 0 ? 1.1 : 0.9;
    for (ADCanva *canvas : canvases_)
    {
        canvas->setScale(canvas->scale() * scaleFactor);
    }
}

void ADContainer::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        // 记录鼠标按下的位置
        lastPos_ = event->pos();
        isMoving_ = true;
    }
}

void ADContainer::mouseMoveEvent(QMouseEvent *event)
{
    if (isMoving_)
    {
        // 计算鼠标移动的偏移量，并将 ADContainer 中所有的 Canvas 控件进行平移
        QPoint delta = event->pos() - lastPos_;
        for (ADCanva *canvas : canvases_)
        {
            canvas->move(canvas->pos() + delta);
            handleOutOfBounds(canvas); // 处理超出边界的情况
        }
        lastPos_ = event->pos();
    }
}

void ADContainer::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        // 停止移动
        isMoving_ = false;
    }
}

void ADContainer::paintEvent(QPaintEvent *event)
{
    // 绘制 ADContainer 的边框
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.drawRect(rect());
}

void ADContainer::addCanvas()
{
    // 创建新的 Canvas 控件并添加到 ADContainer 中
    ADCanva *canvas = new ADCanva(this);
    layout()->addWidget(canvas);
    canvases_.append(canvas);

    // 监听 Canvas 的尺寸变化
    connect(canvas, &ADCanva::sizeChanged, this, [this, canvas]()
            {
                handleOutOfBounds(canvas); // 处理超出边界的情况
            });
}

void ADContainer::handleOutOfBounds(ADCanva *canvas)
{
    // 处理控件超出边界的情况
    int canvasWidth = canvas->width();
    int canvasHeight = canvas->height();

    // 检查右边界
    if (canvas->x() + canvasWidth > width())
    {
        canvas->move(width() - canvasWidth, canvas->y());
    }
    // 检查下边界
    if (canvas->y() + canvasHeight > height())
    {
        canvas->move(canvas->x(), height() - canvasHeight);
    }
    // 检查左边界
    if (canvas->x() < 0)
    {
        canvas->move(0, canvas->y());
    }
    // 检查上边界
    if (canvas->y() < 0)
    {
        canvas->move(canvas->x(), 0);
    }
}

void ADContainer::optimizePerformance(bool optimize)
{
    // 标记是否优化性能，并通知 Canvas 控件进行相应的处理
    optimizePerformance_ = optimize;
    for (ADCanva *canvas : canvases_)
    {
        canvas->setOptimizePerformance(optimize);
    }
}