#include "Config.h"

// 这句一定要写,因为instance是静态变量,必须要初始化值
Config *Config::instance = NULL;

// 加锁的懒汉式实现
Config *Config::getInstance()
{
    // 当多线程获取单例时有可能引发竞态条件
    static QMutex mutex;
    // 判断是否是第一次调用
    // 假如不为NULL,会直接return
    if (instance == NULL)
    {

        // 防止多进程同时调用创建2个对象的问题
        // 原理是因为是静态变量只会定义一次
        static QMutex mutex;

        // 上锁  QMutexLocker会锁住mutex，当QMutexLocker 被释放的时候会自动解锁
        // locker是局部变量，所以getInstance（）函数结束之后会自动解锁
        QMutexLocker locker(&mutex);

        // 在判断一次,防止其它进程抢先new过了
        if (instance == NULL)
        {
            instance = new Config;
        }
    }

    return instance; // 返回指针
}

Config::Config(QObject *parent) : QObject(parent),
{
}

Config::~Config()
{
    qDebug() << "~ Config";
}