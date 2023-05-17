/*
 * @Description:
 * @Author: Xiao
 * @Date: 2023-05-17 12:17:08
 * @LastEditTime: 2023-05-18 00:19:13
 * @LastEditors: Xiao
 */
#ifndef LEFTFLOATINGBAR_H
#define LEFTFLOATINGBAR_H

#include <QWidget>
#include <QGridLayout>
#include "../Controls/ADButton.h"

class LeftFloatingBar : public QWidget
{
    Q_OBJECT
public:
    LeftFloatingBar(QWidget *parent = nullptr);
    ~LeftFloatingBar();

private:
    void initWidget(QWidget *parent);
    void initAtr();

private:
    QGridLayout *glay;  // 布局
    ADButton *Two_pen;  // 画布的画笔
    ADButton *Two_none; // 画布的橡皮擦
};
#endif // LEFTFLOATINGBAR_H