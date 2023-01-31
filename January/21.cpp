class Solution {
public:
    void dfs(vector<int>&nums, vector<vector<int>>&val, vector<int>& cur, int start){
        if(cur.size()>1)val.push_back(cur);
        unordered_set<int>added;
        for(int i=start;i<nums.size();i++){
            if(!added.count(nums[i]) && (!cur.size() || cur.back()<=nums[i])){
                cur.push_back(nums[i]);
                dfs(nums,val,cur,i+1);
                cur.pop_back();
                added.insert(nums[i]);
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>val;
        vector<int>cur;
        dfs(nums,val,cur,0);
        return val;
    }
};