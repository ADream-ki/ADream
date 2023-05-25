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

class ADCanva : public QWidget
{
    Q_OBJECT
public:
    explicit ADCanva(QWidget *parent = nullptr);
    ~ADCanva();
signals:

public slots:
    // void canva_move(int offsetX, int offsetY); // 移动
    // void cnava_scale(float scale);             // 缩放
    // void setZ(int z);                          // 设置z值
protected:
    // void paintEvent(QPaintEvent *event) override;

private:
    // 设置属性
    void initAtr();
    // 设置内容
    void initWidget();

private:
    float scale;
    int offsetX; // 偏移量
    int offsetY;
    int z; // 对应z值
};

#endif // ADCANVA_H
