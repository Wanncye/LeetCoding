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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){ //存在环
                ListNode* res = head;
                while(res != slow){
                    res = res->next;
                    slow = slow->next;
                }
                return res;
            }
        }
        return NULL;

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