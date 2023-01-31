class Solution {
public:
    bool ispall(string a,int start,int end)
    {
        while(start<=end)
        {
            if(a[start++]!=a[end--]){return false;}
        }
        return true;
    }
    
    void solve(string s,vector<vector<string>>&ans,vector<string>res,int st)
    {
        if(st==s.size()){ans.push_back(res);return ;}
        
        for(int i=st;i<s.size();i++)
        {
            string temp = s.substr(st,i-st+1);
            if(ispall(s,st,i)){
                res.push_back(temp);
                solve(s,ans,res,i+1);
                res.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>res;
        solve(s,ans,res,0);
        return ans;
    }
};