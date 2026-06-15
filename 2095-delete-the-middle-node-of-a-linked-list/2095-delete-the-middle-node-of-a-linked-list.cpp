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
int size(ListNode* head){
    if(!head) return 0;
    return 1 + size(head->next);
}
    ListNode* deleteMiddle(ListNode* head) {
        int sz = size(head);
        if(sz==0||sz==1) return NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        for(int i=0;i<sz/2;i++){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        return head;
    }
};