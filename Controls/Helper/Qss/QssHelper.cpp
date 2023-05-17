#include "QssHelper.h"

QssHelper::QssHelper(QObject *parent) : QObject(parent)
{
    // parent->setAttribute(Qt::WA_StyledBackground); // 启用 QSS
}

QssHelper::~QssHelper() {}

void QssHelper::setStyle(const QString &qssFile)
{
    // QFile file(qssFile);
    // if (file.open(QFile::ReadOnly))
    // {
    //     QString qss = QLatin1String(file.readAll());
    //     qApp->setStyleSheet(qss);
    //     QString PaletteColor = qss.mid(20, 7);
    //     qApp->setPalette(QPalette(QColor(PaletteColor)));
    //     file.close();
    // }
}