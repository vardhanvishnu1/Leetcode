/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        bool flag = false;
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) {flag=true;break;}
        }
        if(!flag) return NULL;
        ListNode * check = head;
        if(check==slow) return check;
        while(check){
            check = check->next;
            slow = slow->next;
            if(check==slow) return check;
        }
    return NULL;
    }
};