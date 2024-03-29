// Problem Link : https://leetcode.com/problems/maximum-erasure-value/

// Author - gladiator-20

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int las=0,ans=0,sum=0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(las<mp[nums[i]]){
                for(int j=las;j<mp[nums[i]];j++)sum-=nums[j];
                las=mp[nums[i]];
            }
            mp[nums[i]]=i+1;
            ans=max(ans,sum);
        }
        return ans;
    }
};
