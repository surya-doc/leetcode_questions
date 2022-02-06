class Solution {
public:
    int calCulatePower(int num, int steps, unordered_map<int, int> &mp){
        if(num == 1) return steps;
        if(num%2 != 0){
            if(mp[(num*3)+1]) return mp[(num*3)+1]+1;
            else steps = calCulatePower((num*3)+1, steps, mp)+1;
        }
        else{
            if(mp[num/2]) return mp[num/2]+1;
            else steps = calCulatePower(num/2, steps, mp)+1;
        }
        mp[num] = steps;
        return steps;
    }
    
    static int sort_1(vector<int> &x, vector<int> &y){
        if(x[0] != y[0]) return x[0] < y[0];
        return x[1] < y[1];
    }
    
    int getKth(int lo, int hi, int k) {
        int ans = 1;
        unordered_map<int, int>mp;
        vector<vector<int>>stor;
        for(int i=lo; i<=hi; i++){
            int temp = calCulatePower(i, 0, mp);
            stor.push_back({temp, i});
        }
        sort(stor.begin(), stor.end(), sort_1);
        return stor[k-1][1];
    }
};