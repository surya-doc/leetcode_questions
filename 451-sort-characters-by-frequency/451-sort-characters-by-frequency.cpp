class Solution {
public:
    string frequencySort(string s) {
        sort(s.begin(), s.end());
        string ans = "";
        pair<char, int>stor[256] = {{0, 0}};
        for(auto it:s){
            stor[it].first = it;
            ++stor[it].second;
        }
        sort(begin(stor), end(stor), [](pair<char, int>& l, pair<char, int>& r) {
            return (l.second > r.second);});
        for(auto it:stor){
            ans.append(it.second, it.first);
        }
        return ans;
    }
};