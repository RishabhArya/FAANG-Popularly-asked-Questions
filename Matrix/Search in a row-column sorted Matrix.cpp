// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define SIZE 801

int search( int n,int m, int x, int[SIZE][SIZE]);

int main()
{
  int t;
  cin>>t;
  while (t--)
  {
    int n,m,x,i,j;
    cin>>n>>m;
    
    int mat[SIZE][SIZE];
    
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
          mat[i][j] = 0;
        cin>>mat[i][j];
      }
    }
    
    cin>>x;
    cout << search(n,m,x, mat) << endl;
  
  }
  return 0;
}
// } Driver Code Ends


/*  Function to search x in the input matrix
*   n, m: rows and columns of matrix
*   x: element to check presence in matrix
*   mat[][]: input matrix
*/
int search( int n,int m, int x, int mat[SIZE][SIZE])
{
   // Your code here
   if (n == 0) 
        return 0; 
    int smallest = mat[0][0], largest = mat[n - 1][m - 1]; 
    if (x < smallest || x > largest) 
        return 0;
    // set indexes for top right element 
    int i = 0, j = m - 1;  
    while (i < n && j >= 0) { 
        if (mat[i][j] == x) {
            return 1;
        } 
        if (mat[i][j] > x){ 
            j--;} 
        else{
            i++;} 
    }
    return 0;
   for(int i=0 ; i<n ;i++)
   {
        for(int j= 0 ; j<m ;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
   }
   return 0;
   
}