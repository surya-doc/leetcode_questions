// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool checkBoard(vector<vector<int>> &m, int row, int col, int n, vector<string> &ans, string temp){
        if(row == n-1 && col == n-1){
            if(m[row][col] == 1){
                ans.push_back(temp);
                return true;
            }
            return false;
        }
        if(m[row][col] == 0 || m[row][col] == '#'){
            return false;
        }
        else{
            char temp_1 = m[row][col];
            m[row][col] = '#';
            if(row-1 >= 0){
                checkBoard(m, row-1, col, n, ans, temp+'U');
            }
            if(row+1 < n){
                checkBoard(m, row+1, col, n, ans, temp+'D');
            }
            if(col-1 >= 0){
                checkBoard(m, row, col-1, n, ans, temp+'L');
            }
            if(col+1 < n){
                checkBoard(m, row, col+1, n, ans, temp+'R');
            }
            m[row][col] = temp_1;
        }
        return true;

    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string temp = "";
        checkBoard(m, 0, 0, n, ans, temp);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends