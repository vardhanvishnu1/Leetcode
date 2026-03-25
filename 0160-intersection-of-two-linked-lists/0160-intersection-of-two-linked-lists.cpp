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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*>s1;
        set<ListNode*>s2;
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        while(t1||t2){
            if(s2.find(t1)!=s2.end()) return t1;
            s1.insert(t1);
            if(s1.find(t2)!=s1.end()) return t2;
            s2.insert(t2);
            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;
        }
        return NULL;
    }
};