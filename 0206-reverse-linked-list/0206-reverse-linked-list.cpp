class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* prev = NULL;   // initially no node before head
        ListNode* curr = head;
        ListNode* upcoming = NULL;

        while (curr) {
            upcoming = curr->next;   // save next node
            curr->next = prev;       // reverse the link
            prev = curr;             // move prev forward
            curr = upcoming;         // move curr forward
        }
        return prev; // prev will be the new head
    }
};
