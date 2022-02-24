class Solution {
public:
    bool isValid(vector<int> &pos, int mid, int m){
        
        int p = pos[0];
        int place = 1;
        for(int i=1; i<pos.size(); i++){
            if(pos[i]-p >= mid){
                place++;
                p = pos[i];
            }
        }
        if(place >= m) return true;
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 1;
        int r = position[position.size()-1]-l;
        int ans = -1;
        while(l <= r){
            int mid = l+(r-l)/2;
            if(isValid(position, mid, m)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return r;
    }
};