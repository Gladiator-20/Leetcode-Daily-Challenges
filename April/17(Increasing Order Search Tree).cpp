/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode * newhead;
    void make(TreeNode* root,TreeNode* &head)
    {
        if(!root)return ;
        make(root->left,head);
        
        if(head)head->right=root;
        else newhead=root;
        // cout<<head<<" "<<newhead->val<<'\n';
        head=root;
        // cout<<root->val<<" "<<newhead->val<<'\n';
        root->left=NULL;  
        make(root->right,head);
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head=NULL;
        make(root,head);
        return newhead;
    }
};