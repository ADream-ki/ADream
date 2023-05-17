#ifndef FLY_H
#define FLY_H

#include <QObject>

class Fly : public QObject
{
private:
    /* data */
public:
    Fly(QObject *parent);
    ~Fly();
};

#endif // FLY_H