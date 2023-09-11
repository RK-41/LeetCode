//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    //11.09.23
	    // code here
	    
	    if(n<2) return -1;
	    if(n==2)    return min(arr[0], arr[1]);
	    
	    int mx = *max_element(arr, arr+n);
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++){
            if(arr[i]==mx)  continue;
            ans = max(ans, arr[i]);
        }
	    
	    return ans==INT_MIN? -1:ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends