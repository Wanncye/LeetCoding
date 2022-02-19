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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        ListNode* preSlow = fast;
        while(n && fast != NULL){
            fast = fast->next;
            n--;
        }
        while(fast != NULL){
            fast = fast->next;
            preSlow = slow;
            slow = slow->next;
        }
        preSlow->next = slow->next;
        delete slow;
        
        return dummyHead->next;
    }
};

int main(){
    int a[6] = {1,2,6,3,4,5};
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
    head = slt.removeNthFromEnd(head,5);
    p = head;
    while(p->next!=NULL){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<p->val<<endl;

}