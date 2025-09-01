class Solution {
public:
     ListNode* solve(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* newNode=solve(head->next);
        head->next->next= head;
        head->next=NULL;
        return newNode;
     }
    ListNode* reverseList(ListNode* head) {
        return solve(head);
    }
};
