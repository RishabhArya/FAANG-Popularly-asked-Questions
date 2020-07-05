// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n){

    // Your code here
    int max_so_far = arr[0];
    int current_max = arr[0];
    for(int i = 1; i < n; i++){
        current_max = max(arr[i], arr[i] + current_max);
        max_so_far = max(current_max, max_so_far);
    }
    return max_so_far;
}

// { Driver Code Starts.

int main()
{
    int t,n;

    cin>>t; //input testcases
    while(t--) //while testcases exist
    {

        cin>>n; //input size of array

        int a[n];

        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array

        cout << maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends
