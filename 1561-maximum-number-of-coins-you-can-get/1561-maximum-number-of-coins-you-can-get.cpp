class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());
        int n = piles.size()/3;
        int ans = 0;
        for(auto it:piles){
            cout << it;
        }
        for(int i=0; i<n; i++){
            ans += piles[(2*i)+1];
        }
        return ans;
    }
};