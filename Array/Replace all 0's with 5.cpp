// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

// Driver program to test above function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}// } Driver Code Ends


/*you are required to complete this method*/
int convertFive(int n) {
    // Your code here
    int num = 0, d=1,temp=0;
    for(int i = n ;i>0 ;i=i/10){
        temp = i % 10 ;
        if (temp == 0){
            temp = 5;
        }
        num = num + temp * d;
        d *= 10;
        temp =0;
    }
    return num;
}
