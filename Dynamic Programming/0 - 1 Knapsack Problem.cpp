// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Returns the maximum value that  
// can be put in a knapsack of capacity W 
int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
}

int static dp_table[1001][1001];

int knapSackRec(int W, int wt[], int val[], int n){
   
   if(W == 0 || n ==0)
        return 0;
        
   if(dp_table[n][W] != -1)
        return dp_table[n][W];
        
    if(wt[n-1] <= W){
        return dp_table[n][W] = max(val[n - 1] + knapSackRec(W - wt[n - 1], wt, val, n-1), knapSackRec(W, wt, val, n-1));
    }
    else if(wt[n-1] > W){
        return dp_table[n][W] = knapSackRec(W, wt, val, n-1);
    }   
}
int knapSack(int W, int wt[], int val[], int n) 
{ 
   memset(dp_table,-1,sizeof(dp_table[0][0]) * 1001 * 1001);
   return knapSackRec(W,wt,val,n);
   
 
}


// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        //calling method knapSack()
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends