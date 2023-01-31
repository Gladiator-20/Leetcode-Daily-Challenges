// Problem Link : https://leetcode.com/problems/determine-if-string-halves-are-alike/

// Author - gladiator-20

class Solution {
    unordered_set<char>v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
public:
    bool halvesAreAlike(string s) {
        int x=0;
        for(int i=0;i<s.size()/2;i++){
            if(v.count(s[i]))x++;
        }
        for(int i = s.size()/2;i<s.size(); i++){
            if(v.count(s[i]))x--;
        }
        return x==0;
    }
};