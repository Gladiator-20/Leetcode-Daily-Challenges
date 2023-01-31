class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int st=0;
        int x=0;
        bool cont=0;
        vector<bool>reach(n);
        for(int i=0;i<n;i++){
            if(x+gas[i]>=cost[i]){
                if(!cont)st=i;
                x+=gas[i]-cost[i];
                reach[(i+1)%n]=1;
                cont=1;
            }
            else {
                cont=0,x=0;
            }
        }

        // x+=gas[0];
        for(int i=0;i<=st;i++){
            if(x+gas[i]>=cost[i]){
                x+=gas[i]-cost[i];
                reach[(i+1)%n]=1;
            }
            else {
                return -1;
            }
        }
        // for(auto i:gas)cout<<i<<" ";
        // cout<<endl;
        for(int i=0;i<n;i++)if(!reach[i])return -1;
        return st;
    }
};