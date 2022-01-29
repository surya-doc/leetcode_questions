class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int len = arr.size();
        int ans = 0;
        for(int i=0; i<len; i++){
            int a_xor = arr[i];
            for(int j=i+1; j<len; j++){
                a_xor ^= arr[j];
                if(a_xor == 0){
                    ans += (j-i);
                }
            }
        }
        return ans;
    }
};