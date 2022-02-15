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
	    int size = check.size();
	    map<char, int>stor;
	    int i = 0;
	    int j = 0;
	    for(; j<txt.size(); j++){
	        check[txt[j]]--;
	        if(check[txt[j]] == 0) size--;
	       // for(auto it:check){
	       //     cout << it.first << "->" << it.second << " ";
	       // }
	       // cout << "\n";
	        if(j-i+1 == k){
	            if(size == 0) ans++;
	            if((check[txt[i]] && check[txt[i]]==0) || !check[txt[i]]) size++;
	            check[txt[i]]++;
	            i++;
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