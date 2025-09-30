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
        ListNode* slow =  head;
        while(slow){
            slow=slow->next;
            l++;
        }
        cout<<l<<endl;
        if(head->next==NULL) return NULL;
        int count =1;
        ListNode* temp = head;
        while(count<(l-n)){
            if(temp&&temp->next) temp = temp->next;
            count++;
        }
        if(n==l) return temp->next;
        if(temp&&temp->next) temp->next = temp->next->next;
        return head;
    }
};