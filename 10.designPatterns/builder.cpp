/*
*关键代码：建造者类：创建和提供实例； Director类：管理建造出来的实例的依赖关系。
*/

#include <iostream>
#include <string>

using namespace std;

//具体的产品类
class Order
{
public:
    void setFood(const string& food)
    {
        m_strFood = food;
    }

    const string& food()
    {
        cout << m_strFood.data() << endl;
        return m_strFood;
    }

    void setDrink(const string& drink)
    {
        m_strDrink = drink;
    }

    const string& drink()
    {
        cout << m_strDrink << endl;
        return m_strDrink;
    }

private:
    string m_strFood;
    string m_strDrink;
};

//抽象建造类，提供建造接口。
class OrderBuilder
{
public:
    virtual ~OrderBuilder()
    {
        cout << "~OrderBuilder()" << endl;
    }
    virtual void setOrderFood() = 0;
    virtual void setOrderDrink() = 0;
    virtual Order* getOrder() = 0;
};

//具体的建造类
class VegetarianOrderBuilder : public OrderBuilder
{
public:
    VegetarianOrderBuilder()
    {
        m_pOrder = new Order;
    }

    ~VegetarianOrderBuilder()
    {
        cout << "~VegetarianOrderBuilder()" << endl;
        delete m_pOrder;
        m_pOrder = nullptr;
    }

    void setOrderFood() override
    {
        m_pOrder->setFood("vegetable salad");
    }

    void setOrderDrink() override
    {
        m_pOrder->setDrink("water");
    }

    Order* getOrder() override
    {
        return m_pOrder;
    }

private:
    Order* m_pOrder;
};

//具体的建造类
class MeatOrderBuilder : public OrderBuilder
{
public:
    MeatOrderBuilder()
    {
        m_pOrder = new Order;
    }
    ~MeatOrderBuilder()
    {
        cout << "~MeatOrderBuilder()" << endl;
        delete m_pOrder;
        m_pOrder = nullptr;
    }

    void setOrderFood() override
    {
        m_pOrder->setFood("beef");
    }

    void setOrderDrink() override
    {
        m_pOrder->setDrink("beer");
    }

    Order* getOrder() override
    {
        return m_pOrder;
    }

private:
    Order* m_pOrder;
};

//Director类，负责管理实例创建的依赖关系，指挥构建者类创建实例
class Director
{
public:
    Director(OrderBuilder* builder) : m_pOrderBuilder(builder)
    {
    }
    void construct()
    {
        m_pOrderBuilder->setOrderFood();
        m_pOrderBuilder->setOrderDrink();
    }

private:
    OrderBuilder* m_pOrderBuilder;
};


int main()
{
//  MeatOrderBuilder* mBuilder = new MeatOrderBuilder;
    OrderBuilder* mBuilder = new MeatOrderBuilder();  //注意抽象构建类必须有虚析构函数，解析时才会调用子类的析构函数
    Director* director = new Director(mBuilder);
    director->construct();
    Order* order = mBuilder->getOrder();
    order->food();
    order->drink();

    delete director;
    director = nullptr;

    delete mBuilder;
    mBuilder = nullptr;

    return 0;
}