vector<int>minstep(100001,1000000);
void cal(){
    minstep[2]=1;minstep[3]=1;
    for(int i=4;i<=100000;i++)minstep[i]=1+min(minstep[i-2],minstep[i-3]);
}
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        if(minstep[100000]==1000000)cal();
        unordered_map<int,int>mp;
        int val=0;
        for(auto i:tasks)mp[i]++;
        for(auto i:mp){
            if(minstep[i.second]>=1000000)return -1;
            val+=minstep[i.second];
        }
        return val;
    }
};