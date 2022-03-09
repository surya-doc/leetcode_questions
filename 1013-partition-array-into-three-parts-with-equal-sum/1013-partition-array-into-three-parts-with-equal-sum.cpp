class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        bool ans = true;
        int count = 0;
        int sum = 0;
        for(auto it:arr){
            sum += it;
        }
        if(sum%3 != 0) return false;
        sum = sum/3;
        int temp = 0;
        for(int i=0; i<arr.size(); i++){
            temp += arr[i];
            if(temp == sum){
                count++;
                temp = 0;
            }
        }
        if(count >= 3) return true;
        return false;
    }
};