class Solution {
    
    bool ch(string& s,int i,int j)
    {
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;j--;
        }
        return true;
    }
    
public:
    bool validPalindrome(string s) {
        bool t=0;
        int l=0,r=s.length()-1;
        while(l<r){
            if(s[l]==s[r]){
                l++;r--;
            }
            else{
                if(t)return false;
                return (ch(s,l+1,r) || ch(s,l,r-1));
            }
        }
        return true;
    }
};