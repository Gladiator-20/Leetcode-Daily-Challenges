// Problem Link : https://leetcode.com/problems/triangle/

// Author - gladiator-20

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        for(int i=n-2;i>=0;i--){
            for(int k=0;k<triangle[i].size();k++)triangle[i][k]+=min(triangle[i+1][k],triangle[i+1][k+1]);
        }
        return triangle[0][0];
    }
};
