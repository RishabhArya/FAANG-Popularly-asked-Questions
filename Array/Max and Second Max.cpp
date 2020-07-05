// { Driver Code Starts
//Initial Template for C++

// CPP code to find largest and
// second largest element in the array

#include <bits/stdc++.h>
using namespace std;

vector<int> largestAndSecondLargest(int, int[]);


 // } Driver Code Ends




/* Function to find largest and second largest element
*sizeOfArray : number of elements in the array
* arr = input array
*/
vector<int> largestAndSecondLargest(int sizeOfArray, int arr[]){
    int max = -1, max2= -1;
    vector<int> maxSecondMax;
    for(int i = 0 ; i < sizeOfArray ; i++){
        int ele = arr[i];
        if(ele > max){
            max2 = max;
            max = ele;
        }
        if((ele < max)&&(ele > max2)){
            max2 = ele;
        }
    }
    maxSecondMax.push_back(max);
    maxSecondMax.push_back(max2);
    return maxSecondMax;
    /*********************************
     * Your code here
     * This function should return a
     * vector with first element as
     * max and second element as
     * second max
     * *******************************/

}

// { Driver Code Starts.

// Driver Code
int main() {

	// Testcase input
	int testcases;
	cin >> testcases;

    // Looping through all testcases
	while(testcases--){
	    int sizeOfArray;
	    cin >> sizeOfArray;

	    int arr[sizeOfArray];

	    // Array input
	    for(int index = 0; index < sizeOfArray; index++){
	        cin >> arr[index];
	    }

	    vector<int> ans = largestAndSecondLargest(sizeOfArray, arr);
	    cout<<ans[0]<<' '<<ans[1]<<endl;
	}

	return 0;
}  // } Driver Code Ends
