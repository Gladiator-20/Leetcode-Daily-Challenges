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
    
    TreeNode* sol(TreeNode* root,int l,int h ,int lef,int rig)
    {
        if(lef>rig || root==NULL || rig<l || lef>h)return NULL;
        if(lef>=l && rig<=h)return root;
        
        int v=root->val;
        
        root->left=sol(root->left,l,h,lef,v-1);
        root->right=sol(root->right,l,h,v+1,rig);
        
        if(v>=l && v<=h)return root;
        else if(v<l)return root->right;
        else return root->left;
    }
    
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        return sol(root,low,high,-1,10001);
        
    }
};