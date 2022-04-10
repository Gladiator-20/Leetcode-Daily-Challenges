class Solution {
public:
    void nextPermutation(vector<int>& nums){
        int n=nums.size();
        bool f=0;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1]){
                for(int j=n-1;j>i;j--){
                    if(nums[j]>nums[i]){
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
                reverse(nums.begin()+i+1,nums.end());
                f=1;
                break;
            }
        }
        if(!f)reverse(nums.begin(),nums.end());
    }
};