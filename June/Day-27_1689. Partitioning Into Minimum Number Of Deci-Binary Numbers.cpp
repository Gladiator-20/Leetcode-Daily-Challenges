// Problem Link : https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

// Author - gladiator-20

class Solution {
public:
    int minPartitions(string n) {
        int a=0;
        for(char i:n)a=max(a,i-'0');
        return a;
    }
};