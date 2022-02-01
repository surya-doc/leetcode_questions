class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int y = 3;
        int ans = 0;
        vector<int>stor;
        stor.push_back(a);
        stor.push_back(b);
        stor.push_back(c);
        while((stor[0] != 0 && stor[1] != 0) || (stor[0] != 0 && stor[2] != 0) || (stor[1] != 0 && stor[2] != 0)){
            sort(stor.begin(), stor.end());
            stor[2] = stor[2]-1;
            stor[1] = stor[1]-1;
            ans++;
        }
        return ans;
    }
};