class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> list, sub;
        for(auto it:nums){
            list[it]++;
        }
        for(auto it:nums){
            if(list[it] == 0){
                continue;
            }
            list[it]--;
            if(sub[it-1] > 0){
                sub[it-1]--;
                sub[it]++;
            }
            else if(list[it+1] > 0 && list[it+2] > 0){
                list[it+1]--;
                list[it+2]--;
                sub[it+2]++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

bool isPossible(vector<int>& A) {
        unordered_map<int, int> left, end;
        for (int i: A) {
            left[i]++;
        }
        for (int i: A) {
            if (left[i] == 0) continue;
            left[i]--;
            if (end[i - 1] > 0) {   
                end[i - 1]--;
                end[i]++;
            } else if (left[i + 1] > 0 && left[i + 2] > 0) {
                left[i + 1]--;
                left[i + 2]--;
                end[i + 2]++;
            } else {   
                return false;
            }
        }
        return true;
    }