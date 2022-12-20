// Problem Link : https://leetcode.com/problems/middle-of-the-linked-list/

// Author - gladiator-20

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slo=head;
        ListNode* fas=head;
        while(fas!=NULL && fas->next!=NULL)
        {
            slo=slo->next;
            fas=fas->next->next;
        }
        return slo;
    }
};