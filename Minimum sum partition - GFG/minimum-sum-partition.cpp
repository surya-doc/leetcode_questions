// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    int getSum(int arr[], int i, int sum, int tot_sum, int n){
        if(i == 0){
            return abs((tot_sum-sum)-sum);
        }
        // cout << sum << " ";
        return min(getSum(arr, i-1, sum+arr[i-1], tot_sum, n), getSum(arr, i-1, sum, tot_sum, n));
    }
  
	int minDifference(int arr[], int n)  {
	    int ans = INT_MAX;
	    int sum = 0;
	    for(int i=0; i<n; i++){
	        sum += arr[i];
	    }
	    bool dp[n+1][sum+1];
	    for(int i=0; i<=n; i++){
	        dp[i][0] = true;
	    }
	    for(int i=1; i<=sum; i++){
	        dp[0][i] = false;
	    }
	    for(int i=1; i<=n; i++){
	        for(int j=1; j<=sum; j++){
	            dp[i][j] = dp[i-1][j];
	            if(arr[i-1] <= j){
	                dp[i][j] |= dp[i-1][j-arr[i-1]];
	            }
	        }
	    }
	    for(int i=sum/2; i>=0; i--){
	        if(dp[n][i] == true){
	            ans = sum-2*i;
	            break;
	        }
	    }
	    return ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends