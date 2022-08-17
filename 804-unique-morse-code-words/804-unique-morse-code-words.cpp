class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int ans = 0;
        vector<string> arr = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int temp = 0;
        map<char, string> mp;
        unordered_map<string, int> count;
        for(char i='a'; i<='z'; i++){
            mp[i] = arr[temp++];
        }
        for(auto it:words){
            string s = "";
            for(int i=0; i<it.size(); i++){
                s += mp[it[i]];
            }
            if(!count[s]){
                count[s]++;
            }
        }
        ans = count.size();
        return ans;
    }
};