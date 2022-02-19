#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(){}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyLinkedList {
public:
    ListNode* dummyHead;
    int size;

    MyLinkedList() {
        dummyHead = new ListNode(0);
        size = 0;
    }
    
    int get(int index) {
        if(index>=0 && index<size){
            ListNode *p = dummyHead;
            int i = 0;
            while(p->next != NULL && i != index+1){
                p = p->next;
                i++;
            }
            cout<<p->val<<endl;
            return p->val;
        }else{
            return -1;
        }
    }
    
    void addAtHead(int val) {
        ListNode * newNode = new ListNode(val);
        newNode->next = dummyHead->next;
        dummyHead->next = newNode;
        size++;
    }
    
    //对于p指针，不能用delete来删掉
    void addAtTail(int val) {
        ListNode *p = dummyHead;
        ListNode *newNode = new ListNode(val);
        while(p->next != NULL){
            p = p->next;
        }
        p->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        else if(index <= 0){
            addAtHead(val);
        }
        else{
            ListNode* newNode = new ListNode(val);
            ListNode *p = dummyHead;
            int i = 0;
            while(p->next != NULL && i != index ){
                p = p->next;
                i++;
            }
            newNode->next = p->next;
            p->next = newNode;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index>=0 && index<size){
            ListNode *p = dummyHead;
            int i = 0;
            while(p->next != NULL && i != index ){
                p = p->next;
                i++;
            }
            ListNode *tmp = p->next;
            p->next = p->next->next;
            delete tmp;
            size--;
        }
    }

    void print(){
        ListNode *p = dummyHead->next;
        while(p != NULL){
            cout<<p->val<<"->";
            p = p->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    MyLinkedList linkedList = MyLinkedList();
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
    linkedList.print();
    linkedList.get(1);            //返回2
    linkedList.deleteAtIndex(1);  //现在链表是1-> 3
    linkedList.print();
    linkedList.get(1);            //返回3

}