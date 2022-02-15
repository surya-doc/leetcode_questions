// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    bool match(map<char, int> &check, map<char, int> &stor){
        for(auto it:stor){
            if(stor[it.first] != check[it.first]){
                return false;
            }
        }
        return true;
    }
    
	int search(string pat, string txt) {
	    // code here
	    int k = pat.size();
	    map<char, int>check;
	    for(int a=0; a<k; a++){
	        check[pat[a]]++;
	    }
	    int ans = 0;
	    map<char, int>stor;
	    int i = 0;
	    int j = 0;
	    for(; j<txt.size(); j++){
	        if(j-i+1 == k){
	            stor[txt[j]]++;
	            if(match(check, stor)) ans++;
	            stor[txt[i]]--;
	            i++;
	        }
	        else{
	            stor[txt[j]]++;
	        }
	    }
	    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends