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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        //如果只放cur->next->next != NULL这一个条件，是会出错的，因为
        //当cur->next为null时，cur->next->next是错误的表达式
        while(cur->next != nullptr && cur->next->next != NULL){
            ListNode* next1 = cur->next;
            ListNode* next2 = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = next1;
            cur->next->next->next = next2;

            cur = cur->next->next;
        }
        return dummyHead->next;
    }
};

int main(){
    int a[7] = {1,2,6,3,4,5};
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    for(int i=1; i<6; i++){
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
    head = slt.swapPairs(head);
    p = head;
    while(p->next!=NULL){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<p->val<<endl;

}