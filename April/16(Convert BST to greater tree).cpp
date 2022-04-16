//  Author - Aashutosh Paroha

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
    
    void dfs(TreeNode* root,int& v)
    {
        if(root==NULL)return;
        if(root->right)dfs(root->right,v);
        v+=root->val;
        root->val=v;
        if(root->left)dfs(root->left,v);
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {
        int v=0;
        dfs(root,v);
        return root;
    }
};