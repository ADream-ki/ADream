#include "Content2D.h"
#include "LeftFloatingBar.h"

Content2D::Content2D(QWidget *parent) : QWidget(parent)
{
    leftbar = new LeftFloatingBar(this);
}

Content2D::~Content2D()
{
}

void Content2D::setLeftbar(QWidget *leftbar)
{
    leftbar = leftbar;
}