// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//Complete this function
long long minimumNumberOfCoins(int coins[],int m,int V)
{
     int table[V+1]; 
    table[0] = 0; 
    for (int i=1; i<=V; i++) 
        table[i] = INT_MAX; 
  
    for (int i=1; i<=V; i++) 
    { 
        for (int j=0; j<m; j++) 
          if (coins[j] <= i) 
          { 
              int sub_res = table[i-coins[j]]; 
              if (sub_res != INT_MAX && sub_res + 1 < table[i]) 
                  table[i] = sub_res + 1; 
          } 
    } 
    if (table[V] == INT_MAX)
        return -1;
        
    return table[V];
    
}

// { Driver Code Starts.



int main() {
	
	//taking total count of testcases
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    //taking value
	    int value;
	    cin>>value;
	    
	    //taking number of coins
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    //taking value of each coin
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    
	    //calling function minimumNumberOfCoins()
	    int answer=minimumNumberOfCoins(coins,numberOfCoins,value);
	    
	    //printing "Not Possible" if answer is -1
	    //else printing answer
	    if(answer==-1)
	    cout<<"Not Possible"<<endl;
	    else
	    cout<<answer<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends