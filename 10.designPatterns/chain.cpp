/*
* 关键代码：Handler内指明其上级，handleRequest()里判断是否合适，不合适则传递给上级。
*/
#include <iostream>

using namespace std;

enum RequestLevel
{
    Level_One = 0,
    Level_Two,
    Level_Three,
    Level_Four
};

//抽象处理者（Handler）角色，提供职责链的统一接口。
class Leader
{
public:
    Leader(Leader* leader):m_leader(leader){}
    virtual ~Leader(){}
    virtual void handleRequest(RequestLevel level) = 0;
protected:
    Leader* m_leader;
};

//具体处理者（Concrete Handler）角色
class Monitor:public Leader   //链扣1
{
public:
    Monitor(Leader* leader):Leader(leader){}
    void handleRequest(RequestLevel level)
    {
        if(level < Level_Two)
        {
            cout << "Mointor handle request : " << level << endl;
        }
        else
        {
            m_leader->handleRequest(level);
        }
    }
};

//具体处理者（Concrete Handler）角色
class Captain:public Leader    //链扣2
{
public:
    Captain(Leader* leader):Leader(leader){}
    void handleRequest(RequestLevel level)
    {
        if(level < Level_Three)
        {
            cout << "Captain handle request : " << level << endl;
        }
        else
        {
            m_leader->handleRequest(level);
        }
    }
};

//具体处理者（Concrete Handler）角色
class General:public Leader   //链扣3
{
public:
    General(Leader* leader):Leader(leader){}
    void handleRequest(RequestLevel level)
    {
        cout << "General handle request : " << level << endl;
    }
};

int main()
{
    Leader* general = new General(nullptr);
    Leader* captain = new Captain(general);
    Leader* monitor = new Monitor(captain);
    monitor->handleRequest(Level_Two);

    delete monitor;
    monitor = nullptr;
    delete captain;
    captain = nullptr;
    delete general;
    general = nullptr;
    return 0;
}