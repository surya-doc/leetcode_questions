class Solution {
public:
    bool vis[16];
    bool getNum(vector<int> &st, int curnt, int oneside, int totside, int indx=0){
        if(totside == 0){
            return true;
        }
        if(curnt == oneside){
            return getNum(st, 0, oneside, totside-1, 0);
        }
        if(indx >= st.size()){
            return false;
        }
        for (int i = indx; i < size(st); i++) {
            if (!vis[i]) {
                if (curnt + st[i] <= oneside) {
                    vis[i] = true;
                    if (getNum(st, curnt + st[i], oneside, totside, i + 1))
                        return true;
                    vis[i] = false;
                }
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        memset(vis, false, sizeof(vis));
        int sum = 0;
        for (int i: matchsticks)
            sum += i;
        if (sum % 4)
            return false;
        int oneSideLength = sum / 4;
        int totalSides = 4;
        return getNum(matchsticks, 0, oneSideLength, totalSides);
    }
//     bool vis[16];
//     bool canMakeSquare(vector < int > & matchsticks, int currentSum, int oneSideLength, int totalSides, int idx = 0) {
//         if (totalSides == 0)
//             return true;
//         if (currentSum == oneSideLength)
//             return canMakeSquare(matchsticks, 0, oneSideLength, totalSides - 1, 0);
//         if (idx >= size(matchsticks))
//             return false;
//         for (int i = idx; i < size(matchsticks); i++) {
//             if (!vis[i]) {
//                 if (currentSum + matchsticks[i] <= oneSideLength) {
//                     vis[i] = true;
//                     if (canMakeSquare(matchsticks, currentSum + matchsticks[i], oneSideLength, totalSides, i + 1))
//                         return true;
//                     vis[i] = false;
//                 }
//             }
//         }
//         return false;
//     }

//     bool makesquare(vector < int > & matchsticks) {
//         memset(vis, false, sizeof(vis));
//         int sum = 0;
//         for (int i: matchsticks)
//             sum += i;
//         if (sum % 4)
//             return false;
//         int oneSideLength = sum / 4;
//         int totalSides = 4;
//         return canMakeSquare(matchsticks, 0, oneSideLength, totalSides);

//     }
};