class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
               color[i]=0;
               queue<pair<int,int>>q;
                q.push({i,0});
                while(!q.empty()){
                    int node=q.front().first;
                    int col = q.front().second;
                    q.pop();
                    for(auto adjnode:graph[node]){

                            if(color[adjnode]==col){
                                return false;
                            }else if(color[adjnode]==-1){
                                color[node]==0?color[adjnode]=1:color[adjnode]=0;
                                q.push({adjnode,color[adjnode]});
                            }

                    }
               } 
            }
        }
        
        return true;
    }
};