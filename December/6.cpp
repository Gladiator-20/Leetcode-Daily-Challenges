// Problem Link : https://leetcode.com/problems/odd-even-linked-list/

// Author - gladiator-20

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)return head;
        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* o = odd;
        ListNode* e = even;
        while(e && e->next){            
            o->next = e->next;
            o = o->next;
            e->next=o->next;
            e=e->next;
        }
        o->next=even;
        return odd;
    }
};