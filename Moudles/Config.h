/*
 * @Description: 软件配置类，单例模式
 * @Author: Xiao
 * @Date: 2023-05-10 19:55:57
 * @LastEditTime: 2023-05-15 23:00:45
 * @LastEditors: Xiao
 */
#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>

class Config : public QObject
{
    Q_OBJECT

public:
    ~Config();

    // 提供一个公有的静态接口,获取该类的实例
    static Config *getInstance();

private:
    // 构造函数私有化,防止外界通过构造创建该类的实例
    explicit Config(QObject *parent = nullptr);

    // 添加私有静态指针变量指向该类的唯一实例
    static Config *instance;

public:
    // 全局变量
    int Min_width = 800; // 最小化时的尺寸，随着窗体的拉伸而修改
    int Min_height = 400;
    bool isMaxScreen = true; // 是否全屏，默认全屏
};

#endif // CONFIG_H
