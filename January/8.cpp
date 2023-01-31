class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int mx=1;
        for(int i=0;i<n;i++){
            map<pair<double,double>,int>val;
            for(int j=i+1;j<n;j++){
                int b=points[i][1]-points[j][1];
                int a=points[i][0]-points[j][0];
                int g=__gcd(a,b);
                b/=g;
                a/=g;
                val[{b,a}]++;
            }
            for(auto x:val)mx=max(mx,1+x.second);
        }
        return mx;
    }
};