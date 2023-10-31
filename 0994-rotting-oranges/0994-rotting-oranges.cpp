class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<grid.size();i++){
            for(int j =0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int ans = 0;
        vector<int> delr = {-1,0,1,0};
        vector<int> delc = {0,-1,0,1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r= it.first.first;
            int c = it.first.second;
            int t = it.second;
            ans= max(ans,t);
            
           
            for(int i =0;i<4;i++){
                int nr=r+delr[i];
                int nc=c+delc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]==0){
                    q.push({{nr,nc},t+1});
                    vis[nr][nc]=1;
                }
            }

        }
       for(int i=0;i<grid.size();i++){
            for(int j =0;j<grid[i].size();j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    return -1;
                }
            }
        }
        return ans;
        
    }
};