class Solution {
public:
    bool res = true;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n,-1);
        int c = 0 ;
        for(int i = 0 ; i < n ;i++){
            if(colors[i]==-1){
                dfs(graph,i,0,colors);
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& graph,int node,int c,vector<int>& colors){
        colors[node]=c;
        for(int i = 0 ; i < graph[node].size();i++){
            int neigh = graph[node][i];
            if(colors[neigh] != -1 && colors[neigh]==c){
                res = false;
                break;
            }
            if(colors[neigh]==-1){
             dfs(graph,neigh,1-c,colors);
            }
        }
        return;
    }
};