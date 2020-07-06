

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;
vector<int> SortBinaryArray(vector<int> binArray);


// } Driver Code Ends


//User function template for C++

// binArray is an array that consists only 0s and 1s
// return sorted binary array
vector<int> SortBinaryArray(vector<int> binArray)
{
// Your code goes here
int j = -1;
for(int i = 0; i < binArray.size();i++)
{
if ( binArray[i] == 0){
    j++;
    swap(binArray[i],binArray[j]);
}
}
return binArray;
}


// { Driver Code Starts.

int main() {
int t;
cin>>t;

while(t--)
{
int n;
cin>>n;
vector<int> binArray(n);

for(int i = 0; i  < n; i++)
cin>>binArray[i];

vector<int> result = SortBinaryArray(binArray);
for(int i=0; i<n; i++)
  cout<<result[i]<<" ";

cout<<endl;
}
return 0;
}
// } Driver Code Ends
