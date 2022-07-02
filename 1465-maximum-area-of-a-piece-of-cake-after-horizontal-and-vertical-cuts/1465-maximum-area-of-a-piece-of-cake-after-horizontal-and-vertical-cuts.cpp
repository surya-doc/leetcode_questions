class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mx_h = 0;
        int mx_v = 0;
        int prev = 0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        for(int i=0; i<horizontalCuts.size(); i++){
            int temp = horizontalCuts[i]-prev;
            mx_h = max(mx_h, temp);
            prev = horizontalCuts[i];
        }
        mx_h = max(mx_h, h-prev);
        prev = 0;
        for(int i=0; i<verticalCuts.size(); i++){
            int temp = verticalCuts[i]-prev;
            mx_v = max(mx_v, temp);
            prev = verticalCuts[i];
        }
        mx_v = max(mx_v, w-prev);
        mx_h = (mx_h)%1000000007;
        mx_v = (mx_v)%1000000007;
        return (long)mx_h * mx_v % 1000000007;
    }
};