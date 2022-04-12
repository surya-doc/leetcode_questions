class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i=1; i<n; i++){
            string temp = "";
            int siz = ans.size();
            // int i = 0;
            int count = 1;
            char a = ans[0];
            for(int i=1; i<siz; i++){
                if(ans[i] != a){
                    temp += to_string(count);
                    temp += a;
                    count = 1;
                    a = ans[i];
                }
                else{
                    count++;
                }
            }
            
            temp += to_string(count);
            temp += a;
            ans = temp;
        }
        return ans;
    }
};