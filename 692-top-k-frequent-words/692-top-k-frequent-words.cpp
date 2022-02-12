class Solution {
public:
    struct compair{
       bool operator()(const pair<int, string> &x1, const pair<int, string> &x2){
            if(x1.first == x2.first){
                return x1.second < x2.second;
            }
            else{
                return x1.first > x2.first;
            }
        } 
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int>mp;
        for(int i=0; i<words.size(); i++){
            mp[words[i]]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, compair>pq;
        for(auto it:mp){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<string>ans;
        while(pq.size() > 0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};