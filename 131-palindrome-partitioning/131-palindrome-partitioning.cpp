class Solution {
public:
    bool isPalindrome(string s, int i, int j, map<string, int> &mp){
        int sz = i;
        int a = j;
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        mp[s.substr(sz, a-sz+1)] = 1;
        return true;
    }
    
    void getTheSubS(string s, vector<vector<string>> &ans, vector<string> temp, int sz, map<string, int> &mp){
        if(sz == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=sz; i<s.size(); i++){
            string tem_str = s.substr(sz, i-sz+1);
            if(mp[tem_str]){
                temp.push_back(tem_str);
                getTheSubS(s, ans, temp, i+1, mp);
                temp.pop_back();
            }
            else if(isPalindrome(s, sz, i, mp)){
                temp.push_back(tem_str);
                getTheSubS(s, ans, temp, i+1, mp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        map<string, int> mp;
        getTheSubS(s, ans, temp, 0, mp);
        for(auto it:mp){
            cout << it.first << " ";
        }
        return ans;
    }
};