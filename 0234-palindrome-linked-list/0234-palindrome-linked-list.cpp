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

    ListNode* reverseList(ListNode* head) {
       ListNode* curr = head;
       ListNode* prev = NULL;
       ListNode* nxt  = curr->next;
       while(curr){
            nxt = curr->next;
            curr->next=prev;
            prev = curr;
            curr = nxt;
       }
       return prev;
    }
    
    ListNode* mid(ListNode* head) {
       ListNode* slow = head;
       ListNode* fast = head;
       while(fast&&fast->next){
            slow = slow->next;
            fast = fast->next->next;
       }
       return slow;
    }

    bool isPalindrome(ListNode* head) {
       ListNode* temp1 = head;
       ListNode* temp2 = mid(head);
       temp2 = reverseList(temp2);
       while(temp2){
        if(temp1->val!=temp2->val) return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
       }
       return true;
    }
};