// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int thirdLargest(int a[],int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    cout<<thirdLargest(a,n)<<endl;
    }
}   // } Driver Code Ends




int thirdLargest(int a[], int n)
{
     //Your code here
     int first = -1 , second = -1 , third = -1,ele;
     for(int i=0; i<n; i++){
         ele = a[i];
         if ( ele > first){
             third = second;
             second = first;
             first = ele;

         }
         else if (( ele <= first) && ( ele >= second)) {
             third = second;
             second = ele;
         }
         else if (( ele <= second) && ( ele >= third)) {
             third = ele;
         }

     }
     return third;
}
