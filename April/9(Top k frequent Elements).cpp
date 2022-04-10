class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i:nums)m[i]++;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        for(auto it:m){
            p.push({it.second,it.first});
            if(p.size()>k)p.pop();
        }
        vector<int>ans;
        while(k--){
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
    }
};