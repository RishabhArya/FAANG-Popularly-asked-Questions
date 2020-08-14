// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


int findPlatform(int arr[], int dep[], int n)
{
	// Your code here
    sort(arr, arr+n);
    sort(dep, dep+n);
    vector<int>platform;
    int platform_no = 1;
    platform.push_back(dep[0]);
    for(int i=1; i<n; i++)
    {
        if(arr[i] < dep[i-1])
        {
            int temp = platform_no;
            for(int j=0; j<platform.size(); j++)
            {
                if(platform[j] < arr[i]){
                    platform[j] = dep[i];
                    break;
                }
                else if((platform[j] > arr[i]) && (j == (platform.size() - 1)))
                {
                    platform_no++;
                }
            }
            if(temp != platform_no)
            {
                platform.push_back(dep[i]);
            }
        }
        else{
           platform[platform_no - 1] = dep[i];
        }
    }
    /*
    for(int j=0; j<platform.size(); j++)
    {
        cout<<platform[j]   /*
    }    */
    return platform_no;
}


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
           for(int i=0;i<n;i++)
        cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
    cout <<findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends