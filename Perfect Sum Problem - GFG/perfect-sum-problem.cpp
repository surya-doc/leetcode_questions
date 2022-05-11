// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int perfectSum(int a[], int n, int sum)
	{
       int tab[n + 1][sum + 1];
  // Initializing the first value of matrix
    // tab[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        tab[0][i] = 0;
    for(int i=0; i<=n; i++){
        tab[i][0] = 1;
    }
     
     long long modul = 1e9 + 7;
   
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
          // if the value is greater than the sum
            if (a[i - 1] > j)
                tab[i][j] = (tab[i - 1][j])%modul;
            else
            {
                tab[i][j] = ((tab[i - 1][j])%modul + (tab[i - 1][j - a[i - 1]])%modul)%modul;
            }
        }
    }
 
 
    return tab[n][sum];
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends