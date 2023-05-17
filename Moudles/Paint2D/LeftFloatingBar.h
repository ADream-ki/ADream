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

private:
    QGridLayout *glay;  // 布局
    ADButton *Two_pen;  // 画布的画笔
    ADButton *Two_none; // 画布的橡皮擦
};
#endif // LEFTFLOATINGBAR_H