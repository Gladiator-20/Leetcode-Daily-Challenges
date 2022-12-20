// Problem Link : https://leetcode.com/problems/sort-characters-by-frequency/

// Author - gladiator-20

vector<int>v(130);

class Solution {
public:
    string frequencySort(string s) {
        for(auto &i:v)i=0;
        for(char i:s)v[i]++;
        sort(s.begin(),s.end(),[](char a,char b){return (v[a]>v[b] || (v[a]==v[b] && a>b));});
        return s;
    }
};