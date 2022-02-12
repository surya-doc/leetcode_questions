class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    int siz = tasks.size();
    if(n == 0) return siz;
    priority_queue<pair<int, char>>pq;
    map<char, int>mp;
    for(auto it:tasks){
        mp[it]++;
    }
    for(auto it:mp){
        pq.push({it.second, it.first});
    }
    int ans = 0;
    while(pq.size() > 0){
        int temp = n;
        vector<pair<int, char>>stor;
        while(temp >= 0){
            if(siz == 0) break;
            if(pq.size() == 0){
                ans++;
            }
            else{
                pair<int, char>t1 = pq.top();
                pq.pop();
                ans++;
                stor.push_back({t1.first-1, t1.second});
                siz--;
            }

            temp--;
        }
        for(auto it:stor){
            if(it.first > 0){
                pq.push(it);           
            }

        }
    }
    return ans;
}
};