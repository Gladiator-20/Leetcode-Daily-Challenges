class Solution {

    bool dfs(int r, int e, int p, int& ans,vector<vector<int>>&adj,vector<bool>& hasApple){
        int f=0;
        for(auto i:adj[r]){
            if(i==p)continue;
            if(dfs(i,e+1,r,ans,adj,hasApple))f++;            
        }

        if(hasApple[r]){
            ans+=2*e;
            f++;
        }        
        if(f)ans-=(f-1)*e*2;
        return (f || hasApple[r]);
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int ans=0;
        dfs(0,0,-1,ans,adj,hasApple);
        return ans;
    }
};