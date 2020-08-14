// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

void segragate012(int A[], int N);

int main() {

    int T;
    cin >> T;

    while(T--){
        int N;
        cin >>N;
        int A[N];
        for(int i=0;i<N;i++){
            cin >> A[i];
        }

        segragate012(A, N);

        for(int i=0;i<N;i++){
            cout << A[i]  << " ";
        }

        cout << endl;
        
        
    }

}
// } Driver Code Ends


// Function to segregate 0s, 1s and 2s

// The function should do the stated modifications in the given array arr[]
// Do not return anything.

// arr[]: Input Array
// N: Size of the Array arr[]
void swap(int &first,int &second){
    int temp = first;
    first = second;
    second = temp;
}

void segragate012(int arr[], int N)
{
    // Your Code Here
    int low = 0, mid = 0, high = N-1;
    while(mid<= high)
    {
        switch(arr[mid])
        {
            case 0:
                swap(arr[mid],arr[low]);
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
            swap(arr[mid],arr[high]);
                high--;
        }
    }
}