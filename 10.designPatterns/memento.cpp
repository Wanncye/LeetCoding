/*
* 关键代码：Memento类、Originator类、Caretaker类；Originator类不与Memento类耦合，而是与Caretaker类耦合。
*/

#include <iostream>

using namespace std;

//需要保存的信息
typedef struct
{
    int grade;
    string arm;
    string corps;
}GameValue;

//Memento类
class Memento
{
public:
    Memento(){}
    Memento(GameValue value):m_gameValue(value){}
    GameValue getValue()
    {
        return m_gameValue;
    }
private:
    GameValue m_gameValue;
};

//Originator类
class Game
{
public:
    Game(GameValue value):m_gameValue(value)
    {}
    void addGrade()  //等级增加
    {
        m_gameValue.grade++;
    }
    void replaceArm(string arm)  //更换武器
    {
        m_gameValue.arm = arm;
    }
    void replaceCorps(string corps)  //更换工会
    {
        m_gameValue.corps = corps;
    }
    Memento saveValue()    //保存当前信息
    {
        Memento memento(m_gameValue);
        return memento;
    }
    void load(Memento memento) //载入信息
    {
        m_gameValue = memento.getValue();
    }
    void showValue()
    {
        cout << "Grade: " << m_gameValue.grade << endl;
        cout << "Arm  : " << m_gameValue.arm.data() << endl;
        cout << "Corps: " << m_gameValue.corps.data() << endl;
    }
private:
    GameValue m_gameValue;
};

//Caretaker类
class Caretake
{
public:
    void save(Memento memento)  //保存信息
    {
        m_memento = memento;
    }
    Memento load()            //读已保存的信息
    {
        return m_memento;
    }
private:
    Memento m_memento;
};

int main()
{
    GameValue v1 = {0, "Ak", "3K"};
    Game game(v1);    //初始值
    game.addGrade();
    game.showValue();
    cout << "----------" << endl;
    Caretake care;
    care.save(game.saveValue());  //保存当前值
    game.addGrade();          //修改当前值
    game.replaceArm("M16");
    game.replaceCorps("123");
    game.showValue();
    cout << "----------" << endl;
    game.load(care.load());   //恢复初始值
    game.showValue();
    return 0;
}