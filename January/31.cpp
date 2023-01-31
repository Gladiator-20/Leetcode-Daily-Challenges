class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=scores.size();
        vector<int>dp(n);
        vector<pair<int,int>>x(n);
        for(int i=0;i<n;i++)x[i]={ages[i],scores[i]};

        sort(x.begin(),x.end());
        int ans=0;
        for(int i=0;i<n;i++){
            int y=0;
            for(int j=0;j<i;j++){
                if(x[i].second>=x[j].second)y=max(y,dp[j]);
            }
            dp[i]=x[i].second+y;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};