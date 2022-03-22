class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    void getTheSubS(string s, vector<vector<string>> &ans, vector<string> temp, int sz){
        if(sz == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=sz; i<s.size(); i++){
            if(isPalindrome(s, sz, i)){
                temp.push_back(s.substr(sz, i-sz+1));
                getTheSubS(s, ans, temp, i+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        getTheSubS(s, ans, temp, 0);
        return ans;
    }
};