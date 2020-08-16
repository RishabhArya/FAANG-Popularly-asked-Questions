// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int N) {

    // Your code here
    vector<int> visited;
    vector<int> bfs_traversal;
    for(int i=0; i<N; i++)
        visited.push_back(0);
        
    queue<int> queue;
    int ele = 0;
    visited[ele] = 1;
    queue.push(ele);
    while(!queue.empty())
    {
        ele = queue.front();
        bfs_traversal.push_back(ele);
        queue.pop();
        for(int i = 0; i<g[ele].size(); i++){
            int temp = g[ele][i];
            if(visited[temp]!=1)
            {
                queue.push(temp);
                visited[temp] = 1;
            }
        }
        
    }
 
    return bfs_traversal;
}