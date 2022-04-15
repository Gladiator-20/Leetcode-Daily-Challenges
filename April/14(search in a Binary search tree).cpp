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
    
    TreeNode* fin(TreeNode* root,int val){
        if(root==NULL || root->val==val)return root;
        
        if(root->val>val)return fin(root->left,val);
        return fin(root->right,val);
        // return NULL;
    }
    
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return fin(root,val);
    }
};