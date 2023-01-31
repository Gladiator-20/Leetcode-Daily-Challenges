class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int r=INT_MAX;
        int c=1;
        sort(points.begin(),points.end());
        for(auto i:points){
            if(r<i[0]){
                c++;
                r=i[1];
            }
            else r=min(r,i[1]);
        }
        return c;
    }
};