// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends


/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
int isSafe(vector<int> M[], int row, int col,int ROW, int COL, vector<bool> visited[]) 
{ 
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !visited[row][col]); 
} 

void countIslands(vector<int> M[], int row, int col,vector<bool> visited[],int ROW, int COL) 
{ 
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
   
    visited[row][col] = true; 
  
    for (int k = 0; k < 8; ++k) 
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], ROW,COL,visited)) 
           countIslands(M, row + rowNbr[k], col + colNbr[k], visited,ROW,COL); 
} 

int findIslands(vector<int> A[], int N, int M) {

    // Your code here
    int count = 0;
    vector<bool> V[N];
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            V[i].push_back(false);
        }
    }
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(A[i][j] == 1 && !V[i][j]){
                countIslands(A,i,j,V,N,M);
                ++count;
            }
        }
    }
    return count;
}
