#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
/*
借助了额外的空间
*/
    ListNode* reverseList_1(ListNode* head) {
        ListNode* dummyHead = new ListNode();
        ListNode* cur = head;
        while(cur != NULL){
            ListNode* insertHeadNode = new ListNode(cur->val);
            cout<<insertHeadNode->val<<endl;
            insertHeadNode->next = dummyHead->next;
            dummyHead->next = insertHeadNode;
            cur = cur->next;
        }
        return dummyHead->next;
    }
/*
双指针法
*/
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur != NULL){
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
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
    head = slt.reverseList(head);
    p = head;
    while(p->next!=NULL){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<p->val<<endl;

}