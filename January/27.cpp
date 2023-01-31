class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string,bool>mp;
        for(string i:words)mp[i]=1;
        vector<string>val;
        for(auto i:words){
            string tem=i;
            vector<string>x={""};
            for(int j=0;j<i.length();j++){
                bool f=0;
                for(int k=0;k<x.size();k++){
                    x[k].push_back(i[j]);
                    if(x[k].length()!=i.length() && mp[x[k]]){
                        f=1;
                    }
                }
                tem.erase(tem.begin());
                if(f){
                    if(mp[tem]){
                        val.push_back(i);
                        break;
                    }
                    x.push_back("");
                }
            }
        }
        return val;
    }
};