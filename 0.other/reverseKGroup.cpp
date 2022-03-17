#include <iostream>
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
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail){
        ListNode* prev = tail->next;
        ListNode* p = head;
        while(prev != tail){
            ListNode* tmp=p->next;
            p->next = prev;
            prev = p;
            p = tmp;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode();
        hair->next = head;
        ListNode* pre = hair;

        while(head){
            ListNode* tail = pre;
            for(int i = 0; i < k; i++){
                tail = tail->next;
                if(!tail){
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            pair<ListNode*, ListNode*> result = myReverse(head, tail);
            head = result.first;
            tail = result.second;
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }
};

int main(){
    ListNode* root = new ListNode(1);
    ListNode* a = new ListNode(2);
    ListNode* b = new ListNode(3);
    ListNode* c = new ListNode(4);
    ListNode* d = new ListNode(5);
    root->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    Solution stl;
    stl.reverseKGroup(root, 2);
}