#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 如果是头节点就是待删除的元素
        /*
        head != NULL && head->val == val
        这两个判断条件有限后顺序的！！！！
        如果没有先后顺序，那么head->val == val这个条件就会报错
        */
        while(head != NULL && head->val == val){
            head = head->next;
        }  
        /*
        注意内存溢出的问题，最好养成一个好习惯
        */
        // while (head != NULL && head->val == val) { // 注意这里不是if
        //     // ListNode* tmp = head;
        //     head = head->next;
        //     // delete tmp;
        // }
        ListNode *p = head;
        while(p != NULL && p->next != NULL){
            if(p->next->val == val){
                p->next = p->next->next;
            }else{
                p = p->next;
            }
            
        }
        return head;
        /*
        还有一种解法是设置虚拟头节点，这样子head节点也可以纳入上面的循环
        */
    }
};

int main(){
    int a[7] = {1,2,6,3,4,5,6};
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    for(int i=1; i<7; i++){
        p->next = new ListNode(a[i]);
        p = p->next;
    }
    p = head;
    while(p->next!=NULL){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<p->val<<endl;
    Solution slt;
    head = slt.removeElements(head, 6);
    p = head;
    while(p->next!=NULL){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<p->val<<endl;

}