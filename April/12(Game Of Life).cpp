class Solution {
    vector<vector<bool>>tem;
public:
    void gameOfLife(vector<vector<int>>& board) {
        // tem=board;
        int n=board.size();
        int m=board[0].size();
        tem.resize(n,vector<bool>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                int c=0;
                for(int p=i-1;p<=i+1;p++){
                    for(int q=j-1;q<=j+1;q++)
                    {
                        if((p<0) || (q<0) || (p>=n) || (q>=m) || (p==i && q==j))continue;
                        if(board[p][q])c++;
                    }
                }
                if(c<2 || c>3)tem[i][j]=0;
                else if(c==3)tem[i][j]=1;
                else tem[i][j]=board[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                board[i][j]=tem[i][j];
            }
        }
    }
};