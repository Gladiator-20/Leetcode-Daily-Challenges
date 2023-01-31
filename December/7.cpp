// Problem Link : https://leetcode.com/problems/range-sum-of-bst/

// Author - gladiator-20

class Solution {

    void dfs(int &n,TreeNode* root, int& low, int& high){
        if(!root)return ;

        if(root->val<=high && root->val>=low){
            n+=root->val;
            dfs(n,root->left,low,high);
            dfs(n,root->right,low,high);
        }

        else if(root->val<low)dfs(n,root->right,low,high);
        else dfs(n,root->left,low,high);

    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int n=0;

        dfs(n,root,low,high);
        return n;
    }
};