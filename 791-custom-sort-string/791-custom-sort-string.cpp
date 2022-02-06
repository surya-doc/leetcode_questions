class Solution {
public:
    string customSortString(string order, string s) {
        int flag = 0;
        for(int i=0; i<order.length(); i++){
            int j = 0;
            while(flag < s.length() && j < s.length()){
                if(s[j] == order[i]){
                    swap(s[flag], s[j]);
                    flag++;
                }
                j++;
            }        
        }
        return s;
    }
};