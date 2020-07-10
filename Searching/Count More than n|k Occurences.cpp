i--;

// { Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int countOccurence(int arr[], int n, int k);
// Position this line where user code will be pasted.

/* Driver program to test above function */
int main() {
int t, k;
cin >> t;
while (t--) {
int n, i;
cin >> n;

int arr[n];

for (i = 0; i < n; i++) cin >> arr[i];
cin >> k;
cout << countOccurence(arr, n, k) << endl;
}
return 0;
}
// } Driver Code Ends


// Function to find element with count more than n/k times
// arr: input array
int countOccurence(int arr[], int n, int k) {
// Your code here
sort(arr, arr+n);
int temp = 1, count = 0, p = n/k;
for(int i= 0 ; i < n - 1 ;i++){
if (arr[i] == arr[i + 1]){
temp++;
}
else{
temp = 1;}
if(temp>p){
count++;
while (arr[i] == arr[i + 1]){
    i++;
}
i--;
}
}
return count;
}
