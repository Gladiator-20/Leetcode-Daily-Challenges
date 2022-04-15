class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int c=1,f=0,l=n-1,s=0,e=n-1;
        bool fl=0;
        vector<vector<int>>a(n,vector<int>(n));
        while(1)
        {
            fl=0;
            for(int i=f;i<=l;i++){
                a[s][i]=c++;
                fl=1;
            }
            s++;
            for(int i=s;i<=e;i++){
                a[i][l]=c++;
                fl=1;
            }
            l--;
            for(int i=l;i>=f;i--){
                a[e][i]=c++;
                fl=1;
            }
            // s++;
            e--;
            for(int i=e;i>=s;i--){
                a[i][f]=c++;
                fl=1;
            }
            f++;
            if(!fl)break;
            
        }
        return a;   
    }
};