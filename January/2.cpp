class Solution {
public:
    bool detectCapitalUse(string word) {
        bool s=0;
        for(char c:word){
            if(c-97<=25 && c-97>=0)s=1;
            else if(s)return false;
        }
        if(s && word[1]-65<=25 && word[1]-65>=0)return false;
        return true;
    }
};