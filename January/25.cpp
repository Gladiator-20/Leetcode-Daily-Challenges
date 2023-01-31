class Solution {
    vector<int> cell(int n, int num){
        if((num/n)%2)return {n-1-(num/n),n-1-(num%n)};
        else return {n-1-(num/n),num%n};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int nn=n*n;
        queue<int>q;
        q.push(0);
        int lev=1;
        vector<bool>vis(nn+1);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int f=q.front();q.pop();
                for(int j=f+1;j<min(nn,f+7);j++){
                    auto x = cell(n,j);
                    int r=x[0],c=x[1],cur= (board[r][c]!=-1)?board[r][c]-1:j;
                    if(cur==nn-1)return lev;
                    if(!vis[cur]){
                        q.push(cur);
                        vis[cur]=1;
                    }
                }
            }
            lev++;
        }
        return -1;
    }
};