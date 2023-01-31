class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int sz=trust.size();
        vector<int>cnt(n+1);
        for(int i=0;i<sz;i++)cnt[trust[i][0]]--,cnt[trust[i][1]]++;
        for(int i=1;i<=n;i++)if(cnt[i]==n-1)return i;
        return -1;
    }
};