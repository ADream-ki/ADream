/*
 * @Description: 画板类，缩放相关都在容器中实现，画板只具备绘制操作，左键按下绘画，右键按下鼠标穿透
 * @Author: Xiao
 * @Date: 2023-05-08 18:33:40
 * @LastEditTime: 2023-05-22 22:19:17
 * @LastEditors: Xiao
 */
#ifndef ADCANVA_H
#define ADCANVA_H

#include <QWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QLabel>

#include <QWidget>

class ADCanva : public QWidget
{
    Q_OBJECT
public:
    explicit ADCanva(QWidget *parent = nullptr);
    ~ADCanva();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    qreal scale_;              // 控制画布的缩放比例
    bool optimizePerformance_; // 标记是否优化性能

public:
    qreal scale() const;
    void setScale(const qreal &scale);
    void setOptimizePerformance(bool optimize);

signals:
    void sizeChanged(); // 尺寸变化信号
};

#endif // ADCANVA_H
