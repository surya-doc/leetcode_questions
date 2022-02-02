class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int mp[2] = {};
        int ans = 0;
        for(int i=0; i<s1.length(); i++){
            if(s1[i] == 'x' && s2[i] == 'y'){
                mp[0]++;
            }
            else if(s1[i] == 'y' && s2[i] == 'x'){
                mp[1]++;
            }
        }
        for(auto it:mp){
            cout << it;
        }
        if((mp[0]%2 == 0 && mp[1]%2 != 0) || (mp[0]%2 != 0 && mp[1]%2 == 0)){
            return -1;
        }
        else{
            int temp_1 = mp[0]/2;
            int temp_2 = mp[1]/2;
            ans = temp_1+temp_2+(mp[0]%2)*2;
            
            cout << temp_1;
        }
        return ans;
    }
};