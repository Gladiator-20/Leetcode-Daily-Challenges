// Problem Link : https://leetcode.com/problems/determine-if-two-strings-are-close/

// Author - gladiator-20

class Solution {
public:
    bool closeStrings(string w1, string w2) {
        if(w1.size()!=w2.size())return false;
        vector<int>a(26),b(26);
        for(char x:w1)a[x-'a']++;
        for(char x:w2)if(a[x-'a'])b[x-'a']++;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a==b;
    }
};