
// Problem Link : https://leetcode.com/problems/minimum-average-difference/

// Author - gladiator-20

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long x=0,y=0,a,b,val=LLONG_MAX;
        int idx=0;
        for (auto i : nums)x+=i;
        
        for(int i=0;i<nums.size();i++){
            y+=nums[i];
            x-=nums[i];
            a= i==nums.size()-1?0:(x)/(nums.size()-i-1);
            b=((y)/(i+1));
            if(val>abs(a - b)){
                val=abs(a-b);
                idx=i;
            }
            
        }
        return idx;
    }
};