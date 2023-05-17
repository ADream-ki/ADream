#ifndef CONTENT2D_H
#define CONTENT2D_H

#include <QWidget>

class Content2D : public QWidget
{
    Q_OBJECT
private:
    QWidget *leftbar; // 侧边栏
public:
    Content2D(QWidget *parent);
    ~Content2D();

    void setLeftbar(QWidget *leftbar);
};

#endif // CONTENT2D_H