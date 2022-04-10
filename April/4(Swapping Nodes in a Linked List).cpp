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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* f=NULL;
        ListNode*s=NULL;
        ListNode*t=head;
        int cnt=0;
        while(t!=NULL){
            cnt++;
            if(cnt==k){
                f=t;
                // s=head;
            }
            t=t->next;
            if(f!=NULL){
                if(s!=NULL)s=s->next;
                else s=head;
            }
        }
        // if(f!=NULL && s!=NULL)
        swap(f->val,s->val);
        return head;
    }
};