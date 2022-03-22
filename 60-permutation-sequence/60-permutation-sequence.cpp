class Solution {
public:
    string makeAns(string ans, int k, vector<int> &org, int fact){
        if(org.size() == 0 || fact == 0) return ans;
        ans += to_string(org[k/fact]);
        // cout << ans;
        org.erase(org.begin()+k/fact);
        if(org.size() == 0) return ans;
        k = k%fact;
        fact = fact/org.size();
        return makeAns(ans, k, org, fact);
    }
    
    string getPermutation(int n, int k) {
        // string org = "";
        vector<int> org;
        for(int i=0; i<n; i++){
            org.push_back(i+1);
        }
        int fact = 1;
        for(int i=1; i<n; i++){
            fact *= i;
        }
        // cout << fact;
        string ans = "";
        ans = makeAns(ans, k-1, org, fact);
        return ans;
    }
        
};
