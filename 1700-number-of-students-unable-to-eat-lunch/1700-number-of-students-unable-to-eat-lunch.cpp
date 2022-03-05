class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int arr[] = {0, 0};
        for(auto it:students){
            arr[it]++;
        }
        int i=0;
        for(; i<sandwiches.size(); i++){
            if(arr[sandwiches[i]] <= 0) break;
            else{
                arr[sandwiches[i]]--;
            }
        }
        return sandwiches.size()-i;
    }
};