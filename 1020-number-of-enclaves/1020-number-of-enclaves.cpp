class Solution {
public:
    void dfs(int r,int c, vector<vector<int>>& grid,vector<vector<int>>&vis){
        vis[r][c]=1;
        int n = grid.size();
        int m = grid[0].size();
        vector<int>delr={1,0,-1,0};
        vector<int>delc={0,-1,0,1};
        for(int i=0;i<4;i++){
            int nr=r+delr[i];
            int nc = c+delc[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&vis[nr][nc]==0&&grid[nr][nc]==1){
                dfs(nr,nc,grid,vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            if(grid[i][0]==1&&vis[i][0]==0){
                dfs(i,0,grid,vis);
            }
            if(grid[i][m-1]==1&&vis[i][m-1]==0){
                dfs(i,m-1,grid,vis);
            }
        }
        for(int j =0;j<m;j++){
            if(grid[0][j]==1&&vis[0][j]==0){
                dfs(0,j,grid,vis);
            }
            if(grid[n-1][j]==1&&vis[n-1][j]==0){
                dfs(n-1,j,grid,vis);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<vis[i][j]<<" ";
                if(vis[i][j]==0&&grid[i][j]==1){
                    ans++;
                }
            }
            // cout<<endl;
        }return ans;
        
    }
};