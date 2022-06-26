class Solution {
public:
    int countAsterisks(string s) {
        int total = 0;
        int even = 0;
        
        for(auto it:s){
            if(it == '|' && even == 1){
                even = 0;
            }
            else if(it == '|' && even == 0){
                even = 1;
            }
            else{
                if(it == '*' && even != 1){
                    total++;
                }
            }
        }
        return total;
    }
};