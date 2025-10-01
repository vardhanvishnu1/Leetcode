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
    ListNode* rev(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt ;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr=nxt;
        }
        return prev;
    }

    int length(ListNode* head){
        int sz =0;
        while(head){
            head = head->next;
            sz++;
        }
        return sz;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* head = l1;
        ListNode* prev = nullptr;
        int carry = 0;
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            
            if (l1 != nullptr) {
                sum += l1->val;
            }
            
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            if (l1 == nullptr) {
                prev->next = new ListNode(sum % 10);
                l1 = prev->next;
            } else {
                l1->val = sum % 10;
            }
            
            carry = sum / 10;
            prev = l1;
            if (l1 != nullptr) l1 = l1->next;
        }  
        return head;

    }
};