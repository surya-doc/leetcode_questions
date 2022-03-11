class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans = 0;
        for(int i=0; i<flowerbed.size(); i++){
            if(flowerbed[i] == 0 && (i==0 || flowerbed[i-1] == 0) && (i==flowerbed.size()-1 || flowerbed[i+1] == 0)){
                ans++;
                flowerbed[i] = 1;
                if(ans >= n) return true;
            }
        }
        return ans >= n;
    }
};