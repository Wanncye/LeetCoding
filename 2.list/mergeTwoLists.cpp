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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur1=list1;
        ListNode* cur2=list2;
        ListNode* newHead = new ListNode(-1);
        ListNode* newCur = newHead;
        while(cur1!=NULL && cur2!=NULL){
            if(cur1->val < cur2->val){
                newCur->next = cur1; 
                newCur = newCur->next;
                cur1 = cur1->next;
            }else{
                newCur->next = cur2;
                newCur = newCur->next;
                cur2 = cur2->next;
            }
        }
        newCur->next = cur1 == NULL ? cur2 : cur1;
        return newHead->next;
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
    stl.mergeTwoLists(head1,head2);

}