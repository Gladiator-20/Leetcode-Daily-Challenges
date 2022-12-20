// Problem Link : https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

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
    void dfs(TreeNode *r,int &v){
        if(!r)return ;
        v+=r->val;
        dfs(r->left, v);
        dfs(r->right, v);        
    }
    int dfs1(TreeNode* r,int &v,long long &mx){
        if(!r)return 0;

        int x=dfs1(r->left ,v,mx) + dfs1(r->right, v, mx) + r->val;
        mx=max(mx, 1ll*x*(v-x));
        return x;
    }

public:
    int maxProduct(TreeNode* root) {
        int val=0;
        dfs(root,val);
        long long mx=0;
        dfs1(root ,val , mx);
        return ((mx)%1000000007);
    }
};