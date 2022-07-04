class Solution {
public:
    int candy(vector<int>& ratings) {
        int j = 0;
        if(ratings.size() == 1){
            return 1;
        }
        int ans = 0;
        
        vector<int> left(ratings.size(), 1);
        vector<int> right(ratings.size(), 1);
        for(int i=1; i<ratings.size(); i++){
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1]+1;
            }
        }
        for(int j=ratings.size()-2; j>=0; j--){
            if(ratings[j] > ratings[j+1]){
                right[j] = right[j+1]+1;
            }
        }
        for(int i=0; i<ratings.size(); i++){
            ans += max(left[i], right[i]);
        }
        return ans;
    }
};