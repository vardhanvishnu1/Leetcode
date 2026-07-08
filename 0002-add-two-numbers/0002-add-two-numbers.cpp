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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;
        ListNode* prev = NULL;
        while(t1||t2){
            int c1 =0,c2 =0;
            if(t1) c1 = t1->val;
            if(t2) c2 = t2->val;
            int total = c1+c2+carry;
            if(carry==1) carry = 0;
            int cur = 0;
            if(total>9) {carry = 1;cur = total%10;}
            else cur = total;
            if(t1) t1->val = cur;
            else {prev->next = new ListNode(cur);t1 = prev->next;}
            prev = t1;
            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;
        }
        if(carry==1&&prev) prev->next = new ListNode(1);
        return l1;
    }
};