/*
关键代码：创建过程在其子类执行。
*/

#include <iostream>

using namespace std;

//产品抽象类
class Tank
{
public:
    virtual const string& type() = 0;
};

//具体的产品类
class Tank56 : public Tank
{
public:
    Tank56():Tank(),m_strType("Tank56")
    {
    }

    const string& type() override
    {
        cout << m_strType.data() << endl;
        return m_strType;
    }
private:
    string m_strType;
};

//具体的产品类
class Tank96 : public Tank
{
public:
    Tank96():Tank(),m_strType("Tank96")
    {
    }
    const string& type() override
    {
        cout << m_strType.data() << endl;
        return m_strType;
    }

private:
    string m_strType;
};

//抽象工厂类，提供一个创建接口
class TankFactory
{
public:
    //提供创建产品实例的接口，返回抽象产品类
    virtual Tank* createTank() = 0;
};

//具体的创建工厂类，使用抽象工厂类提供的接口，去创建具体的产品实例
class Tank56Factory : public TankFactory
{
public:
    Tank* createTank() override
    {
        return new Tank56();
    }
};

//具体的创建工厂类，使用抽象工厂类提供的接口，去创建具体的产品实例
class Tank96Factory : public TankFactory
{
public:
    Tank* createTank() override
    {
        return new Tank96();
    }
};

//另一种菜鸟教程的实现
class TankFactory_1{
public:
    Tank* createTank(string tankName){
        if(tankName == ""){
         return NULL;
        }        
        if(tankName == "tank56"){
            return new Tank56();
        } else if(tankName == "tank96"){
            return new Tank96();
        }
        return NULL;
    }
};

int main()
{
    TankFactory* factory56 = new Tank56Factory();
    Tank* tank56 = factory56->createTank();
    tank56->type();

    TankFactory* factory96 = new Tank96Factory();
    Tank* tank96 = factory96->createTank();
    tank96->type();

    TankFactory_1* factory = new TankFactory_1();
    Tank* tank96_1 = factory->createTank("tank96");
    tank96_1->type();

    return 0;
}