class Solution {
public:
    
//     bool getNum(vector<int> &st, int indx, int sum, int arm, vector<bool> &vis, int tot){
//         if(tot == 0){
//             return true;
//         }
//         if(sum == arm){
//             return getNum(st, 0, 0, arm, vis, tot-1);
//         }
//         if(indx >= st.size()){
//             return false;
//         }
//         for(int i=indx; i<st.size(); i++){
//             if(!vis[indx]){
//                 if(sum+st[indx] <= arm){
//                     vis[indx] = true;
//                     if(getNum(st, indx+1, sum+st[indx], arm, vis, tot-1)){
//                         return true;
//                     }
//                     vis[indx] = false;
//                 }
//             }
//         }
//         return false;
//     }
    
//     bool makesquare(vector<int>& matchsticks) {
//         int sum = 0;
//         for(auto it:matchsticks){
//             sum += it;
//         }
//         if(sum%4 != 0) return false;
//         sum /= 4;
//         vector<bool> vis(16, false);
//         return getNum(matchsticks, 0, 0, sum, vis, 4);
//     }
    bool vis[16];
    bool canMakeSquare(vector < int > & matchsticks, int currentSum, int oneSideLength, int totalSides, int idx = 0) {
        if (totalSides == 0)
            return true;
        if (currentSum == oneSideLength)
            return canMakeSquare(matchsticks, 0, oneSideLength, totalSides - 1, 0);
        if (idx >= size(matchsticks))
            return false;
        for (int i = idx; i < size(matchsticks); i++) {
            if (!vis[i]) {
                if (currentSum + matchsticks[i] <= oneSideLength) {
                    vis[i] = true;
                    if (canMakeSquare(matchsticks, currentSum + matchsticks[i], oneSideLength, totalSides, i + 1))
                        return true;
                    vis[i] = false;
                }
            }
        }
        return false;
    }

    bool makesquare(vector < int > & matchsticks) {
        memset(vis, false, sizeof(vis));
        int sum = 0;
        for (int i: matchsticks)
            sum += i;
        if (sum % 4)
            return false;
        int oneSideLength = sum / 4;
        int totalSides = 4;
        return canMakeSquare(matchsticks, 0, oneSideLength, totalSides);

    }
};