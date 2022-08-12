class Solution {
public:
    
    void dfs(int i, vector<int> adj[], int &cnt, vector<int> &vis){
        vis[i] = 1;
        cnt++;
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(it, adj, cnt, vis);
            }
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> vis(n, 0);
        vector<int> adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(auto it:restricted){
            vis[it] = 1;
        }
        int count = 0;
        dfs(0, adj, count, vis);
        return count;
    }
};