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
    ListNode* oddEvenList(ListNode* head) {
        int i=0;
        ListNode* temp = head;
        ListNode* odd = new ListNode(0);
        ListNode* even = new ListNode(0);
        ListNode* t1 = even;
        ListNode* t2 = odd;
        while(temp){
            if(i&1){
                t2->next = new ListNode(temp->val);
                t2=t2->next;
            }
            else{
                t1->next = new ListNode(temp->val);
                t1=t1->next;
            }
            temp = temp->next;
            i++;
        }
        t1->next = odd->next;
        return even->next;
    }
};