class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>>pq;
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});
        
        string ans = "";
        while(pq.size() > 1){
            pair<int, char>t1;
            pair<int, char>t2;
            t1 = pq.top();
            pq.pop();
            t2 = pq.top();
            pq.pop();
            if(t1.first >= 2){
                ans += string(2, t1.second);
                t1 = {t1.first-2, t1.second};
            }
            else{
                ans += t1.second;
                t1 = {t1.first-1, t1.second};
            }
            if(t2.first >= 2 && t1.first <= t2.first){
                ans += string(2, t2.second);
                t2 = {t2.first-2, t2.second};
            }
            else{
                ans += t2.second;
                t2 = {t2.first-1, t2.second};
            }
            if(t1.first > 0){
                pq.push(t1);
            }
            if(t2.first > 0){
                pq.push(t2);
            }
        }
        if(pq.empty()){
            return ans;
        }
        if(pq.top().first >= 2){
            ans += string(2, pq.top().second);
        }
        else{
            ans += pq.top().second;
        }
        return ans;
    }
};