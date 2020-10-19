// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

int maxSubArray( vector<int> array);

//User code will be pasted here

int main()
{
    int t;
    cin>>t; //input testcases
    
    while(t--) //while testcases exist
    {
        int n;
        cin>>n; //input size of array
        vector<int> vec(n);
        
        for(int i=0; i<n; i++)
            cin>>vec[i]; //inputting elements of array
            
        cout << maxSubArray(vec) << "\n";
    }
}
// } Driver Code Ends


//User function template for C++


int maxSubArray(vector<int> array) {
    // code here      
    int max_so_far = array[0], max_till_now = array[0];
    for(int i = 1; i < array.size(); i++)
    {
        max_so_far = max(array[i], max_so_far + array[i]);
        max_till_now = max(max_till_now, max_so_far);
    }    
    return max_till_now;
    
}