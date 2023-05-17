/*
 * @Description:自定义鼠标控件，鼠标悬浮时颜色改变，
 * @Author: Xiao
 * @Date: 2023-05-08 18:33:40
 * @LastEditTime: 2023-05-17 21:46:24
 * @LastEditors: Xiao
 */

#ifndef ADBUTTON_H
#define ADBUTTON_H

#include <QWidget>
#include <QMouseEvent>
#include <QLabel>

class ADButton : public QWidget
{
    Q_OBJECT
public:
    explicit ADButton(QString ico_url, int w, int h, QWidget *parent = nullptr);
    ~ADButton() = default;

    // 设置图片
    void setIco(QString url);
signals:
    // 发送点击信号
    void clicked();

protected:
    // 鼠标点击事件
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    // 设置属性
    void initAtr();
    // 设置内容
    void initWidget();

private:
    QString ico_url; // 图片路径
    QLabel *contain; // 图片显示容器
    int w;
    int h; // 宽高
};

#endif // ADBUTTON_H
