class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> mp;
        int count = 0;
        for(int i=0; i<sentence.size(); i++){
            if(mp[sentence[i]] == 0){
                mp[sentence[i]]++;
                count++;
            }
            if(count >= 26){
                return true;
            }
        }
        if(count >= 26){
            return true;
        }
        return false;
    }
};