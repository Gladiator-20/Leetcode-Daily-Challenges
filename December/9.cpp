// Problem Link : https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

// Author - gladiator-20

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

    void dfs(TreeNode* ro, int l, int r,int &mx){
        if(!ro)return;
        mx=max(mx,max(abs(ro->val-l),abs(ro->val-r)));
        l = min(l,ro->val);
        r = max(ro->val,r);
        dfs(ro->left,l,r,mx);
        dfs(ro->right,l,r,mx);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        int l=root->val,r=root->val;
        int mx=0;
        dfs(root,l,r,mx);
        return mx;
    }
};