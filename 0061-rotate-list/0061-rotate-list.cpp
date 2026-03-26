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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int n = 0;
        ListNode* last = NULL;
        while(temp){
            n++;
            if(temp->next==NULL) last = temp;
            temp = temp->next;
        }
        if(n==0) return NULL;
        k = k%n;
        if(k==0||n==1) return head;
        int cnt =1;
        ListNode* new_head = NULL;
        temp = head;
        while(temp){
            if(cnt==n-k){
                new_head = temp->next;
                temp->next=NULL;
                break;
            }
            temp = temp->next;
            cnt++;
        }
        last->next = head;
        return new_head; 
    }
};