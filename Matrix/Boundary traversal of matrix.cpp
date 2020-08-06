// { Driver Code Starts


#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
public:     
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here 
        vector<int> temp;
        int i ;
        for(i = 0; i < m; i++){
            temp.push_back(matrix[0][i]);
            //cout<<matrix[0][i]<< "!";
        }
        //cout<<endl;
        for(i = 1; i < n ; i++){
            temp.push_back(matrix[i][m-1]);
           //cout<<matrix[i][m-1]<< " ";
        }
        //cout<<endl;
        for(i = m - 2 ; i >= 0 ; i--){
            if( n > 1){
            temp.push_back(matrix[n-1][i]);
           //cout<<matrix[n-1][i]<< "!";
           }
        }
        //cout<<endl;
        for(i = n - 2 ; i >= 1 ; i--){
            if(m>1){
            temp.push_back(matrix[i][0]);
            //cout<<matrix[i][0]<< " ";
            }
        }
    return temp;
        
    }
};



// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends