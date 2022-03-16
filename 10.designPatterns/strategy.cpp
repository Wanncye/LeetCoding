/*
* 关键代码：实现同一个接口。
* 以下代码实例中，以游戏角色不同的攻击方式为不同的策略，游戏角色即为执行不同策略的环境角色。
*/

#include <iostream>

using namespace std;

//抽象策略类，提供一个接口
class Hurt
{
public:
    virtual void blood() = 0;
};

//具体的策略实现类，具体实现接口， Adc持续普通攻击
class AdcHurt : public Hurt
{
public:
    void blood() override
    {
        cout << "Adc hurt, Blood loss" << endl;
    }
};

//具体的策略实现类，具体实现接口， Apc技能攻击
class ApcHurt : public Hurt
{
public:
    void blood() override
    {
        cout << "Apc Hurt, Blood loss" << endl;
    }
};

//环境角色类， 游戏角色战士，传入一个策略类指针参数。
class Soldier
{
public:
    Soldier(Hurt* hurt):m_pHurt(hurt)
    {
    }
    //在不同的策略下，该游戏角色表现出不同的攻击
    void attack()
    {
        m_pHurt->blood();
    }
private:
    Hurt* m_pHurt;
};

//定义策略标签
typedef enum
{
    Hurt_Type_Adc,
    Hurt_Type_Apc,
    Hurt_Type_Num
}HurtType;

//环境角色类， 游戏角色法师，传入一个策略标签参数。
class Mage
{
public:
    Mage(HurtType type)
    {
        switch(type)
        {
        case Hurt_Type_Adc:
            m_pHurt = new AdcHurt();
            break;
        case Hurt_Type_Apc:
            m_pHurt = new ApcHurt();
            break;
        default:
            break;
        }
    }
    ~Mage()
    {
        delete m_pHurt;
        m_pHurt = nullptr;
        cout << "~Mage()" << endl;
    }

    void attack()
    {
        m_pHurt->blood();
    }
private:
    Hurt* m_pHurt;
};

//环境角色类， 游戏角色弓箭手，实现模板传递策略。
template<typename T>
class Archer
{
public:
    void attack()
    {
        m_hurt.blood();
    }
private:
    T m_hurt;
};

int main()
{
    Archer<AdcHurt>* arc = new Archer<AdcHurt>;
    arc->attack();

    Soldier* sod = new Soldier(new AdcHurt());
    sod->attack();

    Mage* mag = new Mage(Hurt_Type_Apc);
    mag->attack();
    
    delete arc;
    arc = nullptr;

    return 0;
}