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
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        int iA = 0, iB = 0;
        ListNode* cur = headA;
        while(cur != NULL){
            cur = cur->next;
            iA++;
        }
        cur = headB;
        while(cur != NULL){
            cur = cur->next;
            iB++;
        }
        int diff = abs(iA-iB);
        delete cur;
        ListNode* curA = headA;
        ListNode* curB = headB;
        if(iA > iB){
            while (diff--) curA = curA->next;
        }else if(iA < iB){
            while (diff--) curB = curB->next;
        }
        //相交指的是到那个相交点之后，两个链表指向的节点一样
        //判断两个指针相不相等，是看这两个指针指向的地方相不相同
        //比如在链表节点里面，不是看val值和next的值相不相等
        while(curA != NULL && &curA != &curB){
        // while(curA != NULL && (curA->val != curB->val || curA->next != curB->next)){
            curA = curA->next;
            curB = curB->next;
        }
        return curA == NULL ? NULL : curA;

    }
};

int main(){
    int a[7] = {1,2,6,3,4,5,6};
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    cout<<p->val<<endl;
    cout<<(p==head)<<endl;

}