#ifndef ADCONTAINER_H
#define ADCONTAINER_H

#include <QWidget>
#include <QVector>
#include "ADCanva.h"

class ADContainer : public QWidget
{
    Q_OBJECT
public:
    explicit ADContainer(QWidget *parent = nullptr);
    ~ADContainer();

protected:
    void wheelEvent(QWheelEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    QVector<ADCanva *> canvases_; // 存储多个 Canvas 控件
    QPoint lastPos_;              // 用于记录上一次鼠标按下的位置
    bool isMoving_;               // 标记是否正在移动 Container
    bool optimizePerformance_;    // 标记是否优化性能

public slots:
    void addCanvas(); // 添加新的 Canvas 控件

private:
    void handleOutOfBounds(ADCanva *canvas); // 处理控件超出边界的情况
    void optimizePerformance(bool optimize); // 优化性能
};

#endif // ADCONTAINER_H