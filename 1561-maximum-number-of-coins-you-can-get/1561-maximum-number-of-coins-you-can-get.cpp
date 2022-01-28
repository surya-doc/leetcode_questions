class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size()/3;
        int ans = 0;
        for(int i=n; i<piles.size(); i+=2){
            ans += piles[i];
        }
        return ans;
    }
};