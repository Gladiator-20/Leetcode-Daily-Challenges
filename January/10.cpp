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
    
    bool dfs(TreeNode* on,TreeNode* tw)
    {
        if(on==NULL && tw==NULL)return true;
        if(on==NULL || tw==NULL )return false;
        if(on->val == tw->val){
            return (dfs(on->left,tw->left)&dfs(on->right,tw->right));
        }
        else return false;
    }
    
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool fin=dfs(p,q);
        return fin;
    }
};