class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        queue<int>q;
        int n = edges.size();
        vector<int>dis(n,-1),dis2(n,-1);
        int x=node1, lev=0;
        while(x!=-1 && dis[x]==-1){
            dis[x]=lev++;
            x=edges[x];
        }
        x=node2, lev=0;
        while(x!=-1 && dis2[x]==-1){
            dis2[x]=lev++;
            x=edges[x];
        }
        int min=INT_MAX,nd=-1;
        
        for(int i=0;i<n;i++){
            if(dis[i]>=0 && dis2[i]>=0 && max(dis[i],dis2[i])<min){
                min=max(dis[i],dis2[i]);
                nd=i;
            }
        }
        return nd;
    }
};