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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            l++;
        }
        if(n==l) return head->next;
        int i =1;
        temp = head;
        while(temp){
            if(i==l-n){
                if(temp->next) temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
            i++;
        }
        return head;
    }
};