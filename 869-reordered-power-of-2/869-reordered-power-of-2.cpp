class Solution {
public:
    
    bool check(unordered_map<int, int> &mp, int n){
        unordered_map<int, int> mp1;
        int temp = n;
       while(n){
            mp1[n%10]++;
            n /= 10;
        }
        if(mp.size() != mp1.size()){
            return false;
        }
        for(auto it:mp){
            if(mp1[it.first] != it.second){
                return false;
            }
        }
        return true;
    }
    
    bool reorderedPowerOf2(int n) {
        unordered_map<int, int> mp;
        int temp = n;
        while(n){
            mp[n%10]++;
            n /= 10;
        }
        for(int i=0; i<31; i++){
            // cout << (1 << i) << "\n";
            int a = (1 << i);
            if(check(mp, a)){
                return true;
            }
        }
        return false;
    }
};