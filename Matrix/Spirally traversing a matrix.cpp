// { Driver Code Starts
#include <iostream>
using namespace std;

#define SIZE 105

void spirallyTraverse(int m, int n, int ar[SIZE][SIZE]);

int main() {
	int T = 0;
	
	scanf("%d",&T);
	
	while(T--)
	{
        int m,n;
        scanf("%d",&m);
        scanf("%d",&n);
	    int ar[SIZE][SIZE] = {{0}};
	    int i = 0;
	    int j = 0;
	    int row = 0;
	    int col = 0;
	    
	    for(i=0; i<m; i++)
	    {
	        for(j=0; j<n; j++)
	        {
	            scanf("%d",&ar[i][j]);
	        }
	    }
	    
	    spirallyTraverse(m, n, ar);
	    cout<<endl;
	   
	}
	return 0;
}// } Driver Code Ends


//Complete this function
void spirallyTraverse(int m, int n, int ar[SIZE][SIZE]){
    //Your code here
    int k = 0, l =0;
    while(k<m && l<n){
        
        //first row
        for(int i =k ; i < n ;++i)
        {
            cout<<ar[k][i]<<" ";
        }
        k++;
        //last column
        for(int j = k ; j < m ; ++j)
        {
            cout<<ar[j][n-1]<<" ";
        }
        n--;
        if(k<m)
        {
            for(int q = n - 1; q >= l ; --q)
            {
                cout<<ar[m - 1 ][q]<<" ";
            } 
            m--;
        }
        if(l<n)
        {
            for(int w = m - 1; w >= k ; --w)
            {
                cout<<ar[w][l]<<" ";
            } 
            l++;
        }
        
    }
}
