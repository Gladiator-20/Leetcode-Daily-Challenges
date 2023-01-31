class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>x(26,"");
        int j=0,n=pattern.length(),m=s.length();
        string tem="";
        for(int i=0;i<n;i++){
            while(j<m && s[j]!=' ')tem.push_back(s[j++]);
            for(int k=0;k<26;k++)if(x[k]==tem && k!=pattern[i]-'a')return false;
            else if(x[pattern[i]-'a']=="")x[pattern[i]-'a']=tem;
            else if(tem!=x[pattern[i]-'a'])return false;
            tem="";j++;
        }
        while(j<m && s[j]!=' ')tem.push_back(s[j++]);
        if(tem!="")return false;
        return true;
    }
};