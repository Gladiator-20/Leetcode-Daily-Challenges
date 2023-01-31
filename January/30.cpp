class Solution {
public:
    int tribonacci(int n) {
        if(n<2)return n;
        else if(n==2)return 1;
        else{
            vector<int>val={0,1,1};
            for(int i=3;i<=n;i++){
                val[i%3]+=val[(i-1)%3]+val[(i-2)%3];                
            }
            return val[n%3];
        }
    }
};