class Solution {
public:
    void getPoints(vector<int> &data, set<pair<int, int>> &st){
        int x = data[0];
        int y = data[1];
        int r = data[2];
        int temp = 0;
        for(int i=x-r; i<=x+r; i++){
            for(int j=y-r; j<=y+r; j++){
                // cout << "(" << i << "," << j << ")" << " ";
                if((x-i)*(x-i)+(y-j)*(y-j) <= r*r){
                    st.insert({i, j});
                }
            }
        }
    }
    
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int, int>> st;
        int ans = 0;
        for(int i=0; i<circles.size(); i++){
            getPoints(circles[i], st);
        }
        ans = st.size();
        return ans;
    }
};