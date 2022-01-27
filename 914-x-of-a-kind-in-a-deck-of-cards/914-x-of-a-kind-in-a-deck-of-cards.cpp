class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int>ct;
        int count;
        if(deck.size() <= 1) return false;
        for(auto i:deck){
            ct[i]++;
        }
        count = ct[deck[0]];
        for(auto it:ct){
           count = gcd(count, it.second);
        }
        if(count == 1) return false;
        return true;
    }
};