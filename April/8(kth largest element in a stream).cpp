class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>x;
    int t;
    
    KthLargest(int k, vector<int>& nums) {
        while(!x.empty())x.pop();
        t=k;
        for(auto it:nums){
            add(it);
        }
    }
    
    int add(int val) {
        x.push(val);
        if(x.size()>t)x.pop();
        return x.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */