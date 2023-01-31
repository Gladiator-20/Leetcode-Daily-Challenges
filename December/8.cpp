// Problem Link : https://leetcode.com/problems/leaf-similar-trees/description/

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

    void dfs(TreeNode* r, vector<int>&nd){
        if(r->left)dfs(r->left,nd);
        if(r->right)dfs(r->right,nd);        
        if(!r->left && !r->right)nd.push_back(r->val);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>a,b;
        dfs(root1,a);
        dfs(root2,b);
        return a==b;
    }
};