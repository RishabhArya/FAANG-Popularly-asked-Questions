// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/
bool checkCycle(int ele,vector<int> g[],int parent,bool visited[])
{
    visited[ele] = true;
    //list<int>::iterator i;
    vector<int>:: iterator i;
    for(i = g[ele].begin(); i!=g[ele].end(); ++i)
    {
        if(!visited[*i])
        {
           if(checkCycle(*i,g,ele,visited))
                return true;
        }
        else if(*i != parent)
            return true;
    }
    return false;
}
bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   bool *visited = new bool[V];
   for(int i=0; i<V; i++)
        visited[i] = false;
    
   for(int i=0; i<V; i++)
        if (!visited[i])
            if(checkCycle(i,g,-1,visited))
                return true;
    
    return false;
}

// { Driver Code Starts.


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends