class Solution {
public:
    bool findSol(string s, unordered_set<string> &set_save, vector<int> &track, int pos){
        if(pos == s.size()){
            return true;
        }
        if(track[pos] != -1){
            return track[pos];
        }
        for(int i=pos+1; i<=s.size(); ++i){
            string s1 = s.substr(pos, i-pos);
            if(set_save.count(s1) == 1){
                if(findSol(s, set_save, track, i)){
                    track[pos] = 1;
                    return true;
                }
            }
        }
        track[pos] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set_save;
        set_save.insert(wordDict.begin(), wordDict.end());
        vector<int> track(s.length(), -1);
        return findSol(s, set_save, track, 0);
    }
};