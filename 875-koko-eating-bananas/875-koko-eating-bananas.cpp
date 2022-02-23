class Solution {
public:
    bool check(vector<int> &piles, int mid, int h){
        int n = piles.size();
        int total_hr = 0;
        for(int i=0; i<n; i++){
            total_hr += (piles[i]%mid == 0) ? (piles[i]/mid) : ((piles[i]/mid)+1);
        }
        if(total_hr > h) return 0;
        return 1;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int l = 1;
        int r = piles[piles.size()-1];
        int ans = r;
        while(l <= r){
            // cout << ans;
            int mid = l+(r-l)/2;
            int temp = check(piles, mid, h);
            if(temp){
                r = mid-1;
                ans = min(ans, mid);
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};