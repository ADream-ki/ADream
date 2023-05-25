/*
 * @Description: 左上角是悬浮侧边窗，左边是画板，右边是工具列表
 * @Author: Xiao
 * @Date: 2023-05-17 14:42:52
 * @LastEditTime: 2023-05-21 14:31:48
 * @LastEditors: Xiao
 */
#ifndef CONTENT2D_H
#define CONTENT2D_H

#include <QWidget>
#include <QVBoxLayout>

class Content2D : public QWidget
{
    Q_OBJECT
private:
    QWidget *leftbar;      // 侧边栏
    QVBoxLayout *v_layout; // 横向布局
    QWidget *CanvaContain; // 画板
    QWidget *Tool;         // 右侧工具

public:
    explicit Content2D(QWidget *parent);
    ~Content2D();

    void setLeftbar(QWidget *leftbar);
    void initWidget(); // 控件
    void setStyle();   // 美化样式
    void initPar();    // 属性
};

#endif // CONTENT2D_H