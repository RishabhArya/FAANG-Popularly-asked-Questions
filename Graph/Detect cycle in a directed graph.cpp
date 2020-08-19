// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool checkForCycles(int ele, vector<int> adj[], bool visited[], bool *currentStack)
{
 if(visited[ele]==false)
 {
    currentStack[ele] = true;
    visited[ele] = true;
    
    vector<int>::iterator i;
    
    for(i=adj[ele].begin(); i != adj[ele].end(); ++i)
    {
        if(!visited[*i] && checkForCycles(*i,adj, visited, currentStack))
            return true;
        else if(currentStack[*i])
            return true;
    }
 }
 currentStack[ele] = false; 
 return false;   
}
bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    bool visited[V],currentStack[V];
    for(int i=0; i<V; i++)
    {
        visited[i]=false;
        currentStack[i]=false;
    }
    for(int i=0; i<V; i++)
    {
     if(checkForCycles(i,adj, visited, currentStack))
        return true;
    }
 return false;   
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends