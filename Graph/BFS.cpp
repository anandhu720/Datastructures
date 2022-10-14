class Solution {
public:
	vector<int>bfsOfGraph(int V, vector<int> adj[],int i){ // i = any node from which we need to start
	    vector<int> bfs; 
	    vector<int> vis(V, 0); 
	    queue<int> q; 
	    q.push(i); 
	    vis[i] = 1; 
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop(); 
	        bfs.push_back(node); 
	        
	        for(auto it : adj[node]) {
	            if(!vis[it]) {
	                q.push(it); 
	                vis[it] = 1; 
	            }
	        }
	    }
	    
	    return bfs; 
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj,1);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
} 
