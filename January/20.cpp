class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int val=0,n=nums.size(),ans=0;
        for(int i=0;i<n;i++)val+=nums[i],nums[i]=(val%k+k)%k;
        vector<int>v(k);
        v[0]=1;
        for(int i=0;i<n;i++){
            ans+=v[nums[i]]++;
        }
        return ans;
    }
};