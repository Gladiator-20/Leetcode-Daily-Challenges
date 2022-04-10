class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>p;
        for(auto i:stones)p.push(i);
        while(p.size()!=0 && p.size()!=1)
        {
            int a=p.top();p.pop();
            int b=p.top();p.pop();
            int val=a-b;
            if(val==0)continue;
            else p.push(val);
        }
        if(p.size()==0)return 0;
        else return p.top();
    }
};