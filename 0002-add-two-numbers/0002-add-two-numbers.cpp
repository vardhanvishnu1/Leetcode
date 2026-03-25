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
        ListNode* prev = NULL;
        bool flag = false;
        while(t1||t2){
            int curr =0;
            if(t1) curr+=t1->val;
            if(t2) curr+=t2->val;
            if(flag){curr++;flag = false;}
            if(t1){
                t1->val = curr%10;
            }
            else{
                prev->next = new ListNode(curr%10);
                t1 = prev->next;
            }
            if(curr>9) flag = true;
            prev = t1;
            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;
        }
        if(flag){
            prev->next = new ListNode(1);
        }
        return l1;
    }
};