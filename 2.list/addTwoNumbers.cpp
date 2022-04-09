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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};

int main(){
    ListNode* head1 = new ListNode(1);
    ListNode* head1sub1 = new ListNode(2);
    ListNode* head1sub2 = new ListNode(4);
    ListNode* head2 = new ListNode(1);
    ListNode* head2sub1 = new ListNode(3);
    ListNode* head2sub2 = new ListNode(4);
    head1->next = head1sub1;
    head1sub1->next = head1sub2;
    head2->next = head2sub1;
    head2sub1->next = head2sub2;
    Solution stl;
    stl.addTwoNumbers(head1,head2);
}