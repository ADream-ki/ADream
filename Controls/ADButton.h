/*
 * @Description: 
 * @Author: Xiao
 * @Date: 2023-05-08 18:33:40
 * @LastEditTime: 2023-05-10 09:36:30
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
    explicit ADButton(QString ico_url,  int w, int h, QWidget *parent = nullptr);
    ~ADButton() = default;
    
    //设置图片
    void setIco(QString url);
signals:
    //发送点击信号
    void clicked();

protected:
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event) override;
    //鼠标点击事件
    void mousePressEvent(QMouseEvent *event) override;
    // void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event) override;
    
private:
    QString ico_url;//图片路径
    QLabel *contain;//图片显示容器
    int w;
    int h;//宽高
};

#endif // ADBUTTON_H
